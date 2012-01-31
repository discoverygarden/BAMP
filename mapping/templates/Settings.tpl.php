<br/>
<div id="admin-settings-main">
  <h3><?php print t('Custom Settings') ?></h3>
  <div id="admin-settings-custom-form">
    <?php print drupal_get_form('content_model_viewer_custom_settings_form'); ?>
  </div>
  <div id="admin-settings-default-form">
    <h3><?php print t('Default Settings') ?></h3>
    <?php print drupal_get_form('content_model_viewer_datastream_default_rules_form'); ?>
    <?php print drupal_get_form('content_model_viewer_datastream_mimetype_rules_form'); ?>
    <?php print drupal_get_form('content_model_viewer_datastream_dsid_rules_form'); ?>
    <?php print drupal_get_form('content_model_viewer_datastream_rels_view_derived_form'); ?>
    <?php print drupal_get_form('content_model_viewer_datastream_dsid_view_derived_form'); ?>
  </div>
</div>