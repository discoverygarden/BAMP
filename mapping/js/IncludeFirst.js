Ext.ns('MappingInterface.widgets');
Ext.ns('MappingInterface.models');
Ext.ns('MappingInterface.filterCombos');

window.modulePath = '/bamp/sites/default/modules/mapping/';

var mapFilters = [];

Ext.onReady(function(){
  //Wild Site Markers Model and Store
/*  Ext.define('MappingInterface.models.wild_site_markers', {
    extend: 'Ext.data.Model',
    fields: ['lat','lng','bamp_id','marker','fish_count','trip_id'],
  });
  Ext.create('Ext.data.Store', {
    storeId: 'wild_site_markers',
    model: MappingInterface.models.wild_site_markers,
    proxy: {
        type: 'ajax',
        url : window.modulePath + 'dataHandler.php?type=customFilter',
        reader: 'json'
    },
    autoLoad: true
  });
*/
  //Filters - Fields Model and Store
  Ext.define('MappingInterface.models.filterFields', {
    extend: 'Ext.data.Model',
    fields: ['field','fieldId','fieldType'],
  });
  Ext.create('Ext.data.Store', {
    autoLoad: true,
    storeId: 'filterFields',
    model: MappingInterface.models.filterFields,
    remoteFilter: true,
    proxy: {
        type: 'ajax',
        url : window.modulePath + 'dataHandler.php?type=filterFields',
        reader: 'json'
    }
  });

  //Filters - Fields Model and Store
  Ext.define('MappingInterface.models.polygons', {
    extend: 'Ext.data.Model',
    fields: ['id','name'],
  });
  Ext.create('Ext.data.Store', {
    autoLoad: true,
    storeId: 'polygons',
    model: MappingInterface.models.polygons,
    remoteFilter: true,
    proxy: {
        type: 'ajax',
        url : window.modulePath + 'dataHandler.php?type=loadSelections',
        reader: 'json'
    }
  });
});
