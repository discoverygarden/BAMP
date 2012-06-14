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
      'bamp_site_number',
      'bamp_site_name',
      'latitude_rec',
      'latitude_calc',
      'latitude',
      'longitude_rec',
      'longitude_calc',
      'longitude',
      'trip_rep',
      'route',
      'collection_period_eer',
      'gear_type',
      'zone',
      'chum_captured',
      'chum_retained',
      'chum_examined',
      'pink_captured',
      'pink_retained',
      'pink_examined',
      'coho_captured',
      'coho_retained',
      'coho_examined',
      'other_salmon_captured',
      'other_salmon_retained',
      'other_salmon_examined',
      'other_species_captured',
      'other_species_retained',
      'other_species_examined',
      'crew',
      'tide',
      'search_time',
      'salinity_avg',
      'salinity_0_2',
      'salinity_1',
      'salinity_5',
      'salinity_refract',
      'salinity_depth_not_specified',
      'temperature_avg',
      'temperature_0_2',
      'temperature_1',
      'temperature_5',
      'temperature_rec',
      'temperature_depth_not_specified',
      'weather_comments',
      'comments',
      'changelog',
      'set_no',
      'site_name_rec',
      'site_number_0309',
      'site_number_mk',
      'waypoint',
      'distance',
      'blind_no',
      'to_lab',
      'trip',
      'trip_time',
      'tsb',
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
    '#default_value' => isset($result['id']) ? $result['id'] : '',
    '#required' => FALSE,
    '#disabled' => TRUE,
  );  
  # trip_set_id text field
  $form['fieldset']['trip_set_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Trip Set ID'),
    '#default_value' => isset($result['trip_set_id']) ? $result['trip_set_id'] : '',
    '#required' => FALSE,
    '#disabled' => $disableEdit,
  );  
  # data_source text field
  $form['fieldset']['data_source'] = array(
    '#type' => 'textfield',
    '#title' => t('Data Source'),
    '#default_value' => isset($result['data_source']) ? $result['data_source'] : '',
    '#required' => FALSE,
    '#disabled' => $disableEdit,
  );  
  # trip_date text field
  $form['fieldset']['trip_date'] = array(
    '#type' => 'textfield',
    '#title' => t('Trip Date'),
    '#default_value' => isset($result['trip_date']) ? $result['trip_date'] : '',
    '#required' => FALSE,
  );  
  # trip_year text field
  $form['fieldset']['trip_year'] = array(
    '#type' => 'textfield',
    '#title' => t('Trip Year'),
    '#default_value' => isset($result['trip_year']) ? $result['trip_year'] : '',
    '#required' => FALSE,
  );  
  # trip_month text field
  $form['fieldset']['trip_month'] = array(
    '#type' => 'textfield',
    '#title' => t('Trip Month'),
    '#default_value' => isset($result['trip_month']) ? $result['trip_month'] : '',
    '#required' => FALSE,
  );  
  # trip_day text field
  $form['fieldset']['trip_day'] = array(
    '#type' => 'textfield',
    '#title' => t('Trip Day'),
    '#default_value' => isset($result['trip_day']) ? $result['trip_day'] : '',
    '#required' => FALSE,
  );  
  # bamp_site_number text field
  $form['fieldset']['bamp_site_number'] = array(
    '#type' => 'textfield',
    '#title' => t('BAMP Site Number'),
    '#default_value' => isset($result['bamp_site_number']) ? $result['bamp_site_number'] : '',
    '#required' => FALSE,
  );  
  # bamp_site_name text field
  $form['fieldset']['bamp_site_name'] = array(
    '#type' => 'textfield',
    '#title' => t('BAMP Site Name'),
    '#default_value' => isset($result['bamp_site_name']) ? $result['bamp_site_name'] : '',
    '#required' => FALSE,
  );  
  # latitude_rec text field
  $form['fieldset']['latitude_rec'] = array(
    '#type' => 'textfield',
    '#title' => t('Latitude (As Recorded)'),
    '#default_value' => isset($result['latitude_rec']) ? $result['latitude_rec'] : '',
    '#required' => FALSE,
  );  
  # latitude_calc text field
  $form['fieldset']['latitude_calc'] = array(
    '#type' => 'textfield',
    '#title' => t('Latitude (Calculated)'),
    '#default_value' => isset($result['latitude_calc']) ? $result['latitude_calc'] : '',
    '#required' => FALSE,
  );  
  # latitude text field
  $form['fieldset']['latitude'] = array(
    '#type' => 'textfield',
    '#title' => t('Latitude'),
    '#default_value' => isset($result['latitude']) ? $result['latitude'] : '',
    '#required' => FALSE,
  );  
  # longitude_rec text field
  $form['fieldset']['longitude_rec'] = array(
    '#type' => 'textfield',
    '#title' => t('Longitude (As Recorded)'),
    '#default_value' => isset($result['longitude_rec']) ? $result['longitude_rec'] : '',
    '#required' => FALSE,
  );  
  # longitude_calc text field
  $form['fieldset']['longitude_calc'] = array(
    '#type' => 'textfield',
    '#title' => t('Longitude (Calculated)'),
    '#default_value' => isset($result['longitude_calc']) ? $result['longitude_calc'] : '',
    '#required' => FALSE,
  );  
  # longitude text field
  $form['fieldset']['longitude'] = array(
    '#type' => 'textfield',
    '#title' => t('Longitude'),
    '#default_value' => isset($result['longitude']) ? $result['longitude'] : '',
    '#required' => FALSE,
  );  
  # trip_rep text field
  $form['fieldset']['trip_rep'] = array(
    '#type' => 'textfield',
    '#title' => t('Trip Rep'),
    '#default_value' => isset($result['trip_rep']) ? $result['trip_rep'] : '',
    '#required' => FALSE,
  );  
  # route text field
  $form['fieldset']['route'] = array(
    '#type' => 'textfield',
    '#title' => t('Route'),
    '#default_value' => isset($result['route']) ? $result['route'] : '',
    '#required' => FALSE,
  );  
  # collection_period_eer text field
  $form['fieldset']['collection_period_eer'] = array(
    '#type' => 'textfield',
    '#title' => t('collection_period_eer'),
    '#default_value' => isset($result['collection_period_eer']) ? $result['collection_period_eer'] : '',
    '#required' => FALSE,
  );  
  # gear_type text field
  $form['fieldset']['gear_type'] = array(
    '#type' => 'textfield',
    '#title' => t('Gear Type'),
    '#default_value' => isset($result['gear_type']) ? $result['gear_type'] : '',
    '#required' => FALSE,
  );  
  # zone text field
  $form['fieldset']['zone'] = array(
    '#type' => 'textfield',
    '#title' => t('Zone'),
    '#default_value' => isset($result['zone']) ? $result['zone'] : '',
    '#required' => FALSE,
  );  
  # chum_captured text field
  $form['fieldset']['chum_captured'] = array(
    '#type' => 'textfield',
    '#title' => t('Chum Captured'),
    '#default_value' => isset($result['chum_captured']) ? $result['chum_captured'] : '',
    '#required' => FALSE,
  );  
  # chum_retained text field
  $form['fieldset']['chum_retained'] = array(
    '#type' => 'textfield',
    '#title' => t('Chum Retained'),
    '#default_value' => isset($result['chum_retained']) ? $result['chum_retained'] : '',
    '#required' => FALSE,
  );  
  # chum_examined text field
  $form['fieldset']['chum_examined'] = array(
    '#type' => 'textfield',
    '#title' => t('Chum Examined'),
    '#default_value' => isset($result['chum_examined']) ? $result['chum_examined'] : '',
    '#required' => FALSE,
  );  
  # pink_captured text field
  $form['fieldset']['pink_captured'] = array(
    '#type' => 'textfield',
    '#title' => t('Pink Captured'),
    '#default_value' => isset($result['pink_captured']) ? $result['pink_captured'] : '',
    '#required' => FALSE,
  );  
  # pink_retained text field
  $form['fieldset']['pink_retained'] = array(
    '#type' => 'textfield',
    '#title' => t('Pink Retained'),
    '#default_value' => isset($result['pink_retained']) ? $result['pink_retained'] : '',
    '#required' => FALSE,
  );  
  # pink_examined text field
  $form['fieldset']['pink_examined'] = array(
    '#type' => 'textfield',
    '#title' => t('Pink Examined'),
    '#default_value' => isset($result['pink_examined']) ? $result['pink_examined'] : '',
    '#required' => FALSE,
  );  
  # coho_captured text field
  $form['fieldset']['coho_captured'] = array(
    '#type' => 'textfield',
    '#title' => t('Coho Captured'),
    '#default_value' => isset($result['coho_captured']) ? $result['coho_captured'] : '',
    '#required' => FALSE,
  );  
  # coho_retained text field
  $form['fieldset']['coho_retained'] = array(
    '#type' => 'textfield',
    '#title' => t('Coho Retained'),
    '#default_value' => isset($result['coho_retained']) ? $result['coho_retained'] : '',
    '#required' => FALSE,
  );  
  # coho_examined text field
  $form['fieldset']['coho_examined'] = array(
    '#type' => 'textfield',
    '#title' => t('Coho Examined'),
    '#default_value' => isset($result['coho_examined']) ? $result['coho_examined'] : '',
    '#required' => FALSE,
  );  
  # other_salmon_captured text field
  $form['fieldset']['other_salmon_captured'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Salmon Captured'),
    '#default_value' => isset($result['other_salmon_captured']) ? $result['other_salmon_captured'] : '',
    '#required' => FALSE,
  );  
  # other_salmon_retained text field
  $form['fieldset']['other_salmon_retained'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Salmon Retained'),
    '#default_value' => isset($result['other_salmon_retained']) ? $result['other_salmon_retained'] : '',
    '#required' => FALSE,
  );  
  # other_salmon_examined text field
  $form['fieldset']['other_salmon_examined'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Salmon Examined'),
    '#default_value' => isset($result['other_salmon_examined']) ? $result['other_salmon_examined'] : '',
    '#required' => FALSE,
  );  
  # other_species_captured text field
  $form['fieldset']['other_species_captured'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Species Captured'),
    '#default_value' => isset($result['other_species_captured']) ? $result['other_species_captured'] : '',
    '#required' => FALSE,
  );  
  # other_species_retained text field
  $form['fieldset']['other_species_retained'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Species Retained'),
    '#default_value' => isset($result['other_species_retained']) ? $result['other_species_retained'] : '',
    '#required' => FALSE,
  );  
  # other_species_examined text field
  $form['fieldset']['other_species_examined'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Species Examined'),
    '#default_value' => isset($result['other_species_examined']) ? $result['other_species_examined'] : '',
    '#required' => FALSE,
  );  
  # crew text field
  $form['fieldset']['crew'] = array(
    '#type' => 'textfield',
    '#title' => t('Crew'),
    '#default_value' => isset($result['crew']) ? $result['crew'] : '',
    '#required' => FALSE,
  );  
  # tide text field
  $form['fieldset']['tide'] = array(
    '#type' => 'textfield',
    '#title' => t('Tide'),
    '#default_value' => isset($result['tide']) ? $result['tide'] : '',
    '#required' => FALSE,
  );  
  # search_time text field
  $form['fieldset']['search_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Search Time'),
    '#default_value' => isset($result['search_time']) ? $result['search_time'] : '',
    '#required' => FALSE,
  );  
  # salinity_avg text field
  $form['fieldset']['salinity_avg'] = array(
    '#type' => 'textfield',
    '#title' => t('Salinity (Average)'),
    '#default_value' => isset($result['salinity_avg']) ? $result['salinity_avg'] : '',
    '#required' => FALSE,
  );  
  # salinity_0_2 text field
  $form['fieldset']['salinity_0_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Salinity (0-2m)'),
    '#default_value' => isset($result['salinity_0_2']) ? $result['salinity_0_2'] : '',
    '#required' => FALSE,
  );  
  # salinity_1 text field
  $form['fieldset']['salinity_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Salinity (1m)'),
    '#default_value' => isset($result['salinity_1']) ? $result['salinity_1'] : '',
    '#required' => FALSE,
  );  
  # salinity_5 text field
  $form['fieldset']['salinity_5'] = array(
    '#type' => 'textfield',
    '#title' => t('Salinity (5m)'),
    '#default_value' => isset($result['salinity_5']) ? $result['salinity_5'] : '',
    '#required' => FALSE,
  );  
  # salinity_refract text field
  $form['fieldset']['salinity_refract'] = array(
    '#type' => 'textfield',
    '#title' => t('Salinity (Refract)'),
    '#default_value' => isset($result['salinity_refract']) ? $result['salinity_refract'] : '',
    '#required' => FALSE,
  );  
  # salinity_depth_not_specified text field
  $form['fieldset']['salinity_depth_not_specified'] = array(
    '#type' => 'textfield',
    '#title' => t('Salinity (Depth not specified)'),
    '#default_value' => isset($result['salinity_depth_not_specified']) ? $result['salinity_depth_not_specified'] : '',
    '#required' => FALSE,
  );  
  # temperature_avg text field
  $form['fieldset']['temperature_avg'] = array(
    '#type' => 'textfield',
    '#title' => t('Temperature (Average)'),
    '#default_value' => isset($result['temperature_avg']) ? $result['temperature_avg'] : '',
    '#required' => FALSE,
  );  
  # temperature_0_2 text field
  $form['fieldset']['temperature_0_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Temperature (0-2m)'),
    '#default_value' => isset($result['temperature_0_2']) ? $result['temperature_0_2'] : '',
    '#required' => FALSE,
  );  
  # temperature_1 text field
  $form['fieldset']['temperature_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Temperature (1m)'),
    '#default_value' => isset($result['temperature_1']) ? $result['temperature_1'] : '',
    '#required' => FALSE,
  );  
  # temperature_5 text field
  $form['fieldset']['temperature_5'] = array(
    '#type' => 'textfield',
    '#title' => t('Temperature (5m)'),
    '#default_value' => isset($result['temperature_5']) ? $result['temperature_5'] : '',
    '#required' => FALSE,
  );  
  # temperature_rec text field
  $form['fieldset']['temperature_rec'] = array(
    '#type' => 'textfield',
    '#title' => t('Temperature (As Recorded)'),
    '#default_value' => isset($result['temperature_rec']) ? $result['temperature_rec'] : '',
    '#required' => FALSE,
  );  
  # temperature_depth_not_specified text field
  $form['fieldset']['temperature_depth_not_specified'] = array(
    '#type' => 'textfield',
    '#title' => t('Temperature (Depth not specified)'),
    '#default_value' => isset($result['temperature_depth_not_specified']) ? $result['temperature_depth_not_specified'] : '',
    '#required' => FALSE,
  );  
  # weather_comments text field
  $form['fieldset']['weather_comments'] = array(
    '#type' => 'textfield',
    '#title' => t('Weather Comments'),
    '#default_value' => isset($result['weather_comments']) ? $result['weather_comments'] : '',
    '#required' => FALSE,
  );  
  # comments text field
  $form['fieldset']['comments'] = array(
    '#type' => 'textfield',
    '#title' => t('Comments'),
    '#default_value' => isset($result['comments']) ? $result['comments'] : '',
    '#required' => FALSE,
  );  
  # changelog text field
  $form['fieldset']['changelog'] = array(
    '#type' => 'textfield',
    '#title' => t('Change Log'),
    '#default_value' => isset($result['changelog']) ? $result['changelog'] : '',
    '#required' => FALSE,
  );  
  # set_no text field
  $form['fieldset']['set_no'] = array(
    '#type' => 'textfield',
    '#title' => t('Set No'),
    '#default_value' => isset($result['set_no']) ? $result['set_no'] : '',
    '#required' => FALSE,
  );  
  # site_name_rec text field
  $form['fieldset']['site_name_rec'] = array(
    '#type' => 'textfield',
    '#title' => t('Site Name (As Recorded)'),
    '#default_value' => isset($result['site_name_rec']) ? $result['site_name_rec'] : '',
    '#required' => FALSE,
  );  
  # site_number_0309 text field
  $form['fieldset']['site_number_0309'] = array(
    '#type' => 'textfield',
    '#title' => t('Site Number (0309)'),
    '#default_value' => isset($result['site_number_0309']) ? $result['site_number_0309'] : '',
    '#required' => FALSE,
  );  
  # site_number_mk text field
  $form['fieldset']['site_number_mk'] = array(
    '#type' => 'textfield',
    '#title' => t('Site Number (MK)'),
    '#default_value' => isset($result['site_number_mk']) ? $result['site_number_mk'] : '',
    '#required' => FALSE,
  );  
  # waypoint text field
  $form['fieldset']['waypoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Waypoint'),
    '#default_value' => isset($result['waypoint']) ? $result['waypoint'] : '',
    '#required' => FALSE,
  );  
  # distance text field
  $form['fieldset']['distance'] = array(
    '#type' => 'textfield',
    '#title' => t('Distance'),
    '#default_value' => isset($result['distance']) ? $result['distance'] : '',
    '#required' => FALSE,
  );  
  # blind_no text field
  $form['fieldset']['blind_no'] = array(
    '#type' => 'textfield',
    '#title' => t('Blind No.'),
    '#default_value' => isset($result['blind_no']) ? $result['blind_no'] : '',
    '#required' => FALSE,
  );  
  # to_lab text field
  $form['fieldset']['to_lab'] = array(
    '#type' => 'textfield',
    '#title' => t('To Lab'),
    '#default_value' => isset($result['to_lab']) ? $result['to_lab'] : '',
    '#required' => FALSE,
  );  
  # trip text field
  $form['fieldset']['trip'] = array(
    '#type' => 'textfield',
    '#title' => t('Trip'),
    '#default_value' => isset($result['trip']) ? $result['trip'] : '',
    '#required' => FALSE,
  );  
  # trip_time text field
  $form['fieldset']['trip_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Trip Time'),
    '#default_value' => isset($result['trip_time']) ? $result['trip_time'] : '',
    '#required' => FALSE,
  );  
  # tsb text field
  $form['fieldset']['tsb'] = array(
    '#type' => 'textfield',
    '#title' => t('TSB'),
    '#default_value' => isset($result['tsb']) ? $result['tsb'] : '',
    '#required' => FALSE,
  );  
  # mortalities text field
  $form['fieldset']['mortalities'] = array(
    '#type' => 'textfield',
    '#title' => t('Mortalities'),
    '#default_value' => isset($result['mortalities']) ? $result['mortalities'] : '',
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
        'bamp_site_number' => $form_state['values']['bamp_site_number'],
        'bamp_site_name' => $form_state['values']['bamp_site_name'],
        'latitude_rec' => $form_state['values']['latitude_rec'],
        'latitude_calc' => $form_state['values']['latitude_calc'],
        'latitude' => $form_state['values']['latitude'],
        'longitude_rec' => $form_state['values']['longitude_rec'],
        'longitude_calc' => $form_state['values']['longitude_calc'],
        'longitude' => $form_state['values']['longitude'],
        'trip_rep' => $form_state['values']['trip_rep'],
        'route' => $form_state['values']['route'],
        'collection_period_eer' => $form_state['values']['collection_period_eer'],
        'gear_type' => $form_state['values']['gear_type'],
        'zone' => $form_state['values']['zone'],
        'chum_captured' => $form_state['values']['chum_captured'],
        'chum_retained' => $form_state['values']['chum_retained'],
        'chum_examined' => $form_state['values']['chum_examined'],
        'pink_captured' => $form_state['values']['pink_captured'],
        'pink_retained' => $form_state['values']['pink_retained'],
        'pink_examined' => $form_state['values']['pink_examined'],
        'coho_captured' => $form_state['values']['coho_captured'],
        'coho_retained' => $form_state['values']['coho_retained'],
        'coho_examined' => $form_state['values']['coho_examined'],
        'other_salmon_captured' => $form_state['values']['other_salmon_captured'],
        'other_salmon_retained' => $form_state['values']['other_salmon_retained'],
        'other_salmon_examined' => $form_state['values']['other_salmon_examined'],
        'other_species_captured' => $form_state['values']['other_species_captured'],
        'other_species_retained' => $form_state['values']['other_species_retained'],
        'other_species_examined' => $form_state['values']['other_species_examined'],
        'crew' => $form_state['values']['crew'],
        'tide' => $form_state['values']['tide'],
        'search_time' => $form_state['values']['search_time'],
        'salinity_avg' => $form_state['values']['salinity_avg'],
        'salinity_0_2' => $form_state['values']['salinity_0_2'],
        'salinity_1' => $form_state['values']['salinity_1'],
        'salinity_5' => $form_state['values']['salinity_5'],
        'salinity_refract' => $form_state['values']['salinity_refract'],
        'salinity_depth_not_specified' => $form_state['values']['salinity_depth_not_specified'],
        'temperature_avg' => $form_state['values']['temperature_avg'],
        'temperature_0_2' => $form_state['values']['temperature_0_2'],
        'temperature_1' => $form_state['values']['temperature_1'],
        'temperature_5' => $form_state['values']['temperature_5'],
        'temperature_rec' => $form_state['values']['temperature_rec'],
        'temperature_depth_not_specified' => $form_state['values']['temperature_depth_not_specified'],
        'weather_comments' => $form_state['values']['weather_comments'],
        'comments' => $form_state['values']['comments'],
        'changelog' => $form_state['values']['changelog'],
        'set_no' => $form_state['values']['set_no'],
        'site_name_rec' => $form_state['values']['site_name_rec'],
        'site_number_0309' => $form_state['values']['site_number_0309'],
        'site_number_mk' => $form_state['values']['site_number_mk'],
        'waypoint' => $form_state['values']['waypoint'],
        'distance' => $form_state['values']['distance'],
        'blind_no' => $form_state['values']['blind_no'],
        'to_lab' => $form_state['values']['to_lab'],
        'trip' => $form_state['values']['trip'],
        'trip_time' => $form_state['values']['trip_time'],
        'tsb' => $form_state['values']['tsb'],
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
        'bamp_site_number' => $form_state['values']['bamp_site_number'],
        'bamp_site_name' => $form_state['values']['bamp_site_name'],
        'latitude_rec' => $form_state['values']['latitude_rec'],
        'latitude_calc' => $form_state['values']['latitude_calc'],
        'latitude' => $form_state['values']['latitude'],
        'longitude_rec' => $form_state['values']['longitude_rec'],
        'longitude_calc' => $form_state['values']['longitude_calc'],
        'longitude' => $form_state['values']['longitude'],
        'trip_rep' => $form_state['values']['trip_rep'],
        'route' => $form_state['values']['route'],
        'collection_period_eer' => $form_state['values']['collection_period_eer'],
        'gear_type' => $form_state['values']['gear_type'],
        'zone' => $form_state['values']['zone'],
        'chum_captured' => $form_state['values']['chum_captured'],
        'chum_retained' => $form_state['values']['chum_retained'],
        'chum_examined' => $form_state['values']['chum_examined'],
        'pink_captured' => $form_state['values']['pink_captured'],
        'pink_retained' => $form_state['values']['pink_retained'],
        'pink_examined' => $form_state['values']['pink_examined'],
        'coho_captured' => $form_state['values']['coho_captured'],
        'coho_retained' => $form_state['values']['coho_retained'],
        'coho_examined' => $form_state['values']['coho_examined'],
        'other_salmon_captured' => $form_state['values']['other_salmon_captured'],
        'other_salmon_retained' => $form_state['values']['other_salmon_retained'],
        'other_salmon_examined' => $form_state['values']['other_salmon_examined'],
        'other_species_captured' => $form_state['values']['other_species_captured'],
        'other_species_retained' => $form_state['values']['other_species_retained'],
        'other_species_examined' => $form_state['values']['other_species_examined'],
        'crew' => $form_state['values']['crew'],
        'tide' => $form_state['values']['tide'],
        'search_time' => $form_state['values']['search_time'],
        'salinity_avg' => $form_state['values']['salinity_avg'],
        'salinity_0_2' => $form_state['values']['salinity_0_2'],
        'salinity_1' => $form_state['values']['salinity_1'],
        'salinity_5' => $form_state['values']['salinity_5'],
        'salinity_refract' => $form_state['values']['salinity_refract'],
        'salinity_depth_not_specified' => $form_state['values']['salinity_depth_not_specified'],
        'temperature_avg' => $form_state['values']['temperature_avg'],
        'temperature_0_2' => $form_state['values']['temperature_0_2'],
        'temperature_1' => $form_state['values']['temperature_1'],
        'temperature_5' => $form_state['values']['temperature_5'],
        'temperature_rec' => $form_state['values']['temperature_rec'],
        'temperature_depth_not_specified' => $form_state['values']['temperature_depth_not_specified'],
        'weather_comments' => $form_state['values']['weather_comments'],
        'comments' => $form_state['values']['comments'],
        'changelog' => $form_state['values']['changelog'],
        'set_no' => $form_state['values']['set_no'],
        'site_name_rec' => $form_state['values']['site_name_rec'],
        'site_number_0309' => $form_state['values']['site_number_0309'],
        'site_number_mk' => $form_state['values']['site_number_mk'],
        'waypoint' => $form_state['values']['waypoint'],
        'distance' => $form_state['values']['distance'],
        'blind_no' => $form_state['values']['blind_no'],
        'to_lab' => $form_state['values']['to_lab'],
        'trip' => $form_state['values']['trip'],
        'trip_time' => $form_state['values']['trip_time'],
        'tsb' => $form_state['values']['tsb'],
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
