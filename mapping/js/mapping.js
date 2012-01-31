/**
 * Display the viewer.
 */
Ext.onReady(function(){
  Ext.define('MyApp.view.ui.MapInterface', {
    extend: 'Ext.container.Container',
    height: 680,
    width: 960,
    renderTo: 'mapInterface',
    layout: {
        type: 'border'
    },

    initComponent: function() {
        var me = this;

        Ext.applyIf(me, {
            items: [
                {
                    xtype: 'panel',
                    width: 150,
                    collapsible: true,
                    title: 'Map Filters',
                    region: 'east',
                },
                {
                    xtype: 'panel',
                    title: 'Map',
                    region: 'center',
                }
            ]
        });

        me.callParent(arguments);
    }
  });
});
