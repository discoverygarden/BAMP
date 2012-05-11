<?php
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

  public function getFarmSites(){
    $query = "SELECT id, site_name, company, latitude, longitude FROM bamp_new.bamp_farm_sites";
    $result = mysql_query($query,$this->dbh) or die(mysql_error($this->dbh));

    $markers = array();
    while($row = mysql_fetch_assoc($result)){
      $markerContent = '<h2> '.ucwords($row['site_name']).' Fish Farm</h2><br/>';
      $markerContent.= '<em>Operated by '.ucwords($row['company']).'</em>';
      $markers[] = array(
          'lat' => $row['latitude'],
          'lng' => '-'.abs($row['longitude']),
          'site_id' => $row['id'],
          'marker' => array(
            'icon'=>'sites/default/modules/mapping/images/gmapicons/farm.png',
            'title'=>ucwords($row['site_name']),
            'infoWindow'=>array(
              'content'=>$markerContent
            )//end array
          )//end array
        );//end array
    }//end while
    return $markers;
  }//end getFarmSites();


  public function getData($filters='', $selection=''){
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
      $latitude = $row['latitude'];
      $longitude = $row['longitude'];
      if(in_array(array($row['latitude'], $row['longitude']), $this->points)){
        $row['latitude'] = $row['latitude'] + 0.002;
        $row['longitude'] = $row['longitude'] + 0.002;
      }//
      $this->points[] = array($row['latitude'], $row['longitude']);

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
        $month = date('m', strtotime($row['date']));
        switch($month){
          case 3:
          case 03:
            $icon = '1';
          break;
          case 4:
          case 04:
            $icon = '2';
          break;
          case 5:
          case 05:
            $icon = '3';
          break;
          case 6:
          case 06:
            $icon = '4';
          break;
          case 7:
          case 07:
            $icon = '5';
          break;
        }//end switch
        switch($row['data_source']){
          case 'MK':
            $shape = 'Circles';
          break;
          case 'DFO':
            $shape = 'Squares';
          break;
          case 'BAMP':
            $shape = 'Triangles';
          break;
        }//end switch

      $fish_count = $row['si_pink_captured'] + $row['si_chum_captured'];
      //$markerContent = '<h2> '.ucwords($row['site_name']).'</h2><br/>';
      //$markerContent.= '<b>Trip Id Number</b> '.$row['trip_id'].'<br/>';
      //$markerContent.= '<b>Trip Date:</b> '.date('n/j/Y',strtotime($row['date'])).'<br/>';
      $markerContent = '<table cellpadding="2" cellspacing="1">';
      $markerContent.= '<tr><th>Site Name</th><td colspan="2">'.ucwords($row['site_name']).'</td></tr>';
      $markerContent.= '<tr><th>Trip Date</th><td colspan="2">'.date('n/j/Y',strtotime($row['date'])).'</td></tr>';
      $markerContent.= '<tr><th colspan="3"></th></tr>';
      $markerContent.= '<tr><th>Fish Counts</th><th>Captured</th><th>Retained</th></tr>';
      $markerContent.= '<tr><td>Pink</td><td>'.$row['si_pink_captured'].'</td><td>'.$row['si_pink_retained'].'</td></tr>';
      $markerContent.= '<tr><td>Chum</td><td>'.$row['si_chum_captured'].'</td><td>'.$row['si_chum_retained'].'</td></tr>';
      $markerContent.= '<tr><th colspan="3"></th></tr>';
      $markerContent.= '<tr><td colspan="2"><a href="?q=bampcrud/crud/wildtrips/modify/'.$row['record_id'].'" target="_BLANK">Edit Sampling Instance</a></td>';
      $markerContent.= '<td><a href="?q=bamp-wild-fish-level-data/'.$row['trip_id'].'" target="_BLANK">View Fish Samples</a></td></tr>';
      $markerContent.= '</table>';
      $markers[] = array(
          'lat' => $row['latitude'],
          'lng' => '-'.abs($row['longitude']),
          'bamp_id' => $row['bamp_id'],
          'fish_count' => $fish_count,
          'marker' => array(
            'icon'=>'sites/default/modules/mapping/images/gmapicons/'.$shape.'/'.$icon.'.png',
            'title'=>ucwords($row['site_name']),
            'infoWindow'=>array(
              'content'=>$markerContent
            )//end array
          )//end array
        );//end array
      }//end if
      $count++;
    }//end while

    //Include the farm sites
    $farm_sites = $this->getFarmSites();
    $markers = array_merge($markers,$farm_sites);

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

  public function getCsvData($filters='', $selection=''){
    if(!empty($filters)){
      $this->parseFilters($filters);
    }//end if
    if(!empty($selection)){
      $this->parseSelection($selection);
    }//end if
    $query = $this->buildCsvQuery();
    $result = mysql_query($query,$this->dbh) or die(mysql_error($this->dbh));

    return $result;
  }//end getCsvData();

  private function buildQuery(){
    $query = "SELECT si_trip_set_id AS trip_id, si_id AS record_id, si_id as bamp_id, si_trip_date as date, ";
    $query.= "si_bamp_site_name AS site_name, si_latitude AS latitude, si_longitude AS longitude,  si_data_source as data_source, ";
    $query.= "si_pink_captured, si_pink_retained, si_chum_captured, si_chum_retained, ";
    $query.= "COUNT(fs_id) AS fish_count ";
    $query.= "FROM bamp_new.bamp_wild_view ";
    $query.= "WHERE si_id != '' ";
    if(!empty($this->filters)){
      foreach($this->filters as $value){
        $query.= $value . " ";
      }//end foreach
    }//end if
    $query.= "GROUP BY si_trip_set_id ";
    return $query;
  }//end buildQuery();

  private function buildCsvQuery(){
    $query = "SELECT * ";
    $query.= "FROM bamp_new.bamp_wild_view ";
    $query.= "WHERE si_trip_set_id != '' ";
    if(!empty($this->filters)){
      foreach($this->filters as $value){
        $query.= $value . " ";
      }//end foreach
    }//end if
    //$query.= "GROUP BY bamp_wild_trips_trip_id ";
    return $query;
  }//end buildCsvQuery();

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
        $selections[] = array('id'=>$row['id'],'name'=>ucwords($row['name']).' ['.$countRow[0].' Points. Created '.date("n/j/Y", strtotime($row['date'])).']');
      }//end if
    }//end foreach
    return json_encode($selections);
  }//end getSelections();

  public function getSelectionPoints($id){
    $query = "SELECT lat, lon FROM bamp_new.polygons_points WHERE polygon_id = $id ORDER BY point_id ASC";
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
    $vertices[] = $vertices[0];

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
