<?php

function bampcrud_wild_fish_form($form, $form_state, $operation = 'add', $record_id = null) {
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
    bampcrud_log('Delete', 'bamp_wild_fish_data', $record_id, '');
    $num_deleted = db_delete('bamp_wild_fish_data', array('target'=>'bamp_new'))
    ->condition('id',$record_id)
    ->execute();

    drupal_set_message($num_deleted . t(' record has been deleted.'));
  }//end if


  //if the operation is modify, grab the record from the database.
  if ($operation == 'modify') {
    $result = db_select('bamp_wild_fish_data', 'n', array('target'=>'bamp_new'))
    ->fields('n',array(
      'year',
      'rep',
      'route',
      'site_number',
      'fish',
      'species',
      'length',
      'height',
      'lep_cop',
      'cal_cop',
      'chal_a',
      'chal_b',
      'mot_unid',
      'lep_pre_male',
      'lep_pre_female',
      'lep_pre_unid',
      'lep_adult_male',
      'lep_adult_female',
      'lep_adult_unid',
      'lep_gravid',
      'caligus',
      'caligus_gravid',
      'chal_scar',
      'mot_scar',
      'pred_marks',
      'hem',
      'mate_guarding',
      'pin_belly',
      'tissue_damage',
      'comments',
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
  # year text field
  $form['fieldset']['year'] = array(
    '#type' => 'textfield',
    '#title' => t('year'),
    '#default_value' => isset($result['year']) ? $result['year'] : '',
    '#required' => FALSE,
  );  
  # rep text field
  $form['fieldset']['rep'] = array(
    '#type' => 'textfield',
    '#title' => t('rep'),
    '#default_value' => isset($result['rep']) ? $result['rep'] : '',
    '#required' => FALSE,
  );  
  # route text field
  $form['fieldset']['route'] = array(
    '#type' => 'textfield',
    '#title' => t('route'),
    '#default_value' => isset($result['route']) ? $result['route'] : '',
    '#required' => FALSE,
  );  
  # site_number text field
  $form['fieldset']['site_number'] = array(
    '#type' => 'textfield',
    '#title' => t('site_number'),
    '#default_value' => isset($result['site_number']) ? $result['site_number'] : '',
    '#required' => FALSE,
  );  
  # fish text field
  $form['fieldset']['fish'] = array(
    '#type' => 'textfield',
    '#title' => t('fish'),
    '#default_value' => isset($result['fish']) ? $result['fish'] : '',
    '#required' => FALSE,
  );  
  # species text field
  $form['fieldset']['species'] = array(
    '#type' => 'textfield',
    '#title' => t('species'),
    '#default_value' => isset($result['species']) ? $result['species'] : '',
    '#required' => FALSE,
  );  
  # length text field
  $form['fieldset']['length'] = array(
    '#type' => 'textfield',
    '#title' => t('length'),
    '#default_value' => isset($result['length']) ? $result['length'] : '',
    '#required' => FALSE,
  );  
  # height text field
  $form['fieldset']['height'] = array(
    '#type' => 'textfield',
    '#title' => t('height'),
    '#default_value' => isset($result['height']) ? $result['height'] : '',
    '#required' => FALSE,
  );  
  # lep_cop text field
  $form['fieldset']['lep_cop'] = array(
    '#type' => 'textfield',
    '#title' => t('lep_cop'),
    '#default_value' => isset($result['lep_cop']) ? $result['lep_cop'] : '',
    '#required' => FALSE,
  );  
  # cal_cop text field
  $form['fieldset']['cal_cop'] = array(
    '#type' => 'textfield',
    '#title' => t('cal_cop'),
    '#default_value' => isset($result['cal_cop']) ? $result['cal_cop'] : '',
    '#required' => FALSE,
  );  
  # chal_a text field
  $form['fieldset']['chal_a'] = array(
    '#type' => 'textfield',
    '#title' => t('chal_a'),
    '#default_value' => isset($result['chal_a']) ? $result['chal_a'] : '',
    '#required' => FALSE,
  );  
  # chal_b text field
  $form['fieldset']['chal_b'] = array(
    '#type' => 'textfield',
    '#title' => t('chal_b'),
    '#default_value' => isset($result['chal_b']) ? $result['chal_b'] : '',
    '#required' => FALSE,
  );  
  # mot_unid text field
  $form['fieldset']['mot_unid'] = array(
    '#type' => 'textfield',
    '#title' => t('mot_unid'),
    '#default_value' => isset($result['mot_unid']) ? $result['mot_unid'] : '',
    '#required' => FALSE,
  );  
  # lep_pre_male text field
  $form['fieldset']['lep_pre_male'] = array(
    '#type' => 'textfield',
    '#title' => t('lep_pre_male'),
    '#default_value' => isset($result['lep_pre_male']) ? $result['lep_pre_male'] : '',
    '#required' => FALSE,
  );  
  # lep_pre_female text field
  $form['fieldset']['lep_pre_female'] = array(
    '#type' => 'textfield',
    '#title' => t('lep_pre_female'),
    '#default_value' => isset($result['lep_pre_female']) ? $result['lep_pre_female'] : '',
    '#required' => FALSE,
  );  
  # lep_pre_unid text field
  $form['fieldset']['lep_pre_unid'] = array(
    '#type' => 'textfield',
    '#title' => t('lep_pre_unid'),
    '#default_value' => isset($result['lep_pre_unid']) ? $result['lep_pre_unid'] : '',
    '#required' => FALSE,
  );  
  # lep_adult_male text field
  $form['fieldset']['lep_adult_male'] = array(
    '#type' => 'textfield',
    '#title' => t('lep_adult_male'),
    '#default_value' => isset($result['lep_adult_male']) ? $result['lep_adult_male'] : '',
    '#required' => FALSE,
  );  
  # lep_adult_female text field
  $form['fieldset']['lep_adult_female'] = array(
    '#type' => 'textfield',
    '#title' => t('lep_adult_female'),
    '#default_value' => isset($result['lep_adult_female']) ? $result['lep_adult_female'] : '',
    '#required' => FALSE,
  );  
  # lep_adult_unid text field
  $form['fieldset']['lep_adult_unid'] = array(
    '#type' => 'textfield',
    '#title' => t('lep_adult_unid'),
    '#default_value' => isset($result['lep_adult_unid']) ? $result['lep_adult_unid'] : '',
    '#required' => FALSE,
  );  
  # lep_gravid text field
  $form['fieldset']['lep_gravid'] = array(
    '#type' => 'textfield',
    '#title' => t('lep_gravid'),
    '#default_value' => isset($result['lep_gravid']) ? $result['lep_gravid'] : '',
    '#required' => FALSE,
  );  
  # caligus text field
  $form['fieldset']['caligus'] = array(
    '#type' => 'textfield',
    '#title' => t('caligus'),
    '#default_value' => isset($result['caligus']) ? $result['caligus'] : '',
    '#required' => FALSE,
  );  
  # caligus_gravid text field
  $form['fieldset']['caligus_gravid'] = array(
    '#type' => 'textfield',
    '#title' => t('caligus_gravid'),
    '#default_value' => isset($result['caligus_gravid']) ? $result['caligus_gravid'] : '',
    '#required' => FALSE,
  );  
  # chal_scar text field
  $form['fieldset']['chal_scar'] = array(
    '#type' => 'textfield',
    '#title' => t('chal_scar'),
    '#default_value' => isset($result['chal_scar']) ? $result['chal_scar'] : '',
    '#required' => FALSE,
  );  
  # mot_scar text field
  $form['fieldset']['mot_scar'] = array(
    '#type' => 'textfield',
    '#title' => t('mot_scar'),
    '#default_value' => isset($result['mot_scar']) ? $result['mot_scar'] : '',
    '#required' => FALSE,
  );  
  # pred_marks text field
  $form['fieldset']['pred_marks'] = array(
    '#type' => 'textfield',
    '#title' => t('pred_marks'),
    '#default_value' => isset($result['pred_marks']) ? $result['pred_marks'] : '',
    '#required' => FALSE,
  );  
  # hem text field
  $form['fieldset']['hem'] = array(
    '#type' => 'textfield',
    '#title' => t('hem'),
    '#default_value' => isset($result['hem']) ? $result['hem'] : '',
    '#required' => FALSE,
  );  
  # mate_guarding text field
  $form['fieldset']['mate_guarding'] = array(
    '#type' => 'textfield',
    '#title' => t('mate_guarding'),
    '#default_value' => isset($result['mate_guarding']) ? $result['mate_guarding'] : '',
    '#required' => FALSE,
  );  
  # pin_belly text field
  $form['fieldset']['pin_belly'] = array(
    '#type' => 'textfield',
    '#title' => t('pin_belly'),
    '#default_value' => isset($result['pin_belly']) ? $result['pin_belly'] : '',
    '#required' => FALSE,
  );  
  # tissue_damage text field
  $form['fieldset']['tissue_damage'] = array(
    '#type' => 'textfield',
    '#title' => t('tissue_damage'),
    '#default_value' => isset($result['tissue_damage']) ? $result['tissue_damage'] : '',
    '#required' => FALSE,
  );  
  # comments text field
  $form['fieldset']['comments'] = array(
    '#type' => 'textfield',
    '#title' => t('comments'),
    '#default_value' => isset($result['comments']) ? $result['comments'] : '',
    '#required' => FALSE,
  );  
  # comments text field
  $form['fieldset']['changelog'] = array(
    '#type' => 'textfield',
    '#title' => t('Changelog - Enter note regarding why this record is being created/edited'),
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

function bampcrud_wild_fish_form_submit($form, &$form_state) {
  switch ($form_state['values']['op']) {
    case 'Add Record' :

      $fields = array(
        'year' => $form_state['values']['year'],
        'rep' => $form_state['values']['rep'],
        'route' => $form_state['values']['route'],
        'site_number' => $form_state['values']['site_number'],
        'fish' => $form_state['values']['fish'],
        'species' => $form_state['values']['species'],
        'length' => $form_state['values']['length'],
        'height' => $form_state['values']['height'],
        'lep_cop' => $form_state['values']['lep_cop'],
        'cal_cop' => $form_state['values']['cal_cop'],
        'chal_a' => $form_state['values']['chal_a'],
        'chal_b' => $form_state['values']['chal_b'],
        'mot_unid' => $form_state['values']['mot_unid'],
        'lep_pre_male' => $form_state['values']['lep_pre_male'],
        'lep_pre_female' => $form_state['values']['lep_pre_female'],
        'lep_pre_unid' => $form_state['values']['lep_pre_unid'],
        'lep_adult_male' => $form_state['values']['lep_adult_male'],
        'lep_adult_female' => $form_state['values']['lep_adult_female'],
        'lep_adult_unid' => $form_state['values']['lep_adult_unid'],
        'lep_gravid' => $form_state['values']['lep_gravid'],
        'caligus' => $form_state['values']['caligus'],
        'caligus_gravid' => $form_state['values']['caligus_gravid'],
        'chal_scar' => $form_state['values']['chal_scar'],
        'mot_scar' => $form_state['values']['mot_scar'],
        'pred_marks' => $form_state['values']['pred_marks'],
        'hem' => $form_state['values']['hem'],
        'mate_guarding' => $form_state['values']['mate_guarding'],
        'pin_belly' => $form_state['values']['pin_belly'],
        'tissue_damage' => $form_state['values']['tissue_damage'],
        'comments' => $form_state['values']['comments'],
        'changelog' => $form_state['values']['changelog'],
      );
      bampcrud_log('Create', 'bamp_wild_fish_data', 'New', $fields);

      //Add db insert 
      $result = db_insert('bamp_wild_fish_data', array('target'=>'bamp_new'))->fields($fields)->execute();
    
      //drupal_goto('test/multi_step_form', array('query' => array('sort' => 'desc', 'order' => 'Id')));
      drupal_set_message('New record has been added.');
      break;
    case 'Save Change' :
      $fields = array(
        'year' => $form_state['values']['year'],
        'rep' => $form_state['values']['rep'],
        'route' => $form_state['values']['route'],
        'site_number' => $form_state['values']['site_number'],
        'fish' => $form_state['values']['fish'],
        'species' => $form_state['values']['species'],
        'length' => $form_state['values']['length'],
        'height' => $form_state['values']['height'],
        'lep_cop' => $form_state['values']['lep_cop'],
        'cal_cop' => $form_state['values']['cal_cop'],
        'chal_a' => $form_state['values']['chal_a'],
        'chal_b' => $form_state['values']['chal_b'],
        'mot_unid' => $form_state['values']['mot_unid'],
        'lep_pre_male' => $form_state['values']['lep_pre_male'],
        'lep_pre_female' => $form_state['values']['lep_pre_female'],
        'lep_pre_unid' => $form_state['values']['lep_pre_unid'],
        'lep_adult_male' => $form_state['values']['lep_adult_male'],
        'lep_adult_female' => $form_state['values']['lep_adult_female'],
        'lep_adult_unid' => $form_state['values']['lep_adult_unid'],
        'lep_gravid' => $form_state['values']['lep_gravid'],
        'caligus' => $form_state['values']['caligus'],
        'caligus_gravid' => $form_state['values']['caligus_gravid'],
        'chal_scar' => $form_state['values']['chal_scar'],
        'mot_scar' => $form_state['values']['mot_scar'],
        'pred_marks' => $form_state['values']['pred_marks'],
        'hem' => $form_state['values']['hem'],
        'mate_guarding' => $form_state['values']['mate_guarding'],
        'pin_belly' => $form_state['values']['pin_belly'],
        'tissue_damage' => $form_state['values']['tissue_damage'],
        'comments' => $form_state['values']['comments'],
        'changelog' => $form_state['values']['changelog'],
      );

      bampcrud_log('Update', 'bamp_wild_fish_data', $form_state['values']['id'], $fields);

      //Add db update code
      $num_updated = db_update('bamp_wild_fish_data', array('target'=>'bamp_new'))
      ->fields($fields)
      ->condition('id', $form_state['values']['id'],'=')
      ->execute();

      //drupal_goto('test/multi_step_form');
      drupal_set_message('Record has been saved.');
      break;
  }//end switch
}//end addedit_form_submit
