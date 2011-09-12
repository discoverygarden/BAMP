<?php
function bampcrud_wild_sites_form() {
  drupal_set_title('Wild Sites Data Entry');
  
  $form['fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Add a new site'),
    '#collapsible' => TRUE, 
  );

  # site_number text field
  $form['fieldset']['site_number'] = array(
    '#type' => 'textfield',
    '#title' => t('site_number'),
    '#required' => FALSE,
  );

  # site_name text field
  $form['fieldset']['site_name'] = array(
    '#type' => 'textfield',
    '#title' => t('site_name'),
    '#required' => FALSE,
  );

  # latitude text field
  $form['fieldset']['latitude'] = array(
    '#type' => 'textfield',
    '#title' => t('latitude'),
    '#required' => FALSE,
  );

  # longitude text field
  $form['fieldset']['longitude'] = array(
    '#type' => 'textfield',
    '#title' => t('longitude'),
    '#required' => FALSE,
  );

  # zone text field
  $form['fieldset']['zone'] = array(
    '#type' => 'textfield',
    '#title' => t('zone'),
    '#required' => FALSE,
  );

  # area text field
  $form['fieldset']['area'] = array(
    '#type' => 'textfield',
    '#title' => t('area'),
    '#required' => FALSE,
  );

  # comment text field
  $form['fieldset']['comment'] = array(
    '#type' => 'textfield',
    '#title' => t('comment'),
    '#required' => FALSE,
  );


  # a simple submit button refreshes the form and clears its contents;
  # this is the default behavior for forms.
  $form['fieldset']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save',
  );
  
  return $form;
}

/**
 * A Drupal module submit handler
 * ------------------------------------------------------------------
 * Displays success message on top of form.
 * Form is still displayed.
 * ------------------------------------------------------------------
 * Adds a submit handler/function to our form to send a successful
 * completion message to the screen.
 */
function bampcrud_wild_sites_form_submit($form, &$form_state) {

  # form is already validated, just save it here
  $data = array(
  'site_number' => $form_state['values']['site_number'],
  'site_name' => $form_state['values']['site_name'],
  'latitude' => $form_state['values']['latitude'],
  'longitude' => $form_state['values']['longitude'],
  'zone' => $form_state['values']['zone'],
  'area' => $form_state['values']['area'],
  'comment' => $form_state['values']['comment'],
  );

  # get the user id
  global $user;
  $uid = $user->uid;

  db_insert('bamp_wild_sites', array('target'=>'bamp_new'))->fields($data)->execute();

  drupal_set_message(t('Your entry has been saved.'));
}

