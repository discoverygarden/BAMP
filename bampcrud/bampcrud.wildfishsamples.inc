<?php

function bampcrud_wild_fish_samples_form($form, $form_state, $operation = 'add', $record_id = null) {
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
    $num_deleted = db_delete('bamp_wild_fish_samples', array('target'=>'bamp_new'))
    ->condition('id',$record_id)
    ->execute();

    drupal_set_message($num_deleted . t(' record has been deleted.'));
  }//end if

  //if the operation is modify, grab the record from the database.
  if ($operation == 'modify') {
    $result = db_select('bamp_wild_fish_samples', 'n', array('target'=>'bamp_new'))
    ->fields('n',array(
      'id',
      'fish_id',
      'trip_set_id',
      'trip_date',
      'trip_year',
      'trip_month',
      'trip_day',
      'fish_species_per_field',
      'fish_species_gr',
      'fish_species_gr_lab',
      'fish_no',
      'fish_species_per_lab',
      'length_mm',
      'height',
      'weight_g',
      'surface_area',
      'l_cop',
      'l_c1',
      'l_c2',
      'l_c3',
      'l_c4',
      'l_nm_not_stage',
      'l_pam',
      'l_paf',
      'l_pa_not_gender',
      'l_am',
      'l_af',
      'l_gravid',
      'l_adult_not_gender',
      'l_mob_not_stage',
      'c_cop',
      'c_c1',
      'c_c2',
      'c_c3',
      'c_c4',
      'c_nm_not_stage',
      'c_pam',
      'c_paf',
      'c_am',
      'c_af',
      'c_mob_not_stage',
      'c_gravid',
      'total_chal_03',
      'lep_total_mob_03',
      'lep_total',
      'cal_total_mob_03',
      'cal_total',
      'u_cop',
      'u_chal',
      'u_chal_stages_i_and_ii',
      'u_chal_stages_iii_and_iv',
      'u_mob',
      'lice_total',
      'lesions',
      'comments',
      'changelog',
      'trip',
      'gp_id',
      'lab',
      'date_examined',
      'examined_month',
      'examined_day',
      'examined_year',
      'initials',
      'scar_chal',
      'scar_mot',
      'pred_marks',
      'hem',
      'mate_guarding',
      'pin_belly',
      'lep_total_poo',
      'cal_total_poo',
      'u_total_poo',
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
  # fish_id text field
  $form['fieldset']['fish_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Fish ID'),
    '#default_value' => isset($result['fish_id']) ? $result['fish_id'] : '',
    '#required' => FALSE,
  );  
  # trip_set_id text field
  $form['fieldset']['trip_set_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Trip Set ID'),
    '#default_value' => isset($result['trip_set_id']) ? $result['trip_set_id'] : '',
    '#required' => FALSE,
  );  
  # trip_date text field
  $form['fieldset']['trip_date'] = array(
    '#type' => 'textfield',
    '#title' => t('Trip Date'),
    '#default_value' => isset($result['trip_date']) ? $result['trip_date'] : '',
    '#required' => FALSE,
  );  
  # trip_year text field
  $form['fieldset']['trip_year'] = array(
    '#type' => 'textfield',
    '#title' => t('Trip Year'),
    '#default_value' => isset($result['trip_year']) ? $result['trip_year'] : '',
    '#required' => FALSE,
  );  
  # trip_month text field
  $form['fieldset']['trip_month'] = array(
    '#type' => 'textfield',
    '#title' => t('Trip Month'),
    '#default_value' => isset($result['trip_month']) ? $result['trip_month'] : '',
    '#required' => FALSE,
  );  
  # trip_day text field
  $form['fieldset']['Trip Day'] = array(
    '#type' => 'textfield',
    '#title' => t('trip_day'),
    '#default_value' => isset($result['trip_day']) ? $result['trip_day'] : '',
    '#required' => FALSE,
  );  
  # fish_species_per_field text field
  $form['fieldset']['fish_species_per_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Fish Species (Per field)'),
    '#default_value' => isset($result['fish_species_per_field']) ? $result['fish_species_per_field'] : '',
    '#required' => FALSE,
  );  
  # fish_species_gr text field
  $form['fieldset']['fish_species_gr'] = array(
    '#type' => 'textfield',
    '#title' => t('Fish Species Gr'),
    '#default_value' => isset($result['fish_species_gr']) ? $result['fish_species_gr'] : '',
    '#required' => FALSE,
  );  
  # fish_species_gr_lab text field
  $form['fieldset']['fish_species_gr_lab'] = array(
    '#type' => 'textfield',
    '#title' => t('Fish Species Gr Lab'),
    '#default_value' => isset($result['fish_species_gr_lab']) ? $result['fish_species_gr_lab'] : '',
    '#required' => FALSE,
  );  
  # fish_no text field
  $form['fieldset']['fish_no'] = array(
    '#type' => 'textfield',
    '#title' => t('Fish No.'),
    '#default_value' => isset($result['fish_no']) ? $result['fish_no'] : '',
    '#required' => FALSE,
  );  
  # fish_species_per_lab text field
  $form['fieldset']['fish_species_per_lab'] = array(
    '#type' => 'textfield',
    '#title' => t('Fish Species (Per Lab)'),
    '#default_value' => isset($result['fish_species_per_lab']) ? $result['fish_species_per_lab'] : '',
    '#required' => FALSE,
  );  
  # length_mm text field
  $form['fieldset']['length_mm'] = array(
    '#type' => 'textfield',
    '#title' => t('Length (mm)'),
    '#default_value' => isset($result['length_mm']) ? $result['length_mm'] : '',
    '#required' => FALSE,
  );  
  # height text field
  $form['fieldset']['height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#default_value' => isset($result['height']) ? $result['height'] : '',
    '#required' => FALSE,
  );  
  # weight_g text field
  $form['fieldset']['weight_g'] = array(
    '#type' => 'textfield',
    '#title' => t('Weight (g)'),
    '#default_value' => isset($result['weight_g']) ? $result['weight_g'] : '',
    '#required' => FALSE,
  );  
  # surface_area text field
  $form['fieldset']['surface_area'] = array(
    '#type' => 'textfield',
    '#title' => t('Surface Area'),
    '#default_value' => isset($result['surface_area']) ? $result['surface_area'] : '',
    '#required' => FALSE,
  );  
  # l_cop text field
  $form['fieldset']['l_cop'] = array(
    '#type' => 'textfield',
    '#title' => t('l_cop'),
    '#default_value' => isset($result['l_cop']) ? $result['l_cop'] : '',
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
  # l_nm_not_stage text field
  $form['fieldset']['l_nm_not_stage'] = array(
    '#type' => 'textfield',
    '#title' => t('l_nm_not_stage'),
    '#default_value' => isset($result['l_nm_not_stage']) ? $result['l_nm_not_stage'] : '',
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
  # l_pa_not_gender text field
  $form['fieldset']['l_pa_not_gender'] = array(
    '#type' => 'textfield',
    '#title' => t('l_pa_not_gender'),
    '#default_value' => isset($result['l_pa_not_gender']) ? $result['l_pa_not_gender'] : '',
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
  # l_gravid text field
  $form['fieldset']['l_gravid'] = array(
    '#type' => 'textfield',
    '#title' => t('l_gravid'),
    '#default_value' => isset($result['l_gravid']) ? $result['l_gravid'] : '',
    '#required' => FALSE,
  );  
  # l_adult_not_gender text field
  $form['fieldset']['l_adult_not_gender'] = array(
    '#type' => 'textfield',
    '#title' => t('l_adult_not_gender'),
    '#default_value' => isset($result['l_adult_not_gender']) ? $result['l_adult_not_gender'] : '',
    '#required' => FALSE,
  );  
  # l_mob_not_stage text field
  $form['fieldset']['l_mob_not_stage'] = array(
    '#type' => 'textfield',
    '#title' => t('l_mob_not_stage'),
    '#default_value' => isset($result['l_mob_not_stage']) ? $result['l_mob_not_stage'] : '',
    '#required' => FALSE,
  );  
  # c_cop text field
  $form['fieldset']['c_cop'] = array(
    '#type' => 'textfield',
    '#title' => t('c_cop'),
    '#default_value' => isset($result['c_cop']) ? $result['c_cop'] : '',
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
  # c_nm_not_stage text field
  $form['fieldset']['c_nm_not_stage'] = array(
    '#type' => 'textfield',
    '#title' => t('c_nm_not_stage'),
    '#default_value' => isset($result['c_nm_not_stage']) ? $result['c_nm_not_stage'] : '',
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
  # c_mob_not_stage text field
  $form['fieldset']['c_mob_not_stage'] = array(
    '#type' => 'textfield',
    '#title' => t('c_mob_not_stage'),
    '#default_value' => isset($result['c_mob_not_stage']) ? $result['c_mob_not_stage'] : '',
    '#required' => FALSE,
  );  
  # c_gravid text field
  $form['fieldset']['c_gravid'] = array(
    '#type' => 'textfield',
    '#title' => t('c_gravid'),
    '#default_value' => isset($result['c_gravid']) ? $result['c_gravid'] : '',
    '#required' => FALSE,
  );  
  # total_chal_03 text field
  $form['fieldset']['total_chal_03'] = array(
    '#type' => 'textfield',
    '#title' => t('total_chal_03'),
    '#default_value' => isset($result['total_chal_03']) ? $result['total_chal_03'] : '',
    '#required' => FALSE,
  );  
  # lep_total_mob_03 text field
  $form['fieldset']['lep_total_mob_03'] = array(
    '#type' => 'textfield',
    '#title' => t('lep_total_mob_03'),
    '#default_value' => isset($result['lep_total_mob_03']) ? $result['lep_total_mob_03'] : '',
    '#required' => FALSE,
  );  
  # lep_total text field
  $form['fieldset']['lep_total'] = array(
    '#type' => 'textfield',
    '#title' => t('lep_total'),
    '#default_value' => isset($result['lep_total']) ? $result['lep_total'] : '',
    '#required' => FALSE,
  );  
  # cal_total_mob_03 text field
  $form['fieldset']['cal_total_mob_03'] = array(
    '#type' => 'textfield',
    '#title' => t('cal_total_mob_03'),
    '#default_value' => isset($result['cal_total_mob_03']) ? $result['cal_total_mob_03'] : '',
    '#required' => FALSE,
  );  
  # cal_total text field
  $form['fieldset']['cal_total'] = array(
    '#type' => 'textfield',
    '#title' => t('cal_total'),
    '#default_value' => isset($result['cal_total']) ? $result['cal_total'] : '',
    '#required' => FALSE,
  );  
  # u_cop text field
  $form['fieldset']['u_cop'] = array(
    '#type' => 'textfield',
    '#title' => t('u_cop'),
    '#default_value' => isset($result['u_cop']) ? $result['u_cop'] : '',
    '#required' => FALSE,
  );  
  # u_chal text field
  $form['fieldset']['u_chal'] = array(
    '#type' => 'textfield',
    '#title' => t('u_chal'),
    '#default_value' => isset($result['u_chal']) ? $result['u_chal'] : '',
    '#required' => FALSE,
  );  
  # u_chal_stages_i_and_ii text field
  $form['fieldset']['u_chal_stages_i_and_ii'] = array(
    '#type' => 'textfield',
    '#title' => t('u_chal_stages_i_and_ii'),
    '#default_value' => isset($result['u_chal_stages_i_and_ii']) ? $result['u_chal_stages_i_and_ii'] : '',
    '#required' => FALSE,
  );  
  # u_chal_stages_iii_and_iv text field
  $form['fieldset']['u_chal_stages_iii_and_iv'] = array(
    '#type' => 'textfield',
    '#title' => t('u_chal_stages_iii_and_iv'),
    '#default_value' => isset($result['u_chal_stages_iii_and_iv']) ? $result['u_chal_stages_iii_and_iv'] : '',
    '#required' => FALSE,
  );  
  # u_mob text field
  $form['fieldset']['u_mob'] = array(
    '#type' => 'textfield',
    '#title' => t('u_mob'),
    '#default_value' => isset($result['u_mob']) ? $result['u_mob'] : '',
    '#required' => FALSE,
  );  
  # lice_total text field
  $form['fieldset']['lice_total'] = array(
    '#type' => 'textfield',
    '#title' => t('Lice Total'),
    '#default_value' => isset($result['lice_total']) ? $result['lice_total'] : '',
    '#required' => FALSE,
  );  
  # lesions text field
  $form['fieldset']['lesions'] = array(
    '#type' => 'textfield',
    '#title' => t('Lesions'),
    '#default_value' => isset($result['lesions']) ? $result['lesions'] : '',
    '#required' => FALSE,
  );  
  # comments text field
  $form['fieldset']['comments'] = array(
    '#type' => 'textfield',
    '#title' => t('Comments'),
    '#default_value' => isset($result['comments']) ? $result['comments'] : '',
    '#required' => FALSE,
  );  
  # changelog text field
  $form['fieldset']['changelog'] = array(
    '#type' => 'textfield',
    '#title' => t('Change Log'),
    '#default_value' => isset($result['changelog']) ? $result['changelog'] : '',
    '#required' => FALSE,
  );  
  # trip text field
  $form['fieldset']['trip'] = array(
    '#type' => 'textfield',
    '#title' => t('Trip'),
    '#default_value' => isset($result['trip']) ? $result['trip'] : '',
    '#required' => FALSE,
  );  
  # gp_id text field
  $form['fieldset']['gp_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Group ID'),
    '#default_value' => isset($result['gp_id']) ? $result['gp_id'] : '',
    '#required' => FALSE,
  );  
  # lab text field
  $form['fieldset']['lab'] = array(
    '#type' => 'textfield',
    '#title' => t('Lab'),
    '#default_value' => isset($result['lab']) ? $result['lab'] : '',
    '#required' => FALSE,
  );  
  # date_examined text field
  $form['fieldset']['date_examined'] = array(
    '#type' => 'textfield',
    '#title' => t('Date Examined'),
    '#default_value' => isset($result['date_examined']) ? $result['date_examined'] : '',
    '#required' => FALSE,
  );  
  # examined_month text field
  $form['fieldset']['Examined Month'] = array(
    '#type' => 'textfield',
    '#title' => t('examined_month'),
    '#default_value' => isset($result['examined_month']) ? $result['examined_month'] : '',
    '#required' => FALSE,
  );  
  # examined_day text field
  $form['fieldset']['examined_day'] = array(
    '#type' => 'textfield',
    '#title' => t('Examined Day'),
    '#default_value' => isset($result['examined_day']) ? $result['examined_day'] : '',
    '#required' => FALSE,
  );  
  # examined_year text field
  $form['fieldset']['examined_year'] = array(
    '#type' => 'textfield',
    '#title' => t('Examined Year'),
    '#default_value' => isset($result['examined_year']) ? $result['examined_year'] : '',
    '#required' => FALSE,
  );  
  # initials text field
  $form['fieldset']['initials'] = array(
    '#type' => 'textfield',
    '#title' => t('Initials'),
    '#default_value' => isset($result['initials']) ? $result['initials'] : '',
    '#required' => FALSE,
  );  
  # scar_chal text field
  $form['fieldset']['scar_chal'] = array(
    '#type' => 'textfield',
    '#title' => t('scar_chal'),
    '#default_value' => isset($result['scar_chal']) ? $result['scar_chal'] : '',
    '#required' => FALSE,
  );  
  # scar_mot text field
  $form['fieldset']['scar_mot'] = array(
    '#type' => 'textfield',
    '#title' => t('scar_mot'),
    '#default_value' => isset($result['scar_mot']) ? $result['scar_mot'] : '',
    '#required' => FALSE,
  );  
  # pred_marks text field
  $form['fieldset']['pred_marks'] = array(
    '#type' => 'textfield',
    '#title' => t('Predator Marks'),
    '#default_value' => isset($result['pred_marks']) ? $result['pred_marks'] : '',
    '#required' => FALSE,
  );  
  # hem text field
  $form['fieldset']['hem'] = array(
    '#type' => 'textfield',
    '#title' => t('Hem'),
    '#default_value' => isset($result['hem']) ? $result['hem'] : '',
    '#required' => FALSE,
  );  
  # mate_guarding text field
  $form['fieldset']['mate_guarding'] = array(
    '#type' => 'textfield',
    '#title' => t('Mate Guarding'),
    '#default_value' => isset($result['mate_guarding']) ? $result['mate_guarding'] : '',
    '#required' => FALSE,
  );  
  # pin_belly text field
  $form['fieldset']['pin_belly'] = array(
    '#type' => 'textfield',
    '#title' => t('Pin Belly'),
    '#default_value' => isset($result['pin_belly']) ? $result['pin_belly'] : '',
    '#required' => FALSE,
  );  
  # lep_total_poo text field
  $form['fieldset']['lep_total_poo'] = array(
    '#type' => 'textfield',
    '#title' => t('Lep Total (Calulated by Poo)'),
    '#default_value' => isset($result['lep_total_poo']) ? $result['lep_total_poo'] : '',
    '#required' => FALSE,
  );  
  # cal_total_poo text field
  $form['fieldset']['cal_total_poo'] = array(
    '#type' => 'textfield',
    '#title' => t('Cal Total (Calculated by Poo)'),
    '#default_value' => isset($result['cal_total_poo']) ? $result['cal_total_poo'] : '',
    '#required' => FALSE,
  );  
  # u_total_poo text field
  $form['fieldset']['u_total_poo'] = array(
    '#type' => 'textfield',
    '#title' => t('u_total_poo'),
    '#default_value' => isset($result['u_total_poo']) ? $result['u_total_poo'] : '',
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

function bampcrud_wild_fish_samples_form_submit($form, &$form_state) {
  switch ($form_state['values']['op']) {
    case 'Add Record' :
      //Add db insert 
      $result = db_insert('bamp_wild_fish_samples', array('target'=>'bamp_new'))
      ->fields(array(
        'fish_id' => $form_state['values']['fish_id'],
        'trip_set_id' => $form_state['values']['trip_set_id'],
        'trip_date' => $form_state['values']['trip_date'],
        'trip_year' => $form_state['values']['trip_year'],
        'trip_month' => $form_state['values']['trip_month'],
        'trip_day' => $form_state['values']['trip_day'],
        'fish_species_per_field' => $form_state['values']['fish_species_per_field'],
        'fish_species_gr' => $form_state['values']['fish_species_gr'],
        'fish_species_gr_lab' => $form_state['values']['fish_species_gr_lab'],
        'fish_no' => $form_state['values']['fish_no'],
        'fish_species_per_lab' => $form_state['values']['fish_species_per_lab'],
        'length_mm' => $form_state['values']['length_mm'],
        'height' => $form_state['values']['height'],
        'weight_g' => $form_state['values']['weight_g'],
        'surface_area' => $form_state['values']['surface_area'],
        'l_cop' => $form_state['values']['l_cop'],
        'l_c1' => $form_state['values']['l_c1'],
        'l_c2' => $form_state['values']['l_c2'],
        'l_c3' => $form_state['values']['l_c3'],
        'l_c4' => $form_state['values']['l_c4'],
        'l_nm_not_stage' => $form_state['values']['l_nm_not_stage'],
        'l_pam' => $form_state['values']['l_pam'],
        'l_paf' => $form_state['values']['l_paf'],
        'l_pa_not_gender' => $form_state['values']['l_pa_not_gender'],
        'l_am' => $form_state['values']['l_am'],
        'l_af' => $form_state['values']['l_af'],
        'l_gravid' => $form_state['values']['l_gravid'],
        'l_adult_not_gender' => $form_state['values']['l_adult_not_gender'],
        'l_mob_not_stage' => $form_state['values']['l_mob_not_stage'],
        'c_cop' => $form_state['values']['c_cop'],
        'c_c1' => $form_state['values']['c_c1'],
        'c_c2' => $form_state['values']['c_c2'],
        'c_c3' => $form_state['values']['c_c3'],
        'c_c4' => $form_state['values']['c_c4'],
        'c_nm_not_stage' => $form_state['values']['c_nm_not_stage'],
        'c_pam' => $form_state['values']['c_pam'],
        'c_paf' => $form_state['values']['c_paf'],
        'c_am' => $form_state['values']['c_am'],
        'c_af' => $form_state['values']['c_af'],
        'c_mob_not_stage' => $form_state['values']['c_mob_not_stage'],
        'c_gravid' => $form_state['values']['c_gravid'],
        'total_chal_03' => $form_state['values']['total_chal_03'],
        'lep_total_mob_03' => $form_state['values']['lep_total_mob_03'],
        'lep_total' => $form_state['values']['lep_total'],
        'cal_total_mob_03' => $form_state['values']['cal_total_mob_03'],
        'cal_total' => $form_state['values']['cal_total'],
        'u_cop' => $form_state['values']['u_cop'],
        'u_chal' => $form_state['values']['u_chal'],
        'u_chal_stages_i_and_ii' => $form_state['values']['u_chal_stages_i_and_ii'],
        'u_chal_stages_iii_and_iv' => $form_state['values']['u_chal_stages_iii_and_iv'],
        'u_mob' => $form_state['values']['u_mob'],
        'lice_total' => $form_state['values']['lice_total'],
        'lesions' => $form_state['values']['lesions'],
        'comments' => $form_state['values']['comments'],
        'changelog' => $form_state['values']['changelog'],
        'trip' => $form_state['values']['trip'],
        'gp_id' => $form_state['values']['gp_id'],
        'lab' => $form_state['values']['lab'],
        'date_examined' => $form_state['values']['date_examined'],
        'examined_month' => $form_state['values']['examined_month'],
        'examined_day' => $form_state['values']['examined_day'],
        'examined_year' => $form_state['values']['examined_year'],
        'initials' => $form_state['values']['initials'],
        'scar_chal' => $form_state['values']['scar_chal'],
        'scar_mot' => $form_state['values']['scar_mot'],
        'pred_marks' => $form_state['values']['pred_marks'],
        'hem' => $form_state['values']['hem'],
        'mate_guarding' => $form_state['values']['mate_guarding'],
        'pin_belly' => $form_state['values']['pin_belly'],
        'lep_total_poo' => $form_state['values']['lep_total_poo'],
        'cal_total_poo' => $form_state['values']['cal_total_poo'],
        'u_total_poo' => $form_state['values']['u_total_poo'],
      ))
      ->execute();
    
      //drupal_goto('test/multi_step_form', array('query' => array('sort' => 'desc', 'order' => 'Id')));
      drupal_set_message('Wild Fish Sample Added.');
      break;
    case 'Save Change' :
      //Add db update code

      $num_updated = db_update('bamp_wild_fish_samples', array('target'=>'bamp_new'))
      ->fields(array(
        'fish_id' => $form_state['values']['fish_id'],
        'trip_set_id' => $form_state['values']['trip_set_id'],
        'trip_date' => $form_state['values']['trip_date'],
        'trip_year' => $form_state['values']['trip_year'],
        'trip_month' => $form_state['values']['trip_month'],
        'trip_day' => $form_state['values']['trip_day'],
        'fish_species_per_field' => $form_state['values']['fish_species_per_field'],
        'fish_species_gr' => $form_state['values']['fish_species_gr'],
        'fish_species_gr_lab' => $form_state['values']['fish_species_gr_lab'],
        'fish_no' => $form_state['values']['fish_no'],
        'fish_species_per_lab' => $form_state['values']['fish_species_per_lab'],
        'length_mm' => $form_state['values']['length_mm'],
        'height' => $form_state['values']['height'],
        'weight_g' => $form_state['values']['weight_g'],
        'surface_area' => $form_state['values']['surface_area'],
        'l_cop' => $form_state['values']['l_cop'],
        'l_c1' => $form_state['values']['l_c1'],
        'l_c2' => $form_state['values']['l_c2'],
        'l_c3' => $form_state['values']['l_c3'],
        'l_c4' => $form_state['values']['l_c4'],
        'l_nm_not_stage' => $form_state['values']['l_nm_not_stage'],
        'l_pam' => $form_state['values']['l_pam'],
        'l_paf' => $form_state['values']['l_paf'],
        'l_pa_not_gender' => $form_state['values']['l_pa_not_gender'],
        'l_am' => $form_state['values']['l_am'],
        'l_af' => $form_state['values']['l_af'],
        'l_gravid' => $form_state['values']['l_gravid'],
        'l_adult_not_gender' => $form_state['values']['l_adult_not_gender'],
        'l_mob_not_stage' => $form_state['values']['l_mob_not_stage'],
        'c_cop' => $form_state['values']['c_cop'],
        'c_c1' => $form_state['values']['c_c1'],
        'c_c2' => $form_state['values']['c_c2'],
        'c_c3' => $form_state['values']['c_c3'],
        'c_c4' => $form_state['values']['c_c4'],
        'c_nm_not_stage' => $form_state['values']['c_nm_not_stage'],
        'c_pam' => $form_state['values']['c_pam'],
        'c_paf' => $form_state['values']['c_paf'],
        'c_am' => $form_state['values']['c_am'],
        'c_af' => $form_state['values']['c_af'],
        'c_mob_not_stage' => $form_state['values']['c_mob_not_stage'],
        'c_gravid' => $form_state['values']['c_gravid'],
        'total_chal_03' => $form_state['values']['total_chal_03'],
        'lep_total_mob_03' => $form_state['values']['lep_total_mob_03'],
        'lep_total' => $form_state['values']['lep_total'],
        'cal_total_mob_03' => $form_state['values']['cal_total_mob_03'],
        'cal_total' => $form_state['values']['cal_total'],
        'u_cop' => $form_state['values']['u_cop'],
        'u_chal' => $form_state['values']['u_chal'],
        'u_chal_stages_i_and_ii' => $form_state['values']['u_chal_stages_i_and_ii'],
        'u_chal_stages_iii_and_iv' => $form_state['values']['u_chal_stages_iii_and_iv'],
        'u_mob' => $form_state['values']['u_mob'],
        'lice_total' => $form_state['values']['lice_total'],
        'lesions' => $form_state['values']['lesions'],
        'comments' => $form_state['values']['comments'],
        'changelog' => $form_state['values']['changelog'],
        'trip' => $form_state['values']['trip'],
        'gp_id' => $form_state['values']['gp_id'],
        'lab' => $form_state['values']['lab'],
        'date_examined' => $form_state['values']['date_examined'],
        'examined_month' => $form_state['values']['examined_month'],
        'examined_day' => $form_state['values']['examined_day'],
        'examined_year' => $form_state['values']['examined_year'],
        'initials' => $form_state['values']['initials'],
        'scar_chal' => $form_state['values']['scar_chal'],
        'scar_mot' => $form_state['values']['scar_mot'],
        'pred_marks' => $form_state['values']['pred_marks'],
        'hem' => $form_state['values']['hem'],
        'mate_guarding' => $form_state['values']['mate_guarding'],
        'pin_belly' => $form_state['values']['pin_belly'],
        'lep_total_poo' => $form_state['values']['lep_total_poo'],
        'cal_total_poo' => $form_state['values']['cal_total_poo'],
        'u_total_poo' => $form_state['values']['u_total_poo'],
      ))
      ->condition('id', $form_state['values']['id'],'=')
      ->execute();

      //drupal_goto('test/multi_step_form');
      drupal_set_message('Wild Fish Sample Updated');
      break;
  }//end switch
}//end addedit_form_submit
