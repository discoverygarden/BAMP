<?php

/**
 * @file Mapping configuration functions
 */

/**
 * Build the configuration manu by displaying all the views sin the database.
 * The user will check off which views they want to access from the mapping report system.
 */
function mapping_admin_settings($form, &$form_state) {
  $form['caption'] = array(
    '#type' => 'markup',
    '#title' => 'Mr. Markup',
    '#markup' => 'Edit available reports in mapping system',
    '#prefix' => '<p>',
    '#suffix' => '</p>',
  );

  // dump the list of available reports to the form
  $reports = "SELECT name, human_name, display_options FROM {views_view} AS vv INNER JOIN {views_display} as vd ON vv.vid=vd.vid WHERE vd.display_plugin='page';";
  $results = db_query($reports);
  $rpts = array();
  while ($rpt = $results->fetchAssoc()) {
    $form['reports']['rpt' . $rpt['name']] = array(
      '#type' => 'checkbox',
      '#title' => $rpt['human_name'],
      '#default_value' => variable_get('rpt' . $rpt['name'], FALSE),
    );
  }

  return system_settings_form($form);
}

