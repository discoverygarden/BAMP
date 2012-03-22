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
      flex: 7,
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
      title: 'Legend',
      collapsible: true,
      collapseDirection: 'bottom',
      flex: 1,
      bodyPadding: '10',
      html: '<img src="sites/default/modules/mapping/images/gmapicons/blue_onwhite/symbol_infinite.png"/> = Marty! ' +
      '<img src="sites/default/modules/mapping/images/gmapicons/red_onwhite/symbol_infinite.png"/>' +
      '<img src="sites/default/modules/mapping/images/gmapicons/purple_onwhite/symbol_infinite.png"/>' +
      '<img src="sites/default/modules/mapping/images/gmapicons/orange_onwhite/symbol_infinite.png"/>' +
      '<img src="sites/default/modules/mapping/images/gmapicons/green_onwhite/symbol_infinite.png"/>'
    }]//end items
  });//end define MappingInterface.widgets.map
});//end onReady()
