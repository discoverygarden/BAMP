Ext.onReady(function(){
  var comboJoin = {
    xtype: 'combo',
    forceSelection: true,
    store: Ext.create('Ext.data.ArrayStore', {
      fields: [ 'join' ],
      data: [['AND'],['OR']]
    }),//End create store
    displayField: 'join',
    fieldLabel: 'Join Type',
    queryMode: 'local',
    selectOnTab: false,
    name: 'join',
    editable: false,
    typeAhead: false,
  };

  var comboField = {
    xtype: 'combo',
    store: 'filterFields',
    displayField: 'field',
    valueField: 'fieldId',
    width: 600,
    fieldLabel: 'Filter Column',
    forceSelection: true,
    autoSelect: false,
    selectOnTab: false,
    name: 'column',
    editable: false,
    typeAhead: false,
  };

  var comboOperator = {
    xtype: 'combo',
    forceSelection: true,
    store: Ext.create('Ext.data.ArrayStore', {
      fields: [ 'operator' ],
      data: [['\='],['\!\='],['\>'],['\>\='],['\<'],['\<\='],['LIKE'],['NOT LIKE']]
    }),//End create store
    displayField: 'operator',
    fieldLabel: 'Operator',
    queryMode: 'local',
    selectOnTab: false,
    name: 'operator',
    editable: false,
    typeAhead: false,
  };

  var comboValue = {
    xtype: 'textfield',
    fieldLabel: 'Value',
    name: 'value',
  };

  window.fieldGroup = {
    xtype: 'fieldcontainer',
    defaults: {
      allowBlank: false,
      blankText: 'This is a required field',
    },
    items: [comboJoin, comboField, comboOperator, comboValue]
  };

  window.fieldGroup1 = {
    xtype: 'fieldcontainer',
    defaults: {
      allowBlank: false,
      blankText: 'This is a required field',
    },
    items: [comboField, comboOperator, comboValue]

  };
});
