<br/>
<div id="admin-settings-main">
  <h3><?php print t('Custom Settings') ?></h3>
  <?php print drupal_get_form('content_model_viewer_datastream_default_rules_form', $model_id); ?>
  <?php print drupal_get_form('content_model_viewer_datastream_mimetype_rules_form', $model_id); ?>
  <?php print drupal_get_form('content_model_viewer_datastream_dsid_rules_form', $model_id); ?>
</div>