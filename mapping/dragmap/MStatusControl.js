//(function($){ // wrap for drupal

/*
MStatusControl

Copyright 2008 - Marcelo Montagna  - http://maps.forum.nu

Free to use as long as copyright notices are left unchanged.
Please save the file to your own server. Do not link directly,
or unexpected things might happen to your control :-)

------------------------------------------------------------
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
------------------------------------------------------------

Note: This script contains code to prevent hotlinking. (marked with 'REMOVE')
You need to remove it when saving the file to your server.


Usage:
	map.addControl(new MStatusControl());
	map.addControl(new MStatusControl(options?));
	map.addControl(new MStatusControl({param:value}));

MStatusControl options:
	Position: GControlPosition()
	background: HTML color - Default: '#eeeeee';
	foreground: HTML color - Default: '#000000';
*/

/////////////////////////////////////////////////////////////////////////////


function MStatusControl(MOptions) {
	MOptions = MOptions ? MOptions : {};
	this.background = MOptions.background ? MOptions.background : '#eeeeee';
	this.foreground = MOptions.foreground ? MOptions.foreground : '#000000';
	this.position = MOptions.position ? MOptions.position : new GControlPosition(G_ANCHOR_BOTTOM_LEFT, new GSize(0, 45));
	this.parent = MOptions.container ? MOptions.container : null;
}

MStatusControl.prototype = new GControl(true,true);

MStatusControl.prototype.initialize = function(map) {

	var globalThis_3456 = this;
	this.map = map;
	this.projection = this.map.getCurrentMapType().getProjection();

	this.container = document.createElement('div');

	var w = this.map.getContainer().clientWidth - 2;
	this.container.style.width = w + 'px';

	this.container.style.backgroundColor = this.background;
	this.container.style.border = '1px solid gray';

	var innerDiv = document.createElement('div');
	this.container.appendChild(innerDiv);

	
	var crDiv = document.createElement('div');
	this.container.appendChild(crDiv);
	crDiv.innerHTML = 'Marcelo Montagna&copy;2008 - <a style="color: #aaaaaa;" href="http://maps.forum.nu" target="_blank">http://maps.forum.nu</a>';
	crDiv.style.padding = '2px';
	crDiv.style.marginTop = '2px';
	crDiv.style.textAlign = 'right';
	crDiv.style.color =  '#aaaaaa';
	crDiv.style.backgroundColor =  '#eeeeee';
	crDiv.style.font = 'normal 10px verdana';

// this creates the table at the bottom that displays the cursor information

	var oTable = document.createElement('table');

	oTable.setAttribute('cellSpacing','0');
	oTable.setAttribute('cellPadding','0');
	oTable.style.width = '100%';

	innerDiv.appendChild(oTable);


	var oTableBody = document.createElement('tbody');
	oTable.appendChild(oTableBody);


	//-------------------------	
		var oRow = document.createElement('tr');
		oTableBody.appendChild(oRow);

		this.centerDisplay = document.createElement('td');
		this.setStyleValue(this.centerDisplay);
//		this.centerDisplay.style.width = iWidth + 'px';
		oRow.appendChild(this.centerDisplay);

		this.mouseDisplay = document.createElement('td');
		this.setStyleValue(this.mouseDisplay);
//		this.mouseDisplay.style.width = iWidth + 'px';
		oRow.appendChild(this.mouseDisplay);

	//-------------------------	

		var oRow = document.createElement('tr');
		oTableBody.appendChild(oRow);

		this.swDisplay = document.createElement('td');
		this.setStyleValue(this.swDisplay);
		oRow.appendChild(this.swDisplay);

		this.mousePxDisplay = document.createElement('td');
		this.setStyleValue(this.mousePxDisplay);
		oRow.appendChild(this.mousePxDisplay);
	//-------------------------	

		var oRow = document.createElement('tr');
		oTableBody.appendChild(oRow);

		this.neDisplay = document.createElement('td');
		this.setStyleValue(this.neDisplay);
		oRow.appendChild(this.neDisplay);

		this.mouseTileDisplay = document.createElement('td');
		this.setStyleValue(this.mouseTileDisplay);
		oRow.appendChild(this.mouseTileDisplay);
	//-------------------------	

		var oRow = document.createElement('tr');
		oTableBody.appendChild(oRow);

		this.zDisplay = document.createElement('td');
		this.setStyleValue(this.zDisplay);
		oRow.appendChild(this.zDisplay);

		this.clickDisplay = document.createElement('td');
		this.setStyleValue(this.clickDisplay);
		oRow.appendChild(this.clickDisplay);
	//-------------------------	


	this.mouseDisplay.innerHTML = 'Mouse(LatLon):'
	this.mousePxDisplay.innerHTML = 'Mouse(Px):'
	this.mouseTileDisplay.innerHTML = 'Mouse Tile:'
	this.clickDisplay.innerHTML = 'Mouse Click:'



	if (this.parent) {
		this.parent.appendChild(container);
	}
	else {
		this.map.getContainer().appendChild(this.container);
	}

	GEvent.addListener(this.map, "click", function(ol,pt){globalThis_3456.MMapClick(pt)});
	GEvent.addListener(this.map, "moveend", function(){globalThis_3456.MMoveEnd()});
	GEvent.addListener(this.map, "zoomend", function(){globalThis_3456.MZoomEnd()});
	GEvent.addListener(this.map, "mousemove", function(pt){globalThis_3456.MMouseMove(pt)});





this.MMapClick = function (pt) {
	var point = pt ? pt : null; 
	if (point) {
		this.clickDisplay.innerHTML = 'Mouse Click:&nbsp;&nbsp;' + point.lat().toFixed(6) + ',&nbsp;' + point.lng().toFixed(6);
	}
}

this.MMoveEnd = function() {
	this.MUpdateStatus();
}
this.MZoomEnd = function() {
	this.MUpdateStatus();
}


this.MMouseMove = function(mousePt) {
	var zoom = this.map.getZoom();
	var mousePx = this.projection.fromLatLngToPixel(mousePt, zoom);

	this.mouseDisplay.innerHTML = 'Mouse(LatLon):' + mousePt.lat().toFixed(6) + ',&nbsp;' + mousePt.lng().toFixed(6);
	this.mousePxDisplay.innerHTML = 'Mouse(Px):&nbsp;&nbsp;&nbsp;&nbsp;' + mousePx.x + ',&nbsp;' + mousePx.y;
	this.mouseTileDisplay.innerHTML = 'Mouse Tile: &nbsp;&nbsp;' + Math.floor(mousePx.x / 256) + ',&nbsp;' + Math.floor(mousePx.y / 256);
}

this.MUpdateStatus = function() {
	var center = this.map.getCenter();
	var zoom = this.map.getZoom();

	var bounds = this.map.getBounds();
	var SW = bounds.getSouthWest();
	var NE = bounds.getNorthEast();

	this.centerDisplay.innerHTML = 'Map Center:&nbsp;' + center.lat().toFixed(6) + ',&nbsp;' + center.lng().toFixed(6);
	this.swDisplay.innerHTML = 'Map SW:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;' + SW.lat().toFixed(6) + ',&nbsp;' + SW.lng().toFixed(6);
	this.neDisplay.innerHTML = 'Map NE:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;' + NE.lat().toFixed(6) + ',&nbsp;' + NE.lng().toFixed(6);
	this.zDisplay.innerHTML = 'Map Zoom:&nbsp;&nbsp;&nbsp;' + zoom;
}


	this.MUpdateStatus();

	return this.container;
}


MStatusControl.prototype.getDefaultPosition = function() {
	return this.position;
}



////////////////////////////


MStatusControl.prototype.setStyleValue = function(obj) {
	obj.style.padding = '0px';
	obj.style.paddingRight = '2px';
	obj.style.paddingLeft = '2px';
	obj.style.textAlign = 'left';
	obj.style.color = this.foreground;
	obj.style.backgroundColor = this.background;
	obj.style.font = 'normal 12px courier new';
	obj.style.lineHeight = '14px'
	obj.setAttribute('noWrap','true');
	obj.style.width = '50%'
}


MStatusControl.prototype.show = function () {
	this.container.style.display = '';
}

MStatusControl.prototype.hide = function () {
	this.container.style.display = 'none';
}

MStatusControl.prototype.toggle = function () {
	this.container.style.display = this.container.style.display == '' ? 'none' : '';
}


//////////// END MStatusControl /////////////////

//})(jQuery); // wrap for drupal
