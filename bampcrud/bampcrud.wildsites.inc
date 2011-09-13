<?php

function bampcrud_wild_sites_form($form, $form_state, $operation = 'add', $record_id = null) {
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
    $num_deleted = db_delete('bamp_wild_sites', array('target'=>'bamp_new'))
    ->condition('id',$record_id)
    ->execute();

    drupal_set_message($num_deleted . t(' record has been deleted.'));
  }//end if

  //if the operation is modify, grab the record from the database.
  if ($operation == 'modify') {
    $result = db_select('bamp_wild_sites', 'n', array('target'=>'bamp_new'))
    ->fields('n',array(
      'site_number',
      'site_name',
      'latitude',
      'longitude',
      'zone',
      'area',
      'comment',
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
  # site_number text field
  $form['fieldset']['site_number'] = array(
    '#type' => 'textfield',
    '#title' => t('site_number'),
    '#default_value' => isset($result['site_number']) ? $result['site_number'] : '',
    '#required' => FALSE,
  );  
  # site_name text field
  $form['fieldset']['site_name'] = array(
    '#type' => 'textfield',
    '#title' => t('site_name'),
    '#default_value' => isset($result['site_name']) ? $result['site_name'] : '',
    '#required' => FALSE,
  );  
  # latitude text field
  $form['fieldset']['latitude'] = array(
    '#type' => 'textfield',
    '#title' => t('latitude'),
    '#default_value' => isset($result['latitude']) ? $result['latitude'] : '',
    '#required' => FALSE,
  );  
  # longitude text field
  $form['fieldset']['longitude'] = array(
    '#type' => 'textfield',
    '#title' => t('longitude'),
    '#default_value' => isset($result['longitude']) ? $result['longitude'] : '',
    '#required' => FALSE,
  );  
  # zone text field
  $form['fieldset']['zone'] = array(
    '#type' => 'textfield',
    '#title' => t('zone'),
    '#default_value' => isset($result['zone']) ? $result['zone'] : '',
    '#required' => FALSE,
  );  
  # area text field
  $form['fieldset']['area'] = array(
    '#type' => 'textfield',
    '#title' => t('area'),
    '#default_value' => isset($result['area']) ? $result['area'] : '',
    '#required' => FALSE,
  );  
  # comment text field
  $form['fieldset']['comment'] = array(
    '#type' => 'textfield',
    '#title' => t('comment'),
    '#default_value' => isset($result['comment']) ? $result['comment'] : '',
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

function bampcrud_wild_sites_form_submit($form, &$form_state) {
  switch ($form_state['values']['op']) {
    case 'Add Record' :
      //Add db insert 
      $result = db_insert('bamp_wild_sites', array('target'=>'bamp_new'))
      ->fields(array(
        'site_number' => $form_state['values']['site_number'],
        'site_name' => $form_state['values']['site_name'],
        'latitude' => $form_state['values']['latitude'],
        'longitude' => $form_state['values']['longitude'],
        'zone' => $form_state['values']['zone'],
        'area' => $form_state['values']['area'],
        'comment' => $form_state['values']['comment'],
      ))
      ->execute();
    
      //drupal_goto('test/multi_step_form', array('query' => array('sort' => 'desc', 'order' => 'Id')));
      drupal_set_message('New record has been added.');
      break;
    case 'Save Change' :
      //Add db update code

      $num_updated = db_update('bamp_wild_sites', array('target'=>'bamp_new'))
      ->fields(array(
        'site_number' => $form_state['values']['site_number'],
        'site_name' => $form_state['values']['site_name'],
        'latitude' => $form_state['values']['latitude'],
        'longitude' => $form_state['values']['longitude'],
        'zone' => $form_state['values']['zone'],
        'area' => $form_state['values']['area'],
        'comment' => $form_state['values']['comment'],
      ))
      ->condition('id', $form_state['values']['id'],'=')
      ->execute();

      //drupal_goto('test/multi_step_form');
      drupal_set_message('Record has been updated.');
      break;
  }//end switch
}//end addedit_form_submit
