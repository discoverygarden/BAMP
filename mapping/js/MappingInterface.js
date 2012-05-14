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

      //Check if polygon exists.... if so, get the points
      if(window.shape != undefined){
        var paths = window.shape.getPaths();
        var polygonData = [];

        //get paths
        paths.getAt(0).forEach(function(value, index){
          var lat = value.lat();
          var lon = value.lng();
          var p = {lat: lat, lng: lon};
          polygonData.push(p);
        });//end getPaths

        polygonData = Ext.JSON.encode(polygonData);
      }else{
        var polygonData = {};
      }//end if

      bampMap.hideMarkers();
      bampMap.clearMarkers();
      if(aFilters != undefined || window.shape != undefined){
        //Send the filters to the server and refresh the map markers
        Ext.Ajax.request({
          url: window.modulePath + 'dataHandler.php?type=customFilter',
          params: {customFilters: aFilters, polygonPoints: polygonData},
          disableCaching: true,
          success: function(response, opts) {
            //Decode JSON response.
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
            bampMap.addMarkers(obj);
            bampMap.showMarkers();
          },
          failure: function(response, opts) {
             alert('server-side failure with status code ' + response.status);
          }
        });
      }//end if
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
        fPanel.html += '<img src="' + window.modulePath + 'images/delete.png" onclick="javascript: window.filterDelete(\'' + filterGroup.id + '\',\'' + fpv.id + '\');"/>';
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

      //Remove the filter from the global array
      for (var key in window.mapFilters) {
        for (var k in window.mapFilters[key]) {
          if(window.mapFilters[key][k].id == filterId){
            window.mapFilters[key].splice(k,1);
          }//end if
        }//end for
      }//end for

      //Reload the map
      window.refreshMap();
    }//end filterDelete();

    //Update the data summary panel
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

    //Save a user drawn polygon selection to the database
    window.saveSelection = function(data){
      //Populate the global plygonPoints array
      window.polygonPoints = data.points;

      //Send the selection data to the server
      Ext.Ajax.request({
        url: window.modulePath + 'dataHandler.php?type=saveSelection',
        jsonData: Ext.JSON.encode(data),
        disableCaching: true,
        success: function(response, opts) {
        },
        failure: function(response, opts) {
           alert('server-side failure with status code ' + response.status);
        }
      });
      window.refreshMap();
    }//end saveSelection();

    //This function grabs the points for a saved selection and displays it on the map. 
    window.showSelection = function(polygonId){
      //Destroy any selection which has been drawn
      window.creator.destroy();

      //Fetch the points for this polygon id
      Ext.Ajax.request({
        url: window.modulePath + 'dataHandler.php?type=getSelectionPoints',
        params: {id: polygonId},
        disableCaching: true,
        success: function(response,opts){
          //Decode the JSON into an object
          var obj = Ext.decode(response.responseText);

          //Arrays to hold the polygon path points. Paths = gLatLng. Points = string
          var paths = [];
          window.polygonPoints = [];

          //Loop over the response and create LatLng objects 
          Ext.each(obj, function(point){
            var point = new google.maps.LatLng(point.lat, point.lon);
            paths.push(point);
            window.polygonPoints.push({lat: point.lat, lon: point.lon});
          });

          //Create the polygon 
          window.shape = new google.maps.Polygon({
            paths: paths,
            strokeColor: '#ff0000',
            strokeOpacity: 0.8,
            strokeWeight: 2,
            fillColor: '#ff0000',
            fillOpacity: 0.35
          });

          //Draw the polygon on the map
          var bampMap = Ext.getCmp('bampMap').getMap();
          window.shape.setMap(bampMap);

          //Apply the selection
          window.refreshMap();
        },
        failure: function(response, opts){
          alert('server-side failure with status code ' + response.status);
        }
      });
    }//end showSelection();

    //Add the polygon creator plugin
    var bampMap= Ext.getCmp('bampMap');
    bampMap.on('mapready', function(myMap){
      window.creator = new PolygonCreator(myMap.getMap());
    });
});
