#!/usr/bin/php
<?
$dbh = mysql_connect('localhost','root','q$%^az');
$tables = array('fs'=>'bamp_wild_fish_samples','si'=>'bamp_wild_sampling_instances', 'ld'=>'bamp_wild_lice_details');

echo 'CREATE VIEW bamp_wild_view AS '."\r\n";
echo "SELECT \r\n";
foreach($tables as $prefix=>$table){
  $result = mysql_query("SHOW COLUMNS FROM bamp_new.$table");
  echo '#TABLE - '.$table."\r\n";
  while ($row = mysql_fetch_assoc($result)) {
    echo $prefix . '.' . $row['Field'] . ' as ' . $prefix . '_' . $row['Field'] . ', ';
  }//end while
  echo "\r\n\r\n";
}//end foreach
echo "FROM bamp_wild_sampling_instances si \r\n";
echo "INNER JOIN bamp_wild_fish_samples fs ON si.trip_set_id = fs.trip_set_id ";
echo "INNER JOIN bamp_wild_lice_details ld ON fs.fish_id = ld.fish_id ";
?>
