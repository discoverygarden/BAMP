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
      html: '<span class="filterInstructions">To refine the data displayed on the map, click the "Add Filter" button above, choose the field you would like to filter on, select an operator and enter a value. Once your new filter is saved it will  appear in this area and you can continue adding filters to achieve the desired result set.</span>',
      flex: 3
    },{
      xtype: 'panel',
      id: 'filterList',
      flex: 8
    },{
      xtype: 'panel',
      title: 'Data Summary',
      id: 'dataSummary',
      flex: 2,
      border: false,
      collapsible: true,
      collapseDirection: 'bottom',
      layout: 'fit'
    }],
    dockedItems: [{
      xtype: 'toolbar',
      items: [{
        text: 'Add Filter Group',
        handler: function(){
          Ext.create("Ext.Window",{
            id: 'addFilterWindow',
            title : 'Add Filter Group',
            width : 700,
            height: 525,
            closable : true,
            bodyPadding: '20px',
            layout: {
              type: 'hbox',
            },
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
              flex: 2
            },{
              xtype: 'panel',
              title: 'Filters in group',
              id: 'filtersInGroup',
              flex: 8,
              autoScroll: true
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
                  //Loop over each fieldContainer
                  Ext.each(Ext.getCmp('filtersInGroup').items.items, function (child) {
                    var filterVal = [];

                    //Loop over fields
                    Ext.each(Ext.getCmp(child.getId()).items.items, function(c){
                       var f = {field: c.getName(), value: c.getValue()};
                       filterVal.push(f);
                    });//end each fieldGroupChildContainer items

                    var fid = filters.length + 1;
                    //Add the field to the filters array
                    filters.push({id: fid, content: filterVal});
                  });//end each fieldGroupContainer items

                  //Add the filters to the global filters array
                  window.mapFilters.push(filters);

                  //Update the filter panel
                  window.updateFilters(filters);

                  //Refresh the map with the new markers
                  window.refreshMap();

                  //Close the add filter window
                  Ext.getCmp('addFilterWindow').close();
                }//end save handler
              }]//end items
            }//end window dockedItems 
          }).show();
        }//end handler
      }, {
        text: 'Clear All',
        disabled: false,
        itemId: 'delete',
        handler: function() {
          //Reload the window to reset everything
          location.reload(true);
        }//end handler
      },{
        text: 'Reset Selection',
        itemId: 'resetSel',
        handler: function() {
          //Destroy the creator object. Removes polygon.
          window.creator.destroy();

          //Add the polygon creator plugin
          var bampMap= Ext.getCmp('bampMap');
          window.creator = new PolygonCreator(bampMap.getMap());
        }//end handler
      },{
        text: 'Save Sel',
        itemId: 'saveSel',
        handler: function() {
           Ext.create("Ext.Window",{
            id: 'addFilterWindow',
            title : 'Add Filter',
            width : 500,
            height: 225,
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
                  window.saveSelection(selSaveData);
                }//end handler
              }]//end items
            }//end dockedItems
          }).show();//end create window
        }//end handler
      }]//end items
    }]//end dockedItems
  });//end panel
});//end on ready
