<?php

function bampcrud_farm_fish_data_form($form, $form_state, $operation = 'add', $record_id = null) {
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
      '#markup' => l(t('Cancel'), 'farm-fish-data'),
    );

    return $form;
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
  # site_name text field
  $form['fieldset']['site_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Site Name'),
    '#default_value' => isset($result['site_name']) ? $result['site_name'] : '',
    '#required' => FALSE,
  );  
  # date text field
  $form['fieldset']['date'] = array(
    '#type' => 'textfield',
    '#title' => t('Date'),
    '#default_value' => isset($result['date']) ? $result['date'] : '',
    '#required' => FALSE,
  );  
  # month text field
  $form['fieldset']['month'] = array(
    '#type' => 'textfield',
    '#title' => t('Month'),
    '#default_value' => isset($result['month']) ? $result['month'] : '',
    '#required' => FALSE,
  );  
  # day text field
  $form['fieldset']['day'] = array(
    '#type' => 'textfield',
    '#title' => t('Day'),
    '#default_value' => isset($result['day']) ? $result['day'] : '',
    '#required' => FALSE,
  );  
  # year text field
  $form['fieldset']['year'] = array(
    '#type' => 'textfield',
    '#title' => t('Year'),
    '#default_value' => isset($result['year']) ? $result['year'] : '',
    '#required' => FALSE,
  );  
  # counted by text field
  $form['fieldset']['countedby'] = array(
    '#type' => 'textfield',
    '#title' => t('Counted by'),
    '#default_value' => isset($result['countedby']) ? $result['countedby'] : '',
    '#required' => FALSE,
  );  
  # fish_sampled text field
  $form['fieldset']['fish_sampled'] = array(
    '#type' => 'textfield',
    '#title' => t('Fish Sampled'),
    '#default_value' => isset($result['fish_sampled']) ? $result['fish_sampled'] : '',
    '#required' => FALSE,
  );  
  # sample_method text field
  $form['fieldset']['sample_method'] = array(
    '#type' => 'textfield',
    '#title' => t('Sample Method'),
    '#default_value' => isset($result['sample_method']) ? $result['sample_method'] : '',
    '#required' => FALSE,
  );  
  # pen text field
  $form['fieldset']['pen'] = array(
    '#type' => 'textfield',
    '#title' => t('Pen'),
    '#default_value' => isset($result['pen']) ? $result['pen'] : '',
    '#required' => FALSE,
  );  
  # fish_number text field
  $form['fieldset']['fish_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Fish Number'),
    '#default_value' => isset($result['fish_number']) ? $result['fish_number'] : '',
    '#required' => FALSE,
  );  
  # size text field
  $form['fieldset']['size'] = array(
    '#type' => 'textfield',
    '#title' => t('Size'),
    '#default_value' => isset($result['size']) ? $result['size'] : '',
    '#required' => FALSE,
  );  
  # chalimus text field
  $form['fieldset']['chalimus'] = array(
    '#type' => 'textfield',
    '#title' => t('Chalimus'),
    '#default_value' => isset($result['chalimus']) ? $result['chalimus'] : '',
    '#required' => FALSE,
  );  
  # pre-adult text field
  $form['fieldset']['preadult'] = array(
    '#type' => 'textfield',
    '#title' => t('Pre Adult'),
    '#default_value' => isset($result['preadult']) ? $result['preadult'] : '',
    '#required' => FALSE,
  );  
  # male text field
  $form['fieldset']['male'] = array(
    '#type' => 'textfield',
    '#title' => t('Male'),
    '#default_value' => isset($result['male']) ? $result['male'] : '',
    '#required' => FALSE,
  );  
  # female text field
  $form['fieldset']['female'] = array(
    '#type' => 'textfield',
    '#title' => t('Female'),
    '#default_value' => isset($result['female']) ? $result['female'] : '',
    '#required' => FALSE,
  );  
  # gravid text field
  $form['fieldset']['gravid'] = array(
    '#type' => 'textfield',
    '#title' => t('Gravid'),
    '#default_value' => isset($result['gravid']) ? $result['gravid'] : '',
    '#required' => FALSE,
  );  
  # caligus text field
  $form['fieldset']['caligus'] = array(
    '#type' => 'textfield',
    '#title' => t('Caligus'),
    '#default_value' => isset($result['caligus']) ? $result['caligus'] : '',
    '#required' => FALSE,
  );  
  # total_motile text field
  $form['fieldset']['total_motile'] = array(
    '#type' => 'textfield',
    '#title' => t('Total Motile'),
    '#default_value' => isset($result['total_motile']) ? $result['total_motile'] : '',
    '#required' => FALSE,
  );  
  # comments text field
  $form['fieldset']['comments'] = array(
    '#type' => 'textfield',
    '#title' => t('Comments'),
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
      drupal_set_message('Farm Fish Data Record Added.');
      break;
    case 'Save Change' :
      //Add db update code

      $num_updated = db_update('bamp_farm_fish_data', array('target'=>'bamp_new'))
      ->fields(array(
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
      drupal_set_message('Farm Fish Data Record Updated.');
      break;
      case 'Delete Record':
        $num_deleted = db_delete('bamp_farm_fish_data', array('target'=>'bamp_new'))
        ->condition('id',$form_state['values']['id'])
        ->execute();

        drupal_goto('farm-fish-data');
        drupal_set_message($num_deleted . t(' record has been deleted.'));
      break;
  }//end switch
}//end addedit_form_submit


