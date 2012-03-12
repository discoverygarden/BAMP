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
    bampcrud_log('Delete', 'bamp_wild_trips', $record_id, '');

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
      'site_name',
      'site_number',
      'waypoint',
      'distance',
      'longitude',
      'latitude',
      'salinity',
      'temperature',
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
  # salinity text field
  $form['fieldset']['salinity'] = array(
    '#type' => 'textfield',
    '#title' => t('salinity'),
    '#default_value' => isset($result['salinity']) ? $result['salinity'] : '',
    '#required' => FALSE,
  );  
  # temperature text field
  $form['fieldset']['temperature'] = array(
    '#type' => 'textfield',
    '#title' => t('temperature'),
    '#default_value' => isset($result['temperature']) ? $result['temperature'] : '',
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
      $fields =array(
        'year' => $form_state['values']['year'],
        'date' => $form_state['values']['date'],
        'rep' => $form_state['values']['rep'],
        'route' => $form_state['values']['route'],
        'site_name' => $form_state['values']['site_name'],
        'site_number' => $form_state['values']['site_number'],
        'waypoint' => $form_state['values']['waypoint'],
        'distance' => $form_state['values']['distance'],
        'longitude' => $form_state['values']['longitude'],
        'latitude' => $form_state['values']['latitude'],
        'salinity' => $form_state['values']['salinity'],
        'temperature' => $form_state['values']['temperature'],
      );

      bampcrud_log('Create', 'bamp_wild_trips', 'New', $fields);

      //Add db insert 
      $result = db_insert('bamp_wild_trips', array('target'=>'bamp_new'))->fields($fields)->execute();
    
      //drupal_goto('test/multi_step_form', array('query' => array('sort' => 'desc', 'order' => 'Id')));
      drupal_set_message('New record has been added.');
    break;
    case 'Save Change' :
      $fields = array(
        'year' => $form_state['values']['year'],
        'date' => $form_state['values']['date'],
        'rep' => $form_state['values']['rep'],
        'route' => $form_state['values']['route'],
        'site_name' => $form_state['values']['site_name'],
        'site_number' => $form_state['values']['site_number'],
        'waypoint' => $form_state['values']['waypoint'],
        'distance' => $form_state['values']['distance'],
        'longitude' => $form_state['values']['longitude'],
        'latitude' => $form_state['values']['latitude'],
        'salinity' => $form_state['values']['salinity'],
        'temperature' => $form_state['values']['temperature'],
      );

      bampcrud_log('Update', 'bamp_wild_trips', $form_state['values']['id'], $fields);

      //Add db update code
      $num_updated = db_update('bamp_wild_trips', array('target'=>'bamp_new'))->fields($fields)->condition('id', $form_state['values']['id'],'=')->execute();

      //drupal_goto('test/multi_step_form');
      drupal_set_message('Record has been updated.');
      break;
  }//end switch
}//end addedit_form_submit


