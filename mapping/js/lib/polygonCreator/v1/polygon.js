function PolygonCreator(map){
  //create pen to draw on map
  this.map = map;
  this.pen = new Pen(this.map);
  var thisOjb=this;
  this.event=google.maps.event.addListener(thisOjb.map, 'click', function(event) {
    thisOjb.pen.draw(event.latLng);
  });//end addListener

  this.showData = function(){
    return this.pen.getData();
  }//end showdata

  this.showColor = function(){
    return this.pen.getColor();
  }//end showcolor

  //destroy the pen
  this.destroy = function(){
    this.pen.deleteMis();
    if(null!=this.pen.polygon){
      this.pen.polygon.remove();
    }//end if
    google.maps.event.removeListener(this.event);
  }//end destroy
}//end polygonCreator

//Pen Class
function Pen(map){
  this.map= map;
  this.listOfDots = new Array();
  this.polyline =null;
  this.polygon = null;
  this.currentDot = null;

  //draw function
  this.draw = function(latLng){
    if (null != this.polygon) {
      alert('Click Reset Selection to draw another');
    }else {
      if (this.currentDot != null && this.listOfDots.length > 1 && this.currentDot == this.listOfDots[0]) {
        this.drawPloygon(this.listOfDots);
      }else {
        //remove previous line
        if(null!=this.polyline){
          this.polyline.remove();
        }
        //draw Dot
        var dot = new Dot(latLng, this.map, this);
        this.listOfDots.push(dot);
        //draw line
        if(this.listOfDots.length > 1){
          this.polyline = new Line(this.listOfDots, this.map);
        }//end if
      }//end if
    }//end if
  }//end draw

  //draw ploygon
  this.drawPloygon = function (listOfDots,color,des,id){
    this.polygon = new Polygon(listOfDots,this.map,this,color,des,id);
    this.deleteMis();
  }//end drawPolygon

  //delete all dots and polylines
  this.deleteMis = function(){
    //delete dots
    jQuery.each(this.listOfDots, function(index, value){
      value.remove();
    });
    this.listOfDots.length=0;

    //delete lines
    if(null!=this.polyline){
      this.polyline.remove();
      this.polyline=null;
    }//end if
  }//end deleteMis();

  //cancel
  this.cancel = function(){
    if(null!=this.polygon){
      (this.polygon.remove());
    }//end if
    this.polygon=null;
    this.deleteMis();
  }//end cancel();

  //setter
  this.setCurrentDot = function(dot){
    this.currentDot = dot;
  }//end setCurrentDot();

  //getter
  this.getListOfDots = function(){
    return this.listOfDots;
  }//end getListofDots();

  //get plots data
  this.getData = function(){
    if(this.polygon!=null){
      var data =[];
      var paths = this.polygon.getPlots();

      //get paths
      paths.getAt(0).forEach(function(value, index){
        var lat = value.lat();
        var lon = value.lng();
        var p = {lat: lat, lng: lon};
        data.push(p);
      });//end getPaths

      return data;
    }else {
      return null;
    }//end if
  }//end getData();

  //get color
  this.getColor = function(){
    if(this.polygon!=null){
      var color = this.polygon.getColor();
      return color;
    }else {
      return null;
    }//end if
  }//end getColor()
}//end pen class

/* Child of Pen class
 * dot class
*/
function Dot(latLng,map,pen){
  //property
  this.latLng=latLng;
  this.parent = pen;
  this.markerObj = new google.maps.Marker({
    position: this.latLng,
    map: map
  });

  //closure
  this.addListener = function(){
    var parent=this.parent;
    var thisMarker=this.markerObj;
    var thisDot=this;
    google.maps.event.addListener(thisMarker, 'click', function() { 
      parent.setCurrentDot(thisDot);
      parent.draw(thisMarker.getPosition());
    });
  }//end addListener();
  this.addListener();

  //getter 
  this.getLatLng = function(){
    return this.latLng;
  }

  this.getMarkerObj = function(){
    return this.markerObj;
  }

  this.remove = function(){
    this.markerObj.setMap(null);
  }
}//end Dot class


/* Child of Pen class
 * Line class
*/
function Line(listOfDots,map){
  this.listOfDots = listOfDots;
  this.map = map;
  this.coords = new Array();
  this.polylineObj=null;

  if (this.listOfDots.length > 1) {
    var thisObj=this;
    jQuery.each(this.listOfDots, function(index, value){
      thisObj.coords.push(value.getLatLng());
    });//end each

    this.polylineObj  = new google.maps.Polyline({
      path: this.coords,
      strokeColor: "#FF0000",
      strokeOpacity: 1.0,
      strokeWeight: 2,
      map: this.map
    });//end new gmapPolyline
  }//end if

  this.remove = function(){
    this.polylineObj.setMap(null);
  }//end remove();
}//end line class

/* Child of Pen class
* polygon class
*/
function Polygon(listOfDots,map,pen,color){
  this.listOfDots = listOfDots;
  this.map = map;
  this.coords = new Array();
  this.parent = pen;
  this.des = 'Hello';

  var thisObj=this;
  jQuery.each(this.listOfDots,function(index,value){
    thisObj.coords.push(value.getLatLng());
  });//end each

  this.polygonObj= new google.maps.Polygon({
    paths: this.coords,
    strokeColor: "#FF0000",
    strokeOpacity: 0.8,
    strokeWeight: 2,
    fillColor: "#FF0000",
    fillOpacity: 0.35,
    map:this.map
  });//end gmapPolygon

  window.shape = this.polygonObj;
  window.refreshMap();

  this.remove = function(){
    this.info.remove();
    this.polygonObj.setMap(null);
  }//end remove();

  this.getContent = function(){
    return this.des;
  }//end getContent();

  this.getPolygonObj= function(){
    return this.polygonObj;
  }//end getPolygonObj();

  this.getListOfDots = function (){
    return this.listOfDots;
  }//end getListOfDots();

  this.getPlots = function(){
    return this.polygonObj.getPaths();
  }//end getPlots();

  this.getColor=function(){
    return 	this.getPolygonObj().fillColor;
  }//end getColor();

  this.setColor = function(color){
    return this.getPolygonObj().setOptions({fillColor:color,strokeColor:color,strokeWeight: 2});
  }//end setColor();

  this.info = new Info(this,this.map);

  //closure
  this.addListener = function(){
    var info=this.info;
    var thisPolygon=this.polygonObj;
    google.maps.event.addListener(thisPolygon, 'rightclick', function(event) {
      info.show(event.latLng);
    });//end gmapAddListener
  }//end addListener();
  this.addListener();
}//end Polygon class

/*
* Child of Polygon class
* Info Class
*/
function Info(polygon,map){
  this.parent = polygon;
  this.map = map;

  this.color =  document.createElement('input');

  this.button = document.createElement('input');
  jQuery(this.button).attr('type','button');
  jQuery(this.button).val("Change Color");
  var thisOjb=this;


  //change color action
  this.changeColor= function(){
    thisOjb.parent.setColor(jQuery(thisOjb.color).val());
  }//end changeColor

  //get content
  this.getContent = function(){
    var content = document.createElement('div');

    jQuery(this.color).val(this.parent.getColor());
    jQuery(this.button).click(function(){
      thisObj.changeColor();
    });//end click

    jQuery(content).append(this.color);
    jQuery(content).append(this.button);
    return content;
  }//end getContent();

  thisObj=this;
  this.infoWidObj = new google.maps.InfoWindow({
    content:thisObj.getContent()
  });//end gmapInfoWindow

  this.show = function(latLng){
    this.infoWidObj.setPosition(latLng);
    this.infoWidObj.open(this.map);
  }//end show();

  this.remove = function(){
    this.infoWidObj.close();
  }//end remove();
}//end info class
