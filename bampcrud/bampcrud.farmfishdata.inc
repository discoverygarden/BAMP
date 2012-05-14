<?php

function bampcrud_farm_fish_data_form($form, $form_state, $operation = 'add', $record_id = null) {
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
    $num_deleted = db_delete('bamp_farm_fish_data', array('target'=>'bamp_new'))
    ->condition('id',$record_id)
    ->execute();

    drupal_set_message($num_deleted . t(' record has been deleted.'));
  }//end if

  //if the operation is modify, grab the record from the database.
  if ($operation == 'modify') {
    $result = db_select('bamp_farm_fish_data', 'n', array('target'=>'bamp_new'))
    ->fields('n',array(
      'id',
      'bamp_farm_id',
      'site_name',
      'date',
      'month',
      'day',
      'year',
      'countedby',
      'fish_sampled',
      'sample_method',
      'pen',
      'fish_number',
      'size',
      'chalimus',
      'preadult',
      'male',
      'female',
      'gravid',
      'caligus',
      'total_motile',
      'comments',
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
  # site_name text field
  $form['fieldset']['site_name'] = array(
    '#type' => 'textfield',
    '#title' => t('site_name'),
    '#default_value' => isset($result['site_name']) ? $result['site_name'] : '',
    '#required' => FALSE,
  );  
  # date text field
  $form['fieldset']['date'] = array(
    '#type' => 'textfield',
    '#title' => t('date'),
    '#default_value' => isset($result['date']) ? $result['date'] : '',
    '#required' => FALSE,
  );  
  # month text field
  $form['fieldset']['month'] = array(
    '#type' => 'textfield',
    '#title' => t('month'),
    '#default_value' => isset($result['month']) ? $result['month'] : '',
    '#required' => FALSE,
  );  
  # day text field
  $form['fieldset']['day'] = array(
    '#type' => 'textfield',
    '#title' => t('day'),
    '#default_value' => isset($result['day']) ? $result['day'] : '',
    '#required' => FALSE,
  );  
  # year text field
  $form['fieldset']['year'] = array(
    '#type' => 'textfield',
    '#title' => t('year'),
    '#default_value' => isset($result['year']) ? $result['year'] : '',
    '#required' => FALSE,
  );  
  # counted by text field
  $form['fieldset']['counted by'] = array(
    '#type' => 'textfield',
    '#title' => t('counted by'),
    '#default_value' => isset($result['countedby']) ? $result['countedby'] : '',
    '#required' => FALSE,
  );  
  # fish_sampled text field
  $form['fieldset']['fish_sampled'] = array(
    '#type' => 'textfield',
    '#title' => t('fish_sampled'),
    '#default_value' => isset($result['fish_sampled']) ? $result['fish_sampled'] : '',
    '#required' => FALSE,
  );  
  # sample_method text field
  $form['fieldset']['sample_method'] = array(
    '#type' => 'textfield',
    '#title' => t('sample_method'),
    '#default_value' => isset($result['sample_method']) ? $result['sample_method'] : '',
    '#required' => FALSE,
  );  
  # pen text field
  $form['fieldset']['pen'] = array(
    '#type' => 'textfield',
    '#title' => t('pen'),
    '#default_value' => isset($result['pen']) ? $result['pen'] : '',
    '#required' => FALSE,
  );  
  # fish_number text field
  $form['fieldset']['fish_number'] = array(
    '#type' => 'textfield',
    '#title' => t('fish_number'),
    '#default_value' => isset($result['fish_number']) ? $result['fish_number'] : '',
    '#required' => FALSE,
  );  
  # size text field
  $form['fieldset']['size'] = array(
    '#type' => 'textfield',
    '#title' => t('size'),
    '#default_value' => isset($result['size']) ? $result['size'] : '',
    '#required' => FALSE,
  );  
  # chalimus text field
  $form['fieldset']['chalimus'] = array(
    '#type' => 'textfield',
    '#title' => t('chalimus'),
    '#default_value' => isset($result['chalimus']) ? $result['chalimus'] : '',
    '#required' => FALSE,
  );  
  # pre-adult text field
  $form['fieldset']['pre-adult'] = array(
    '#type' => 'textfield',
    '#title' => t('pre-adult'),
    '#default_value' => isset($result['preadult']) ? $result['preadult'] : '',
    '#required' => FALSE,
  );  
  # male text field
  $form['fieldset']['male'] = array(
    '#type' => 'textfield',
    '#title' => t('male'),
    '#default_value' => isset($result['male']) ? $result['male'] : '',
    '#required' => FALSE,
  );  
  # female text field
  $form['fieldset']['female'] = array(
    '#type' => 'textfield',
    '#title' => t('female'),
    '#default_value' => isset($result['female']) ? $result['female'] : '',
    '#required' => FALSE,
  );  
  # gravid text field
  $form['fieldset']['gravid'] = array(
    '#type' => 'textfield',
    '#title' => t('gravid'),
    '#default_value' => isset($result['gravid']) ? $result['gravid'] : '',
    '#required' => FALSE,
  );  
  # caligus text field
  $form['fieldset']['caligus'] = array(
    '#type' => 'textfield',
    '#title' => t('caligus'),
    '#default_value' => isset($result['caligus']) ? $result['caligus'] : '',
    '#required' => FALSE,
  );  
  # total_motile text field
  $form['fieldset']['total_motile'] = array(
    '#type' => 'textfield',
    '#title' => t('total_motile'),
    '#default_value' => isset($result['total_motile']) ? $result['total_motile'] : '',
    '#required' => FALSE,
  );  
  # comments text field
  $form['fieldset']['comments'] = array(
    '#type' => 'textfield',
    '#title' => t('comments'),
    '#default_value' => isset($result['comments']) ? $result['comments'] : '',
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

function bampcrud_farm_fish_data_form_submit($form, &$form_state) {
  switch ($form_state['values']['op']) {
    case 'Add Record' :
      //Add db insert 
      $result = db_insert('bamp_farm_fish_data', array('target'=>'bamp_new'))
      ->fields(array(
        'id' => $form_state['values']['id'],
        'bamp_farm_id' => $form_state['values']['bamp_farm_id'],
        'site_name' => $form_state['values']['site_name'],
        'date' => $form_state['values']['date'],
        'month' => $form_state['values']['month'],
        'day' => $form_state['values']['day'],
        'year' => $form_state['values']['year'],
        'countedby' => $form_state['values']['countedby'],
        'fish_sampled' => $form_state['values']['fish_sampled'],
        'sample_method' => $form_state['values']['sample_method'],
        'pen' => $form_state['values']['pen'],
        'fish_number' => $form_state['values']['fish_number'],
        'size' => $form_state['values']['size'],
        'chalimus' => $form_state['values']['chalimus'],
        'preadult' => $form_state['values']['preadult'],
        'male' => $form_state['values']['male'],
        'female' => $form_state['values']['female'],
        'gravid' => $form_state['values']['gravid'],
        'caligus' => $form_state['values']['caligus'],
        'total_motile' => $form_state['values']['total_motile'],
        'comments' => $form_state['values']['comments'],
      ))
      ->execute();
    
      //drupal_goto('test/multi_step_form', array('query' => array('sort' => 'desc', 'order' => 'Id')));
      drupal_set_message('adddddddd');
      break;
    case 'Save Change' :
      //Add db update code

      $num_updated = db_update('bamp_farm_fish_data', array('target'=>'bamp_new'))
      ->fields(array(
        'id' => $form_state['values']['id'],
        'bamp_farm_id' => $form_state['values']['bamp_farm_id'],
        'site_name' => $form_state['values']['site_name'],
        'date' => $form_state['values']['date'],
        'month' => $form_state['values']['month'],
        'day' => $form_state['values']['day'],
        'year' => $form_state['values']['year'],
        'countedby' => $form_state['values']['countedby'],
        'fish_sampled' => $form_state['values']['fish_sampled'],
        'sample_method' => $form_state['values']['sample_method'],
        'pen' => $form_state['values']['pen'],
        'fish_number' => $form_state['values']['fish_number'],
        'size' => $form_state['values']['size'],
        'chalimus' => $form_state['values']['chalimus'],
        'preadult' => $form_state['values']['preadult'],
        'male' => $form_state['values']['male'],
        'female' => $form_state['values']['female'],
        'gravid' => $form_state['values']['gravid'],
        'caligus' => $form_state['values']['caligus'],
        'total_motile' => $form_state['values']['total_motile'],
        'comments' => $form_state['values']['comments'],
      ))
      ->condition('id', $form_state['values']['id'],'=')
      ->execute();

      //drupal_goto('test/multi_step_form');
      drupal_set_message('updatttteeeee');
      break;
  }//end switch
}//end addedit_form_submit


