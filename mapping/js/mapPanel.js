Ext.onReady(function(){
  Ext.define('MappingInterface.widgets.map', {
    extend: 'Ext.panel.Panel',
    id: 'mapPanel',
    title: 'Map',
    region: 'center',
    layout: {
      type: 'vbox',
    },
    defaults: {
      width: '100%',
      split: true
    },
    items: [{
      xtype: 'gmappanel',
      id: 'bampMap',
      /*height: 600,*/
      flex: 11,
      border: false,
      zoomLevel: 9,
      gmapTypeId: 'map',
      mapConfOpts: ['enableDoubleClickZoom','enableDragging'],
      mapControls: ['GSmallMapControl','GMapTypeControl'],
      setCenter: {
        lat: 50.8182,
        lng: -126.508
      },//end setCenter
      markers: [],
      listeners: {
        mapready: function(){
          this.hideMarkers();
          var markers = [];
          var wild_site_markers = Ext.data.StoreManager.lookup('wild_site_markers');
          var site_markers = wild_site_markers.load();
          var dataSummary = {total_fish_count: 0, total_trips: 0};
          site_markers.each(function(m){
            dataSummary.total_fish_count = dataSummary.total_fish_count + parseInt(m.raw.fish_count);
            dataSummary.total_trips++;
            markers.push(m.raw);
          });
          this.addMarkers(markers);
          this.showMarkers();

          //Update the data summary panel
          window.updateDataSummary(dataSummary);
        }//end mapready()
      }//end listeners
    },{
      xtype: 'panel',
      title: 'Map Marker Legend',
      collapsible: true,
      collapseDirection: 'bottom',
      flex: 2,
      border: false,
      html: '<table style="width: 100%;"><tr><th colspan="4">Marker Shapes</th><th colspan="5">Marker Colors</th></tr><tr><th style="background-color: #FFF; text-align: center; font-weight: bold;"><img src="' + window.modulePath + 'images/gmapicons/Circles/1.png"/><br/>Marty</th><th style="background-color: #FFF; text-align: center; font-weight: bold;"><img src="' + window.modulePath + 'images/gmapicons/Squares/1.png"/><br/>DFO</th><th style="background-color: #FFF; text-align: center; font-weight: bold;"><img src="' + window.modulePath + 'images/gmapicons/Triangles/1.png"/><br/>BAMP</th><th  style="background-color: #FFF; text-align: center; font-weight: bold;"><img src="' + window.modulePath + 'images/gmapicons/farm.png"/><br/>Farm Site</th><th style="background-color: #B52C38; text-align: center; font-weight: bold;">March</th><th style="background-color: #EBD1B0; text-align: center; font-weight: bold;">April</th><th style="background-color: #536682; text-align: center; font-weight: bold;">May</th><th style="background-color: #D9964B; text-align: center; font-weight: bold;">June</th><th style="background-color: #DE6846; text-align: center; font-weight: bold;">July</th></table>'
    }]//end items
  });//end define MappingInterface.widgets.map
});//end onReady()
