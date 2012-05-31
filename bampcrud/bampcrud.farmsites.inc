<?php

function bampcrud_farm_sites_form($form, $form_state, $operation = 'add', $record_id = null) {
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
    $num_deleted = db_delete('bamp_farm_sites', array('target'=>'bamp_new'))
    ->condition('id',$record_id)
    ->execute();

    drupal_set_message($num_deleted . t(' record has been deleted.'));
  }//end if

  //if the operation is modify, grab the record from the database.
  if ($operation == 'modify') {
    $result = db_select('bamp_farm_sites', 'n', array('target'=>'bamp_new'))
    ->fields('n',array(
      'id',
      'bamp_farm_id',
      'site_name',
      'company',
      'latitude',
      'longitude',
      'management_sub_area',
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
  );  
  # site_name text field
  $form['fieldset']['site_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Site Name'),
    '#default_value' => isset($result['site_name']) ? $result['site_name'] : '',
    '#required' => FALSE,
  );  
  # company text field
  $form['fieldset']['company'] = array(
    '#type' => 'textfield',
    '#title' => t('Company'),
    '#default_value' => isset($result['company']) ? $result['company'] : '',
    '#required' => FALSE,
  );  
  # latitude text field
  $form['fieldset']['latitude'] = array(
    '#type' => 'textfield',
    '#title' => t('Latitude'),
    '#default_value' => isset($result['latitude']) ? $result['latitude'] : '',
    '#required' => FALSE,
  );  
  # longitude text field
  $form['fieldset']['longitude'] = array(
    '#type' => 'textfield',
    '#title' => t('Longitude'),
    '#default_value' => isset($result['longitude']) ? $result['longitude'] : '',
    '#required' => FALSE,
  );  
  # management_sub_area text field
  $form['fieldset']['management_sub_area'] = array(
    '#type' => 'textfield',
    '#title' => t('Management Sub Area'),
    '#default_value' => isset($result['management_sub_area']) ? $result['management_sub_area'] : '',
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

function bampcrud_farm_sites_form_submit($form, &$form_state) {
  switch ($form_state['values']['op']) {
    case 'Add Record' :
      //Add db insert 
      $result = db_insert('bamp_farm_sites', array('target'=>'bamp_new'))
      ->fields(array(
        'bamp_farm_id' => $form_state['values']['bamp_farm_id'],
        'site_name' => $form_state['values']['site_name'],
        'company' => $form_state['values']['company'],
        'latitude' => $form_state['values']['latitude'],
        'longitude' => $form_state['values']['longitude'],
        'management_sub_area' => $form_state['values']['management_sub_area'],
      ))
      ->execute();
    
      //drupal_goto('test/multi_step_form', array('query' => array('sort' => 'desc', 'order' => 'Id')));
      drupal_set_message('Site has been added');
      break;
    case 'Save Change' :
      //Add db update code

      $num_updated = db_update('bamp_farm_sites', array('target'=>'bamp_new'))
      ->fields(array(
        'bamp_farm_id' => $form_state['values']['bamp_farm_id'],
        'site_name' => $form_state['values']['site_name'],
        'company' => $form_state['values']['company'],
        'latitude' => $form_state['values']['latitude'],
        'longitude' => $form_state['values']['longitude'],
        'management_sub_area' => $form_state['values']['management_sub_area'],
      ))
      ->condition('id', $form_state['values']['id'],'=')
      ->execute();

      //drupal_goto('test/multi_step_form');
      drupal_set_message('Site has been Updated');
      break;
  }//end switch
}//end addedit_form_submit


