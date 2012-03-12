Ext.onReady(function(){
  Ext.require('Ext.LoadMask', function() {
    Ext.override(Ext.LoadMask, {
      onHide: function() {
        this.callParent();
      }
    });
  });

  Ext.define('MappingInterface.widgets.filters', {
    extend: 'Ext.panel.Panel',
    itemId: 'filterPanel',
    id: 'filterPanel',
    title: 'Filters',
    region: 'east',
    collapsible: false,
    width: 300,
    dockedItems: [{
        xtype: 'toolbar',
        items: [{
          text: 'Add Filter',
          //scope: this,
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
                  }
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
                        ['\<\=']
                      ]   
                  }), 
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
                  }
                },
                {
                  xtype: 'textfield',
                  id: 'comboValue',
                  fieldLabel: 'Value',
                  name: 'value',
                  disabled: true,
                }],
                modal : true,
                dockedItems: {
                  xtype: 'toolbar',
                  dock: 'bottom',
                  ui: 'footer',
                  defaults: {
                    minWidth: 75
                  },
                  items: ['->',
                  {
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

                      window.mapFilters = '';
                    }
                  }, {
                    text: 'Save',
                    handler: function(){
                      var comboField = Ext.getCmp('comboField');
                      var field = comboField.getValue();

                      var comboOperator = Ext.getCmp('comboOperator');
                      var operator = comboOperator.getValue();

                      var comboValue = Ext.getCmp('comboValue');
                      var value = comboValue.getValue();

                      var filter = {field: field, operator: operator, value: value};
                      window.mapFilters.push(filter);

                      //Add filter to the filterPanel

                      var filterHtml = '';
                      filterHtml = {
                        xtype: 'panel',
                        html: '<span class="filterEntry"><span class="filterText">' + field + ' <b>' + operator + '</b> ' + value + '</span> <span class="filterDelete"><img src="sites/default/modules/mapping/images/delete.png" onclick="javascript:alert(\'TODO: Milestone 3\');"/></span></span>',
                      };

                      var filterPanel = Ext.getCmp('filterPanel');
                      filterPanel.add(filterHtml);
                      //Refresh the map with the new markers
                      window.refreshMap();

                      //Close the add filter window
                      Ext.getCmp('addFilterWindow').close();
                    }
                  }]
                } 
            }).show();
          }
        }, {
          text: 'Clear Filters',
          disabled: false,
          itemId: 'delete',
          //:scope: this,
          handler: function() {
            location.reload(true);
            /*window.mapFilters = [];
            var mappy = Ext.getCmp('bampMap');
            mappy.hideMarkers();
            var markers = [];
            var wild_site_markers = Ext.data.StoreManager.lookup('wild_site_markers');
            var site_markers = wild_site_markers.load();
            site_markers.each(function(m){
              markers.push({
                lat: m.get('lat'), 
                lng: m.get('lng'), 
                marker: {
                  title: m.get('marker').title,
                },
                listeners: {
                  click: function(){
                  }
                }
              });
            });
            mappy.addMarkers(markers);
            mappy.showMarkers();*/
          }
        }]
      }], 
      items: [{
        xtype: 'panel',
        html: '<span class="filterInstructions">To refine the data displayed on the map, click the "Add Filter" button above, choose the field you would like to filter on, select an operator and enter a value. Once your new filter is saved it will appear in this area and you can continue adding filters to achieve the desired result set.</span>'
      }]
  });
});
