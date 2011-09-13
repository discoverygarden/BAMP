<?php

function bampcrud_wild_trips_form($form, $form_state, $operation = 'add', $record_id = null) {
  $form['record_operation'] = array(
    '#type' => 'hidden',
    '#value' => $operation,
  );


  $form['fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Data Entry Form'),
    '#collapsible' => TRUE, 
  );  

  if($operation == 'delete') {
    $num_deleted = db_delete('bamp_wild_trips', array('target'=>'bamp_new'))
    ->condition('id',$record_id)
    ->execute();

    drupal_set_message($num_deleted . t(' record has been deleted.'));
  }//end if 

  //if the operation is modify, grab the record from the database.
  if ($operation == 'modify') {
    $result = db_select('bamp_wild_trips', 'n', array('target'=>'bamp_new'))
    ->fields('n',array(
      'year',
      'date',
      'rep',
      'route',
      'set_number',
      'site_name',
      'site_number',
      'waypoint',
      'distance',
      'longitude',
      'latitude',
      'blind_no',
      'crew',
      'tide',
      'search_time',
      'salinity',
      'salinity_0_2',
      'salinity_1',
      'salinity_5',
      'temperature',
      'temperature_0_2',
      'temperature_1',
      'temperature_5',
      'chum_capture',
      'chum_retain',
      'pink_capture',
      'pink_retain',
      'coho_capture',
      'coho_retain',
      'weather_comments',
      'to_lab',
    ))
    ->condition('id', $record_id,'=')
    ->execute()
    ->fetchAssoc();

    //store the id
    $form['id'] = array(
      '#type' => 'hidden',
      '#value' => $record_id,
    );
  }//end if


  //Form Fields
  # year text field
  $form['fieldset']['year'] = array(
    '#type' => 'textfield',
    '#title' => t('year'),
    '#default_value' => isset($result['year']) ? $result['year'] : '',
    '#required' => FALSE,
  );  
  # date text field
  $form['fieldset']['date'] = array(
    '#type' => 'textfield',
    '#title' => t('date'),
    '#default_value' => isset($result['date']) ? $result['date'] : '',
    '#required' => FALSE,
  );  
  # rep text field
  $form['fieldset']['rep'] = array(
    '#type' => 'textfield',
    '#title' => t('rep'),
    '#default_value' => isset($result['rep']) ? $result['rep'] : '',
    '#required' => FALSE,
  );  
  # route text field
  $form['fieldset']['route'] = array(
    '#type' => 'textfield',
    '#title' => t('route'),
    '#default_value' => isset($result['route']) ? $result['route'] : '',
    '#required' => FALSE,
  );  
  # set_number text field
  $form['fieldset']['set_number'] = array(
    '#type' => 'textfield',
    '#title' => t('set_number'),
    '#default_value' => isset($result['set_number']) ? $result['set_number'] : '',
    '#required' => FALSE,
  );  
  # site_name text field
  $form['fieldset']['site_name'] = array(
    '#type' => 'textfield',
    '#title' => t('site_name'),
    '#default_value' => isset($result['site_name']) ? $result['site_name'] : '',
    '#required' => FALSE,
  );  
  # site_number text field
  $form['fieldset']['site_number'] = array(
    '#type' => 'textfield',
    '#title' => t('site_number'),
    '#default_value' => isset($result['site_number']) ? $result['site_number'] : '',
    '#required' => FALSE,
  );  
  # waypoint text field
  $form['fieldset']['waypoint'] = array(
    '#type' => 'textfield',
    '#title' => t('waypoint'),
    '#default_value' => isset($result['waypoint']) ? $result['waypoint'] : '',
    '#required' => FALSE,
  );  
  # distance text field
  $form['fieldset']['distance'] = array(
    '#type' => 'textfield',
    '#title' => t('distance'),
    '#default_value' => isset($result['distance']) ? $result['distance'] : '',
    '#required' => FALSE,
  );  
  # longitude text field
  $form['fieldset']['longitude'] = array(
    '#type' => 'textfield',
    '#title' => t('longitude'),
    '#default_value' => isset($result['longitude']) ? $result['longitude'] : '',
    '#required' => FALSE,
  );  
  # latitude text field
  $form['fieldset']['latitude'] = array(
    '#type' => 'textfield',
    '#title' => t('latitude'),
    '#default_value' => isset($result['latitude']) ? $result['latitude'] : '',
    '#required' => FALSE,
  );  
  # blind_no text field
  $form['fieldset']['blind_no'] = array(
    '#type' => 'textfield',
    '#title' => t('blind_no'),
    '#default_value' => isset($result['blind_no']) ? $result['blind_no'] : '',
    '#required' => FALSE,
  );  
  # crew text field
  $form['fieldset']['crew'] = array(
    '#type' => 'textfield',
    '#title' => t('crew'),
    '#default_value' => isset($result['crew']) ? $result['crew'] : '',
    '#required' => FALSE,
  );  
  # tide text field
  $form['fieldset']['tide'] = array(
    '#type' => 'textfield',
    '#title' => t('tide'),
    '#default_value' => isset($result['tide']) ? $result['tide'] : '',
    '#required' => FALSE,
  );  
  # search_time text field
  $form['fieldset']['search_time'] = array(
    '#type' => 'textfield',
    '#title' => t('search_time'),
    '#default_value' => isset($result['search_time']) ? $result['search_time'] : '',
    '#required' => FALSE,
  );  
  # salinity text field
  $form['fieldset']['salinity'] = array(
    '#type' => 'textfield',
    '#title' => t('salinity'),
    '#default_value' => isset($result['salinity']) ? $result['salinity'] : '',
    '#required' => FALSE,
  );  
  # salinity_0_2 text field
  $form['fieldset']['salinity_0_2'] = array(
    '#type' => 'textfield',
    '#title' => t('salinity_0_2'),
    '#default_value' => isset($result['salinity_0_2']) ? $result['salinity_0_2'] : '',
    '#required' => FALSE,
  );  
  # salinity_1 text field
  $form['fieldset']['salinity_1'] = array(
    '#type' => 'textfield',
    '#title' => t('salinity_1'),
    '#default_value' => isset($result['salinity_1']) ? $result['salinity_1'] : '',
    '#required' => FALSE,
  );  
  # salinity_5 text field
  $form['fieldset']['salinity_5'] = array(
    '#type' => 'textfield',
    '#title' => t('salinity_5'),
    '#default_value' => isset($result['salinity_5']) ? $result['salinity_5'] : '',
    '#required' => FALSE,
  );  
  # temperature text field
  $form['fieldset']['temperature'] = array(
    '#type' => 'textfield',
    '#title' => t('temperature'),
    '#default_value' => isset($result['temperature']) ? $result['temperature'] : '',
    '#required' => FALSE,
  );  
  # temperature_0_2 text field
  $form['fieldset']['temperature_0_2'] = array(
    '#type' => 'textfield',
    '#title' => t('temperature_0_2'),
    '#default_value' => isset($result['temperature_0_2']) ? $result['temperature_0_2'] : '',
    '#required' => FALSE,
  );  
  # temperature_1 text field
  $form['fieldset']['temperature_1'] = array(
    '#type' => 'textfield',
    '#title' => t('temperature_1'),
    '#default_value' => isset($result['temperature_1']) ? $result['temperature_1'] : '',
    '#required' => FALSE,
  );  
  # temperature_5 text field
  $form['fieldset']['temperature_5'] = array(
    '#type' => 'textfield',
    '#title' => t('temperature_5'),
    '#default_value' => isset($result['temperature_5']) ? $result['temperature_5'] : '',
    '#required' => FALSE,
  );  
  # chum_capture text field
  $form['fieldset']['chum_capture'] = array(
    '#type' => 'textfield',
    '#title' => t('chum_capture'),
    '#default_value' => isset($result['chum_capture']) ? $result['chum_capture'] : '',
    '#required' => FALSE,
  );  
  # chum_retain text field
  $form['fieldset']['chum_retain'] = array(
    '#type' => 'textfield',
    '#title' => t('chum_retain'),
    '#default_value' => isset($result['chum_retain']) ? $result['chum_retain'] : '',
    '#required' => FALSE,
  );  
  # pink_capture text field
  $form['fieldset']['pink_capture'] = array(
    '#type' => 'textfield',
    '#title' => t('pink_capture'),
    '#default_value' => isset($result['pink_capture']) ? $result['pink_capture'] : '',
    '#required' => FALSE,
  );  
  # pink_retain text field
  $form['fieldset']['pink_retain'] = array(
    '#type' => 'textfield',
    '#title' => t('pink_retain'),
    '#default_value' => isset($result['pink_retain']) ? $result['pink_retain'] : '',
    '#required' => FALSE,
  );  
  # coho_capture text field
  $form['fieldset']['coho_capture'] = array(
    '#type' => 'textfield',
    '#title' => t('coho_capture'),
    '#default_value' => isset($result['coho_capture']) ? $result['coho_capture'] : '',
    '#required' => FALSE,
  );  
  # coho_retain text field
  $form['fieldset']['coho_retain'] = array(
    '#type' => 'textfield',
    '#title' => t('coho_retain'),
    '#default_value' => isset($result['coho_retain']) ? $result['coho_retain'] : '',
    '#required' => FALSE,
  );  
  # weather_comments text field
  $form['fieldset']['weather_comments'] = array(
    '#type' => 'textfield',
    '#title' => t('weather_comments'),
    '#default_value' => isset($result['weather_comments']) ? $result['weather_comments'] : '',
    '#required' => FALSE,
  );  
  # to_lab text field
  $form['fieldset']['to_lab'] = array(
    '#type' => 'textfield',
    '#title' => t('to_lab'),
    '#default_value' => isset($result['to_lab']) ? $result['to_lab'] : '',
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

function bampcrud_wild_trips_form_submit($form, &$form_state) {
  switch ($form_state['values']['op']) {
    case 'Add Record' :
      //Add db insert 
      $result = db_insert('bamp_wild_trips', array('target'=>'bamp_new'))
      ->fields(array(
        'year' => $form_state['values']['year'],
        'date' => $form_state['values']['date'],
        'rep' => $form_state['values']['rep'],
        'route' => $form_state['values']['route'],
        'set_number' => $form_state['values']['set_number'],
        'site_name' => $form_state['values']['site_name'],
        'site_number' => $form_state['values']['site_number'],
        'waypoint' => $form_state['values']['waypoint'],
        'distance' => $form_state['values']['distance'],
        'longitude' => $form_state['values']['longitude'],
        'latitude' => $form_state['values']['latitude'],
        'blind_no' => $form_state['values']['blind_no'],
        'crew' => $form_state['values']['crew'],
        'tide' => $form_state['values']['tide'],
        'search_time' => $form_state['values']['search_time'],
        'salinity' => $form_state['values']['salinity'],
        'salinity_0_2' => $form_state['values']['salinity_0_2'],
        'salinity_1' => $form_state['values']['salinity_1'],
        'salinity_5' => $form_state['values']['salinity_5'],
        'temperature' => $form_state['values']['temperature'],
        'temperature_0_2' => $form_state['values']['temperature_0_2'],
        'temperature_1' => $form_state['values']['temperature_1'],
        'temperature_5' => $form_state['values']['temperature_5'],
        'chum_capture' => $form_state['values']['chum_capture'],
        'chum_retain' => $form_state['values']['chum_retain'],
        'pink_capture' => $form_state['values']['pink_capture'],
        'pink_retain' => $form_state['values']['pink_retain'],
        'coho_capture' => $form_state['values']['coho_capture'],
        'coho_retain' => $form_state['values']['coho_retain'],
        'weather_comments' => $form_state['values']['weather_comments'],
        'to_lab' => $form_state['values']['to_lab'],
      ))
      ->execute();
    
      //drupal_goto('test/multi_step_form', array('query' => array('sort' => 'desc', 'order' => 'Id')));
      drupal_set_message('New record has been added.');
      break;
    case 'Save Change' :
      //Add db update code

      $num_updated = db_update('bamp_wild_trips', array('target'=>'bamp_new'))
      ->fields(array(
        'year' => $form_state['values']['year'],
        'date' => $form_state['values']['date'],
        'rep' => $form_state['values']['rep'],
        'route' => $form_state['values']['route'],
        'set_number' => $form_state['values']['set_number'],
        'site_name' => $form_state['values']['site_name'],
        'site_number' => $form_state['values']['site_number'],
        'waypoint' => $form_state['values']['waypoint'],
        'distance' => $form_state['values']['distance'],
        'longitude' => $form_state['values']['longitude'],
        'latitude' => $form_state['values']['latitude'],
        'blind_no' => $form_state['values']['blind_no'],
        'crew' => $form_state['values']['crew'],
        'tide' => $form_state['values']['tide'],
        'search_time' => $form_state['values']['search_time'],
        'salinity' => $form_state['values']['salinity'],
        'salinity_0_2' => $form_state['values']['salinity_0_2'],
        'salinity_1' => $form_state['values']['salinity_1'],
        'salinity_5' => $form_state['values']['salinity_5'],
        'temperature' => $form_state['values']['temperature'],
        'temperature_0_2' => $form_state['values']['temperature_0_2'],
        'temperature_1' => $form_state['values']['temperature_1'],
        'temperature_5' => $form_state['values']['temperature_5'],
        'chum_capture' => $form_state['values']['chum_capture'],
        'chum_retain' => $form_state['values']['chum_retain'],
        'pink_capture' => $form_state['values']['pink_capture'],
        'pink_retain' => $form_state['values']['pink_retain'],
        'coho_capture' => $form_state['values']['coho_capture'],
        'coho_retain' => $form_state['values']['coho_retain'],
        'weather_comments' => $form_state['values']['weather_comments'],
        'to_lab' => $form_state['values']['to_lab'],
      ))
      ->condition('id', $form_state['values']['id'],'=')
      ->execute();

      //drupal_goto('test/multi_step_form');
      drupal_set_message('Record has been updated.');
      break;
  }//end switch
}//end addedit_form_submit


