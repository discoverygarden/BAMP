<?php

function bampcrud_farm_inventory_form($form, $form_state, $operation = 'add', $record_id = null) {
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
      '#markup' => l(t('Cancel'), 'farm-inventory'),
    );

    return $form;
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
  # quarter text field
  $form['fieldset']['quarter'] = array(
    '#type' => 'textfield',
    '#title' => t('Quarter'),
    '#default_value' => isset($result['quarter']) ? $result['quarter'] : '',
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
  # fish_group_name text field
  $form['fieldset']['fish_group_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Fish Group Name'),
    '#default_value' => isset($result['fish_group_name']) ? $result['fish_group_name'] : '',
    '#required' => FALSE,
  );  
  # fish_group_id text field
  $form['fieldset']['fish_group_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Fish Group ID'),
    '#default_value' => isset($result['fish_group_id']) ? $result['fish_group_id'] : '',
    '#required' => FALSE,
  );  
  # inventory_balance_fish_in text field
  $form['fieldset']['inventory_balance_fish_in'] = array(
    '#type' => 'textfield',
    '#title' => t('Inventory Balance Fish In'),
    '#default_value' => isset($result['inventory_balance_fish_in']) ? $result['inventory_balance_fish_in'] : '',
    '#required' => FALSE,
  );  
  # inventory_balance_inventory_start text field
  $form['fieldset']['inventory_balance_inventory_start'] = array(
    '#type' => 'textfield',
    '#title' => t('Inventory Balance Inventory Start'),
    '#default_value' => isset($result['inventory_balance_inventory_start']) ? $result['inventory_balance_inventory_start'] : '',
    '#required' => FALSE,
  );  
  # species text field
  $form['fieldset']['species'] = array(
    '#type' => 'textfield',
    '#title' => t('Species'),
    '#default_value' => isset($result['species']) ? $result['species'] : '',
    '#required' => FALSE,
  );  
  # species_group_name text field
  $form['fieldset']['species_group_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Species Group Name'),
    '#default_value' => isset($result['species_group_name']) ? $result['species_group_name'] : '',
    '#required' => FALSE,
  );  
  # freshwater_yearclass text field
  $form['fieldset']['freshwater_yearclass'] = array(
    '#type' => 'textfield',
    '#title' => t('Freshwater Yearclass'),
    '#default_value' => isset($result['freshwater_yearclass']) ? $result['freshwater_yearclass'] : '',
    '#required' => FALSE,
  );  
  # fish_group_sw_entry_date text field
  $form['fieldset']['fish_group_sw_entry_date'] = array(
    '#type' => 'textfield',
    '#title' => t('Fish Group Software Entry Date'),
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
        'bamp_farm_id' => $form_state['values']['bamp_farm_id'],
        'year' => $form_state['values']['year'],
        'quarter' => $form_state['values']['quarter'],
        'month' => $form_state['values']['month'],
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
      drupal_set_message('Farm Inventory Record Added.');
      break;
    case 'Save Change' :
      //Add db update code

      $num_updated = db_update('bamp_farm_inventory', array('target'=>'bamp_new'))
      ->fields(array(
        'bamp_farm_id' => $form_state['values']['bamp_farm_id'],
        'year' => $form_state['values']['year'],
        'quarter' => $form_state['values']['quarter'],
        'month' => $form_state['values']['month'],
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
      drupal_set_message('Farm Inventory Record Updated.');
      break;
      case 'Delete Record':
        $num_deleted = db_delete('bamp_farm_inventory', array('target'=>'bamp_new'))
        ->condition('id',$form_state['values']['id'])
        ->execute();

        drupal_goto('farm-inventory');
        drupal_set_message($num_deleted . t(' record has been deleted.'));
      break;
  }//end switch
}//end addedit_form_submit


