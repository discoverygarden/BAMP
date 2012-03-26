<?php
/***********************************************************************
*Temporary file to return data from the server. This should be integrated
*into the .module file and use the drupal mysql functions.
************************************************************************/

$dbh = mysql_connect('localhost','root','q$%^az');
switch($_GET['type']){
  case 'wild_site_markers':
    $colors = array('purple','green','blue','orange','red');
    $query = "SELECT bamp_wild_trips_trip_id AS trip_id, bamp_wild_trips_id AS record_id, bamp_wild_trips_id as bamp_id, ";
    $query.= "bamp_wild_trips_site_name AS site_name, bamp_wild_trips_latitude AS latitude, bamp_wild_trips_longitude AS longitude, ";
    $query.= "COUNT(bamp_wild_fish_data_id) AS fish_count ";
    $query.= "FROM bamp_new.bamp_wild_view ";
    $query.= "GROUP BY bamp_wild_trips_trip_id ";

    $result = mysql_query($query, $dbh) or die(mysql_error($dbh));
    $markers = array();
    while($row = mysql_fetch_assoc($result)){
      $markers[] = array(
        'lat' => $row['latitude'],
        'lng' => '-'.abs($row['longitude']),
        'bamp_id' => $row['bamp_id'],
        'fish_count' => $row['fish_count'],
        'marker' => array(
          'icon'=>'sites/default/modules/mapping/images/gmapicons/blue_onwhite/number_'.$row['fish_count'].'.png',
          'shadow'=>'sites/default/modules/mapping/images/gmapicons/shadow.png',
          'zIndex'=>(int)$row['fish_count'],
          'title'=>$row['site_name'],
          'infoWindow'=>array(
            'content'=>
              '<h2> '.$row['site_name'].'</h2><br/>'.
              //'<b>Trip Id Number</b> '.$row['trip_id'].'<br/>'.
              '<b>Fish Sampled:</b> '.$row['fish_count'].'<br/>'.
              //'<b>Coordinates:</b> '.$row['latitude'].', -'.$row['longitude'].'<br/><br/>'.
              '<b><a href="?q=bampcrud/crud/wildtrips/modify/'.$row['record_id'].'" target="_BLANK">Edit Trip Data</a></b> | '.
              '<b><a href="?q=bamp-wild-fish-level-data/'.$row['trip_id'].'" target="_BLANK">View/Edit Fish Data</a></b><br/>'
          )
        )
      );
    }//end while
    echo json_encode($markers);
  break;
  case 'filterFields':
      $query = "SHOW COLUMNS FROM bamp_new.bamp_wild_view ";
      $result = mysql_query($query, $dbh) or die(mysql_error($dbh));
      while($row = mysql_fetch_assoc($result)){
        $columns[] = array('field'=>$row['Field'], 'fieldId'=>$row['Field'], 'fieldType'=>$row['Type']);
      }//end while
      echo json_encode($columns);
  break;
  case 'customFilter':
    $dh = new dataHandler();
    $data = $dh->getData(json_decode($_POST['customFilters']));
    echo json_encode($data);
  break;
  default: 
    echo 'Error no type specified';
  break;
}//end switch
?>

<?
class dataHandler {
  private $dbh = null;//DB Handle
  private $tables = null;//tables included in query(tables array k=>tablename)
  private $tableAlias = null;//table alias array (tablename=>alias)
  private $values = null;//values included in query

  public function __construct(){
    $this->dbh = mysql_connect('localhost','root','q$%^az');
  }//end construct()

  public function getData($filters){
    if(!empty($filters)){
      $this->parseFilters($filters);
    }//end if
    $query = $this->buildQuery();
    $result = mysql_query($query,$this->dbh) or die(mysql_error($this->dbh));
    //$colors = array('purple','green','blue','orange','red');
    while($row = mysql_fetch_assoc($result)){
      $markers[] = array(
        'lat' => $row['latitude'],
        'lng' => '-'.abs($row['longitude']),
        'bamp_id' => $row['bamp_id'],
        'fish_count' => $row['fish_count'],
        'marker' => array(
          'icon'=>'sites/default/modules/mapping/images/gmapicons/blue_onwhite/number_'.$row['fish_count'].'.png',
          'shadow'=>'sites/default/modules/mapping/images/gmapicons/shadow.png',
          'zIndex'=>(int)$row['fish_count'],
          'title'=>$row['site_name'],
          'infoWindow'=>array(
            'content'=>
              '<h2> '.$row['site_name'].'</h2><br/>'.
              //'<b>Trip Id Number</b> '.$row['trip_id'].'<br/>'.
              '<b>Fish Sampled:</b> '.$row['fish_count'].'<br/>'.
              //'<b>Coordinates:</b> '.$row['latitude'].', -'.$row['longitude'].'<br/><br/>'.
              '<b><a href="?q=bampcrud/crud/wildtrips/modify/'.$row['record_id'].'" target="_BLANK">Click here to edit</a></b> | '.
              '<b><a href="?q=bamp-wild-fish-level-data/'.$row['trip_id'].'" target="_BLANK">View/Edit Fish Data</a></b><br/>'
          )
        )
      );
    }//end while
    return $markers;
  }//end getData

  private function parseFilters($filters){
    $this->filters = array();
    
    foreach($filters as $k=>$filterGroup){
      $filtertxt = 'AND (';
      foreach($filterGroup as $fgk=>$filter){
        foreach($filter->content as $fk=>$fv){
          switch($fv->field){
            case 'column':
              $filtertxt.= $fv->value;
            break;
            case 'operator':
              $filtertxt.= ' '.$fv->value.' ';
            break;
            case 'value':
              $filtertxt.= '"'.mysql_real_escape_string($fv->value, $this->dbh).'" ';
            break;
            case 'join':
              $filtertxt.= ' '.$fv->value.' ';
            break;
          }//end switch
        }//end foreach
      }//end foreach
      $filtertxt.= ') ';
      $this->filters[] = $filtertxt;
    }//end foreach
  }//end parseFilters();

  private function buildQuery(){
    $query = "SELECT bamp_wild_trips_trip_id AS trip_id, bamp_wild_trips_id AS record_id, bamp_wild_trips_id as bamp_id, ";
    $query.= "bamp_wild_trips_site_name AS site_name, bamp_wild_trips_latitude AS latitude, bamp_wild_trips_longitude AS longitude, ";
    $query.= "COUNT(bamp_wild_fish_data_id) AS fish_count ";
    $query.= "FROM bamp_new.bamp_wild_view ";
    $query.= "WHERE bamp_wild_trips_id != '' ";
    if(!empty($this->filters)){
      foreach($this->filters as $value){
        $query.= $value . " ";
      }//end foreach
    }//end if
    $query.= "GROUP BY bamp_wild_trips_trip_id ";
    return $query;
  }//end buildQuery();
}//end dataHandler class
?>
