<?php

function bampcrud_farm_environment_form($form, $form_state, $operation = 'add', $record_id = null) {
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
      '#markup' => l(t('Cancel'), 'farm-environment'),
    );

    return $form;
  }//end if

  //if the operation is modify, grab the record from the database.
  if ($operation == 'modify') {
    $result = db_select('bamp_farm_environment', 'n', array('target'=>'bamp_new'))
    ->fields('n',array(
      'id',
      'bamp_farm_id',
      'year',
      'month',
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

    $disableEdit = TRUE;
  }//end if


  //Form Fields
  # id text field
  $form['fieldset']['id'] = array(
    '#type' => 'textfield',
    '#title' => t('Internal Database ID'),
    '#default_value' => isset($result['id']) ? $result['id'] : '',
    '#required' => FALSE,
    '#disabled' => TRUE,
  );  
  # bamp_farm_id text field
  $form['fieldset']['bamp_farm_id'] = array(
    '#type' => 'textfield',
    '#title' => t('BAMP Farm ID'),
    '#default_value' => isset($result['bamp_farm_id']) ? $result['bamp_farm_id'] : '',
    '#required' => FALSE,
    '#disabled' => $disableEdit,
  );  
  # year text field
  $form['fieldset']['year'] = array(
    '#type' => 'textfield',
    '#title' => t('Year'),
    '#default_value' => isset($result['year']) ? $result['year'] : '',
    '#required' => FALSE,
  );  
  # month text field
  $form['fieldset']['month'] = array(
    '#type' => 'textfield',
    '#title' => t('Month'),
    '#default_value' => isset($result['month']) ? $result['month'] : '',
    '#required' => FALSE,
  );  
  # site_name text field
  $form['fieldset']['site_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Site Name'),
    '#default_value' => isset($result['site_name']) ? $result['site_name'] : '',
    '#required' => FALSE,
  );  
  # facility_type text field
  $form['fieldset']['facility_type'] = array(
    '#type' => 'textfield',
    '#title' => t('Facility Type'),
    '#default_value' => isset($result['facility_type']) ? $result['facility_type'] : '',
    '#required' => FALSE,
  );  
  # no_sample_reason text field
  $form['fieldset']['no_sample_reason'] = array(
    '#type' => 'textfield',
    '#title' => t('No Sample Reason'),
    '#default_value' => isset($result['no_sample_reason']) ? $result['no_sample_reason'] : '',
    '#required' => FALSE,
  );  
  # sampling_date text field
  $form['fieldset']['sampling_date'] = array(
    '#type' => 'textfield',
    '#title' => t('Sampling Date'),
    '#default_value' => isset($result['sampling_date']) ? $result['sampling_date'] : '',
    '#required' => FALSE,
  );  
  # temperature_0_1 text field
  $form['fieldset']['temperature_0_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Temperature (0-1m)'),
    '#default_value' => isset($result['temperature_0_1']) ? $result['temperature_0_1'] : '',
    '#required' => FALSE,
  );  
  # temperature_5 text field
  $form['fieldset']['temperature_5'] = array(
    '#type' => 'textfield',
    '#title' => t('Temperature (5m)'),
    '#default_value' => isset($result['temperature_5']) ? $result['temperature_5'] : '',
    '#required' => FALSE,
  );  
  # do_0_1 text field
  $form['fieldset']['do_0_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Disolved Oxygen (0-1m)'),
    '#default_value' => isset($result['do_0_1']) ? $result['do_0_1'] : '',
    '#required' => FALSE,
  );  
  # do_5 text field
  $form['fieldset']['do_5'] = array(
    '#type' => 'textfield',
    '#title' => t('Disolved Oxygen (5m)'),
    '#default_value' => isset($result['do_5']) ? $result['do_5'] : '',
    '#required' => FALSE,
  );  
  # salinity_0_1 text field
  $form['fieldset']['salinity_0_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Salinity (0-1m)'),
    '#default_value' => isset($result['salinity_0_1']) ? $result['salinity_0_1'] : '',
    '#required' => FALSE,
  );  
  # salinity_5 text field
  $form['fieldset']['salinity_5'] = array(
    '#type' => 'textfield',
    '#title' => t('Salinity (5m)'),
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
        'bamp_farm_id' => $form_state['values']['bamp_farm_id'],
        'year' => $form_state['values']['year'],
        'month' => $form_state['values']['month'],
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
      drupal_set_message('Farm Environment Record Added.');
      break;
    case 'Save Change' :
      //Add db update code

      $num_updated = db_update('bamp_farm_environment', array('target'=>'bamp_new'))
      ->fields(array(
        'bamp_farm_id' => $form_state['values']['bamp_farm_id'],
        'year' => $form_state['values']['year'],
        'month' => $form_state['values']['month'],
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
      drupal_set_message('Farm Environment Record Updated.');
      break;
      case 'Delete Record':
        $num_deleted = db_delete('bamp_farm_environment', array('target'=>'bamp_new'))
        ->condition('id',$form_state['values']['id'])
        ->execute();

        drupal_goto('farm-environment');
        drupal_set_message($num_deleted . t(' record has been deleted.'));
      break;
  }//end switch
}//end addedit_form_submit
