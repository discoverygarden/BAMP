//(function($){ // wrap for drupal

//alert(Drupal.settings.base_path);
	var styleStr = '';
	styleStr += '<style>';
	styleStr += '.MDR_labelStyle {background: #FFFF40;font: bold 10px verdana;text-align: left;border: 1px solid gray;width: 180px;padding: 2px;}';
	styleStr += '</style>';
	styleStr += '<script src="/dragmap/elabel.js"></script>';
	document.write(styleStr);


MPolyDragControl = function(MOptions) {
	MOptions = MOptions ? MOptions : {};
	this.map = MOptions.map ? MOptions.map : null;

	this.initialize()
};


MPolyDragControl.prototype.initialize = function() {
	this.self = this;
	this.polyInitialized = false;
	this.bounds = null;

	this.dragMarker0;
	this.dragMarker1;

	var baseIcon = new GIcon();
	baseIcon.iconSize = new GSize(11,11);
	baseIcon.iconAnchor = new GPoint(6,6);
	baseIcon.infoWindowAnchor = new GPoint(1,1);
	baseIcon.dragCrossSize = new GSize(0,0);
	baseIcon.maxHeight = 0.1;

	this.dragImage = appRoot + "images/polyEditSquare.png";
	this.transImage = appRoot + "images/transparent.png";
	this.polyEditIcon = (new GIcon(baseIcon, this.dragImage));
	this.transIcon = (new GIcon(baseIcon, this.transImage));

	this.floatingLabel = new ELabel(this.map.getCenter(), 'Label text', 'MDR_labelStyle',new GSize(10,20));
	this.floatingLabel.hide();
	this.map.addOverlay(this.floatingLabel); 

	this.addMarkers();
	this.enableTransMarker();

};


MPolyDragControl.prototype.addMarkers = function() {
	var self = this.self;
//	GEvent.addListener(this.map,'click',function(a,b,c){self.mapClick(b)});

	this.dragMarker0 = new GMarker(this.map.getCenter(),{icon:this.transIcon,draggable:true,bouncy:false,dragCrossMove:true});
	this.map.addOverlay(this.dragMarker0);

	this.mdListener = GEvent.addListener(this.dragMarker0,'mousedown',function(){self.markerMouseDown()});
	GEvent.addListener(this.dragMarker0,'dragstart',function(){self.dragStart(this)});
	GEvent.addListener(this.dragMarker0,'drag',function(){self.drag(this)});
	GEvent.addListener(this.dragMarker0,'dragend',function(){self.dragEnd(this)});

	this.dragMarker1 = new GMarker(this.map.getCenter(),{icon:this.polyEditIcon,draggable:true,bouncy:false,dragCrossMove:true});
	this.map.addOverlay(this.dragMarker1);
	GEvent.addListener(self.dragMarker1,'dragstart',function(){self.dragStart(this)});
	GEvent.addListener(self.dragMarker1,'drag',function(){self.drag(this)});
	GEvent.addListener(self.dragMarker1,'dragend',function(){self.dragEnd(this)});
	this.dragMarker1.hide();
}


MPolyDragControl.prototype.markerMouseDown = function() {
	var self = this.self;
	this.dragMarker0.setImage(this.dragImage);
	this.dragMarker1.setLatLng(this.dragMarker0.getLatLng());
	this.dragMarker1.show();
	GEvent.removeListener(this.mdListener);
}

MPolyDragControl.prototype.mapClick = function(latlon) {
	var self = this.self;
	this.poly = new GPolygon([latlon,latlon,latlon,latlon,latlon],'#0000ff',1,1,'#0000ff',0.3);
	this.map.addOverlay(this.poly);

	GEvent.trigger(self.dragMarker1,'dragstart');
};


MPolyDragControl.prototype.enableTransMarker = function() {
	var self = this.self;
	this.dragMarker0.setImage(this.transImage);
	this.movelistener = GEvent.addListener(this.map,'mousemove',function(latlon){
		self.dragMarker0.setLatLng(latlon);
	});
}

MPolyDragControl.prototype.disableTransMarker = function() {
	GEvent.removeListener(this.movelistener);
}

MPolyDragControl.prototype.reset = function() {
	var self = this.self;
	if (this.poly) {
		this.poly.hide();
	}

	if (this.dragMarker1) {
		this.dragMarker1.hide();
	}
	if (this.floatingLabel) {
		this.floatingLabel.hide();
	}

	this.enableTransMarker();
	this.mdListener = GEvent.addListener(this.dragMarker0,'mousedown',function(){self.markerMouseDown()});

};




MPolyDragControl.prototype.dragStart = function(marker) {
	var self = this.self;
};

MPolyDragControl.prototype.drag = function() {
	var self = this.self;
	self.updateRectangle();
};	

MPolyDragControl.prototype.dragEnd = function() {
	var self = this.self;
	if (typeof self.ondragend == 'function') {
		self.ondragend();
	}
	self.disableTransMarker();
};





MPolyDragControl.prototype.updateRectangle = function() {
	var self = this.self;
	var latlon0 = self.dragMarker0.getLatLng();
	var latlon1 = self.dragMarker1.getLatLng();

	self.bounds = null;
	self.bounds = new GLatLngBounds();

// not sure why this if/else is here, every block is the exact same
	if (latlon0.lat() <= latlon1.lat() && latlon0.lng() <= latlon1.lng()) {
		var p1 = latlon0; // SW
		var p2 = latlon1; // NE
	}
	else if (latlon0.lat() <= latlon1.lat() && latlon0.lng() >= latlon1.lng()) {
		var p1 = latlon0; // SE
		var p2 = latlon1; // NW
	}
	else if (latlon0.lat() >= latlon1.lat() && latlon0.lng() >= latlon1.lng()) {
		var p1 = latlon0; // NE
		var p2 = latlon1; // SW
	}
	else if (latlon0.lat() >= latlon1.lat() && latlon0.lng() <= latlon1.lng()) {
		var p1 = latlon0; // NW
		var p2 = latlon1; // SE
	}

	self.bounds.extend(p1);
	self.bounds.extend(p2);

	var p1 = this.bounds.getSouthWest();
	var p2 = new GLatLng(this.bounds.getNorthEast().lat(),this.bounds.getSouthWest().lng());
	var p3 = this.bounds.getNorthEast();
	var p4 = new GLatLng(this.bounds.getSouthWest().lat(),this.bounds.getNorthEast().lng());
	var points = Array(p1,p2,p3,p4,p1);

	self.drawPoly(points);

};


MPolyDragControl.prototype.drawPoly = function(points) {
	if (this.poly) {
		this.map.removeOverlay(this.poly);
		this.poly = null;
	}
	this.poly = new GPolygon(points,'#0000ff',1,1,'#0000ff',0.2);
	this.map.addOverlay(this.poly);

	var html = '';
	html += 'Lat:&nbsp;' + this.bounds.getSouthWest().lat().toFixed(5) + '&nbsp;to&nbsp;' + this.bounds.getNorthEast().lat().toFixed(5) + '<br>';
	html += 'Lon:&nbsp;' + this.bounds.getSouthWest().lng().toFixed(5) + '&nbsp;to&nbsp;' + this.bounds.getNorthEast().lng().toFixed(5) + '<br>';
	
	this.floatingLabel.setContents(html);
	this.floatingLabel.setPoint(this.dragMarker1.getLatLng());
	this.floatingLabel.show();
}


MPolyDragControl.prototype.getParams = function() {
  if (!this.bounds){
    return "";
  }
  var str =   'latitude_avg[min]=' + this.bounds.getSouthWest().lat().toFixed(5) +  '&latitude_avg[max]=' + this.bounds.getNorthEast().lat().toFixed(5)
          + '&longitude_avg[min]=' + this.bounds.getSouthWest().lng().toFixed(5) + '&longitude_avg[max]=' + this.bounds.getNorthEast().lng().toFixed(5);

  return str;
}

MPolyDragControl.prototype.setType = function(type) {
	this.type = type;
	if (this.poly) {
		this.drag();
		this.dragEnd();
	}
};




MPolyDragControl.prototype.show = function() {
	this.poly.show();
};

MPolyDragControl.prototype.hide = function() {
	this.poly.hide();
};

MPolyDragControl.prototype.isVisible = function() {
	return !this.poly.isHidden();
};

//})(jQuery); // wrap for drupal
