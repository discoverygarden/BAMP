//(function($){ // wrap for drupal

var map;
var container;
var polyDragControl;
var infoWnd = new google.maps.InfoWindow();

function load() {
  container = document.getElementById("mapDiv");
  //map = new GMap2(container, {draggableCursor:"crosshair"});
  var options = {
    zoom: 9,
    mapTypeId: google.maps.MapTypeId.HYBRID,
    streetViewControl: false,
    draggable: false,
  };
  map = new google.maps.Map(container, options);

  //map.addControl(new GScaleControl());
  //map.addControl(new GLargeMapControl());
  //map.addControl(new GMapTypeControl());
  //map.enableScrollWheelZoom();		

  var json = JSON.parse(Drupal.settings.mapping);
//  console.log(json);
  // and add them to the map
  var x = 0, y = 0;
  for (var i=0; i<json.row.length; i++){
    //console.log(json.row[i]);
    var point = new google.maps.LatLng(json.row[i].lat, json.row[i].lng);
    var mrkr = new google.maps.Marker({
      position: point,
      map: map,
    });
    mrkr.set("code", json.row[i].code);
    google.maps.event.addListener(mrkr, 'click', function(){showInfoWnd(this);});
    x += point.lat();
    y += point.lng();
  }
  // auto-calculate the center position
  centerPoint = new google.maps.LatLng(x/json.row.length, y/json.row.length);
  map.setCenter(centerPoint);
//  google.maps.event.addListener(map, 'click', function(){infoWnd.close();});

  polyDragControl = new MPolyDragControl({map:map});
  polyDragControl.ondragend = getParameters;

}

function getParameters() {
  var params = polyDragControl.getParams();
  var url = '';
  url += params;

  document.getElementById('coords').value = url;
  //return url;
}

function eraseSelection() {
  polyDragControl.clearRectangle();
}

function unload() {
//	GUnload();
}

function showInfoWnd(marker){
  var pos = marker.getPosition();
  
  var caption = marker.get("code") + '<br>' + pos.lat().toFixed(5) + '&deg; lat, ' + pos.lng().toFixed(5) + '&deg; lon';
  infoWnd.setOptions({position: marker.position, content: caption});
  infoWnd.open(marker.map, map);
  infoWnd.open(marker.map, marker);
}

//Drupal.Behaviors.mapping = load;
window.onload = load;
//window.onfocus = loadmap;
window.onunload = unload;

//})(jQuery); // wrap for drupal
