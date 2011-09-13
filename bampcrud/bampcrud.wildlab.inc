<?php

function bampcrud_wild_lab_form($form, $form_state, $operation = 'add', $record_id = null) {
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
    $num_deleted = db_delete('bamp_wild_lab_results', array('target'=>'bamp_new'))
    ->condition('id',$record_id)
    ->execute();

    drupal_set_message($num_deleted . t(' record has been deleted.'));
  }//end if
 
  //if the operation is modify, grab the record from the database.
  if ($operation == 'modify') {
    $result = db_select('bamp_wild_lab_results', 'n', array('target'=>'bamp_new'))
    ->fields('n',array(
      'fish_id',
      'year',
      'trip',
      'gp_id',
      'lab',
      'date_examined',
      'fish_species_per_field',
      'fish_number',
      'fish_species_per_lab',
      'length',
      'weight',
      'l_co',
      'l_c1',
      'l_c2',
      'l_c3',
      'l_c4',
      'l_pam',
      'l_paf',
      'l_am',
      'l_af',
      'lep_total',
      'c_co',
      'c_c1',
      'c_c2',
      'c_c3',
      'c_c4',
      'c_pam',
      'c_paf',
      'c_am',
      'c_af',
      'cal_total',
      'lice_total',
      'lessions',
      'comments',
      'initials',
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
  # fish_id text field
  $form['fieldset']['fish_id'] = array(
    '#type' => 'textfield',
    '#title' => t('fish_id'),
    '#default_value' => isset($result['fish_id']) ? $result['fish_id'] : '',
    '#required' => FALSE,
  );  
  # year text field
  $form['fieldset']['year'] = array(
    '#type' => 'textfield',
    '#title' => t('year'),
    '#default_value' => isset($result['year']) ? $result['year'] : '',
    '#required' => FALSE,
  );  
  # trip text field
  $form['fieldset']['trip'] = array(
    '#type' => 'textfield',
    '#title' => t('trip'),
    '#default_value' => isset($result['trip']) ? $result['trip'] : '',
    '#required' => FALSE,
  );  
  # gp_id text field
  $form['fieldset']['gp_id'] = array(
    '#type' => 'textfield',
    '#title' => t('gp_id'),
    '#default_value' => isset($result['gp_id']) ? $result['gp_id'] : '',
    '#required' => FALSE,
  );  
  # lab text field
  $form['fieldset']['lab'] = array(
    '#type' => 'textfield',
    '#title' => t('lab'),
    '#default_value' => isset($result['lab']) ? $result['lab'] : '',
    '#required' => FALSE,
  );  
  # date_examined text field
  $form['fieldset']['date_examined'] = array(
    '#type' => 'textfield',
    '#title' => t('date_examined'),
    '#default_value' => isset($result['date_examined']) ? $result['date_examined'] : '',
    '#required' => FALSE,
  );  
  # fish_species_per_field text field
  $form['fieldset']['fish_species_per_field'] = array(
    '#type' => 'textfield',
    '#title' => t('fish_species_per_field'),
    '#default_value' => isset($result['fish_species_per_field']) ? $result['fish_species_per_field'] : '',
    '#required' => FALSE,
  );  
  # fish_number text field
  $form['fieldset']['fish_number'] = array(
    '#type' => 'textfield',
    '#title' => t('fish_number'),
    '#default_value' => isset($result['fish_number']) ? $result['fish_number'] : '',
    '#required' => FALSE,
  );  
  # fish_species_per_lab text field
  $form['fieldset']['fish_species_per_lab'] = array(
    '#type' => 'textfield',
    '#title' => t('fish_species_per_lab'),
    '#default_value' => isset($result['fish_species_per_lab']) ? $result['fish_species_per_lab'] : '',
    '#required' => FALSE,
  );  
  # length text field
  $form['fieldset']['length'] = array(
    '#type' => 'textfield',
    '#title' => t('length'),
    '#default_value' => isset($result['length']) ? $result['length'] : '',
    '#required' => FALSE,
  );  
  # weight text field
  $form['fieldset']['weight'] = array(
    '#type' => 'textfield',
    '#title' => t('weight'),
    '#default_value' => isset($result['weight']) ? $result['weight'] : '',
    '#required' => FALSE,
  );  
  # l_co text field
  $form['fieldset']['l_co'] = array(
    '#type' => 'textfield',
    '#title' => t('l_co'),
    '#default_value' => isset($result['l_co']) ? $result['l_co'] : '',
    '#required' => FALSE,
  );  
  # l_c1 text field
  $form['fieldset']['l_c1'] = array(
    '#type' => 'textfield',
    '#title' => t('l_c1'),
    '#default_value' => isset($result['l_c1']) ? $result['l_c1'] : '',
    '#required' => FALSE,
  );  
  # l_c2 text field
  $form['fieldset']['l_c2'] = array(
    '#type' => 'textfield',
    '#title' => t('l_c2'),
    '#default_value' => isset($result['l_c2']) ? $result['l_c2'] : '',
    '#required' => FALSE,
  );  
  # l_c3 text field
  $form['fieldset']['l_c3'] = array(
    '#type' => 'textfield',
    '#title' => t('l_c3'),
    '#default_value' => isset($result['l_c3']) ? $result['l_c3'] : '',
    '#required' => FALSE,
  );  
  # l_c4 text field
  $form['fieldset']['l_c4'] = array(
    '#type' => 'textfield',
    '#title' => t('l_c4'),
    '#default_value' => isset($result['l_c4']) ? $result['l_c4'] : '',
    '#required' => FALSE,
  );  
  # l_pam text field
  $form['fieldset']['l_pam'] = array(
    '#type' => 'textfield',
    '#title' => t('l_pam'),
    '#default_value' => isset($result['l_pam']) ? $result['l_pam'] : '',
    '#required' => FALSE,
  );  
  # l_paf text field
  $form['fieldset']['l_paf'] = array(
    '#type' => 'textfield',
    '#title' => t('l_paf'),
    '#default_value' => isset($result['l_paf']) ? $result['l_paf'] : '',
    '#required' => FALSE,
  );  
  # l_am text field
  $form['fieldset']['l_am'] = array(
    '#type' => 'textfield',
    '#title' => t('l_am'),
    '#default_value' => isset($result['l_am']) ? $result['l_am'] : '',
    '#required' => FALSE,
  );  
  # l_af text field
  $form['fieldset']['l_af'] = array(
    '#type' => 'textfield',
    '#title' => t('l_af'),
    '#default_value' => isset($result['l_af']) ? $result['l_af'] : '',
    '#required' => FALSE,
  );  
  # lep_total text field
  $form['fieldset']['lep_total'] = array(
    '#type' => 'textfield',
    '#title' => t('lep_total'),
    '#default_value' => isset($result['lep_total']) ? $result['lep_total'] : '',
    '#required' => FALSE,
  );  
  # c_co text field
  $form['fieldset']['c_co'] = array(
    '#type' => 'textfield',
    '#title' => t('c_co'),
    '#default_value' => isset($result['c_co']) ? $result['c_co'] : '',
    '#required' => FALSE,
  );  
  # c_c1 text field
  $form['fieldset']['c_c1'] = array(
    '#type' => 'textfield',
    '#title' => t('c_c1'),
    '#default_value' => isset($result['c_c1']) ? $result['c_c1'] : '',
    '#required' => FALSE,
  );  
  # c_c2 text field
  $form['fieldset']['c_c2'] = array(
    '#type' => 'textfield',
    '#title' => t('c_c2'),
    '#default_value' => isset($result['c_c2']) ? $result['c_c2'] : '',
    '#required' => FALSE,
  );  
  # c_c3 text field
  $form['fieldset']['c_c3'] = array(
    '#type' => 'textfield',
    '#title' => t('c_c3'),
    '#default_value' => isset($result['c_c3']) ? $result['c_c3'] : '',
    '#required' => FALSE,
  );  
  # c_c4 text field
  $form['fieldset']['c_c4'] = array(
    '#type' => 'textfield',
    '#title' => t('c_c4'),
    '#default_value' => isset($result['c_c4']) ? $result['c_c4'] : '',
    '#required' => FALSE,
  );  
  # c_pam text field
  $form['fieldset']['c_pam'] = array(
    '#type' => 'textfield',
    '#title' => t('c_pam'),
    '#default_value' => isset($result['c_pam']) ? $result['c_pam'] : '',
    '#required' => FALSE,
  );  
  # c_paf text field
  $form['fieldset']['c_paf'] = array(
    '#type' => 'textfield',
    '#title' => t('c_paf'),
    '#default_value' => isset($result['c_paf']) ? $result['c_paf'] : '',
    '#required' => FALSE,
  );  
  # c_am text field
  $form['fieldset']['c_am'] = array(
    '#type' => 'textfield',
    '#title' => t('c_am'),
    '#default_value' => isset($result['c_am']) ? $result['c_am'] : '',
    '#required' => FALSE,
  );  
  # c_af text field
  $form['fieldset']['c_af'] = array(
    '#type' => 'textfield',
    '#title' => t('c_af'),
    '#default_value' => isset($result['c_af']) ? $result['c_af'] : '',
    '#required' => FALSE,
  );  
  # cal_total text field
  $form['fieldset']['cal_total'] = array(
    '#type' => 'textfield',
    '#title' => t('cal_total'),
    '#default_value' => isset($result['cal_total']) ? $result['cal_total'] : '',
    '#required' => FALSE,
  );  
  # lice_total text field
  $form['fieldset']['lice_total'] = array(
    '#type' => 'textfield',
    '#title' => t('lice_total'),
    '#default_value' => isset($result['lice_total']) ? $result['lice_total'] : '',
    '#required' => FALSE,
  );  
  # lessions text field
  $form['fieldset']['lessions'] = array(
    '#type' => 'textfield',
    '#title' => t('lessions'),
    '#default_value' => isset($result['lessions']) ? $result['lessions'] : '',
    '#required' => FALSE,
  );  
  # comments text field
  $form['fieldset']['comments'] = array(
    '#type' => 'textfield',
    '#title' => t('comments'),
    '#default_value' => isset($result['comments']) ? $result['comments'] : '',
    '#required' => FALSE,
  );  
  # initials text field
  $form['fieldset']['initials'] = array(
    '#type' => 'textfield',
    '#title' => t('initials'),
    '#default_value' => isset($result['initials']) ? $result['initials'] : '',
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

function bampcrud_wild_lab_form_submit($form, &$form_state) {
  switch ($form_state['values']['op']) {
    case 'Add Record' :
      //Add db insert 
      $result = db_insert('bamp_wild_lab_results', array('target'=>'bamp_new'))
      ->fields(array(
        'fish_id' => $form_state['values']['fish_id'],
        'year' => $form_state['values']['year'],
        'trip' => $form_state['values']['trip'],
        'gp_id' => $form_state['values']['gp_id'],
        'lab' => $form_state['values']['lab'],
        'date_examined' => $form_state['values']['date_examined'],
        'fish_species_per_field' => $form_state['values']['fish_species_per_field'],
        'fish_number' => $form_state['values']['fish_number'],
        'fish_species_per_lab' => $form_state['values']['fish_species_per_lab'],
        'length' => $form_state['values']['length'],
        'weight' => $form_state['values']['weight'],
        'l_co' => $form_state['values']['l_co'],
        'l_c1' => $form_state['values']['l_c1'],
        'l_c2' => $form_state['values']['l_c2'],
        'l_c3' => $form_state['values']['l_c3'],
        'l_c4' => $form_state['values']['l_c4'],
        'l_pam' => $form_state['values']['l_pam'],
        'l_paf' => $form_state['values']['l_paf'],
        'l_am' => $form_state['values']['l_am'],
        'l_af' => $form_state['values']['l_af'],
        'lep_total' => $form_state['values']['lep_total'],
        'c_co' => $form_state['values']['c_co'],
        'c_c1' => $form_state['values']['c_c1'],
        'c_c2' => $form_state['values']['c_c2'],
        'c_c3' => $form_state['values']['c_c3'],
        'c_c4' => $form_state['values']['c_c4'],
        'c_pam' => $form_state['values']['c_pam'],
        'c_paf' => $form_state['values']['c_paf'],
        'c_am' => $form_state['values']['c_am'],
        'c_af' => $form_state['values']['c_af'],
        'cal_total' => $form_state['values']['cal_total'],
        'lice_total' => $form_state['values']['lice_total'],
        'lessions' => $form_state['values']['lessions'],
        'comments' => $form_state['values']['comments'],
        'initials' => $form_state['values']['initials'],
      ))
      ->execute();
    
      //drupal_goto('test/multi_step_form', array('query' => array('sort' => 'desc', 'order' => 'Id')));
      drupal_set_message('adddddddd');
      break;
    case 'Save Change' :
      //Add db update code

      $num_updated = db_update('bamp_wild_lab_results', array('target'=>'bamp_new'))
      ->fields(array(
        'fish_id' => $form_state['values']['fish_id'],
        'year' => $form_state['values']['year'],
        'trip' => $form_state['values']['trip'],
        'gp_id' => $form_state['values']['gp_id'],
        'lab' => $form_state['values']['lab'],
        'date_examined' => $form_state['values']['date_examined'],
        'fish_species_per_field' => $form_state['values']['fish_species_per_field'],
        'fish_number' => $form_state['values']['fish_number'],
        'fish_species_per_lab' => $form_state['values']['fish_species_per_lab'],
        'length' => $form_state['values']['length'],
        'weight' => $form_state['values']['weight'],
        'l_co' => $form_state['values']['l_co'],
        'l_c1' => $form_state['values']['l_c1'],
        'l_c2' => $form_state['values']['l_c2'],
        'l_c3' => $form_state['values']['l_c3'],
        'l_c4' => $form_state['values']['l_c4'],
        'l_pam' => $form_state['values']['l_pam'],
        'l_paf' => $form_state['values']['l_paf'],
        'l_am' => $form_state['values']['l_am'],
        'l_af' => $form_state['values']['l_af'],
        'lep_total' => $form_state['values']['lep_total'],
        'c_co' => $form_state['values']['c_co'],
        'c_c1' => $form_state['values']['c_c1'],
        'c_c2' => $form_state['values']['c_c2'],
        'c_c3' => $form_state['values']['c_c3'],
        'c_c4' => $form_state['values']['c_c4'],
        'c_pam' => $form_state['values']['c_pam'],
        'c_paf' => $form_state['values']['c_paf'],
        'c_am' => $form_state['values']['c_am'],
        'c_af' => $form_state['values']['c_af'],
        'cal_total' => $form_state['values']['cal_total'],
        'lice_total' => $form_state['values']['lice_total'],
        'lessions' => $form_state['values']['lessions'],
        'comments' => $form_state['values']['comments'],
        'initials' => $form_state['values']['initials'],
      ))
      ->condition('id', $form_state['values']['id'],'=')
      ->execute();

      //drupal_goto('test/multi_step_form');
      drupal_set_message('updatttteeeee');
      break;
  }//end switch
}//end addedit_form_submit
