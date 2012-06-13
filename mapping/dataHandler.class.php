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
  private $crudUrl = '';//Url to crud forms
  private $fishSamplesUrl = '';//Wild Fish Samples View Report URL
  private $markerImagesUrl = '';//Marker images URL
  private $dbName = '';

  public function __construct(){
    require('config.php');
    $this->dbh = mysql_connect($config['db']['host'],$config['db']['user'],$config['db']['pass']);
    $this->dbName = $config['db']['name'];
    $this->crudUrl = $config['paths']['crudUrl'];
    $this->fishSamplesUrl = $config['paths']['fishSamplesUrl'];
    $this->markerImagesUrl = $config['paths']['markerImagesUrl'];
  }//end construct()

  public function getFarmSites(){
    $query = "SELECT id, site_name, company, latitude, longitude FROM ".$this->dbName.".bamp_farm_sites";
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
            'icon'=>$this->markerImagesUrl.'/farm.png',
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

    //Initialize variables
    $markers = array();
    $farmSites = array();
    $counts = array('totalFish'=>0, 'totalTrips'=>0);

    //Loop through records
    while($row = mysql_fetch_assoc($result)){
      //Check to see if coordinates are already present. If they are, slightly offset so the markers don't touch.
      $latitude = $row['latitude'];
      $longitude = $row['longitude'];
      if(in_array(array($row['latitude'], $row['longitude']), $this->points)){
        $row['latitude'] = $row['latitude'] + 0.002;
        $row['longitude'] = $row['longitude'] + 0.002;
      }//
      $this->points[] = array($row['latitude'], $row['longitude']);

      //Check to see if the marker is inside the polygon selection if it's defined
      $isInside = false;
      if(!empty($selection)){
        $longitude = -1 * abs($row['longitude']);
        $latitude = 1 * abs($row['latitude']);
        $isInside = $this->isWithinBoundary($latitude, $longitude);
      }else{
        $isInside = true;
      }//end if

      //If the marker is inside the selection or the selection is not defined add it to the markers array
      if($isInside){
        //Set the marker color
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
        
        //Set the marker shape (represents group);
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

      //Counters
      $fishCount = (int)$row['si_pink_captured'] + (int)$row['si_chum_captured'];
      $counts['totalFish'] += $fishCount;
      $counts['totalTrips']++; 
      
      //Create the content for the marker tooltip
      $markerContent = '<table cellpadding="2" cellspacing="1">';
      $markerContent.= '<tr><th>Site Name</th><td colspan="2">'.ucwords($row['site_name']).'</td></tr>';
      $markerContent.= '<tr><th>Trip Date</th><td colspan="2">'.date('n/j/Y',strtotime($row['date'])).'</td></tr>';
      $markerContent.= '<tr><th colspan="3"></th></tr>';
      $markerContent.= '<tr><th>Fish Counts</th><th>Captured</th><th>Retained</th></tr>';
      $markerContent.= '<tr><td>Pink</td><td>'.$row['si_pink_captured'].'</td><td>'.$row['si_pink_retained'].'</td></tr>';
      $markerContent.= '<tr><td>Chum</td><td>'.$row['si_chum_captured'].'</td><td>'.$row['si_chum_retained'].'</td></tr>';
      $markerContent.= '<tr><th colspan="3"></th></tr>';
      $markerContent.= '<tr><td colspan="2"><a href="'.$this->crudUrl.'/wildsamplinginstances/modify/'.$row['record_id'].'" target="_BLANK">Edit Sampling Instance</a></td>';
      $markerContent.= '<td><a href="'.$this->fishSamplesUrl.'/'.$row['trip_id'].'" target="_BLANK">View Fish Samples</a></td></tr>';
      $markerContent.= '</table>';

      //Create the marker definition
      $markers[] = array(
          'lat' => $row['latitude'],
          'lng' => '-'.abs($row['longitude']),
          'bamp_id' => $row['bamp_id'],
          'fish_count' => $fishCount,
          'marker' => array(
            'icon'=>$this->markerImagesUrl.'/'.$shape.'/'.$icon.'.png',
            'title'=>ucwords($row['site_name']),
            'infoWindow'=>array(
              'content'=>$markerContent
            )//end array
          )//end array
        );//end array
      }//end if
    }//end while

    //Include the farm sites
    $farmSites = $this->getFarmSites();

    //Combine data into data array
    $data = array('counts'=>$counts, 'markers'=>$markers, 'farms'=>$farmSites);

    //Return the data
    return $data;
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

  public function getCsvData($filters='', $selection='', $type){
    if(!empty($filters)){
      $this->parseFilters($filters);
    }//end if
    if(!empty($selection)){
      $this->parseSelection($selection);
    }//end if
    $query = $this->buildCsvQuery($type);
    $result = mysql_query($query,$this->dbh) or die(mysql_error($this->dbh));

    while($row = mysql_fetch_assoc($result)){
      //Check to see if the marker is inside the polygon selection if it's defined
      $isInside = false;
      if(!empty($selection)){
        $longitude = -1 * abs($row['longitude']);
        $latitude = 1 * abs($row['latitude']);
        $isInside = $this->isWithinBoundary($latitude, $longitude);
      }else{
        $isInside = true;
      }//end if

      if($isInside){
        $exportRows[] = $row;
      }//end if
    }//end while
    return $exportRows;
  }//end getCsvData();

  private function buildQuery(){
    $query = "SELECT si_trip_set_id AS trip_id, si_id AS record_id, si_id as bamp_id, si_trip_date as date, ";
    $query.= "si_bamp_site_name AS site_name, si_latitude AS latitude, si_longitude AS longitude,  si_data_source as data_source, ";
    $query.= "si_pink_captured, si_pink_retained, si_chum_captured, si_chum_retained, ";
    $query.= "COUNT(fs_id) AS fish_count ";
    $query.= "FROM ".$this->dbName.".bamp_wild_view ";
    $query.= "WHERE si_id != '' ";
    if(!empty($this->filters)){
      foreach($this->filters as $value){
        $query.= $value . " ";
      }//end foreach
    }//end if
    $query.= "GROUP BY si_trip_set_id ";
    return $query;
  }//end buildQuery();

  private function buildCsvQuery($type){
    switch($type){
      case 'exportAll':
        $query = "SELECT si_id, si_trip_set_id, si_data_source, si_trip_date, si_trip_year, si_trip_month, si_trip_day, si_bamp_site_number, si_bamp_site_name, si_latitude_rec, si_latitude_calc, si_latitude as latitude, si_longitude_rec, si_longitude_calc, si_longitude as longitude, si_trip_rep, si_route, si_collection_period_eer, si_gear_type, si_zone, si_chum_captured, si_chum_retained, si_chum_examined, si_pink_captured, si_pink_retained, si_pink_examined, si_coho_captured, si_coho_retained, si_coho_examined, si_other_salmon_captured, si_other_salmon_retained, si_other_salmon_examined, si_other_species_captured, si_other_species_retained, si_other_species_examined, si_crew, si_tide, si_search_time, si_salinity_avg, si_salinity_0_2, si_salinity_1, si_salinity_5, si_salinity_refract, si_salinity_depth_not_specified, si_temperature_avg, si_temperature_0_2, si_temperature_1, si_temperature_5, si_temperature_rec, si_temperature_depth_not_specified, si_weather_comments, si_comments, si_changelog, si_set_no, si_site_name_rec, si_site_number_0309, si_site_number_mk, si_waypoint, si_distance, si_blind_no, si_to_lab, si_trip, si_trip_time, si_tsb, si_mortalities,
        fs_id, fs_fish_id, fs_trip_set_id, fs_trip_date, fs_trip_year, fs_trip_month, fs_trip_day, fs_fish_species_per_field, fs_fish_species_gr, fs_fish_species_gr_lab, fs_fish_no, fs_fish_species_per_lab, fs_length_mm, fs_height, fs_weight_g, fs_surface_area, fs_l_cop, fs_l_c1, fs_l_c2, fs_l_c3, fs_l_c4, fs_l_nm_not_stage, fs_l_pam, fs_l_paf, fs_l_pa_not_gender, fs_l_am, fs_l_af, fs_l_gravid, fs_l_adult_not_gender, fs_l_mob_not_stage, fs_c_cop, fs_c_c1, fs_c_c2, fs_c_c3, fs_c_c4, fs_c_nm_not_stage, fs_c_pam, fs_c_paf, fs_c_am, fs_c_af, fs_c_mob_not_stage, fs_c_gravid, fs_total_chal_03, fs_lep_total_mob_03, fs_lep_total, fs_cal_total_mob_03, fs_cal_total, fs_u_cop, fs_u_chal, fs_u_chal_stages_I_and_II, fs_u_chal_stages_III_and_IV, fs_u_mob, fs_lice_total, fs_lesions, fs_comments, fs_changelog, fs_trip, fs_gp_id, fs_lab, fs_date_examined, fs_examined_month, fs_examined_day, fs_examined_year, fs_initials, fs_scar_chal, fs_scar_mot, fs_pred_marks, fs_hem, fs_mate_guarding, fs_pin_belly, fs_lep_total_poo, fs_cal_total_poo, fs_u_total_poo ";
        $query.= "FROM ".$this->dbName.".bamp_wild_view_export ";
        $query.= "WHERE 1=1 ";
        if(!empty($this->filters)){
          foreach($this->filters as $value){
            $query.= $value . " ";
          }//end foreach
        }//end if
        $query.= "GROUP BY si_trip_set_id ";
      break;
      case 'exportFishSamples':
        $query = "SELECT si_trip_set_id, si_latitude as latitude, si_longitude as longitude, fs_id, fs_fish_id, fs_trip_set_id, fs_trip_date, fs_trip_year, fs_trip_month, fs_trip_day, fs_fish_species_per_field, fs_fish_species_gr, fs_fish_species_gr_lab, fs_fish_no, fs_fish_species_per_lab, fs_length_mm, fs_height, fs_weight_g, fs_surface_area, fs_l_cop, fs_l_c1, fs_l_c2, fs_l_c3, fs_l_c4, fs_l_nm_not_stage, fs_l_pam, fs_l_paf, fs_l_pa_not_gender, fs_l_am, fs_l_af, fs_l_gravid, fs_l_adult_not_gender, fs_l_mob_not_stage, fs_c_cop, fs_c_c1, fs_c_c2, fs_c_c3, fs_c_c4, fs_c_nm_not_stage, fs_c_pam, fs_c_paf, fs_c_am, fs_c_af, fs_c_mob_not_stage, fs_c_gravid, fs_total_chal_03, fs_lep_total_mob_03, fs_lep_total, fs_cal_total_mob_03, fs_cal_total, fs_u_cop, fs_u_chal, fs_u_chal_stages_I_and_II, fs_u_chal_stages_III_and_IV, fs_u_mob, fs_lice_total, fs_lesions, fs_comments, fs_changelog, fs_trip, fs_gp_id, fs_lab, fs_date_examined, fs_examined_month, fs_examined_day, fs_examined_year, fs_initials, fs_scar_chal, fs_scar_mot, fs_pred_marks, fs_hem, fs_mate_guarding, fs_pin_belly, fs_lep_total_poo, fs_cal_total_poo, fs_u_total_poo ";
        $query.= "FROM ".$this->dbName.".bamp_wild_view_export ";
        $query.= "WHERE 1=1 ";
        if(!empty($this->filters)){
          foreach($this->filters as $value){
            $query.= $value . " ";
          }//end foreach
        }//end if
        $query.= "GROUP BY si_trip_set_id ";
      break;
      case 'exportSamplingInstances':
        $query = "SELECT si_id, si_trip_set_id, si_data_source, si_trip_date, si_trip_year, si_trip_month, si_trip_day, si_bamp_site_number, si_bamp_site_name, si_latitude_rec, si_latitude_calc, si_latitude as latitude, si_longitude_rec, si_longitude_calc, si_longitude as longitude, si_trip_rep, si_route, si_collection_period_eer, si_gear_type, si_zone, si_chum_captured, si_chum_retained, si_chum_examined, si_pink_captured, si_pink_retained, si_pink_examined, si_coho_captured, si_coho_retained, si_coho_examined, si_other_salmon_captured, si_other_salmon_retained, si_other_salmon_examined, si_other_species_captured, si_other_species_retained, si_other_species_examined, si_crew, si_tide, si_search_time, si_salinity_avg, si_salinity_0_2, si_salinity_1, si_salinity_5, si_salinity_refract, si_salinity_depth_not_specified, si_temperature_avg, si_temperature_0_2, si_temperature_1, si_temperature_5, si_temperature_rec, si_temperature_depth_not_specified, si_weather_comments, si_comments, si_changelog, si_set_no, si_site_name_rec, si_site_number_0309, si_site_number_mk, si_waypoint, si_distance, si_blind_no, si_to_lab, si_trip, si_trip_time, si_tsb, si_mortalities ";
        $query.= "FROM ".$this->dbName.".bamp_wild_view_export ";
        $query.= "WHERE 1=1 ";
        if(!empty($this->filters)){
          foreach($this->filters as $value){
            $query.= $value . " ";
          }//end foreach
        }//end if
        $query.= "GROUP BY si_trip_set_id ";
      break;
    }//end switch();
    return $query;
  }//end buildCsvQuery();

  public function savePolygonSelection($data){
    $data = json_decode($data);
    $query = "INSERT INTO ".$this->dbName.".polygons (name) VALUES('".mysql_real_escape_string($data->name,$this->dbh)."')";
    $result = mysql_query($query,$this->dbh) or die(mysql_error($this->dbh));
    $polygonId = mysql_insert_id ($this->dbh);

    $pointCount = 1;
    foreach($data->points as $k=>$v){
      $query = "INSERT INTO ".$this->dbName.".polygons_points(polygon_id,point_id, lat, lon) VALUES(".$polygonId.",".$pointCount.",".$v->lat.",".$v->lng.")";
      $result = mysql_query($query,$this->dbh) or die(mysql_error($this->dbh));
      $pointCount++;
    }//end foreach
  }//end savePolygonSelection();

  public function getSelections(){
    $query = "SELECT id, name, date ";
    $query.= "FROM ".$this->dbName.".polygons";
    $result = mysql_query($query,$this->dbh) or die(mysql_error($this->dbh));
    $selections = array();
    while($row = mysql_fetch_assoc($result)){
      $query = "SELECT count(*) FROM ".$this->dbName.".polygons_points WHERE polygon_id = ".$row['id'];
      $result2 = mysql_query($query,$this->dbh) or die(mysql_error($this->dbh));
      $countRow = mysql_fetch_row($result2);
      if($countRow[0] > 0){
        $selections[] = array('id'=>$row['id'],'name'=>ucwords($row['name']).' ['.$countRow[0].' Points. Created '.date("n/j/Y", strtotime($row['date'])).']');
      }//end if
    }//end foreach
    return json_encode($selections);
  }//end getSelections();

  public function getSelectionPoints($id){
    $query = "SELECT lat, lon FROM ".$this->dbName.".polygons_points WHERE polygon_id = $id ORDER BY point_id ASC";
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
