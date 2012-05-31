<?php

function bampcrud_farm_aggregate_form($form, $form_state, $operation = 'add', $record_id = null) {
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
    $num_deleted = db_delete('bamp_farm_aggregate', array('target'=>'bamp_new'))
    ->condition('id',$record_id)
    ->execute();

    drupal_set_message($num_deleted . t(' record has been deleted.'));
  }//end if

  //if the operation is modify, grab the record from the database.
  if ($operation == 'modify') {
    $result = db_select('bamp_farm_aggregate', 'n', array('target'=>'bamp_new'))
    ->fields('n',array(
      'id',
      'bamp_farm_id',
      'year',
      'month',
      'dfo_zone',
      'dfo_subzone',
      'site_name',
      'no_counts_reason',
      'date_sampled',
      'pen',
      'sample_method',
      'number_sampled',
      'adult_females',
      'motile',
      'chalimus',
      'caligus',
      'action_taken',
      'changelog',
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
  # dfo_zone text field
  $form['fieldset']['dfo_zone'] = array(
    '#type' => 'textfield',
    '#title' => t('DFO Zone'),
    '#default_value' => isset($result['dfo_zone']) ? $result['dfo_zone'] : '',
    '#required' => FALSE,
  );  
  # dfo_subzone text field
  $form['fieldset']['dfo_subzone'] = array(
    '#type' => 'textfield',
    '#title' => t('DFO Subzone'),
    '#default_value' => isset($result['dfo_subzone']) ? $result['dfo_subzone'] : '',
    '#required' => FALSE,
  );  
  # site_name text field
  $form['fieldset']['site_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Site Name'),
    '#default_value' => isset($result['site_name']) ? $result['site_name'] : '',
    '#required' => FALSE,
  );  
  # no_counts_reason text field
  $form['fieldset']['no_counts_reason'] = array(
    '#type' => 'textfield',
    '#title' => t('No Counts Reason'),
    '#default_value' => isset($result['no_counts_reason']) ? $result['no_counts_reason'] : '',
    '#required' => FALSE,
  );  
  # date_sampled text field
  $form['fieldset']['date_sampled'] = array(
    '#type' => 'textfield',
    '#title' => t('Date Sampled'),
    '#default_value' => isset($result['date_sampled']) ? $result['date_sampled'] : '',
    '#required' => FALSE,
  );  
  # pen text field
  $form['fieldset']['pen'] = array(
    '#type' => 'textfield',
    '#title' => t('Pen'),
    '#default_value' => isset($result['pen']) ? $result['pen'] : '',
    '#required' => FALSE,
  );  
  # sample_method text field
  $form['fieldset']['sample_method'] = array(
    '#type' => 'textfield',
    '#title' => t('Sample Method'),
    '#default_value' => isset($result['sample_method']) ? $result['sample_method'] : '',
    '#required' => FALSE,
  );  
  # number_sampled text field
  $form['fieldset']['number_sampled'] = array(
    '#type' => 'textfield',
    '#title' => t('Number Sampled'),
    '#default_value' => isset($result['number_sampled']) ? $result['number_sampled'] : '',
    '#required' => FALSE,
  );  
  # adult_females text field
  $form['fieldset']['adult_females'] = array(
    '#type' => 'textfield',
    '#title' => t('Adult Females'),
    '#default_value' => isset($result['adult_females']) ? $result['adult_females'] : '',
    '#required' => FALSE,
  );  
  # motile text field
  $form['fieldset']['motile'] = array(
    '#type' => 'textfield',
    '#title' => t('Motile'),
    '#default_value' => isset($result['motile']) ? $result['motile'] : '',
    '#required' => FALSE,
  );  
  # chalimus text field
  $form['fieldset']['chalimus'] = array(
    '#type' => 'textfield',
    '#title' => t('Chalimus'),
    '#default_value' => isset($result['chalimus']) ? $result['chalimus'] : '',
    '#required' => FALSE,
  );  
  # caligus text field
  $form['fieldset']['caligus'] = array(
    '#type' => 'textfield',
    '#title' => t('Caligus'),
    '#default_value' => isset($result['caligus']) ? $result['caligus'] : '',
    '#required' => FALSE,
  );  
  # action_taken text field
  $form['fieldset']['action_taken'] = array(
    '#type' => 'textfield',
    '#title' => t('Action Taken'),
    '#default_value' => isset($result['action_taken']) ? $result['action_taken'] : '',
    '#required' => FALSE,
  );  
  # changelog text field
  $form['fieldset']['changelog'] = array(
    '#type' => 'textfield',
    '#title' => t('Change Log'),
    '#default_value' => isset($result['changelog']) ? $result['changelog'] : '',
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

function bampcrud_farm_aggregate_form_submit($form, &$form_state) {
  switch ($form_state['values']['op']) {
    case 'Add Record' :
      //Add db insert 
      $result = db_insert('bamp_farm_aggregate', array('target'=>'bamp_new'))
      ->fields(array(
        'bamp_farm_id' => $form_state['values']['bamp_farm_id'],
        'year' => $form_state['values']['year'],
        'month' => $form_state['values']['month'],
        'dfo_zone' => $form_state['values']['dfo_zone'],
        'dfo_subzone' => $form_state['values']['dfo_subzone'],
        'site_name' => $form_state['values']['site_name'],
        'no_counts_reason' => $form_state['values']['no_counts_reason'],
        'date_sampled' => $form_state['values']['date_sampled'],
        'pen' => $form_state['values']['pen'],
        'sample_method' => $form_state['values']['sample_method'],
        'number_sampled' => $form_state['values']['number_sampled'],
        'adult_females' => $form_state['values']['adult_females'],
        'motile' => $form_state['values']['motile'],
        'chalimus' => $form_state['values']['chalimus'],
        'caligus' => $form_state['values']['caligus'],
        'action_taken' => $form_state['values']['action_taken'],
        'changelog' => $form_state['values']['changelog'],
      ))
      ->execute();
    
      //drupal_goto('test/multi_step_form', array('query' => array('sort' => 'desc', 'order' => 'Id')));
      drupal_set_message('Farm Aggregate Record Added.');
      break;
    case 'Save Change' :
      //Add db update code

      $num_updated = db_update('bamp_farm_aggregate', array('target'=>'bamp_new'))
      ->fields(array(
        'bamp_farm_id' => $form_state['values']['bamp_farm_id'],
        'year' => $form_state['values']['year'],
        'month' => $form_state['values']['month'],
        'dfo_zone' => $form_state['values']['dfo_zone'],
        'dfo_subzone' => $form_state['values']['dfo_subzone'],
        'site_name' => $form_state['values']['site_name'],
        'no_counts_reason' => $form_state['values']['no_counts_reason'],
        'date_sampled' => $form_state['values']['date_sampled'],
        'pen' => $form_state['values']['pen'],
        'sample_method' => $form_state['values']['sample_method'],
        'number_sampled' => $form_state['values']['number_sampled'],
        'adult_females' => $form_state['values']['adult_females'],
        'motile' => $form_state['values']['motile'],
        'chalimus' => $form_state['values']['chalimus'],
        'caligus' => $form_state['values']['caligus'],
        'action_taken' => $form_state['values']['action_taken'],
        'changelog' => $form_state['values']['changelog'],
      ))
      ->condition('id', $form_state['values']['id'],'=')
      ->execute();

      //drupal_goto('test/multi_step_form');
      drupal_set_message('Farm Aggregate Record Updated.');
      break;
  }//end switch
}//end addedit_form_submit
