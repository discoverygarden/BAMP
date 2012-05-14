Ext.onReady(function(){

  //Find out what this is for.... forget.
  Ext.require('Ext.LoadMask', function() {
    Ext.override(Ext.LoadMask, {
      onHide: function() {
        this.callParent();
      }
    });
  });

  //Filter panel definition.
  Ext.define('MappingInterface.widgets.filters', {
    extend: 'Ext.panel.Panel',
    id: 'filterPanel',
    title: 'Filters',
    region: 'east',
    collapsible: false,
    width: 300,
    defaults: {
      width: 300,
      autoscroll: true,
      border: false
    },
    layout: {
      type: 'vbox'
    },
    items: [{
      xtype: 'panel',
      id: 'filterList',
      flex: 11
    },{
      xtype: 'panel',
      title: 'Data Summary',
      id: 'dataSummary',
      flex: 4,
      border: false,
      collapsible: true,
      collapseDirection: 'bottom',
      layout: 'fit',
      dockedItems: [{
        xtype: 'buttongroup',
        title: 'Export data to CSV',
        columns: 3,
        flex: 2, 
        defaults: {
          scale: 'small',
          border: false
        }, 
        items:[{
        xtype: 'button',
        text: 'All Data',
        handler: function(){
          if(window.mapFilters == undefined && window.mapShape == undefined){
            alert('Please add a filter or polygon selection to the map. For full dataset, please use the reports module.');
          }else{
            if(window.mapFilters != undefined){
              var mapFilters = Ext.encode(window.mapFilters);
              var mapFilters = encodeURIComponent(mapFilters);
            }else{
              var mapFilters = null;
            }//end if
            if(window.shape != undefined){
              var mapShape = Ext.encode(window.shape);
              var mapShape = encodeURIComponent(mapShape);
            }else{
              var mapShape = null;
            }//end if
            Ext.DomHelper.append(
              Ext.getBody(),{
                tag:'form',
                name:'transportform',
                id:'transportform',
                action: window.modulePath + "export.php",
                method:"POST",
                children:[{
                  tag: 'input',
                  type: 'hidden',
                  name: 'type',
                  value: 'exportAll'
                },{
                  tag:'input',
                  type:'hidden',
                  name:'mapFilters',
                  value: mapFilters
                },{
                  tag: 'input',
                  type: 'hidden',
                  name: 'polygonPoints',
                  value: mapShape
                }]
            }).submit();
          }//end if
        }//end handler
      },{
        xtype: 'button',
        text: 'Sampling Instances',
        handler: function(){
          if(window.mapFilters == undefined && window.mapShape == undefined){
            alert('Please add a filter or polygon selection to the map. For full dataset, please use the reports module.');
          }else{
            if(window.mapFilters != undefined){
              var mapFilters = Ext.encode(window.mapFilters);
              var mapFilters = encodeURIComponent(mapFilters);
            }else{
              var mapFilters = null;
            }//end if
            if(window.shape != undefined){
              var mapShape = Ext.encode(window.shape);
              var mapShape = encodeURIComponent(mapShape);
            }else{
              var mapShape = null;
            }//end if
            Ext.DomHelper.append(
              Ext.getBody(),{
                tag:'form',
                name:'transportform',
                id:'transportform',
                action: window.modulePath + "export.php",
                method:"POST",
                children:[{
                  tag: 'input',
                  type: 'hidden',
                  name: 'type',
                  value: 'exportSamplingInstances'
                },{
                  tag:'input',
                  type:'hidden',
                  name:'mapFilters',
                  value: mapFilters
                },{
                  tag: 'input',
                  type: 'hidden',
                  name: 'polygonPoints',
                  value: mapShape
                }]
            }).submit();
          }//end if
        }//end handler
      },{
        xtype: 'button',
        text: 'Fish Samples',
        handler: function(){
           if(window.mapFilters == undefined && window.mapShape == undefined){
             alert('Please add a filter or polygon selection to the map. For full dataset, please use the reports module.');
           }else{
            if(window.mapFilters != undefined){
              var mapFilters = Ext.JSON.encode(window.mapFilters);
              var mapFilters = encodeURIComponent(mapFilters);
            }else{
              var mapFilters = null;
            }//end if
            if(window.shape != undefined){
              var mapShape = Ext.encode(window.shape);
              var mapShape = encodeURIComponent(mapShape);
            }else{
              var mapShape = null;
            }//end if

            Ext.DomHelper.append(
              Ext.getBody(),{
                tag:'form',
                name:'transportform',
                id:'transportform',
                action: window.modulePath + "export.php",
                method:"POST",
                children:[{
                  tag: 'input',
                  type: 'hidden',
                  name: 'type',
                  value: 'exportFishSamples'
                },{
                  tag:'input',
                  type:'hidden',
                  name:'mapFilters',
                  value: mapFilters
                },{
                  tag: 'input',
                  type: 'hidden',
                  name: 'polygonPoints',
                  value: mapShape
                }]
            }).submit();
          }//end if
        }//end handler
      }]
      }]
    }],
    dockedItems: [{
      xtype: 'toolbar',
      items: [{
        xtype: 'buttongroup',
        title: 'Filter Groups',
        columns: 2,
        flex: 2,
        defaults: {
          scale: 'small',
          border: false
        },
        items: [{
          text: 'Add',
          handler: function(){
            Ext.create("Ext.Window",{
              id: 'addFilterWindow',
              title : 'Add Filter Group',
              width : 700,
              height: 525,
              closable : true,
              bodyPadding: '20px',
              layout: {
                type: 'fit',
              },
              items: [{
                xtype: 'panel',
                title: 'Filters in group',
                id: 'filtersInGroup',
                autoScroll: true,
                dockedItems: [{
                  xtype: 'toolbar',
                  items: [{
                    xtype: 'button',
                    text: 'Add filter',
                    handler: function(){
                      var fig = Ext.getCmp('filtersInGroup');
                      var figItems = fig.items.items;
                      if(figItems.length == 0){
                        Ext.getCmp('filtersInGroup').add(window.fieldGroup1);
                      }else{
                        Ext.getCmp('filtersInGroup').add(window.fieldGroup);
                      }//end if
                    },//end handler
                  }]
                }]
              }],//end window items[]
              modal : true,
              dockedItems: {
                xtype: 'toolbar',
                dock: 'bottom',
                ui: 'footer',
                defaults: {minWidth: 75},
                items: ['->',{
                  text: 'Save',
                  handler: function(){
                    var filters = [];
                    var errorInForm = false;
                    //Loop over each fieldContainer
                    Ext.each(Ext.getCmp('filtersInGroup').items.items, function (child) {
                      var filterVal = [];
  
                      //Loop over fields
                      Ext.each(Ext.getCmp(child.getId()).items.items, function(c){
                        if(c.getValue() == undefined || c.getValue() == ""){
                          errorInForm = true;
                        }//end if
                        var f = {field: c.getName(), value: c.getValue()};
                        filterVal.push(f);
                      });//end each fieldGroupChildContainer items
  
                      //Create a unique id for the filter (container id + filter number)
                      var cid = child.getId();
                      var fid = filters.length + 1;
                      fid = cid + fid;
  
                      //Add the field to the filters array
                      filters.push({id: fid, content: filterVal});
                    });//end each fieldGroupContainer items
  
                    //If form has errors, alert user.
                    if(errorInForm == false){
                      //Add the filters to the global filters array
                      window.mapFilters.push(filters);
  
                      //Update the filter panel
                      window.updateFilters(filters);
  
                      //Refresh the map with the new markers
                      window.refreshMap();
  
                      //Close the add filter window
                      Ext.getCmp('addFilterWindow').close();
                    }else{
                      alert('All fields are required');
                    }//end if
                  }//end save handler
                }]//end items
              }//end window dockedItems 
            }).show();
          }//end handler
        }, {
          text: 'Clear',
          disabled: false,
          itemId: 'delete',
          handler: function() {
            window.mapFilters = [];
            window.refreshMap();
            var filterList = Ext.getCmp('filterList');
            filterList.removeAll();
          }//end handler
        }//end clear filters button
      ]},{
        xtype: 'buttongroup',
        title: 'Polygon Selection',
        flex: 3,
        columns: 3,
        defaults: {
          scale: 'small'
        },
        items: [{
          text: 'Load',
          itemId: 'loadSel',
          handler: function() {
            Ext.create("Ext.Window",{
              id: 'loadSelWindow',
              title: 'Load Saved Polygon Selection',
              width: 600,
              height: 150,
              closable: true,
              bodyPadding: '20px',
              layout: {
                type: 'vbox',
              },
              items: [{
                xtype: 'combo',
                store: 'polygons',
                displayField: 'name',
                valueField: 'id',
                width: 490,
                fieldLabel: 'Choose Polygon',
                labelWidth: 110,
                forceSelection: true,
                autoSelect: false,
                selectOnTab: false,
                name: 'polygon',
                id: 'polygon'
              }],
              modal: true,
              dockedItems:[{
                xtype: 'toolbar',
                dock: 'bottom',
                ui: 'footer',
                defaults: {minWidth: 75},
                items: ['->',{
                  text: 'Load Selection',
                  handler: function() {
                    var polygonId = Ext.getCmp('polygon').getValue();
                    window.showSelection(polygonId);
                    Ext.getCmp('loadSelWindow').close();
                  }//end handler
                }]//end items
              }]
            }).show();
          }//end handler
        },{
          text: 'Save',
          itemId: 'saveSel',
          handler: function() {
            if(window.creator.showData() == undefined){
              alert('Please define a polygon selection by either clicking on the map or loading one from the Polygon Selections menu');
            }else{
               Ext.create("Ext.Window",{
                id: 'saveSelWindow',
                title : 'Save Polygon Selection',
                width : 400,
                height: 150,
                closable : true,
                bodyPadding: '20px',
                layout: {
                  type: 'vbox',
                },
                items: [{
                  xtype: 'textfield',
                  id: 'comboSelectionName',
                  fieldLabel: 'Selection Name',
                  name: 'selectionName'
                }],//end window items[]
                modal : true,
                dockedItems: {
                  xtype: 'toolbar',
                  dock: 'bottom',
                  ui: 'footer',
                  defaults: {minWidth: 75},
                  items: ['->',{
                    text: 'Save',
                    handler: function() {
                      var comboSelectionName = Ext.getCmp('comboSelectionName').getValue();

                      var polygonData = window.creator.showData();

                      var selSaveData = {name:comboSelectionName, points: polygonData};

                      //Save the selection to the database
                      window.saveSelection(selSaveData);

                      //Close the window
                      Ext.getCmp('saveSelWindow').close();
                    }//end handler
                  }]//end items
                }//end dockedItems
              }).show();//end create window
            }//end if
          }//end handler
        },{
          text: 'Clear',
          itemId: 'resetSel',
          handler: function() {
            //Destroy the creator object. Removes polygon.
            window.creator.destroy();

            //Check to see if any shapes have been loaded onto the map
            if(window.shape != undefined){
              //Clear loaded polygons
              window.shape.setMap(null);
              window.shape = null;
            }//end if

            //Refresh the map
            window.refreshMap();

            //Add the polygon creator plugin
            var bampMap= Ext.getCmp('bampMap');
            window.creator = new PolygonCreator(bampMap.getMap());
          }//end handler
        }]//end items
      }]//end buttonGroup
    }]//end toolbar  
  });//end panel
});//end on ready
