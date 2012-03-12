Ext.onReady(function(){
  Ext.define('MappingInterface.widgets.map', {
    extend: 'Ext.panel.Panel',
    id: 'mapPanel',
    itemId: 'mapPanel',
    title: 'Map',
    region: 'center',
    items: {
      xtype: 'gmappanel',
      id: 'bampMap',
      width: 860,
      height: 600,
      zoomLevel: 9,
      gmapTypeId: 'map',
      mapConfOpts: ['enableDoubleClickZoom','enableDragging'],
      mapControls: ['GSmallMapControl','GMapTypeControl'],
      setCenter: {
        lat: 50.8182,
        lng: -126.508
      },//end setCenter
      markers: [],
      maplisteners: {
        click: function(mevt){
          /*Ext.Msg.alert('Lat/Lng of Click', mevt.latLng.lat() + ' / ' + mevt.latLng.lng());
          var input = Ext.get('ac').dom,
          sw = new google.maps.LatLng(39.26940,-76.64323),
          ne = new google.maps.LatLng(39.38904,-76.54848),
          bounds = new google.maps.LatLngBounds(sw,ne);
          var options = {
            location: mevt.latLng,
            radius: '1000',
            types: ['geocode']
          };*/
        }//end click
      },//end mapListeners
      listeners: {
        mapready: function(){
          //Load all markers by default. 
          this.hideMarkers();
          var markers = [];
          var wild_site_markers = Ext.data.StoreManager.lookup('wild_site_markers');
          var site_markers = wild_site_markers.load();
          /*this.clearMarkers();
          this.addMarkers(site_markers);
          this.showMarkers();*/

          site_markers.each(function(m){
            markers.push(m.raw);
          });
          this.addMarkers(markers);
          this.showMarkers();

          /*site_markers.each(function(m){
            markers.push({
              lat: m.get('lat'),
              lng: m.get('lng'),
              bamp_id: m.get('bamp_id'),
              marker: {
                title: m.get('marker').title,
                infoWindow: {
                  content: m.get('marker').infoWindow.content
                }
              }
            });
          });
          this.addMarkers(markers);
          this.showMarkers();*/
        }//end mapready()
      }//end listeners
    }//end items
  });//end define MappingInterface.widgets.map
});//end onReady()
