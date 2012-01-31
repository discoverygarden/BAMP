<?php
$dbh = mysql_connect('localhost','root','q$%^az');
switch($_GET['type']){
  case 'wild_site_markers':
    $query = "SELECT s.site_name, s.latitude, s.longitude ";
    $query.= "FROM bamp_new.bamp_wild_sites s ";
    $result = mysql_query($query, $dbh) or die(mysql_error($dbh));
    $markers = array();
    while($row = mysql_fetch_assoc($result)){
      $markers[] = array('lat' => $row['latitude'], 'lng' => $row['longitude'], 'marker' => array('title'=>$row['site_name']));
    }//end while
    echo json_encode($markers);
  break;
  case 'filterFields':
    if(!empty($_GET['filter'])){;
      $filters = json_decode($_GET['filter']);
      $table = $filters[0]->value;
      $columns = array();
      if(!empty($table)){
        $query = "SHOW COLUMNS FROM bamp_new.".$table." ";
        $result = mysql_query($query, $dbh) or die(mysql_error($dbh));
        while($row = mysql_fetch_assoc($result)){
          $columns[] = array('field'=>$row['Field'], 'fieldId'=>$row['Field'], 'fieldType'=>$row['Type']);
        }//end while
      }//end if
      echo json_encode($columns);
    }//end if
  break;
  case 'customFilter':
    $filters = json_decode($_POST['customFilters']);
    $tables = array();
    $values = array();
    foreach($filters as $k=>$filter){
      if(!in_array($filter->table, $tables)){
        $tables[] = $filter->table;
        $tablesStr = $filter->table.", ";
      }
      $values[] = $filter->table . '.' . $filter->field . ' ' . $filter->operator . ' "' . $filter->value . '"';
    }//end foreach

    $query = "SELECT s.site_name, s.latitude, s.longitude ";
    //$query.= "FROM ".substr($tablesStr);

    //todo: dynamically build query based on filters above.
    //For testing, limit query to 5 and pass back for map refresh
    $query = "SELECT s.site_name, s.latitude, s.longitude ";
    $query.= "FROM bamp_new.bamp_wild_sites s ";
    $query.= "LIMIT 0,5";
    $result = mysql_query($query, $dbh) or die(mysql_error($dbh));
    $markers = array();
    while($row = mysql_fetch_assoc($result)){
      $markers[] = array('lat' => $row['latitude'], 'lng' => $row['longitude'], 'marker' => array('title'=>$row['site_name']));
    }//end while
    echo json_encode($markers);
  break;
  default: 
    echo 'Error no type specified';
  break;
}//end switch
?>
