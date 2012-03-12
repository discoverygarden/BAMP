#!/usr/bin/php
<?
$dbh = mysql_connect('localhost','root','q$%^az');
$tables = array('bamp_wild_lab_results','bamp_wild_trips','bamp_wild_sites','bamp_wild_fish_data');
foreach($tables as $k=>$table){
  $result = mysql_query("SHOW COLUMNS FROM bamp_new.$table");
  echo '#TABLE - '.$table."\r\n";
  while ($row = mysql_fetch_assoc($result)) {
    echo $table . '.' . $row['Field'] . ' as ' . $table . '_' . $row['Field'] . ', ';
  }//end while
  echo "\r\n\r\n";
}//end foreach
?>
