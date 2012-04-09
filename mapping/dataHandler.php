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
    $data = $dh->getData(json_decode($_POST['customFilters']), json_decode($_POST['polygonPoints']));
    echo json_encode($data);
  break;
  case 'saveSelection':
    $dh = new dataHandler();
    $selectionId = $dh->savePolygonSelection($HTTP_RAW_POST_DATA);
    echo $selectionId;
  break;
  case 'loadSelections':
    $dh = new dataHandler();
    $selections = $dh->getSelections();
    echo $selections;
  break;
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

<?
class dataHandler {
  private $dbh = null;//DB Handle
  private $tables = null;//tables included in query(tables array k=>tablename)
  private $tableAlias = null;//table alias array (tablename=>alias)
  private $values = null;//values included in query
  private $vertices_x = array(); // x-coordinates of the vertices of the polygon
  private $vertices_y = array(); // y-coordinates of the vertices of the polygon
  private $vertices = array();
  private $points_polygon = 0; // number vertices
  private $points = array();//All points contained here.

  public function __construct(){
    $this->dbh = mysql_connect('localhost','root','q$%^az');
  }//end construct()

  public function getData($filters, $selection){
    if(!empty($filters)){
      $this->parseFilters($filters);
    }//end if
    if(!empty($selection)){
      $this->parseSelection($selection);
    }//end if
    $query = $this->buildQuery();
    $result = mysql_query($query,$this->dbh) or die(mysql_error($this->dbh));
    $count = 1;
    while($row = mysql_fetch_assoc($result)){
      //Make sure lat/long are unique
      if(in_array(array($row['longitude'], $row['latitude']), $this->points) ){
        $offset = 0.002;
        $row['longitude'] = $row['longitude'] + $offset;
        $row['latitude'] = $row['latitude'] + $offset;
      }else{
        $this->points[] = array($row['longitude'], $row['latitude']);
      }//end if

      $isInside = false;
      //if the selection isn't empty, check if the point is inside. Otherwise exlude it from the results
      if(!empty($selection)){
        $longitude = -1 * abs($row['longitude']);
        $latitude = 1 * abs($row['latitude']);
        $isInside = $this->isWithinBoundary($latitude, $longitude);
      }else{
        $isInside = true;
      }//end if

      if($isInside){
        $markers[] = array(
          'lat' => $row['latitude'],
          'lng' => '-'.abs($row['longitude']),
          'bamp_id' => $row['bamp_id'],
          'fish_count' => $row['fish_count'],
          'marker' => array(
            'icon'=>'sites/default/modules/mapping/images/gmapicons/blue_onwhite/number_'.$row['fish_count'].'.png',
            'shadow'=>'sites/default/modules/mapping/images/gmapicons/shadow.png',
            'zIndex'=>(int)$count,
            'title'=>$row['site_name'],
            'infoWindow'=>array(
              'content'=>
                '<h2> '.$row['site_name'].'</h2><br/>'.
                '<b>Trip Id Number</b> '.$row['trip_id'].'<br/>'.
                '<b>Fish Sampled:</b> '.$row['fish_count'].'<br/>'.
                //'<b>Coordinates:</b> '.$row['latitude'].', -'.$row['longitude'].'<br/><br/>'.
                '<b><a href="?q=bampcrud/crud/wildtrips/modify/'.$row['record_id'].'" target="_BLANK">Click here to edit</a></b> | '.
                '<b><a href="?q=bamp-wild-fish-level-data/'.$row['trip_id'].'" target="_BLANK">View/Edit Fish Data</a></b><br/>'
            )//end array
          )//end array
        );//end array
      }//end if
      $count++;
    }//end while
    return $markers;
  }//end getData

  private function parseFilters($filters){
    //Create internal array for storing filters
    $this->filters = array();

    //Loop through user input and parse into SQL filters.
    foreach($filters as $k=>$filterGroup){
      $filterGroupCount = count($filterGroup);

      if(!empty($filterGroup)){
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
                //Don't both with the join operator if there is only one filter
                if($filterGroupCount > 1){
                  $filtertxt.= ' '.$fv->value.' ';
                }//end if
              break;
            }//end switch
          }//end foreach
        }//end foreach
        $filtertxt.= ') ';
        $this->filters[] = $filtertxt;
      }//end if
    }//end foreach
  }//end parseFilters();

  private function parseSelection($selection){
    foreach($selection as $k=>$point){
      $lng = ($point->lng);
      $this->vertices_x[] = $lng;
      $this->vertices_y[] = $point->lat;
      $this->vertices[] = array('x'=>$point->lat, 'y'=>$lng);
    }//end foreach
    $this->points_polygon = count($this->vertices_x);
  }//end parseSelection();

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

  public function savePolygonSelection($data){
    $data = json_decode($data);
    $query = "INSERT INTO bamp_new.polygons (name) VALUES('".mysql_real_escape_string($data->name,$this->dbh)."')";
    $result = mysql_query($query,$this->dbh) or die(mysql_error($this->dbh));
    $polygonId = mysql_insert_id ($this->dbh);

    $pointCount = 1;
    foreach($data->points as $k=>$v){
      $query = "INSERT INTO bamp_new.polygons_points(polygon_id,point_id, lat, lon) VALUES(".$polygonId.",".$pointCount.",".$v->lat.",".$v->lng.")";
      $result = mysql_query($query,$this->dbh) or die(mysql_error($this->dbh));
      $pointCount++;
    }//end foreach
  }//end savePolygonSelection();

  public function getSelections(){
    $query = "SELECT id, name, date ";
    $query.= "FROM bamp_new.polygons";
    $result = mysql_query($query,$this->dbh) or die(mysql_error($this->dbh));
    $selections = array();
    while($row = mysql_fetch_assoc($result)){
      $query = "SELECT count(*) FROM bamp_new.polygons_points WHERE polygon_id = ".$row['id'];
      $result2 = mysql_query($query,$this->dbh) or die(mysql_error($this->dbh));
      $countRow = mysql_fetch_row($result2);
      if($countRow[0] > 0){
        $selections[] = array('id'=>$row['id'],'name'=>ucwords($row['name']).' ['.$countRow[0].' Points in Polygon. Created '.date("F j, Y ", strtotime($row['date'])).']');
      }//end if
    }//end foreach
    return json_encode($selections);
  }//end getSelections();

  public function getSelectionPoints($id){
    $query = "SELECT lat, lon FROM bamp_new.polygons_points WHERE polygon_id = $id";
    $result = mysql_query($query,$this->dbh) or die(mysql_error($this->dbh));
    $points = array();
    while($row = mysql_fetch_assoc($result)){
      $points[] = array('lat'=>(float)$row['lat'], 'lon'=>(float)$row['lon']);
    }//end while
    return json_encode($points);
  }//end getSelectionPoints();

  //Check to see if a point lies within a polygon selection
  //Use raycasting method: http://en.wikipedia.org/wiki/Point_in_polygon
  function isWithinBoundary($latitude, $longitude){
    $point = array('x'=>$latitude, 'y'=>$longitude);

    $vertices = $this->vertices;

    // Check if the point is inside the polygon or on the boundary
    $intersections = 0;
    $vertices_count = count($vertices);

    for ($i=1; $i < $vertices_count; $i++) {
        $vertex1 = $vertices[$i-1];
        $vertex2 = $vertices[$i];

        if ($vertex1['y'] == $vertex2['y'] and $vertex1['y'] == $point['y'] and $point['x'] > min($vertex1['x'], $vertex2['x']) and $point['x'] < max($vertex1['x'], $vertex2['x'])) { // Check if point is on an horizontal polygon boundary
            $result = TRUE;
        }//end if

        if ($point['y'] > min($vertex1['y'], $vertex2['y']) and $point['y'] <= max($vertex1['y'], $vertex2['y']) and $point['x'] <= max($vertex1['x'], $vertex2['x']) and $vertex1['y'] != $vertex2['y']) { 
            $xinters = ($point['y'] - $vertex1['y']) * ($vertex2['x'] - $vertex1['x']) / ($vertex2['y'] - $vertex1['y']) + $vertex1['x'];
            if ($xinters == $point['x']) { // Check if point is on the polygon boundary (other than horizontal)
                $result = TRUE;
            }//end if

            if ($vertex1['x'] == $vertex2['x'] || $point['x'] <= $xinters) {
                $intersections++;
            }//end if
        }//end if

    }//end for

    // If the number of edges we passed through is even, then it's in the polygon. 
    if ($intersections % 2 != 0) {
        $result = TRUE;
    } else {
        $result = FALSE;
    }//end if
    return $result;
  }//end isWithinBoundary();
}//end dataHandler class
?>
