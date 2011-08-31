<?php

// $Id: dlLookup.php

$databaseName = "bamp_new";
$table = array( 1 => array('bamp_farm_sites'),
                2 => array('bamp_wild_sites')
              );

/**
 * @file
 * Performs the database search for results in a selection box
 */

// shift off the first argument
array_shift($argv);
// if we have a sub-range
if ($argc == 4){
  dbLookup($argv[0], $argv[1], $argv[2], $argv[3]);
}
// otherwise use the entire globe
else {
  dbLookup(-90.0, 90.0, -180.0, 180.0);
}

function dbLookup($latMin, $latMax, $lonMin, $lonMax){
  global $databaseName;//, $tableNames;

  $dbh = Database::getConnection($databaseName, 'default');
  /// @todo Make this general/parameterized
  $qry = "SELECT * FROM bamp_wild_sites WHERE latitide_avg >= " . $latMin .
  " AND latitude_avg <= " . $latMax . " AND longitude_avg >= " . $lonMin .
  " AND longitude_avg <= " . $lonMin . ";";

  // for multi-table searches: compose the query  in pieces
//  foreach ($tableNames as &$table){
//    $qry .= 
//  }

  $result = $dbh->query($qry);
  return $result->fetch_assoc();
//  $return_array = array();

//  while ($record = $result->fetch_assoc()){
//    // just compose the list?
//    array_push($return_array, );
//  }
}
