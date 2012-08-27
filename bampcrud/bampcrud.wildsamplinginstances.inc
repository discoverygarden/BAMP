<?php

function bampcrud_wild_sampling_instances_form($form, $form_state, $operation = 'add', $record_id = null) {
  $form['record_operation'] = array(
    '#type' => 'hidden',
    '#value' => $operation,
  );

  $disableEdit = FALSE;

  $form['fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Data Form'),
    '#collapsible' => TRUE, 
  );  

  if($operation == 'delete') {
    //store the id
    $form['id'] = array(
      '#type' => 'hidden',
      '#value' => $record_id,
    );
    //Confirmation Message
    $form['fieldset']['confirm'] = array(
      '#markup' => '<strong>Are you sure you want to delete this record?</strong><br/><br/>',
    );
    $form['fieldset']['actions'] = array('#type' => 'actions');
    $form['fieldset']['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete Record'),
    );
    $form['fieldset']['actions']['cancel'] = array(
      '#markup' => l(t('Cancel'), 'wild-sampling-instances'),
    );

    return $form;
  }//end if

  //if the operation is modify, grab the record from the database.
  if ($operation == 'modify') {
    $result = db_select('bamp_wild_sampling_instances', 'n', array('target'=>'bamp_new'))
    ->fields('n',array(
      'id',
      'trip_set_id',
      'data_source',
      'trip_date',
      'trip_year',
      'trip_month',
      'trip_day',
      'wild_site_number',
      'wild_site_name',
      'latitude_as_recorded',
      'latitude_as_calculated',
      'latitude',
      'longitude_as_recorded',
      'longitude_as_calculated',
      'longitude',
      'trip_replicate',
      'route',
      'gear_type',
      'zone',
      'chum_captured',
      'chum_retained',
      'chum_assessed',
      'pink_captured',
      'pink_retained',
      'pink_assessed',
      'coho_captured',
      'coho_retained',
      'coho_assessed',
      'other_salmon_captured',
      'other_salmon_retained',
      'other_salmon_assessed',
      'other_species_captured',
      'other_species_retained',
      'other_species_assessed',
      'other_fish_assessed',
      'crew',
      'tide',
      'search_time',
      'salinity',
      'salinity_surface',
      'salinity_1m',
      'salinity_5m',
      'salinity_refract',
      'salinity_depth_not_specified',
      'temperature',
      'temperature_surface',
      'temperature_1m',
      'temperature_5m',
      'temperature_dfo_surface',
      'temperature_depth_not_specified',
      'weather_comments',
      'comments',
      'change_log',
      'set_no',
      'site_name_rec',
      'blind_no',
      'to_lab',
      'trip',
      'trip_time',
      'three_spine_stickleback',
      'mortalities',
    ))
    ->condition('id', $record_id,'=')
    ->execute()
    ->fetchAssoc();

    //store the id
    $form['id'] = array(
      '#type' => 'hidden',
      '#value' => $record_id,
    );

    $disableEdit = TRUE;
  }//end if


  //Form Fields
  # id text field
  $form['fieldset']['id'] = array(
    '#type' => 'textfield',
    '#title' => t('id'),
    '#default_value' => isset($result['id']) ? $result['id'] : null,
    '#required' => FALSE,
    '#disabled' => TRUE,
  );  
  # trip_set_id text field
  $form['fieldset']['trip_set_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Trip Set ID'),
    '#default_value' => isset($result['trip_set_id']) ? $result['trip_set_id'] : null,
    '#required' => TRUE,
    '#disabled' => $disableEdit,
  );  
  # data_source text field
  $form['fieldset']['data_source'] = array(
    '#type' => 'textfield',
    '#title' => t('Data Source (BAMP, MK, DFO)'),
    '#default_value' => isset($result['data_source']) ? $result['data_source'] : null,
    '#required' => TRUE,
    '#disabled' => $disableEdit,
  );  
  # trip_date text field
  $form['fieldset']['trip_date'] = array(
    '#type' => 'textfield',
    '#title' => t('Trip Date'),
    '#default_value' => isset($result['trip_date']) ? $result['trip_date'] : null,
    '#required' => FALSE,
  );  
  # trip_year text field
  $form['fieldset']['trip_year'] = array(
    '#type' => 'textfield',
    '#title' => t('Trip Year'),
    '#default_value' => isset($result['trip_year']) ? $result['trip_year'] : null,
    '#required' => TRUE,
  );  
  # trip_month text field
  $form['fieldset']['trip_month'] = array(
    '#type' => 'textfield',
    '#title' => t('Trip Month'),
    '#default_value' => isset($result['trip_month']) ? $result['trip_month'] : null,
    '#required' => TRUE,
  );  
  # trip_day text field
  $form['fieldset']['trip_day'] = array(
    '#type' => 'textfield',
    '#title' => t('Trip Day'),
    '#default_value' => isset($result['trip_day']) ? $result['trip_day'] : null,
    '#required' => FALSE,
  );  
  # bamp_site_number text field
  $form['fieldset']['wild_site_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Wild Site Number'),
    '#default_value' => isset($result['wild_site_number']) ? $result['wild_site_number'] : null,
    '#required' => FALSE,
  );  
  # bamp_site_name text field
  $form['fieldset']['wild_site_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Wild Site Name'),
    '#default_value' => isset($result['wild_site_name']) ? $result['wild_site_name'] : null,
    '#required' => FALSE,
  );  
  # latitude_rec text field
  $form['fieldset']['latitude_as_recorded'] = array(
    '#type' => 'textfield',
    '#title' => t('Latitude (As Recorded)'),
    '#default_value' => isset($result['latitude_as_recorded']) ? $result['latitude_as_recorded'] : null,
    '#required' => FALSE,
  );  
  # latitude_calc text field
  $form['fieldset']['latitude_as_calculated'] = array(
    '#type' => 'textfield',
    '#title' => t('Latitude (Calculated)'),
    '#default_value' => isset($result['latitude_as_calculated']) ? $result['latitude_as_calculated'] : null,
    '#required' => FALSE,
  );  
  # latitude text field
  $form['fieldset']['latitude'] = array(
    '#type' => 'textfield',
    '#title' => t('Latitude'),
    '#default_value' => isset($result['latitude']) ? $result['latitude'] : null,
    '#required' => TRUE,
  );  
  # longitude_rec text field
  $form['fieldset']['longitude_as_recorded'] = array(
    '#type' => 'textfield',
    '#title' => t('Longitude (As Recorded)'),
    '#default_value' => isset($result['longitude_as_recorded']) ? $result['longitude_as_recorded'] : null,
    '#required' => FALSE,
  );  
  # longitude_calc text field
  $form['fieldset']['longitude_as_calculated'] = array(
    '#type' => 'textfield',
    '#title' => t('Longitude (Calculated)'),
    '#default_value' => isset($result['longitude_as_calculated']) ? $result['longitude_as_calculated'] : null,
    '#required' => FALSE,
  );  
  # longitude text field
  $form['fieldset']['longitude'] = array(
    '#type' => 'textfield',
    '#title' => t('Longitude'),
    '#default_value' => isset($result['longitude']) ? $result['longitude'] : null,
    '#required' => TRUE,
  );  
  # trip_rep text field
  $form['fieldset']['trip_replicate'] = array(
    '#type' => 'textfield',
    '#title' => t('Trip Replicate'),
    '#default_value' => isset($result['trip_replicate']) ? $result['trip_replicate'] : null,
    '#required' => FALSE,
  );  
  # route text field
  $form['fieldset']['route'] = array(
    '#type' => 'textfield',
    '#title' => t('Route'),
    '#default_value' => isset($result['route']) ? $result['route'] : null,
    '#required' => FALSE,
  );  
  # gear_type text field
  $form['fieldset']['gear_type'] = array(
    '#type' => 'textfield',
    '#title' => t('Gear Type'),
    '#default_value' => isset($result['gear_type']) ? $result['gear_type'] : null,
    '#required' => FALSE,
  );  
  # zone text field
  $form['fieldset']['zone'] = array(
    '#type' => 'textfield',
    '#title' => t('Zone'),
    '#default_value' => isset($result['zone']) ? $result['zone'] : null,
    '#required' => FALSE,
  );  
  # chum_captured text field
  $form['fieldset']['chum_captured'] = array(
    '#type' => 'textfield',
    '#title' => t('Chum Captured'),
    '#default_value' => isset($result['chum_captured']) ? $result['chum_captured'] : null,
    '#required' => FALSE,
  );  
  # chum_retained text field
  $form['fieldset']['chum_retained'] = array(
    '#type' => 'textfield',
    '#title' => t('Chum Retained'),
    '#default_value' => isset($result['chum_retained']) ? $result['chum_retained'] : null,
    '#required' => FALSE,
  );  
  # chum_examined text field
  $form['fieldset']['chum_assessed'] = array(
    '#type' => 'textfield',
    '#title' => t('Chum Assessed'),
    '#default_value' => isset($result['chum_assessed']) ? $result['chum_assessed'] : null,
    '#required' => FALSE,
  );  
  # pink_captured text field
  $form['fieldset']['pink_captured'] = array(
    '#type' => 'textfield',
    '#title' => t('Pink Captured'),
    '#default_value' => isset($result['pink_captured']) ? $result['pink_captured'] : null,
    '#required' => FALSE,
  );  
  # pink_retained text field
  $form['fieldset']['pink_retained'] = array(
    '#type' => 'textfield',
    '#title' => t('Pink Retained'),
    '#default_value' => isset($result['pink_retained']) ? $result['pink_retained'] : null,
    '#required' => FALSE,
  );  
  # pink_examined text field
  $form['fieldset']['pink_assessed'] = array(
    '#type' => 'textfield',
    '#title' => t('Pink Assessed'),
    '#default_value' => isset($result['pink_assessed']) ? $result['pink_assessed'] : null,
    '#required' => FALSE,
  );  
  # coho_captured text field
  $form['fieldset']['coho_captured'] = array(
    '#type' => 'textfield',
    '#title' => t('Coho Captured'),
    '#default_value' => isset($result['coho_captured']) ? $result['coho_captured'] : null,
    '#required' => FALSE,
  );  
  # coho_retained text field
  $form['fieldset']['coho_retained'] = array(
    '#type' => 'textfield',
    '#title' => t('Coho Retained'),
    '#default_value' => isset($result['coho_retained']) ? $result['coho_retained'] : null,
    '#required' => FALSE,
  );  
  # coho_examined text field
  $form['fieldset']['coho_assessed'] = array(
    '#type' => 'textfield',
    '#title' => t('Coho Assessed'),
    '#default_value' => isset($result['coho_assessed']) ? $result['coho_assessed'] : null,
    '#required' => FALSE,
  );  
  # other_salmon_captured text field
  $form['fieldset']['other_salmon_captured'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Salmon Captured'),
    '#default_value' => isset($result['other_salmon_captured']) ? $result['other_salmon_captured'] : null,
    '#required' => FALSE,
  );  
  # other_salmon_retained text field
  $form['fieldset']['other_salmon_retained'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Salmon Retained'),
    '#default_value' => isset($result['other_salmon_retained']) ? $result['other_salmon_retained'] : null,
    '#required' => FALSE,
  );  
  # other_salmon_examined text field
  $form['fieldset']['other_salmon_assessed'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Salmon Assessed'),
    '#default_value' => isset($result['other_salmon_assessed']) ? $result['other_salmon_assessed'] : null,
    '#required' => FALSE,
  );  
  # other_species_captured text field
  $form['fieldset']['other_species_captured'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Species Captured'),
    '#default_value' => isset($result['other_species_captured']) ? $result['other_species_captured'] : null,
    '#required' => FALSE,
  );  
  # other_species_retained text field
  $form['fieldset']['other_species_retained'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Species Retained'),
    '#default_value' => isset($result['other_species_retained']) ? $result['other_species_retained'] : null,
    '#required' => FALSE,
  );  
  # other_species_examined text field
  $form['fieldset']['other_species_assessed'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Species Assessed'),
    '#default_value' => isset($result['other_species_assessed']) ? $result['other_species_assessed'] : null,
    '#required' => FALSE,
  );  
  # other_species_examined text field
  $form['fieldset']['other_fish_assessed'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Fish Assessed'),
    '#default_value' => isset($result['other_fish_assessed']) ? $result['other_fish_assessed'] : null,
    '#required' => FALSE,
  );
  # crew text field
  $form['fieldset']['crew'] = array(
    '#type' => 'textfield',
    '#title' => t('Crew'),
    '#default_value' => isset($result['crew']) ? $result['crew'] : null,
    '#required' => FALSE,
  );  
  # tide text field
  $form['fieldset']['tide'] = array(
    '#type' => 'textfield',
    '#title' => t('Tide'),
    '#default_value' => isset($result['tide']) ? $result['tide'] : null,
    '#required' => FALSE,
  );  
  # search_time text field
  $form['fieldset']['search_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Search Time'),
    '#default_value' => isset($result['search_time']) ? $result['search_time'] : null,
    '#required' => FALSE,
  );  
  # salinity_avg text field
  $form['fieldset']['salinity'] = array(
    '#type' => 'textfield',
    '#title' => t('Salinity'),
    '#default_value' => isset($result['salinity']) ? $result['salinity'] : null,
    '#required' => FALSE,
  );  
  # salinity_0_2 text field
  $form['fieldset']['salinity_surface'] = array(
    '#type' => 'textfield',
    '#title' => t('Salinity (Surface)'),
    '#default_value' => isset($result['salinity_surface']) ? $result['salinity_surface'] : null,
    '#required' => FALSE,
  );  
  # salinity_1 text field
  $form['fieldset']['salinity_1m'] = array(
    '#type' => 'textfield',
    '#title' => t('Salinity (1m)'),
    '#default_value' => isset($result['salinity_1m']) ? $result['salinity_1m'] : null,
    '#required' => FALSE,
  );  
  # salinity_5 text field
  $form['fieldset']['salinity_5m'] = array(
    '#type' => 'textfield',
    '#title' => t('Salinity (5m)'),
    '#default_value' => isset($result['salinity_5m']) ? $result['salinity_5m'] : null,
    '#required' => FALSE,
  );  
  # salinity_refract text field
  $form['fieldset']['salinity_refract'] = array(
    '#type' => 'textfield',
    '#title' => t('Salinity (Refract)'),
    '#default_value' => isset($result['salinity_refract']) ? $result['salinity_refract'] : null,
    '#required' => FALSE,
  );  
  # salinity_depth_not_specified text field
  $form['fieldset']['salinity_depth_not_specified'] = array(
    '#type' => 'textfield',
    '#title' => t('Salinity (Depth not specified)'),
    '#default_value' => isset($result['salinity_depth_not_specified']) ? $result['salinity_depth_not_specified'] : null,
    '#required' => FALSE,
  );  
  # temperature_avg text field
  $form['fieldset']['temperature'] = array(
    '#type' => 'textfield',
    '#title' => t('Temperature'),
    '#default_value' => isset($result['temperature']) ? $result['temperature'] : null,
    '#required' => FALSE,
  );  
  # temperature_0_2 text field
  $form['fieldset']['temperature_surface'] = array(
    '#type' => 'textfield',
    '#title' => t('Temperature (Surface)'),
    '#default_value' => isset($result['temperature_surface']) ? $result['temperature_surface'] : null,
    '#required' => FALSE,
  );  
  # temperature_1 text field
  $form['fieldset']['temperature_1m'] = array(
    '#type' => 'textfield',
    '#title' => t('Temperature (1m)'),
    '#default_value' => isset($result['temperature_1m']) ? $result['temperature_1m'] : null,
    '#required' => FALSE,
  );  
  # temperature_5 text field
  $form['fieldset']['temperature_5m'] = array(
    '#type' => 'textfield',
    '#title' => t('Temperature (5m)'),
    '#default_value' => isset($result['temperature_5m']) ? $result['temperature_5m'] : null,
    '#required' => FALSE,
  );  
  # temperature_rec text field
  $form['fieldset']['temperature_dfo_surface'] = array(
    '#type' => 'textfield',
    '#title' => t('Temperature (DFO, Surface)'),
    '#default_value' => isset($result['temperature_dfo_surface']) ? $result['temperature_dfo_surface'] : null,
    '#required' => FALSE,
  );  
  # temperature_depth_not_specified text field
  $form['fieldset']['temperature_depth_not_specified'] = array(
    '#type' => 'textfield',
    '#title' => t('Temperature (Depth not specified)'),
    '#default_value' => isset($result['temperature_depth_not_specified']) ? $result['temperature_depth_not_specified'] : null,
    '#required' => FALSE,
  );  
  # weather_comments text field
  $form['fieldset']['weather_comments'] = array(
    '#type' => 'textfield',
    '#title' => t('Weather Comments'),
    '#default_value' => isset($result['weather_comments']) ? $result['weather_comments'] : null,
    '#required' => FALSE,
  );  
  # comments text field
  $form['fieldset']['comments'] = array(
    '#type' => 'textfield',
    '#title' => t('Comments'),
    '#default_value' => isset($result['comments']) ? $result['comments'] : null,
    '#required' => FALSE,
  );  
  # changelog text field
  $form['fieldset']['change_log'] = array(
    '#type' => 'textfield',
    '#title' => t('Change Log (Describe Change/Addition)'),
    '#default_value' => isset($result['change_log']) ? $result['change_log'] : null,
    '#required' => TRUE,
  );  
  # set_no text field
  $form['fieldset']['set_no'] = array(
    '#type' => 'textfield',
    '#title' => t('Set No'),
    '#default_value' => isset($result['set_no']) ? $result['set_no'] : null,
    '#required' => FALSE,
  );  
  # site_name_rec text field
  $form['fieldset']['site_name_as_recorded'] = array(
    '#type' => 'textfield',
    '#title' => t('Site Name (As Recorded)'),
    '#default_value' => isset($result['site_name_as_recorded']) ? $result['site_name_as_recorded'] : null,
    '#required' => FALSE,
  );  
  # blind_no text field
  $form['fieldset']['blind_no'] = array(
    '#type' => 'textfield',
    '#title' => t('Blind No.'),
    '#default_value' => isset($result['blind_no']) ? $result['blind_no'] : null,
    '#required' => FALSE,
  );  
  # to_lab text field
  $form['fieldset']['to_lab'] = array(
    '#type' => 'textfield',
    '#title' => t('To Lab'),
    '#default_value' => isset($result['to_lab']) ? $result['to_lab'] : null,
    '#required' => FALSE,
  );  
  # trip_time text field
  $form['fieldset']['trip_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Trip Time'),
    '#default_value' => isset($result['trip_time']) ? $result['trip_time'] : null,
    '#required' => FALSE,
  );  
  # tsb text field
  $form['fieldset']['three_spine_stickleback'] = array(
    '#type' => 'textfield',
    '#title' => t('TSB'),
    '#default_value' => isset($result['three_spine_stickleback']) ? $result['three_spine_stickleback'] : null,
    '#required' => FALSE,
  );  
  # mortalities text field
  $form['fieldset']['mortalities'] = array(
    '#type' => 'textfield',
    '#title' => t('Mortalities'),
    '#default_value' => isset($result['mortalities']) ? $result['mortalities'] : null,
    '#required' => FALSE,
  );  
 

  if($operation == 'modify'){
    $form['fieldset']['submit'] = array(
      '#type' => 'submit',
      '#value' => 'Save Change',
    );
  }else{
    $form['fieldset']['submit'] = array(
      '#type' => 'submit',
      '#value' => 'Add Record',
    );
  }//end if

  return $form;
}//end addedit_form();

function bampcrud_wild_sampling_instances_form_submit($form, &$form_state) {
  switch ($form_state['values']['op']) {
    case 'Add Record' :
      //Add db insert 
      $result = db_insert('bamp_wild_sampling_instances', array('target'=>'bamp_new'))
      ->fields(array(
        'trip_set_id' => $form_state['values']['trip_set_id'],
        'data_source' => $form_state['values']['data_source'],
        'trip_date' => $form_state['values']['trip_date'],
        'trip_year' => $form_state['values']['trip_year'],
        'trip_month' => $form_state['values']['trip_month'],
        'trip_day' => $form_state['values']['trip_day'],
        'wild_site_number' => $form_state['values']['wild_site_number'],
        'wild_site_name' => $form_state['values']['wild_site_name'],
        'latitude_as_recorded' => $form_state['values']['latitude_as_recorded'],
        'latitude_as_calculated' => $form_state['values']['latitude_as_calculated'],
        'latitude' => $form_state['values']['latitude'],
        'longitude_as_recorded' => $form_state['values']['longitude_as_recorded'],
        'longitude_as_calculated' => $form_state['values']['longitude_as_calculated'],
        'longitude' => $form_state['values']['longitude'],
        'trip_replicate' => $form_state['values']['trip_replicate'],
        'route' => $form_state['values']['route'],
        'gear_type' => $form_state['values']['gear_type'],
        'zone' => $form_state['values']['zone'],
        'chum_captured' => $form_state['values']['chum_captured'],
        'chum_retained' => $form_state['values']['chum_retained'],
        'chum_assessed' => $form_state['values']['chum_assessed'],
        'pink_captured' => $form_state['values']['pink_captured'],
        'pink_retained' => $form_state['values']['pink_retained'],
        'pink_assessed' => $form_state['values']['pink_assessed'],
        'coho_captured' => $form_state['values']['coho_captured'],
        'coho_retained' => $form_state['values']['coho_retained'],
        'coho_assessed' => $form_state['values']['coho_assessed'],
        'other_salmon_captured' => $form_state['values']['other_salmon_captured'],
        'other_salmon_retained' => $form_state['values']['other_salmon_retained'],
        'other_salmon_assessed' => $form_state['values']['other_salmon_assessed'],
        'other_species_captured' => $form_state['values']['other_species_captured'],
        'other_species_retained' => $form_state['values']['other_species_retained'],
        'other_species_assessed' => $form_state['values']['other_species_assessed'],
        'other_fish_assessed' => $form_state['values']['other_fish_assessed'],
        'crew' => $form_state['values']['crew'],
        'tide' => $form_state['values']['tide'],
        'search_time' => $form_state['values']['search_time'],
        'salinity' => $form_state['values']['salinity'],
        'salinity_surface' => $form_state['values']['salinity_surface'],
        'salinity_1m' => $form_state['values']['salinity_1m'],
        'salinity_5m' => $form_state['values']['salinity_5m'],
        'salinity_refract' => $form_state['values']['salinity_refract'],
        'salinity_depth_not_specified' => $form_state['values']['salinity_depth_not_specified'],
        'temperature' => $form_state['values']['temperature'],
        'temperature_surface' => $form_state['values']['temperature_surface'],
        'temperature_1m' => $form_state['values']['temperature_1m'],
        'temperature_5m' => $form_state['values']['temperature_5m'],
        'temperature_dfo_surface' => $form_state['values']['temperature_dfo_surface'],
        'temperature_depth_not_specified' => $form_state['values']['temperature_depth_not_specified'],
        'weather_comments' => $form_state['values']['weather_comments'],
        'comments' => $form_state['values']['comments'],
        'change_log' => $form_state['values']['change_log'],
        'set_no' => $form_state['values']['set_no'],
        'site_name_as_recorded' => $form_state['values']['site_name_as_recorded'],
        'blind_no' => $form_state['values']['blind_no'],
        'to_lab' => $form_state['values']['to_lab'],
        'trip_time' => $form_state['values']['trip_time'],
        'three_spine_stickleback' => $form_state['values']['three_spine_stickleback'],
        'mortalities' => $form_state['values']['mortalities'],
      ))
      ->execute();
    
      //drupal_goto('test/multi_step_form', array('query' => array('sort' => 'desc', 'order' => 'Id')));
      drupal_set_message('Wild Sampling Instance Added.');
      break;
    case 'Save Change' :
      //Add db update code

      $num_updated = db_update('bamp_wild_sampling_instances', array('target'=>'bamp_new'))
      ->fields(array(
        'trip_set_id' => $form_state['values']['trip_set_id'],
        'data_source' => $form_state['values']['data_source'],
        'trip_date' => $form_state['values']['trip_date'],
        'trip_year' => $form_state['values']['trip_year'],
        'trip_month' => $form_state['values']['trip_month'],
        'trip_day' => $form_state['values']['trip_day'],
        'wild_site_number' => $form_state['values']['wild_site_number'],
        'wild_site_name' => $form_state['values']['wild_site_name'],
        'latitude_as_recorded' => $form_state['values']['latitude_as_recorded'],
        'latitude_as_calculated' => $form_state['values']['latitude_as_calculated'],
        'latitude' => $form_state['values']['latitude'],
        'longitude_as_recorded' => $form_state['values']['longitude_as_recorded'],
        'longitude_as_calculated' => $form_state['values']['longitude_as_calculated'],
        'longitude' => $form_state['values']['longitude'],
        'trip_replicate' => $form_state['values']['trip_replicate'],
        'route' => $form_state['values']['route'],
        'gear_type' => $form_state['values']['gear_type'],
        'zone' => $form_state['values']['zone'],
        'chum_captured' => $form_state['values']['chum_captured'],
        'chum_retained' => $form_state['values']['chum_retained'],
        'chum_assessed' => $form_state['values']['chum_assessed'],
        'pink_captured' => $form_state['values']['pink_captured'],
        'pink_retained' => $form_state['values']['pink_retained'],
        'pink_assessed' => $form_state['values']['pink_assessed'],
        'coho_captured' => $form_state['values']['coho_captured'],
        'coho_retained' => $form_state['values']['coho_retained'],
        'coho_assessed' => $form_state['values']['coho_assessed'],
        'other_salmon_captured' => $form_state['values']['other_salmon_captured'],
        'other_salmon_retained' => $form_state['values']['other_salmon_retained'],
        'other_salmon_assessed' => $form_state['values']['other_salmon_assessed'],
        'other_species_captured' => $form_state['values']['other_species_captured'],
        'other_species_retained' => $form_state['values']['other_species_retained'],
        'other_species_assessed' => $form_state['values']['other_species_assessed'],
        'other_fish_assessed' => $form_state['values']['other_fish_assessed'],
        'crew' => $form_state['values']['crew'],
        'tide' => $form_state['values']['tide'],
        'search_time' => $form_state['values']['search_time'],
        'salinity' => $form_state['values']['salinity'],
        'salinity_surface' => $form_state['values']['salinity_surface'],
        'salinity_1m' => $form_state['values']['salinity_1m'],
        'salinity_5m' => $form_state['values']['salinity_5m'],
        'salinity_refract' => $form_state['values']['salinity_refract'],
        'salinity_depth_not_specified' => $form_state['values']['salinity_depth_not_specified'],
        'temperature' => $form_state['values']['temperature'],
        'temperature_surface' => $form_state['values']['temperature_surface'],
        'temperature_1m' => $form_state['values']['temperature_1m'],
        'temperature_5m' => $form_state['values']['temperature_5m'],
        'temperature_dfo_surface' => $form_state['values']['temperature_dfo_surface'],
        'temperature_depth_not_specified' => $form_state['values']['temperature_depth_not_specified'],
        'weather_comments' => $form_state['values']['weather_comments'],
        'comments' => $form_state['values']['comments'],
        'change_log' => $form_state['values']['change_log'],
        'set_no' => $form_state['values']['set_no'],
        'site_name_as_recorded' => $form_state['values']['site_name_as_recorded'],
        'blind_no' => $form_state['values']['blind_no'],
        'to_lab' => $form_state['values']['to_lab'],
        'trip_time' => $form_state['values']['trip_time'],
        'three_spine_stickleback' => $form_state['values']['three_spine_stickleback'],
        'mortalities' => $form_state['values']['mortalities'],
      ))
      ->condition('id', $form_state['values']['id'],'=')
      ->execute();

      //drupal_goto('test/multi_step_form');
      drupal_set_message('Wild Sampling Instance Updated');
      break;
      case 'Delete Record':
        $num_deleted = db_delete('bamp_wild_sampling_instances', array('target'=>'bamp_new'))
        ->condition('id',$form_state['values']['id'])
        ->execute();

        drupal_goto('wild-sampling-instances');
        drupal_set_message($num_deleted . t(' record has been deleted.'));
      break;
  }//end switch
}//end addedit_form_submit
