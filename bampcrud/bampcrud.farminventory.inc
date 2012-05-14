<?php

function bampcrud_farm_inventory_form($form, $form_state, $operation = 'add', $record_id = null) {
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
    $num_deleted = db_delete('bamp_farm_inventory', array('target'=>'bamp_new'))
    ->condition('id',$record_id)
    ->execute();

    drupal_set_message($num_deleted . t(' record has been deleted.'));
  }//end if

  //if the operation is modify, grab the record from the database.
  if ($operation == 'modify') {
    $result = db_select('bamp_farm_inventory', 'n', array('target'=>'bamp_new'))
    ->fields('n',array(
      'id',
      'bamp_farm_id',
      'year',
      'quarter',
      'month',
      'dfo_zone',
      'dfo_subzone',
      'site_name',
      'fish_group_name',
      'fish_group_id',
      'inventory_balance_fish_in',
      'inventory_balance_inventory_start',
      'species',
      'species_group_name',
      'freshwater_yearclass',
      'fish_group_sw_entry_date',
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
  # quarter text field
  $form['fieldset']['quarter'] = array(
    '#type' => 'textfield',
    '#title' => t('quarter'),
    '#default_value' => isset($result['quarter']) ? $result['quarter'] : '',
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
  # fish_group_name text field
  $form['fieldset']['fish_group_name'] = array(
    '#type' => 'textfield',
    '#title' => t('fish_group_name'),
    '#default_value' => isset($result['fish_group_name']) ? $result['fish_group_name'] : '',
    '#required' => FALSE,
  );  
  # fish_group_id text field
  $form['fieldset']['fish_group_id'] = array(
    '#type' => 'textfield',
    '#title' => t('fish_group_id'),
    '#default_value' => isset($result['fish_group_id']) ? $result['fish_group_id'] : '',
    '#required' => FALSE,
  );  
  # inventory_balance_fish_in text field
  $form['fieldset']['inventory_balance_fish_in'] = array(
    '#type' => 'textfield',
    '#title' => t('inventory_balance_fish_in'),
    '#default_value' => isset($result['inventory_balance_fish_in']) ? $result['inventory_balance_fish_in'] : '',
    '#required' => FALSE,
  );  
  # inventory_balance_inventory_start text field
  $form['fieldset']['inventory_balance_inventory_start'] = array(
    '#type' => 'textfield',
    '#title' => t('inventory_balance_inventory_start'),
    '#default_value' => isset($result['inventory_balance_inventory_start']) ? $result['inventory_balance_inventory_start'] : '',
    '#required' => FALSE,
  );  
  # species text field
  $form['fieldset']['species'] = array(
    '#type' => 'textfield',
    '#title' => t('species'),
    '#default_value' => isset($result['species']) ? $result['species'] : '',
    '#required' => FALSE,
  );  
  # species_group_name text field
  $form['fieldset']['species_group_name'] = array(
    '#type' => 'textfield',
    '#title' => t('species_group_name'),
    '#default_value' => isset($result['species_group_name']) ? $result['species_group_name'] : '',
    '#required' => FALSE,
  );  
  # freshwater_yearclass text field
  $form['fieldset']['freshwater_yearclass'] = array(
    '#type' => 'textfield',
    '#title' => t('freshwater_yearclass'),
    '#default_value' => isset($result['freshwater_yearclass']) ? $result['freshwater_yearclass'] : '',
    '#required' => FALSE,
  );  
  # fish_group_sw_entry_date text field
  $form['fieldset']['fish_group_sw_entry_date'] = array(
    '#type' => 'textfield',
    '#title' => t('fish_group_sw_entry_date'),
    '#default_value' => isset($result['fish_group_sw_entry_date']) ? $result['fish_group_sw_entry_date'] : '',
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

function bampcrud_farm_inventory_form_submit($form, &$form_state) {
  switch ($form_state['values']['op']) {
    case 'Add Record' :
      //Add db insert 
      $result = db_insert('bamp_farm_inventory', array('target'=>'bamp_new'))
      ->fields(array(
        'id' => $form_state['values']['id'],
        'bamp_farm_id' => $form_state['values']['bamp_farm_id'],
        'year' => $form_state['values']['year'],
        'quarter' => $form_state['values']['quarter'],
        'month' => $form_state['values']['month'],
        'dfo_zone' => $form_state['values']['dfo_zone'],
        'dfo_subzone' => $form_state['values']['dfo_subzone'],
        'site_name' => $form_state['values']['site_name'],
        'fish_group_name' => $form_state['values']['fish_group_name'],
        'fish_group_id' => $form_state['values']['fish_group_id'],
        'inventory_balance_fish_in' => $form_state['values']['inventory_balance_fish_in'],
        'inventory_balance_inventory_start' => $form_state['values']['inventory_balance_inventory_start'],
        'species' => $form_state['values']['species'],
        'species_group_name' => $form_state['values']['species_group_name'],
        'freshwater_yearclass' => $form_state['values']['freshwater_yearclass'],
        'fish_group_sw_entry_date' => $form_state['values']['fish_group_sw_entry_date'],
      ))
      ->execute();
    
      //drupal_goto('test/multi_step_form', array('query' => array('sort' => 'desc', 'order' => 'Id')));
      drupal_set_message('adddddddd');
      break;
    case 'Save Change' :
      //Add db update code

      $num_updated = db_update('bamp_farm_inventory', array('target'=>'bamp_new'))
      ->fields(array(
        'id' => $form_state['values']['id'],
        'bamp_farm_id' => $form_state['values']['bamp_farm_id'],
        'year' => $form_state['values']['year'],
        'quarter' => $form_state['values']['quarter'],
        'month' => $form_state['values']['month'],
        'dfo_zone' => $form_state['values']['dfo_zone'],
        'dfo_subzone' => $form_state['values']['dfo_subzone'],
        'site_name' => $form_state['values']['site_name'],
        'fish_group_name' => $form_state['values']['fish_group_name'],
        'fish_group_id' => $form_state['values']['fish_group_id'],
        'inventory_balance_fish_in' => $form_state['values']['inventory_balance_fish_in'],
        'inventory_balance_inventory_start' => $form_state['values']['inventory_balance_inventory_start'],
        'species' => $form_state['values']['species'],
        'species_group_name' => $form_state['values']['species_group_name'],
        'freshwater_yearclass' => $form_state['values']['freshwater_yearclass'],
        'fish_group_sw_entry_date' => $form_state['values']['fish_group_sw_entry_date'],
      ))
      ->condition('id', $form_state['values']['id'],'=')
      ->execute();

      //drupal_goto('test/multi_step_form');
      drupal_set_message('updatttteeeee');
      break;
  }//end switch
}//end addedit_form_submit


