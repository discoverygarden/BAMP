Ext.onReady(function(){
    //Create the panels (defined in mapPanel.js and filterPanel.js)
    var panels = [];
    panels.push(Ext.create('MappingInterface.widgets.map'));
    panels.push(Ext.create('MappingInterface.widgets.filters'));

    //Create a container to house our panels. 
    var MappingInterface = Ext.create('Ext.container.Container', {
        width: 1160,
        height: 700,
        renderTo: 'mapContainer',
        layout: {
          type: 'border'
        },
        items: panels
    });
    MappingInterface.show();


    //Function to pass filters to server and update map markers. 
    window.refreshMap = function(){
      var bampMap = Ext.getCmp('bampMap');
      var aFilters = Ext.JSON.encode(window.mapFilters);

      Ext.Ajax.request({
        url: '/bamp/sites/default/modules/mapping/dataHandler.php?type=customFilter',
        params: {customFilters: aFilters},
        disableCaching: true,
        success: function(response, opts) {
          var obj = Ext.decode(response.responseText);

          //Generate data summary information
          var dataSummary = {total_fish_count: 0, total_trips: 0};
          for(var key in obj){
            dataSummary.total_fish_count = dataSummary.total_fish_count + parseInt(obj[key].fish_count);
            dataSummary.total_trips++;
          };
          console.log(dataSummary);

          //Update the data summary panel
          window.updateDataSummary(dataSummary);

          //Show the markers
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
    
    //Delete filter functionality
    window.filterDelete = function(filterId){
      var filterPanel = Ext.getCmp('filter-'+filterId);
      filterPanel.destroy();
      console.log(window.mapFilters);
      for (var key in window.mapFilters) {
        if(window.mapFilters[key].filterId == filterId){
          window.mapFilters.splice(key,1);
        }//end if
      }//end for
      window.refreshMap();
    }//end filterDelete();

    window.updateDataSummary = function(dataSummary){
      //Get the data summary panel
      var panel = Ext.getCmp('dataSummary');
      var grid = Ext.getCmp('dataSummaryGrid');

      if(grid != undefined){
        grid.destroy();
      }//end if

      //Create a store for the data summary grid data
      var store = Ext.create('Ext.data.Store', {
        storeId: 'dataSummary',
        fields: ['total_fish_count','total_trips'],
        data: {'items': [
          {'total_fish_count': dataSummary.total_fish_count, 'total_trips': dataSummary.total_trips}
        ]},
        proxy: {
          type: 'memory',
          reader: {
            type: 'json',
            root: 'items'
          }//end reader
        }//end proxy
      });//end store

      //Create a grid for the data summary
      var dsHtml = '';
      dsHtml = {
        xtype: 'gridpanel',
        id: 'dataSummaryGrid',
        store: Ext.data.StoreManager.lookup('dataSummary'),
        border: false,
        bodyBorder: false,
        columnLines: true,
        sortableColumns: false,
        enableColumnHide: false,
        enableColumnMove: false,
        enableColumnResize: false,
        scroll: false,
        forceFit: true,
        columns: [
          {header: 'Total Trips Displayed', dataIndex: 'total_trips' },
          {header: 'Total Fish Represented', dataIndex: 'total_fish_count'}
        ]
      };//end grid 

      //Add the grid to the data summary panel
      panel.add(dsHtml);
    }//end updateDataSummary

    window.saveSelection = function(data){
      /////////////////////////////////////////////
      //TODO: Save to db
      /////////////////////////////////////////////
      console.log(data);
      ////////////////////////////////////////////
    }//end saveSelection();

    //Add the polygon creator plugin
    var bampMap= Ext.getCmp('bampMap');
    bampMap.on('mapready', function(myMap){
      window.creator = new PolygonCreator(myMap.getMap());
    });
});
