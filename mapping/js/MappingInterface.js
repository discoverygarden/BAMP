Ext.onReady(function(){
    //Create the panels (defined in mapPanel.js and filterPanel.js)
    var panels = [];
    panels.push(Ext.create('MappingInterface.widgets.map'));
    panels.push(Ext.create('MappingInterface.widgets.filters'));

    //Create a container to house our panels. 
    var MappingInterface = Ext.create('Ext.container.Container', {
        width: 1160,
        height: 600,
        renderTo: 'mapContainer',
        layout: {
          type: 'border'
        },
        items: panels
    });
    MappingInterface.show();


    //Function to pass filters to server and update map markers. 
    //Figure out a more EXT way to do this (possibly with custom events)
    //Would have done this initially but, not sure how without modifying the gmap extension.
    //Had to prefix with window. to make global for firefox. Should use EXT Namespace(??)
    window.refreshMap = function(){
      var bampMap = Ext.getCmp('bampMap');
      var aFilters = Ext.JSON.encode(window.mapFilters);

      Ext.Ajax.request({
        url: '/bamp/sites/default/modules/mapping/dataHandler.php?type=customFilter',
        params: {customFilters: aFilters},
        disableCaching: true,
        success: function(response, opts) {
          var obj = Ext.decode(response.responseText);
          bampMap.hideMarkers();
          bampMap.clearMarkers();
          bampMap.addMarkers(obj);
          bampMap.showMarkers();
        },
        failure: function(response, opts) {
           console.log('server-side failure with status code ' + response.status);
        }
      });
    }//end refreshMap();
});
