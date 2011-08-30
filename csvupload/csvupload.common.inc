<?php
// $Id: csvupload common functions$

/**
 * @file
 * Contains common code for upload form wizard
 */

/**
 * Function that parses a csv file into an array and returns the array
 * @param type $file
 * @param type $delimiter
 * @return type 
 */
if (!function_exists('csvupload_csv2aa')) {
  function csvupload_csv2aa($file, $delimiter) {
    if (($handle = fopen($file, "r")) !== FALSE) {
      $i = 0;
      while (($line_array = fgetcsv($handle, 4000, $delimiter)) !== FALSE) {
        for ($j = 0; $j < count($line_array); $j++) {
          $arrarr[$i][$j] = $line_array[$j];
        }   
        $i++;
      }   
      fclose($handle);
    }   
    return $arrarr;
  }
}

/**
 * Function that creates a temporary table named $table_<uid> so we can stage the CSV import
 * @param type $table
 * @return $tmpTableName
 */
if (!function_exists('csvupload_createTempTable')) {
  function csvupload_createTempTable($table) {
    global $user;
    $dbh = Database::getConnection('bamp_new','default');
    $tmp_table = $table . '_' . $user->uid . '_tmp_' . time();
    $result = $dbh->query("CREATE TABLE IF NOT EXISTS $tmp_table LIKE $table");

    return $tmp_table;
  }//end csvupload_createTempTable();
}

/**
 * Function that ingests csv file into temporary table
 * 
 * This function is responsible for importing a CSV file into a temporary table.
 * It begins by converting the CSV file to an associative array which is then 
 * processed into an array suitable for passing to db_insert() function. 
 * Once the array is built, a second loop is performed which checks to see if
 * the data will fit into the column in the database and if so, inserts the 
 * row. This is wrapped in a transaction so if a failure occurs an error will
 * be logged to watchdog which is viewable in the drupal administrative 
 * interface.
 *
 * @param $table
 *    Production table that will eventually hold the imported data
 * @param $tmp_table
 *    Temporary table that will be used for initial import and review
 * @param $file
 *    File pointer for uploaded csv file
 * @param $map
 *    Associative array containing the field map chosen by the user in step 2
 *    Key is position in the file
 *    Value is column name
 * @return $error
 *    If all goes well, this will be empty, if there are errors, it will
 *    contain an array witht he line numbers and the error. 
 */
if (!function_exists('csvupload_csvimport')) {
  function csvupload_csvimport($table, $tmp_table, $file, $map) {
      $dbh = Database::getConnection('bamp_new','default');

      //Array to hold error messages.
      $error = array();

      //Load the CSV
      $data = csvupload_csv2aa($file, ',');

      //Get the number of lines in the CSV File minus the header row
      $lines = (count($data) -1);
      
      //Create insert array
      $row = array();
      $warnings = array();
      foreach ($data as $line => $coldata) {
        if ($line != 0) {
          foreach ($coldata as $k => $v) {
            if ($map[$k]['colname'] != 'sk') {
              $row[$line][$map[$k]['colname']] =$v;
            }
          }
        }
      }//end foreach

      //Loop over the insert array and save to database
      foreach ($row as $line => $data1) {
        $test_type = csvupload_checkColType($tmp_table, $data1);
        if ($test_type['check'] !== FALSE) {
          $dbh->insert($tmp_table)->fields($data1)->execute();
        }
        else {
          $error[$line] = $test_type;
        }
      }
      return $error;
  }//end csvupload_csvimport();
}

if (!function_exists('csvupload_array2table')) {
  function csvupload_array2table($array) {
    if (is_array($array)) {
      foreach ($array as $k => $row) {
        foreach ($row as $head => $v) {
          $header[] = $head;
        }
        break;
      }

      foreach ($array as $k => $row) {
        $rows[$k] = $row;
      }

      $vars['header'] = $header;
      $vars['empty'] = 'Empty List - No Entries';
      $vars['rows'] = $rows;
 
      $render_array['table'] = array(
        '#theme' => 'table',
        '#rows' => $rows,    
        '#empty' => 'Empty List - No Entries',
        '#header' => $header,
      );
 
      $render_array['pager'] = array(
        '#theme' => 'pager',
      );    
      return $render_array;
    }
    return FALSE;
  }//end csvupload_array2table();
}

if (!function_exists('csvupload_checkColType')) {
  function csvupload_checkColType($table, $data) {
    $dbh = Database::getConnection('bamp_new','default');

    //Get the field definitions from the database
    $fields = $dbh->query('SHOW columns FROM ' . $table)->fetchAll();

    //Loop over field definitions and check to see if data is proper type
    foreach ($fields as $fd) {
      //Check if the field exists in the data
      if (array_key_exists($fd->field, $data)) {
        //Get the actual value
        $var = $data[$fd->field];

        //field type is in datatype(length) format, split that apart
        $type = explode('(', $fd->type);
        
        error_log('type: '.var_export($type, true));

        $d_type = $type[0];
        switch ($d_type) {
          case 'int':
            if(isset($type[1])){
              $length = substr($type[1], 0, -1);
              if (!is_int($var) && strlen($var) > $length) {
                $error = t('Error: Value is not an integer or is longer than the allowed length for this field.');
              }//end if
            }//end if
            break;

          case 'float':
            break;

          case 'char':
          case 'varchar':
            if(isset($type[1])){
              $length = substr($type[1], 0, -1);
              if (!is_string($var) && strlen($var) > $length) {
                $error = t('Error: Value is not a valid char/varchar or is longer than the allowed length for this field.');
              }//end if
            }//end if
            break;
          
          case 'timestamp':
            //hmmmmmmm.....how to handle this :)
            break;
        }
      }
    }
    return (empty($error)) ? TRUE : $error;
  }//end csvupload_checkColType();
}
