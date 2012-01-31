Ext.onReady(function(){
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
              width : 350,
              height: 220,
              closable : true,
              bodyPadding: '20px',
              layout: {
                type: 'vbox',
              },
              items: [{
                  xtype: 'combo',
                  id: 'comboTable',
                  store: 'filterTables',
                  displayField: 'table',
                  valueField: 'tableId',
                  fieldLabel: 'Filter Group',
                  queryMode: 'local',
                  selectOnTab: false,
                  name: 'table',
                  forceSelection: true,
                  listeners: {
                    //scope: this,
                    select: function(){
                      var comboField = Ext.getCmp('comboField');
                      comboField.clearValue();
                      comboField.enable();
                      comboField.store.clearFilter();
                      comboField.store.filter('tid',this.getValue());

                      var comboOperator = Ext.getCmp('comboOperator');
                      comboOperator.clearValue();
                      comboOperator.disable();

                      var comboValue = Ext.getCmp('comboValue');
                      comboValue.setValue('');
                      comboValue.disable();
                    }
                  }
                },{
                  xtype: 'combo',
                  id: 'comboField',
                  store: 'filterFields',
                  displayField: 'field',
                  valueField: 'fieldId',
                  fieldLabel: 'Filter Column',
                  forceSelection: true,
                  //queryMode: 'remote',
                  autoSelect: true,
                  selectOnTab: false,
                  name: 'column',
                  disabled: true,
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
                      comboField.disable();

                      var comboOperator = Ext.getCmp('comboOperator');
                      comboOperator.clearValue();
                      comboOperator.disable();

                      var comboValue = Ext.getCmp('comboValue');
                      comboValue.setValue('');
                      comboValue.disable();
                    }
                  }, {
                    text: 'Save',
                    handler: function(){
                      var comboTable = Ext.getCmp('comboTable');
                      var table = comboTable.getValue();

                      var comboField = Ext.getCmp('comboField');
                      var field = comboField.getValue();

                      var comboOperator = Ext.getCmp('comboOperator');
                      var operator = comboOperator.getValue();

                      var comboValue = Ext.getCmp('comboValue');
                      var value = comboValue.getValue();

                      var filter = {table: table, field: field, operator: operator, value: value};
                      window.mapFilters.push(filter);

                      //Add filter to the filterPanel

                      var filterHtml = {
                        xtype: 'panel',
                        html: '<h3>' + table + '.' + field + ' ' + operator + ' ' + value + '</h3>',
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
            window.mapFilters = [];
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
            mappy.showMarkers();
          }
        }]
      }], 
      items: [{
        
      }]
  });
});
