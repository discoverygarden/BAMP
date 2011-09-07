//(function($){ // wrap for drupal

MPolyDragControl = function(MOptions) {
	MOptions = MOptions ? MOptions : {};
	this.map = MOptions.map ? MOptions.map : null;

	this.initialize()
};

MPolyDragControl.prototype.initialize = function() {
  this.self = this;
  this.bounds = null;
  this.poly = null;

// maybe we should use two different images since they behave slightly different
  var path = Drupal.settings.imagePath + "/polyEditSquare.png";
  this.dragImage = new google.maps.MarkerImage(path, new google.maps.Size(10,10), new google.maps.Point(0,0), new google.maps.Point(5,5));

  this.dragging = false;
  this.addMarkers();

  this.poly = new google.maps.Rectangle({
    bounds: null,//new google.maps.LatLngBounds(new google.maps.LatLng(50, -130), new google.maps.LatLng(60, -120)),
    clickable: false,
    fillColor: "#0000FF",
    fillOpacity: 0.25,
    strokeColor: "#0000FF",
    strokeOpacity: 0.5,
    map:this.map,
  });
}

MPolyDragControl.prototype.addMarkers = function() {
  var self = this.self;

  var opts = {
    icon:this.dragImage,
    draggable:true,
    bouncy:false,
    dragCrossMove:true,
    position:this.map.getCenter(),
    map:this.map,
    raiseOnDrag:false,
  };
  this.mdListener = google.maps.event.addListener(this.map, 'mousedown', function(latlon){self.markerMouseDown(latlon)});
  this.muListener = google.maps.event.addListener(this.map, 'mouseup', function(latlon){self.markerMouseUp(latlon)});
  this.mmListener = google.maps.event.addListener(this.map, 'mousemove', function(latlon){self.markerMouseDrag(latlon)});

  // create marker 0
  this.dragMarker0 = new google.maps.Marker(opts);
  // hude this until we're ready
  this.dragMarker0.setVisible(false);
  // create marker 1
  this.dragMarker1 = new google.maps.Marker(opts);
	// hide it since we don't need it yet
	this.dragMarker1.setVisible(false);

  // update the rectangles when dragged
  google.maps.event.addListener(this.dragMarker0, 'drag', function(event){self.updateMarker0()});
  google.maps.event.addListener(this.dragMarker1, 'drag', function(event){self.updateMarker1()});
  // update the export corrdinates when finished
  google.maps.event.addListener(this.dragMarker0, 'dragend', function(event){self.finishDrag()});
  google.maps.event.addListener(this.dragMarker1, 'dragend', function(event){self.finishDrag()});

}

MPolyDragControl.prototype.markerMouseDown = function(latlon) {
  this.dragMarker0.setVisible(true);
	this.dragMarker1.setPosition(latlon.latLng); // place marker1 at the start of the rectangle
	this.dragMarker1.setVisible(true); // show marker 1

  this.dragging = true;
  // stop listening for mouse down
//	google.maps.event.removeListener(this.mdListener);
}

MPolyDragControl.prototype.markerMouseDrag = function(latlon){
  if (this.dragging){
    this.dragMarker0.setPosition(latlon.latLng);
    this.updateRectangle();
  }
}

MPolyDragControl.prototype.markerMouseUp = function(latlon){
//  google.maps.event.removeListener(this.mmListener);
//  google.maps.event.remove(this.muListener);
//  google.maps.event.addListener(this.mdListener);
  this.dragging = false;
  this.updateRectangle();
  this.finishDrag();
}

MPolyDragControl.prototype.updateMarker0 = function(){
//  if (dragging) return;
//  this.dragMarker0.setPosition(latlon.latLng);
  this.updateRectangle();
}
MPolyDragControl.prototype.updateMarker1 = function(){
//  if (dragging) return;
//  this.dragMarker1.setPosition(latlon.latLng);
  this.updateRectangle();
}

MPolyDragControl.prototype.updateRectangle = function() {

	this.bounds = new google.maps.LatLngBounds();
	this.bounds.extend(this.dragMarker0.getPosition());
	this.bounds.extend(this.dragMarker1.getPosition());

	this.poly.setBounds(this.bounds);
}

MPolyDragControl.prototype.finishDrag = function(){
  if (typeof this.ondragend == 'function')
    this.ondragend();
}

MPolyDragControl.prototype.clearRectangle = function(){
  this.poly.setBounds(null);
  this.dragMarker0.setVisible(false);
  this.dragMarker1.setVisible(false);
}

MPolyDragControl.prototype.getParams = function() {
  var bounds = this.poly.getBounds();
  if (!this.poly){
    return "";
  }
  var str =   'latitude[min]=' + this.bounds.getSouthWest().lat().toFixed(5) +  '&latitude[max]=' + this.bounds.getNorthEast().lat().toFixed(5)
          + '&longitude[min]=' + this.bounds.getSouthWest().lng().toFixed(5) + '&longitude[max]=' + this.bounds.getNorthEast().lng().toFixed(5);

  return str;
}

//})(jQuery); // wrap for drupal
