//(function($){ // wrap for drupal

var appRoot = 'http://' + window.location.host + '/';

var map;
var container;
var zoom = 10;
var centerPoint = new GLatLng(50.62,-126.25);
var polyDragControl;

function load() {
	if (GBrowserIsCompatible()) {
		container = document.getElementById("mapDiv");
		map = new GMap2(container, {draggableCursor:"crosshair"});

		map.setCenter(centerPoint, zoom);
    map.setMapType(G_HYBRID_MAP);
		map.addControl(new GScaleControl());
		map.addControl(new GLargeMapControl());
		map.addControl(new GMapTypeControl());
		map.enableScrollWheelZoom();		

    // the table at the bottom to display the mouse information
		//var pos = new GControlPosition(G_ANCHOR_BOTTOM_LEFT, new GSize(0, -85));
		//map.addControl(new MStatusControl({position:pos}));

		polyDragControl = new MPolyDragControl({map:map,type:'rectangle'});
		polyDragControl.ondragend = getParameters;
	}
}

function getParameters(){
  var params = polyDragControl.getParams();
  var url = '';
//  url += appRoot;
//  url += 'bamp/';
//  url += '?q='; //this clean_url code doesnt work right //(variable_get('clean_url', 0) ? '' : '?q=');
//  url += 'map_report';
  url += params;

  document.getElementById('coords').value = url;
  //return url;
}

function unload() {
	GUnload();
}

window.onload = load;
window.onunload = unload;

//})(jQuery); // wrap for drupal
