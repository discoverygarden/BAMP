<?php
/***********************************************************************
*Temporary file to return data from the server. This should be integrated
*into the .module file and use the drupal mysql functions.
************************************************************************/
require_once('dataHandler.class.php');
require_once('config.php');
$dbh = mysql_connect($config['db']['host'],$config['db']['user'],$config['db']['pass']);
switch($_REQUEST['type']){
  //Get marker data for when page is first loaded.
  //Seperated so we can remove tooltips etc if there are performance issues with showing ALL markers.
  case 'wild_site_markers':
    $dh = new dataHandler();
    $data = $dh->getData();
    echo json_encode($data);
  break;

  //Drop down list in the add filter dialog
  case 'filterFields':
      $query = "SELECT column_name, column_comment,data_type, table_name ";
      $query.= "FROM information_schema.columns ";
      //The two tables that make up our view
      $query.= "WHERE table_name IN ('bamp_wild_sampling_instances','bamp_wild_lice_details') ";
      //Fields to exclude as filters
      $query.= "AND column_name NOT IN ('id','changelog','trip_id','year_rep_route_site','comments','site_number','fish','route','tissue_damage', 'latitude','longitude', 'date', 'waypoint', 'trip_date','latitude_rec','latitude_calc','longitude_rec','longitude_calc', 'fish_id','lice_id','crew','search_time', 'salinity_0_2','salinity_1','salinity_5','salinity_refract','salinity_depth_not_specified','temperature_0_2','temperature_1','temperature_5','temperature_rec','temperature_depth_not_specified','weather_comments', 'distance','trip','trip_time','tsb','trip_set_id')";
      $result = mysql_query($query, $dbh) or die(mysql_error($dbh));

      while($row = mysql_fetch_assoc($result)){
        switch($row['table_name']){
          case 'bamp_wild_sampling_instances':
            $tableName = 'si';
            $tableNameStr = 'Sampling Instances';
          break;
          case 'bamp_wild_lice_details':
            $tableName = 'ld';
            $tableNameStr = 'Lice Details';
          break;
        }//end switch
        $columns[] = array('field'=>$tableNameStr.': '.$row['column_comment'], 'fieldId'=>$tableName.'_'.$row['column_name']);
      }//end while
      echo json_encode($columns);
  break;

  //Process custom filters and return markers
  case 'customFilter':
    $dh = new dataHandler();
    $data = $dh->getData(json_decode($_REQUEST['customFilters']), json_decode($_REQUEST['polygonPoints']));
    echo json_encode($data);
  break;

  //Save selection data
  case 'saveSelection':
    $dh = new dataHandler();
    $selectionId = $dh->savePolygonSelection($HTTP_RAW_POST_DATA);
    echo $selectionId;
  break;

  //Load selection data
  case 'loadSelections':
    $dh = new dataHandler();
    $selections = $dh->getSelections();
    echo $selections;
  break;

  //Get selection data points
  case 'getSelectionPoints':
    $dh = new dataHandler();
    $points = $dh->getSelectionPoints($_POST['id']);
    echo $points;
  break;
  default: 
    echo 'Error no type specified';
  break;
}//end switch
?>
