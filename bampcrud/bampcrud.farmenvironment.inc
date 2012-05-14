<?php

function bampcrud_farm_environment_form($form, $form_state, $operation = 'add', $record_id = null) {
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
    $num_deleted = db_delete('bamp_farm_environment', array('target'=>'bamp_new'))
    ->condition('id',$record_id)
    ->execute();

    drupal_set_message($num_deleted . t(' record has been deleted.'));
  }//end if

  //if the operation is modify, grab the record from the database.
  if ($operation == 'modify') {
    $result = db_select('bamp_farm_environment', 'n', array('target'=>'bamp_new'))
    ->fields('n',array(
      'id',
      'bamp_farm_id',
      'year',
      'month',
      'dfo_zone',
      'dfo_subzone',
      'site_name',
      'facility_type',
      'no_sample_reason',
      'sampling_date',
      'temperature_0_1',
      'temperature_5',
      'do_0_1',
      'do_5',
      'salinity_0_1',
      'salinity_5',
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
  # id text field
  $form['fieldset']['id'] = array(
    '#type' => 'textfield',
    '#title' => t('id'),
    '#default_value' => isset($result['id']) ? $result['id'] : '',
    '#required' => FALSE,
  );  
  # bamp_farm_id text field
  $form['fieldset']['bamp_farm_id'] = array(
    '#type' => 'textfield',
    '#title' => t('bamp_farm_id'),
    '#default_value' => isset($result['bamp_farm_id']) ? $result['bamp_farm_id'] : '',
    '#required' => FALSE,
  );  
  # year text field
  $form['fieldset']['year'] = array(
    '#type' => 'textfield',
    '#title' => t('year'),
    '#default_value' => isset($result['year']) ? $result['year'] : '',
    '#required' => FALSE,
  );  
  # month text field
  $form['fieldset']['month'] = array(
    '#type' => 'textfield',
    '#title' => t('month'),
    '#default_value' => isset($result['month']) ? $result['month'] : '',
    '#required' => FALSE,
  );  
  # dfo_zone text field
  $form['fieldset']['dfo_zone'] = array(
    '#type' => 'textfield',
    '#title' => t('dfo_zone'),
    '#default_value' => isset($result['dfo_zone']) ? $result['dfo_zone'] : '',
    '#required' => FALSE,
  );  
  # dfo_subzone text field
  $form['fieldset']['dfo_subzone'] = array(
    '#type' => 'textfield',
    '#title' => t('dfo_subzone'),
    '#default_value' => isset($result['dfo_subzone']) ? $result['dfo_subzone'] : '',
    '#required' => FALSE,
  );  
  # site_name text field
  $form['fieldset']['site_name'] = array(
    '#type' => 'textfield',
    '#title' => t('site_name'),
    '#default_value' => isset($result['site_name']) ? $result['site_name'] : '',
    '#required' => FALSE,
  );  
  # facility_type text field
  $form['fieldset']['facility_type'] = array(
    '#type' => 'textfield',
    '#title' => t('facility_type'),
    '#default_value' => isset($result['facility_type']) ? $result['facility_type'] : '',
    '#required' => FALSE,
  );  
  # no_sample_reason text field
  $form['fieldset']['no_sample_reason'] = array(
    '#type' => 'textfield',
    '#title' => t('no_sample_reason'),
    '#default_value' => isset($result['no_sample_reason']) ? $result['no_sample_reason'] : '',
    '#required' => FALSE,
  );  
  # sampling_date text field
  $form['fieldset']['sampling_date'] = array(
    '#type' => 'textfield',
    '#title' => t('sampling_date'),
    '#default_value' => isset($result['sampling_date']) ? $result['sampling_date'] : '',
    '#required' => FALSE,
  );  
  # temperature_0_1 text field
  $form['fieldset']['temperature_0_1'] = array(
    '#type' => 'textfield',
    '#title' => t('temperature_0_1'),
    '#default_value' => isset($result['temperature_0_1']) ? $result['temperature_0_1'] : '',
    '#required' => FALSE,
  );  
  # temperature_5 text field
  $form['fieldset']['temperature_5'] = array(
    '#type' => 'textfield',
    '#title' => t('temperature_5'),
    '#default_value' => isset($result['temperature_5']) ? $result['temperature_5'] : '',
    '#required' => FALSE,
  );  
  # do_0_1 text field
  $form['fieldset']['do_0_1'] = array(
    '#type' => 'textfield',
    '#title' => t('do_0_1'),
    '#default_value' => isset($result['do_0_1']) ? $result['do_0_1'] : '',
    '#required' => FALSE,
  );  
  # do_5 text field
  $form['fieldset']['do_5'] = array(
    '#type' => 'textfield',
    '#title' => t('do_5'),
    '#default_value' => isset($result['do_5']) ? $result['do_5'] : '',
    '#required' => FALSE,
  );  
  # salinity_0_1 text field
  $form['fieldset']['salinity_0_1'] = array(
    '#type' => 'textfield',
    '#title' => t('salinity_0_1'),
    '#default_value' => isset($result['salinity_0_1']) ? $result['salinity_0_1'] : '',
    '#required' => FALSE,
  );  
  # salinity_5 text field
  $form['fieldset']['salinity_5'] = array(
    '#type' => 'textfield',
    '#title' => t('salinity_5'),
    '#default_value' => isset($result['salinity_5']) ? $result['salinity_5'] : '',
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

function bampcrud_farm_environment_form_submit($form, &$form_state) {
  switch ($form_state['values']['op']) {
    case 'Add Record' :
      //Add db insert 
      $result = db_insert('bamp_farm_environment', array('target'=>'bamp_new'))
      ->fields(array(
        'id' => $form_state['values']['id'],
        'bamp_farm_id' => $form_state['values']['bamp_farm_id'],
        'year' => $form_state['values']['year'],
        'month' => $form_state['values']['month'],
        'dfo_zone' => $form_state['values']['dfo_zone'],
        'dfo_subzone' => $form_state['values']['dfo_subzone'],
        'site_name' => $form_state['values']['site_name'],
        'facility_type' => $form_state['values']['facility_type'],
        'no_sample_reason' => $form_state['values']['no_sample_reason'],
        'sampling_date' => $form_state['values']['sampling_date'],
        'temperature_0_1' => $form_state['values']['temperature_0_1'],
        'temperature_5' => $form_state['values']['temperature_5'],
        'do_0_1' => $form_state['values']['do_0_1'],
        'do_5' => $form_state['values']['do_5'],
        'salinity_0_1' => $form_state['values']['salinity_0_1'],
        'salinity_5' => $form_state['values']['salinity_5'],
      ))
      ->execute();
    
      //drupal_goto('test/multi_step_form', array('query' => array('sort' => 'desc', 'order' => 'Id')));
      drupal_set_message('adddddddd');
      break;
    case 'Save Change' :
      //Add db update code

      $num_updated = db_update('bamp_farm_environment', array('target'=>'bamp_new'))
      ->fields(array(
        'id' => $form_state['values']['id'],
        'bamp_farm_id' => $form_state['values']['bamp_farm_id'],
        'year' => $form_state['values']['year'],
        'month' => $form_state['values']['month'],
        'dfo_zone' => $form_state['values']['dfo_zone'],
        'dfo_subzone' => $form_state['values']['dfo_subzone'],
        'site_name' => $form_state['values']['site_name'],
        'facility_type' => $form_state['values']['facility_type'],
        'no_sample_reason' => $form_state['values']['no_sample_reason'],
        'sampling_date' => $form_state['values']['sampling_date'],
        'temperature_0_1' => $form_state['values']['temperature_0_1'],
        'temperature_5' => $form_state['values']['temperature_5'],
        'do_0_1' => $form_state['values']['do_0_1'],
        'do_5' => $form_state['values']['do_5'],
        'salinity_0_1' => $form_state['values']['salinity_0_1'],
        'salinity_5' => $form_state['values']['salinity_5'],
      ))
      ->condition('id', $form_state['values']['id'],'=')
      ->execute();

      //drupal_goto('test/multi_step_form');
      drupal_set_message('updatttteeeee');
      break;
  }//end switch
}//end addedit_form_submit
