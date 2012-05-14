<?php

function bampcrud_wild_lice_details_form($form, $form_state, $operation = 'add', $record_id = null) {
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
    $num_deleted = db_delete('bamp_wild_lice_details', array('target'=>'bamp_new'))
    ->condition('id',$record_id)
    ->execute();

    drupal_set_message($num_deleted . t(' record has been deleted.'));
  }//end if

  //if the operation is modify, grab the record from the database.
  if ($operation == 'modify') {
    $result = db_select('bamp_wild_lice_details', 'n', array('target'=>'bamp_new'))
    ->fields('n',array(
      'fish_id',
      'lice_id',
      'gender_label',
      'species_label',
      'stage_label',
      'stage_aggr_label',
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
  # lice_id text field
  $form['fieldset']['lice_id'] = array(
    '#type' => 'textfield',
    '#title' => t('lice_id'),
    '#default_value' => isset($result['lice_id']) ? $result['lice_id'] : '',
    '#required' => FALSE,
  );  
  # gender_label text field
  $form['fieldset']['gender_label'] = array(
    '#type' => 'textfield',
    '#title' => t('gender_label'),
    '#default_value' => isset($result['gender_label']) ? $result['gender_label'] : '',
    '#required' => FALSE,
  );  
  # species_label text field
  $form['fieldset']['species_label'] = array(
    '#type' => 'textfield',
    '#title' => t('species_label'),
    '#default_value' => isset($result['species_label']) ? $result['species_label'] : '',
    '#required' => FALSE,
  );  
  # stage_label text field
  $form['fieldset']['stage_label'] = array(
    '#type' => 'textfield',
    '#title' => t('stage_label'),
    '#default_value' => isset($result['stage_label']) ? $result['stage_label'] : '',
    '#required' => FALSE,
  );  
  # stage_aggr_label text field
  $form['fieldset']['stage_aggr_label'] = array(
    '#type' => 'textfield',
    '#title' => t('stage_aggr_label'),
    '#default_value' => isset($result['stage_aggr_label']) ? $result['stage_aggr_label'] : '',
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

function bampcrud_wild_lice_details_form_submit($form, &$form_state) {
  switch ($form_state['values']['op']) {
    case 'Add Record' :
      //Add db insert 
      $result = db_insert('bamp_wild_lice_details', array('target'=>'bamp_new'))
      ->fields(array(
        'fish_id' => $form_state['values']['fish_id'],
        'lice_id' => $form_state['values']['lice_id'],
        'gender_label' => $form_state['values']['gender_label'],
        'species_label' => $form_state['values']['species_label'],
        'stage_label' => $form_state['values']['stage_label'],
        'stage_aggr_label' => $form_state['values']['stage_aggr_label'],
      ))
      ->execute();
    
      //drupal_goto('test/multi_step_form', array('query' => array('sort' => 'desc', 'order' => 'Id')));
      drupal_set_message('adddddddd');
      break;
    case 'Save Change' :
      //Add db update code

      $num_updated = db_update('bamp_wild_lice_details', array('target'=>'bamp_new'))
      ->fields(array(
        'fish_id' => $form_state['values']['fish_id'],
        'lice_id' => $form_state['values']['lice_id'],
        'gender_label' => $form_state['values']['gender_label'],
        'species_label' => $form_state['values']['species_label'],
        'stage_label' => $form_state['values']['stage_label'],
        'stage_aggr_label' => $form_state['values']['stage_aggr_label'],
      ))
      ->condition('id', $form_state['values']['id'],'=')
      ->execute();

      //drupal_goto('test/multi_step_form');
      drupal_set_message('updatttteeeee');
      break;
  }//end switch
}//end addedit_form_submit
