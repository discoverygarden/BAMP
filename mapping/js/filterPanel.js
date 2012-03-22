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
        text: 'Add Filter',
        handler: function(){
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
              xtype: 'radiogroup',
              id: 'conditionRadio',
              fieldLabel : 'Join Type',
              width: 350,
              items: [
                {fieldLabel: 'AND', labelWidth: 30, name: 'condition', inputValue: 'AND', checked: true},
                {fieldLabel: 'OR', labelWidth: 30, name: 'condition', inputValue: 'OR'}
              ]
            },{
              xtype: 'combo',
              id: 'comboField',
              store: 'filterFields',
              displayField: 'field',
              valueField: 'fieldId',
              width: 400,
              fieldLabel: 'Filter Column',
              forceSelection: true,
              autoSelect: false,
              selectOnTab: false,
              name: 'column',
              disabled: false,
              listeners: {
                select: function(){
                  var comboOperator = Ext.getCmp('comboOperator');
                  comboOperator.clearValue();
                  comboOperator.enable();
    
                  var comboValue = Ext.getCmp('comboValue');
                  comboValue.setValue('');
                  comboValue.disable();
                }
              }//end listeners
            },{
              xtype: 'combo',
              id: 'comboOperator',
              forceSelection: true,
              store: Ext.create('Ext.data.ArrayStore', {
                fields: [ 'operator' ],
                data: [
                  ['\='],
                  ['\>'],
                  ['\>\='],
                  ['\<'],
                  ['\<\='],
                  ['LIKE'],
                  ['NOT LIKE'],
                  ['IN'],
                  ['NOT IN']
                ]
              }),//End create store 
              displayField: 'operator',
              fieldLabel: 'Operator',
              queryMode: 'local',
              selectOnTab: false,
              name: 'operator',
              disabled: true,
              listeners: {
                select: function(){
                  var comboValue = Ext.getCmp('comboValue');
                  comboValue.enable();
                }
              }//end listeners
            },{
              xtype: 'textfield',
              id: 'comboValue',
              fieldLabel: 'Value',
              name: 'value',
              disabled: true,
            }],//end window items[]
            modal : true,
            dockedItems: {
              xtype: 'toolbar',
              dock: 'bottom',
              ui: 'footer',
              defaults: {minWidth: 75},
              items: ['->',/*{
                text: 'Reset',
                handler: function() {
                  var comboField = Ext.getCmp('comboField');
                  comboField.clearValue();
                  var comboOperator = Ext.getCmp('comboOperator');
                  comboOperator.clearValue();
                  comboOperator.disable();
                  var comboValue = Ext.getCmp('comboValue');
                  comboValue.setValue('');
                  comboValue.disable();
                }
              },*/{
                text: 'Save',
                handler: function(){
                  //Get the values entered by the user
                  var condition = Ext.getCmp('conditionRadio').getValue();
                  var field = Ext.getCmp('comboField').getValue();
                  var operator = Ext.getCmp('comboOperator').getValue();
                  var value = Ext.getCmp('comboValue').getValue();
                  var filterId = window.mapFilters.length + 1;
                  
                  ///////////////////////////////////////////////////////////
                  //TODO: VALIDATE nulls
                  //////////////////////////////////////////////////////////

                  //Add the filters to the global filters javascript object 
                  var filter = {filterId: filterId, join: condition['condition'], field: field, operator: operator, value: value};
                  window.mapFilters.push(filter);
    
                  //Add filter to the filterList
                  var fhtml = '<span class="filterEntry" id="' + filterId + '">';
                  fhtml += '<span class="filterText">' + field + ' <b>' + operator + '</b> ' + value + '</span>';
                  fhtml += '<span class="filterDelete">';
                  fhtml += '<img src="sites/default/modules/mapping/images/delete.png" onclick="javascript: filterDelete(' + filterId + ');"/>';
                  fhtml += '</span>';
                  fhtml += '</span>';
                  
                  //Create a panel to hold the filter info
                  var filterHtml = '';
                  filterHtml = {
                    xtype: 'panel',
                    id: 'filter-' + filterId,
                    html: fhtml,
                  };
    
                  //Add the filter to the filterList panel
                  var filterList = Ext.getCmp('filterList');
                  filterList.add(filterHtml);

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
