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

          //Update the data summary panel
          window.updateDataSummary(dataSummary);

          //Show the markers
          bampMap.hideMarkers();
          bampMap.clearMarkers();
          bampMap.addMarkers(obj);
          bampMap.showMarkers();
        },
        failure: function(response, opts) {
           alert('server-side failure with status code ' + response.status);
        }
      });
    }//end refreshMap();

    //Add filters to filter pane
    window.updateFilters = function(filters){
      var filterList = Ext.getCmp('filterList');
      var filterGroupPanel = {
        xtype: 'panel',
        title: 'AND',
        layout: 'fit'
      };

      var fpv = filterList.add(filterGroupPanel);

      Ext.each(filters, function(filterGroup){
        var fPanel = {xtype: 'panel', id: fpv.id + filterGroup.id, html: ''};
        fPanel.html += '<span class="filterEntry">';
        fPanel.html += '<span class="filterText">';
        Ext.each(filterGroup.content, function(filter){
          switch(filter.field){
            case 'column':
              fPanel.html += filter.value + ' ';
            break;
            case 'operator': 
              fPanel.html += filter.value + ' ';
            break;
            case 'value':
              fPanel.html += filter.value + ' ';
            break;
            case 'join':
              fPanel.html += '<span class="filterJoin">' + filter.value + '</span> ';
            break;
          }//end switch
        });//end each
        fPanel.html += '</span>';
        fPanel.html += '<span class="filterDelete">';
        fPanel.html += '<img src="sites/default/modules/mapping/images/delete.png" onclick="javascript: window.filterDelete(\'' + filterGroup.id + '\',\'' + fpv.id + '\');"/>';
        fPanel.html += '</span>';
        fPanel.html += '</span>';
        var fpx = fpv.add(fPanel);
      });//end each
    };//end updateFilters();

    //Delete filter functionality
    window.filterDelete = function(filterId, filterParentId){
      //Get the filter group panel
      var filterPanel = Ext.getCmp(filterParentId);

      //Remove the filter
      filterPanel.remove(filterParentId + filterId);

      //If no items are left, destroy the panel
      if(filterPanel.items.items.length == 0){
        filterPanel.destroy();
      }//end if

      for (var key in window.mapFilters) {
        var ki = parseInt(key) + 1;
        if(ki == filterId){
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
