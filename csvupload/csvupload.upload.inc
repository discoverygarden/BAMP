<?php
// $Id$

/**
 * @file
 * Contains code for upload form wizard
 */

/**
 * Contains main upload form wizard
 * 
 * This function generates the three step upload wizard form. The first step 
 * is to choose the destination table and csv file. The second step is to map
 * the fields in the csv to the fields in the database. The third step is to 
 * review the information that is to be imported and address any errors found
 * in the import file. Once the data has been reviewed and the user is happy
 * with the result, the user can click "Commit Import" and the data will be 
 * moved to the appropriate production table. 
 *
 * @param $form
 * 
 * @param $form_state
 * 
 */
function csvupload_upload_form($form, &$form_state) {
  //Create wrapper around the form for ajax callback
  $form['#prefix'] = '<div id="wizard-form-wrapper">';
  $form['#suffix'] = '</div>';
  $form['#tree'] = TRUE; // We want to deal with hierarchical form values.

  //Store which step we are on
  $step = empty($form_state['storage']['step']) ? 1 : $form_state['storage']['step'];
  $form_state['storage']['step'] = $step;

  //Decide what to do based on which step we are on
  switch ($step) {
    //Case 1: Select Desintation and CSV File. 
    case 1:
      $form['#attributes'] = array('enctype' => "multipart/form-data");
      $form['step1'] = array(
        '#type' => 'fieldset', 
        '#title' => t('Step 1: Choose database destination for import'),
      );

      //Get database tables
      $tables = db_query("SHOW TABLES FROM bamp_new WHERE Tables_in_bamp_new NOT IN ('ChangeLog','polygons','polygons_points') AND Tables_in_bamp_new NOT LIKE '%tmp%' AND Tables_in_bamp_new NOT LIKE '%view%'", array(), array('target' => 'bamp_new'))->fetchCol();

      //Create import_tables array to hold importable tables for dropdown
      $import_tables = array('ps' => '--Please Select--');

      //Loop over tables and see if they have been selected in the admin config (easier way to do this??)
      foreach ($tables as $k => $table) {
        $import_tables[$table] = $table;
      }//end foreach

      if (count($import_tables) > 0) {
        drupal_add_css(drupal_get_path('module', 'csvupload') . '/csvupload.css');
        $form['step1']['selectTable'] = array(
          '#type' => 'select',
          '#options' => $import_tables,
          '#title' => t('Import Destination'),
          '#description' => t('Please select the table you wish to import data to.'),
          '#default_value' => empty($form_state['values']['step1']['selectTable']) ? '' : $form_state['values']['step1']['selectTable'], 
          '#required' => TRUE,
        );
        $form['step1']['csv'] = array(
          '#type' => 'file',
          '#title' => t('Import File (*.csv)'),
          '#size' => 40,
          '#description' => t('Select the file you wish to upload.'),
        );
      }
      else {
        //set error message for no tables
        drupal_set_message(t('Error: There are no destination tables available. Please select tables in the csvupload admin module.'));
      }//end if	
    break;

    case 2:
      $form['step2'] = array(
        '#type' => 'fieldset', 
        '#title' => t('Step 2: Map Fields'),
      );

      $form['step2']['map'] = array(
        '#prefix' => '<div id="map">',
        '#suffix' => '</div>',
        '#tree' => TRUE,
        '#theme' => 'table',
        '#header' => array(t('CSV Name'), t('Database Name')),
        '#rows' => array(),
      );

      $csv_file_path = $form_state['storage']['values']['step1']['csv']['filepath'];
      $csv_file_name = $form_state['storage']['values']['step1']['csv']['title'];

      $aa = csvupload_csv2aa($csv_file_path, ',');
      $headers = $aa[0];
      $table_cols = db_query("SHOW COLUMNS FROM " . $form_state['values']['step1']['selectTable'] . " WHERE Field NOT IN ('id')", array(), array('target' => 'bamp_new'))->fetchCol();//Get database Columns 
      $cols = array('sk' => 'Skip this field');
      foreach ($table_cols as $k => $v) {
        $cols[$v] = $v;
      }//end foreach 
      $table_cols = $cols;
      foreach ($headers as $k => $v) {
        $csvnames = array(
          '#markup' => $v,
        );

        $colnames = array(
          '#id' => 'csv-' . $k . '-db',
          '#type' => 'select',
          '#options' => $table_cols,
          '#default_value' => strtolower($v),
        );

        $form['step2']['map'][$k] = array(
          'csvname' => &$csvnames,
          'colname' => &$colnames,
        );

        $form['step2']['map']['#rows'][] = array(
          array('data' => &$csvnames),
          array('data' => &$colnames),
        );

        unset($csvnames);
        unset($colnames);
      }
    break;
    
    case 3:
      $error = FALSE;
      $rows = array();
      
      //Get first 100 rows from temporary tables
      $sql = "SELECT * FROM {" . $form_state['storage']['tempTable'] . "}";
      $result = db_query_range($sql, 0, 100, array(), array('target' => 'bamp_new'));
      while ($record = $result->fetchAssoc()) {
        $rows[] = $record;
      }
      if (count($rows) > 0) {
        $form['step3'] = array(
          '#type' => 'fieldset',
          '#title' => t('Step 3: Review and Commit'),
        );

        $form['step3']['info'] = array(
          '#markup' => '<strong>Please review import data below and fix any problems in the data file before you commit this import to the database.</strong>',
        );

        //Check for errors.
        if (!empty($form_state['storage']['import_errors'])) {
          $errorTxt = '<br/><br/><b style="color:#FF0000;">Import Errors</b><br/><br/>';
          foreach($form_state['storage']['import_errors'] as $line_no=>$problem){
            $errorTxt.= '<b>Line '.($line_no + 1).':</b> '.$problem.'<br/>';
          }//end foreach
          $form['step3']['errors'] = array(
            '#markup' => $errorTxt,
          );
        }else{
          //No errors, display sample!
          $form['step3']['rows'] = array(
            '#markup' => drupal_render(csvupload_array2table($rows)),
          );
        }//end if
      }
      else {
        drupal_set_message(t('There was an error during import. Possible causes may include: Errors in the input file, Mismatched columns, Foreign charecters, blank fields mapped to a database field that requires input.'), 'error');
        db_query('DROP TABLE ' . $form_state['storage']['tempTable'], array(), array('target' => 'bamp_new')); 
        $error = TRUE;
      }//end if
    break;
  }//end switch

  if ($step == 3) {
    if ($error !== TRUE) {
      $form['submit'] = array(
        '#type' => 'submit', 
        '#value' => t("Commit Import"),
      );
    }//end if
  }
  if ($step < 3) {
    $form['next'] = array(
      '#type' => 'submit', 
      '#value' => t('Next step'), 
      '#ajax' => array(
        'wrapper' => 'wizard-form-wrapper', 
        'callback' => 'csvupload_upload_form_callback',
      ),
    );
  }

  return $form;
}

function csvupload_upload_form_callback($form, $form_state) {
  return $form;
}

function csvupload_upload_form_submit($form, &$form_state) {
  // Save away the current informationr
  $current_step = 'step' . $form_state['storage']['step'];
  if (!empty($form_state['values'][$current_step])) {
    $form_state['storage']['values'][$current_step] = $form_state['values'][$current_step];
  }

  switch ($current_step) {
    case 'step1':
      $validators = array('file_validate_extensions' => array('csv'));
      $file = file_save_upload('step1', $validators);
      if (!$file)
        form_set_error('upload', 'You must select a valid file to upload.');
      else {
        // Manually add the uploaded file to the $form_state
        $form_state['storage']['values']['step1']['csv']['title'] = $file->filename;
        $form_state['storage']['values']['step1']['csv']['file'] = $file;
        $form_state['storage']['values']['step1']['csv']['filepath'] = $file->destination;
      }
      break;

    case 'step2':
      $table = $form_state['storage']['values']['step1']['selectTable'];
      $tmp_table = csvupload_createTempTable($table);
      $form_state['storage']['tempTable'] = $tmp_table;
      $form_state['storage']['destTable'] = $table;
      $file = $form_state['storage']['values']['step1']['csv']['filepath'];
      $map = $form_state['storage']['values']['step2']['map'];
      $form_state['storage']['import_errors'] = csvupload_csvimport($table, $tmp_table, $file, $map);
      break;

    case 'step3':
      if (!empty($form_state['storage']['tempTable']) && !empty($form_state['storage']['destTable'])) {
        $results = db_query('SELECT * FROM {' . $form_state['storage']['tempTable'] . '}', array(), array('target' => 'bamp_new'));
        if ($results) {
          $totalrows = count($results);
          while ($result = $results->fetchAssoc()) {
            if (isset($result['id'])) {
              unset($result['id']);
            }//end if
            db_insert($form_state['storage']['destTable'], array('target' => 'bamp_new'))->fields($result)->execute();
          }//end while

          db_query('DROP TABLE ' . $form_state['storage']['tempTable'], array(), array('target' => 'bamp_new'));
          drupal_set_message(t('Import has been completed.'));
          drupal_goto('csvupload');
        }
        else{
          drupal_set_message(t('The destination table or temporary table is not currently set. Please try again.'), 'error');
        }//end if
      }//end if
      break;
  }//end switch

  // Increment or decrement the step as needed. Recover values if they exist.
  if ($form_state['triggering_element']['#value'] == t('Next step')) {
    $form_state['storage']['step']++;
    // If values have already been entered for this step, recover them from
    // $form_state['storage'] to pre-populate them.
    $step_name = 'step' . $form_state['storage']['step'];
    if (!empty($form_state['storage']['values'][$step_name])) {
      $form_state['values'][$step_name] = $form_state['storage']['values'][$step_name];
    }
  }
  if ($form_state['triggering_element']['#value'] == t('Previous step')) {
    $form_state['storage']['step']--;
    // Recover our values from $form_state['storage'] to pre-populate them.
    $step_name = 'step' . $form_state['storage']['step'];
    $form_state['values'][$step_name] = $form_state['storage']['values'][$step_name];
  }

  // If they're done, submit.
  if ($form_state['triggering_element']['#value'] == t('Submit your information')) {
    drupal_set_message(t('Your import has been submitted'));
    $form_state['rebuild'] = FALSE;
    return;
  }

  // Otherwise, we still have work to do.
  $form_state['rebuild'] = TRUE;
}
