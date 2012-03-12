<?
function ireport_views_data(){
  $data = array();
  $data['bamp_farm_aggregate']['table'] = array('group' =>'BAMP-Farm-Aggregate', 'title'=>'Bamp Farm Aggregate Data', 'help' => 'bamp_farm_aggregate');
  $data['bamp_farm_aggregate']['table']['base'] = array(
    'field' => 'id',
    'title' => t('BAMP Farm - Aggregate Data'),
    'help' => t('Contains aggregate information from BAMP farms.'),
    'database' => 'bamp_new',
    'weight' => -10,
  );
  $data['bamp_farm_aggregate']['id'] = array(
    'title' => t('id'),
    'help' => t('Internal database record ID. Auto-Incrementing. Do not import to this field.'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_aggregate']['year'] = array(
    'title' => t('year'),
    'help' => t('Year'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_aggregate']['month'] = array(
    'title' => t('month'),
    'help' => t('Month'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_aggregate']['dfo_zone'] = array(
    'title' => t('dfo_zone'),
    'help' => t('DFO Zone'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_aggregate']['dfo_subzone'] = array(
    'title' => t('dfo_subzone'),
    'help' => t('DFO SubZone'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_aggregate']['site_name'] = array(
    'title' => t('site_name'),
    'help' => t('Site Name'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_aggregate']['no_counts_reason'] = array(
    'title' => t('no_counts_reason'),
    'help' => t('Reason for no count'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_aggregate']['date_sampled'] = array(
    'title' => t('date_sampled'),
    'help' => t('Sampling Date'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_aggregate']['pen'] = array(
    'title' => t('pen'),
    'help' => t('Pen Number'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_aggregate']['sample_method'] = array(
    'title' => t('sample_method'),
    'help' => t('Sampling method'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_aggregate']['number_sampled'] = array(
    'title' => t('number_sampled'),
    'help' => t('Number sampled'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_aggregate']['adult_females'] = array(
    'title' => t('adult_females'),
    'help' => t('Adult Females'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_aggregate']['motile'] = array(
    'title' => t('motile'),
    'help' => t('Motile'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_aggregate']['chalimus'] = array(
    'title' => t('chalimus'),
    'help' => t('Chalimus'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_aggregate']['caligus'] = array(
    'title' => t('caligus'),
    'help' => t('Caligus'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_aggregate']['action_taken'] = array(
    'title' => t('action_taken'),
    'help' => t(''),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['bamp_farm_environment']['table'] = array('group' =>'BAMP-Farm-Environment', 'title'=>'BAMP Farm Environmental Information', 'help' => 'bamp_farm_environment');
  $data['bamp_farm_environment']['table']['base'] = array(
    'field' => 'id',
    'title' => t('BAMP Farm - Environment Data'),
    'help' => t('Contains environmental data from BAMP sites'),
    'database' => 'bamp_new',
    'weight' => -10, 
  );

  $data['bamp_farm_environment']['id'] = array(
    'title' => t('id'),
    'help' => t('Internal database record ID. Auto-Incrementing. Do not import to this field.'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_environment']['year'] = array(
    'title' => t('year'),
    'help' => t(''),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_environment']['month'] = array(
    'title' => t('month'),
    'help' => t('Month of collection'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_environment']['dfo_zone'] = array(
    'title' => t('dfo_zone'),
    'help' => t('DFO Zone'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_environment']['dfo_subzone'] = array(
    'title' => t('dfo_subzone'),
    'help' => t('DFO SubZone'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_environment']['site_name'] = array(
    'title' => t('site_name'),
    'help' => t('Site Name'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_environment']['facility_type'] = array(
    'title' => t('facility_type'),
    'help' => t('Facility Type'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_environment']['no_sample_reason'] = array(
    'title' => t('no_sample_reason'),
    'help' => t('Reason no sample was taken'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_environment']['sampling_date'] = array(
    'title' => t('sampling_date'),
    'help' => t('Date Sample was taken'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_environment']['temperature_0_1'] = array(
    'title' => t('temperature_0_1'),
    'help' => t('Temperature between 0-1m'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_environment']['temperature_5'] = array(
    'title' => t('temperature_5'),
    'help' => t('Temperature at 5m'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_environment']['do_0_1'] = array(
    'title' => t('do_0_1'),
    'help' => t('Dissolved Oxygen between 0-1m'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_environment']['do_5'] = array(
    'title' => t('do_5'),
    'help' => t('Dissolved Oxygen at 5m'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_environment']['salinity_0_1'] = array(
    'title' => t('salinity_0_1'),
    'help' => t('Salinity between 0-1m'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_environment']['salinity_5'] = array(
    'title' => t('salinity_5'),
    'help' => t('Salinity at 5m'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['bamp_farm_fish_data']['table'] = array('group' =>'BAMP-Farm-Fish-Data', 'title'=>'BAMP Farm Fish Level', 'help' => 'bamp_farm_fish_data');
  $data['bamp_farm_fish_data']['table']['base'] = array(
    'field' => 'id',
    'title' => t('BAMP Farm - Fish Level Data'),
    'help' => t('Contains Fish Level information from BAMP farms.'),
    'database' => 'bamp_new',
    'weight' => -10, 
  );  


  $data['bamp_farm_fish_data']['id'] = array(
    'title' => t('id'),
    'help' => t('Internal database record ID. Auto-Incrementing. Do not import to this field.'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_fish_data']['site_name'] = array(
    'title' => t('site_name'),
    'help' => t('Site Name'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_fish_data']['date'] = array(
    'title' => t('date'),
    'help' => t('Date of collection'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  );
  $data['bamp_farm_fish_data']['counted by'] = array(
    'title' => t('counted by'),
    'help' => t('Counted By'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_fish_data']['fish_sampled'] = array(
    'title' => t('fish_sampled'),
    'help' => t('Number of Fish Sampled'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_fish_data']['sample_method'] = array(
    'title' => t('sample_method'),
    'help' => t('Sampling Method'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_fish_data']['pen'] = array(
    'title' => t('pen'),
    'help' => t('Pen Number'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_fish_data']['fish_number'] = array(
    'title' => t('fish_number'),
    'help' => t('Fish Number (in set)'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_fish_data']['size'] = array(
    'title' => t('size'),
    'help' => t('Size '),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_fish_data']['chalimus'] = array(
    'title' => t('chalimus'),
    'help' => t('Chalimus'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_fish_data']['pre-adult'] = array(
    'title' => t('pre-adult'),
    'help' => t('Pre-Adult'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_fish_data']['male'] = array(
    'title' => t('male'),
    'help' => t('Male'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_fish_data']['female'] = array(
    'title' => t('female'),
    'help' => t('Female'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_fish_data']['gravid'] = array(
    'title' => t('gravid'),
    'help' => t('Gravid'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_fish_data']['caligus'] = array(
    'title' => t('caligus'),
    'help' => t('Caligus'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_fish_data']['total_motile'] = array(
    'title' => t('total_motile'),
    'help' => t('Total Motile'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_fish_data']['comments'] = array(
    'title' => t('comments'),
    'help' => t('Additional Comments'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['bamp_farm_inventory']['table'] = array('group' =>'BAMP-Farm-Inventory', 'title'=>'BAMP Farm Inventory', 'help' => 'bamp_farm_inventory');
  $data['bamp_farm_inventory']['table']['base'] = array(
    'field' => 'id',
    'title' => t('BAMP Farm - Inventory'),
    'help' => t('Contains Inventory information from BAMP farms.'),
    'database' => 'bamp_new',
    'weight' => -10, 
  );

  $data['bamp_farm_inventory']['id'] = array(
    'title' => t('id'),
    'help' => t('Internal database record ID. Auto-Incrementing. Do not import to this field.'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_inventory']['year'] = array(
    'title' => t('year'),
    'help' => t('Year'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_inventory']['quarter'] = array(
    'title' => t('quarter'),
    'help' => t('Quarter'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_inventory']['month'] = array(
    'title' => t('month'),
    'help' => t('Month'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_inventory']['dfo_zone'] = array(
    'title' => t('dfo_zone'),
    'help' => t('DFO Zone'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_inventory']['dfo_subzone'] = array(
    'title' => t('dfo_subzone'),
    'help' => t('DFO SubZone'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_inventory']['site_name'] = array(
    'title' => t('site_name'),
    'help' => t('Site Name'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_inventory']['fish_group_name'] = array(
    'title' => t('fish_group_name'),
    'help' => t('Fish Group Name'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_inventory']['fish_group_id'] = array(
    'title' => t('fish_group_id'),
    'help' => t('Fish Group ID'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_inventory']['inventory_balance_fish_in'] = array(
    'title' => t('inventory_balance_fish_in'),
    'help' => t('Inventory Balance Fish In'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_inventory']['inventory_balance_inventory_start'] = array(
    'title' => t('inventory_balance_inventory_start'),
    'help' => t('Inventory Balance Inventory Start'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_inventory']['species'] = array(
    'title' => t('species'),
    'help' => t('Species'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_inventory']['species_group_name'] = array(
    'title' => t('species_group_name'),
    'help' => t('Species Group Name'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_inventory']['freshwater_yearclass'] = array(
    'title' => t('freshwater_yearclass'),
    'help' => t('Freshwater Year Class'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_inventory']['fish_group_sw_entry_date'] = array(
    'title' => t('fish_group_sw_entry_date'),
    'help' => t('Fish Group Software Entry Date'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );


  $data['bamp_farm_sites']['table'] = array('group' =>'BAMP-Farm-Sites', 'title'=>'BAMP Farm Sites', 'help' => 'bamp_farm_sites');
  $data['bamp_farm_sites']['table']['base'] = array(
    'field' => 'id',
    'title' => t('BAMP Farm - Sites'),
    'help' => t('Contains BAMP farm sites. All farm tables are linked to sites.'),
    'database' => 'bamp_new',
    'weight' => -10,
  );

  $data['bamp_farm_sites']['id'] = array(
    'title' => t('id'),
    'help' => t('Internal database record ID. Auto-Incrementing. Do not import to this field.'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_farm_sites']['site_name'] = array(
    'title' => t('site_name'),
    'help' => t('The site name'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_sites']['company'] = array(
    'title' => t('company'),
    'help' => t('Site managing company'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_sites']['latitude'] = array(
    'title' => t('latitude'),
    'help' => t('The latitude of the site location'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_sites']['longitude'] = array(
    'title' => t('longitude'),
    'help' => t('The longitude of the site location'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_farm_sites']['management_sub_area'] = array(
    'title' => t('management_sub_area'),
    'help' => t('Management Sub Area'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['bamp_wild_fish_data']['table'] = array('group' =>'BAMP-Wild-Fish-Data', 'title'=>'BAMP Wild Fish Data', 'help' => 'bamp_wild_fish_data');
  $data['bamp_wild_fish_data']['table']['base'] = array(
    'field' => 'id',
    'title' => t('BAMP Wild - Fish Level Data'),
    'help' => t('Contains fish level data from wild trips.'),
    'database' => 'bamp_new',
    'weight' => -10, 
  );

  $data['bamp_wild_fish_data']['id'] = array(
    'title' => t('id'),
    'help' => t('Internal database record ID. Auto-Incrementing. Do not import to this field.'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_fish_data']['trip_id'] = array(
    'title' => t('Trip ID'),
    'help' => t('Trip ID'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),   
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),   
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['year'] = array(
    'title' => t('year'),
    'help' => t('The year of the data'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_fish_data']['rep'] = array(
    'title' => t('rep'),
    'help' => t('The within-year replicate number of the survey of migration routes'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_fish_data']['route'] = array(
    'title' => t('route'),
    'help' => t('Migration Route'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['site_number'] = array(
    'title' => t('site_number'),
    'help' => t('The number of the site along the migration route'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['fish'] = array(
    'title' => t('fish'),
    'help' => t('Fish'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_fish_data']['species'] = array(
    'title' => t('species'),
    'help' => t('The species of fish (1 = pink, 2 = chum)'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_fish_data']['length'] = array(
    'title' => t('length'),
    'help' => t('Fork length of the fish (mm)'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_fish_data']['height'] = array(
    'title' => t('height'),
    'help' => t('Body depth of the fish (mm)'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['lep_cop'] = array(
    'title' => t('lep_cop'),
    'help' => t('Number of L. salmonis copepodites on the fish'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['cal_cop'] = array(
    'title' => t('cal_cop'),
    'help' => t('Number of C. clemensi copepodites on the fish'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['chal_a'] = array(
    'title' => t('chal_a'),
    'help' => t('Number of chalimus stage 1/2 lice on a fish (species of lice not identified)'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['chal_b'] = array(
    'title' => t('chal_b'),
    'help' => t('Number of chalimus stage 3/4 lice on a fish (species of lice not identified)'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['mot_unid'] = array(
    'title' => t('mot_unid'),
    'help' => t('Number of unidentified motile stage lice on the fish'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['lep_pre_male'] = array(
    'title' => t('lep_pre_male'),
    'help' => t('Number of L. salmonis preadult male lice on the fish'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['lep_pre_female'] = array(
    'title' => t('lep_pre_female'),
    'help' => t('Number of L. salmonis preadult female lice on the fish'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['lep_pre_unid'] = array(
    'title' => t('lep_pre_unid'),
    'help' => t('Number of L. salmonis preadult lice on the fish (sex not identified)'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['lep_adult_male'] = array(
    'title' => t('lep_adult_male'),
    'help' => t('Number of adult male L. salmonis on the fish'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['lep_adult_female'] = array(
    'title' => t('lep_adult_female'),
    'help' => t('Number of adult female L. salmonis on the fish'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['lep_adult_unid'] = array(
    'title' => t('lep_adult_unid'),
    'help' => t('Number of adult L. salmonis on the fish (sex not identified)'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['lep_gravid'] = array(
    'title' => t('lep_gravid'),
    'help' => t('Number of gravid female L. salmonis on the fish'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['caligus'] = array(
    'title' => t('caligus'),
    'help' => t('Number of non-gravid C.clemensi motiles on the fish'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['caligus_gravid'] = array(
    'title' => t('caligus_gravid'),
    'help' => t('Number of gravid C. clemensi motiles on the fish'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['chal_scar'] = array(
    'title' => t('chal_scar'),
    'help' => t('Number of chalimus-associated scars/lesions on the fish'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['mot_scar'] = array(
    'title' => t('mot_scar'),
    'help' => t('Pressence or absence of motile L. salmonis associated wounds on the fish'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['pred_marks'] = array(
    'title' => t('pred_marks'),
    'help' => t('Pressence or absence of predation marks on the fish'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['hem'] = array(
    'title' => t('hem'),
    'help' => t('Pressence or absence of bleeding in fins, scales, or lesions on the fish'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['mate_guarding'] = array(
    'title' => t('mate_guarding'),
    'help' => t('Pressence or absence of a male-female L. salmonis copulatory or pre-copulatory pair'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['pin_belly'] = array(
    'title' => t('pin_belly'),
    'help' => t('Presence or absence of pinched belly. A deformation of very small fish associated with chalimus lice'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['tissue_damage'] = array(
    'title' => t('tissue_damage'),
    'help' => t('Notes on damage to surface tissues of the fish'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_fish_data']['comments'] = array(
    'title' => t('comments'),
    'help' => t('Additional Comments'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['bamp_wild_lab_results']['table'] = array('group' =>'BAMP-Wild-Lab-Results', 'title'=>'BAMP Wild Lab Results', 'help' => 'bamp_wild_lab_results');
  $data['bamp_wild_lab_results']['table']['base'] = array(
    'field' => 'id',
    'title' => t('BAMP Wild - Lab Results'),
    'help' => t('Contains lab result information from fish harvested in the wild.'),
    'database' => 'bamp_new',
    'weight' => -10, 
  );

  $data['bamp_wild_lab_results']['id'] = array(
    'title' => t('id'),
    'help' => t('Internal database record ID. Auto-Incrementing. Do not import to this field.'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_lab_results']['fish_id'] = array(
    'title' => t('fish_id'),
    'help' => t('Fish Unique Identifer'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['year'] = array(
    'title' => t('year'),
    'help' => t('Year of data'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_lab_results']['trip'] = array(
    'title' => t('trip'),
    'help' => t('Trip Number'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_lab_results']['gp_id'] = array(
    'title' => t('gp_id'),
    'help' => t('Group Id?'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_lab_results']['lab'] = array(
    'title' => t('lab'),
    'help' => t('Examining Lab'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['date_examined'] = array(
    'title' => t('date_examined'),
    'help' => t('Examination Date'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['fish_species_per_field'] = array(
    'title' => t('fish_species_per_field'),
    'help' => t('Fish species as identified in field'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['fish_number'] = array(
    'title' => t('fish_number'),
    'help' => t('Fish Number (in set)'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_lab_results']['fish_species_per_lab'] = array(
    'title' => t('fish_species_per_lab'),
    'help' => t('Fish species as identified by lab'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['length'] = array(
    'title' => t('length'),
    'help' => t('Length of fish (mm)'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['weight'] = array(
    'title' => t('weight'),
    'help' => t('Weight of fish (g)'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['l_co'] = array(
    'title' => t('l_co'),
    'help' => t('Leps Copeopodid'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['l_c1'] = array(
    'title' => t('l_c1'),
    'help' => t('Leps Chalimus stage 1'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['l_c2'] = array(
    'title' => t('l_c2'),
    'help' => t('Leps Chalimus stage 2'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['l_c3'] = array(
    'title' => t('l_c3'),
    'help' => t('Leps Chalimus stage 3'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['l_c4'] = array(
    'title' => t('l_c4'),
    'help' => t('Leps Chalimus stage 4'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['l_pam'] = array(
    'title' => t('l_pam'),
    'help' => t('Leps Pre Adult Male'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['l_paf'] = array(
    'title' => t('l_paf'),
    'help' => t('Leps Pre Adult Female'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['l_am'] = array(
    'title' => t('l_am'),
    'help' => t('Leps Adult Male'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['l_af'] = array(
    'title' => t('l_af'),
    'help' => t('Leps Adult Female'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['lep_total'] = array(
    'title' => t('lep_total'),
    'help' => t('Leps Total'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['c_co'] = array(
    'title' => t('c_co'),
    'help' => t('Caligus Copeopodid'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['c_c1'] = array(
    'title' => t('c_c1'),
    'help' => t('Caligus Chalimus Stage 1'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['c_c2'] = array(
    'title' => t('c_c2'),
    'help' => t('Caligus Chalimus Stage 2'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['c_c3'] = array(
    'title' => t('c_c3'),
    'help' => t('Caligus Chalimus Stage 3'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['c_c4'] = array(
    'title' => t('c_c4'),
    'help' => t('Caligus Chalimus Stage 4'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['c_pam'] = array(
    'title' => t('c_pam'),
    'help' => t('Caligus Pre Adult Male'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['c_paf'] = array(
    'title' => t('c_paf'),
    'help' => t('Caligus Pre Adult Female'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['c_am'] = array(
    'title' => t('c_am'),
    'help' => t('Caligus Adult Male'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['c_af'] = array(
    'title' => t('c_af'),
    'help' => t('Caligus Adult Female'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['cal_total'] = array(
    'title' => t('cal_total'),
    'help' => t('Caligus Total'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['lice_total'] = array(
    'title' => t('lice_total'),
    'help' => t('Lice Total'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['lessions'] = array(
    'title' => t('lessions'),
    'help' => t('Lessions on fish'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['comments'] = array(
    'title' => t('comments'),
    'help' => t('Additional Comments'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_lab_results']['initials'] = array(
    'title' => t('initials'),
    'help' => t(''),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['bamp_wild_sites']['table'] = array('group' =>'BAMP-Wild-Sites', 'title'=>'BAMP Wild Sites', 'help' => 'bamp_wild_sites');

  $data['bamp_wild_sites']['table']['base'] = array(
    'field' => 'id',
    'title' => t('BAMP Wild - Sites'),
    'help' => t("Contains information about BAMP sites in the wild."),
    'database' => 'bamp_new',
    'weight' => -10,
  );

  $data['bamp_wild_sites']['id'] = array(
    'title' => t('id'),
    'help' => t('Internal database record ID. Auto-Incrementing. Do not import to this field.'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_sites']['site_number'] = array(
    'title' => t('site_number'),
    'help' => t('Site Number'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_sites']['site_name'] = array(
    'title' => t('site_name'),
    'help' => t('Site Name'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_sites']['latitude'] = array(
    'title' => t('latitude'),
    'help' => t('Latitude'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_sites']['longitude'] = array(
    'title' => t('longitude'),
    'help' => t('Longitude'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_sites']['zone'] = array(
    'title' => t('zone'),
    'help' => t('Zone'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_sites']['area'] = array(
    'title' => t('area'),
    'help' => t('Area'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_sites']['Comment'] = array(
    'title' => t('Comment'),
    'help' => t('Additional Comments'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['bamp_wild_trips']['table'] = array('group' =>'BAMP-Wild-Trips', 'title'=>'BAMP Wild Trips', 'help' => 'bamp_wild_trips');
  $data['bamp_wild_trips']['table']['base'] = array(
    'field' => 'id',
    'title' => t('BAMP Wild - Trips Information'),
    'help' => t('Contains wild trips information'),
    'database' => 'bamp_new',
    'weight' => -10, 
  );
  //year/trip/lab in lab_results relates to trips by year, rep, to_lab
  /*$data['bamp_wild_trips']['table']['join']['bamp_wild_sites'] = array(
    'left_field' => 'site_number',
    'field' => 'site_number',
  );*/


  $data['bamp_wild_trips']['id'] = array(
    'title' => t('id'),
    'help' => t('Internal database record ID. Auto-Incrementing. Do not import to this field.'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_trips']['year'] = array(
    'title' => t('year'),
    'help' => t('Trip Year'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_trips']['date'] = array(
    'title' => t('date'),
    'help' => t('Trip Date'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_trips']['rep'] = array(
    'title' => t('rep'),
    'help' => t('Trip Number'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_trips']['route'] = array(
    'title' => t('route'),
    'help' => t('Trip Route'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_trips']['set_number'] = array(
    'title' => t('set_number'),
    'help' => t('Set Number'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),   
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),   
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),   
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),   
  );
  $data['bamp_wild_trips']['site_name'] = array(
    'title' => t('site_name'),
    'help' => t('Site Name'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_trips']['site_number'] = array(
    'title' => t('site_number'),
    'help' => t('Site Number'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_trips']['waypoint'] = array(
    'title' => t('waypoint'),
    'help' => t('Waypoint'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_trips']['distance'] = array(
    'title' => t('distance'),
    'help' => t('Distance'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_trips']['longitude'] = array(
    'title' => t('longitude'),
    'help' => t('Longitude'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_trips']['latitude'] = array(
    'title' => t('latitude'),
    'help' => t('Latitude'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_trips']['blind_no'] = array(
    'title' => t('blind_no'),
    'help' => t('Blind number'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_trips']['crew'] = array(
    'title' => t('crew'),
    'help' => t('Crew Members'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_trips']['tide'] = array(
    'title' => t('tide'),
    'help' => t('Tide (Low, Mid, High)'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_trips']['search_time'] = array(
    'title' => t('search_time'),
    'help' => t('Search Time'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_trips']['salinity'] = array(
    'title' => t('salinity'),
    'help' => t('Salinity'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_trips']['salinity_0_2'] = array(
    'title' => t('salinity_0_2'),
    'help' => t('Salinity between 0-2m'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_trips']['salinity_1'] = array(
    'title' => t('salinity_1'),
    'help' => t('Salinity at 1m'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_trips']['salinity_5'] = array(
    'title' => t('salinity_5'),
    'help' => t('Salinity at 5m'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_trips']['temperature'] = array(
    'title' => t('temperature'),
    'help' => t('Temperature'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_trips']['temperature_0_2'] = array(
    'title' => t('temperature_0_2'),
    'help' => t('Temperature between 0-2m'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_trips']['temperature_1'] = array(
    'title' => t('temperature_1'),
    'help' => t('Temperature at 1m'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_trips']['temperature_5'] = array(
    'title' => t('temperature_5'),
    'help' => t('Temperature at 5m'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_trips']['chum_capture'] = array(
    'title' => t('chum_capture'),
    'help' => t('Chum Captured'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_trips']['chum_retain'] = array(
    'title' => t('chum_retain'),
    'help' => t('Chum Retained'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_trips']['pink_capture'] = array(
    'title' => t('pink_capture'),
    'help' => t('Pink Captured'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_trips']['pink_retain'] = array(
    'title' => t('pink_retain'),
    'help' => t('Pink Retained'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_trips']['coho_capture'] = array(
    'title' => t('coho_capture'),
    'help' => t('Coho Captured'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_trips']['coho_retain'] = array(
    'title' => t('coho_retain'),
    'help' => t('Coho Retained'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['bamp_wild_trips']['weather_comments'] = array(
    'title' => t('weather_comments'),
    'help' => t('Weather comments'),
    'field' => array( 
      'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['bamp_wild_trips']['to_lab'] = array(
    'title' => t('to_lab'),
    'help' => t('Fish sent to lab'),
    'field' => array( 
      'click sortable' => TRUE,
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

    $data['changelog']['table'] = array('group' =>'changelog', 'title'=>'Change Log', 'help' => 'changelog');

  $data['changelog']['table']['base'] = array(
    'field' => 'id',
    'title' => t('BAMP Change Log'),
    'help' => t("Contains information about data which has been added or modified through the BAMP website."),
    'database' => 'bamp_new',
    'weight' => -10,
  );

  $data['changelog']['id'] = array(
    'title' => t('id'),
    'help' => t('Internal database record ID. Auto-Incrementing.'),
    'field' => array( 'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['changelog']['timestamp'] = array(
    'title' => t('Timestamp'),
    'help' => t(''),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['changelog']['user'] = array(
    'title' => t('User'),
    'help' => t(''),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['changelog']['action'] = array(
    'title' => t('Action'),
    'help' => t(''),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['changelog']['dbtable'] = array(
    'title' => t('Database Table'),
    'help' => t(''),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  /*
  $data['changelog']['recordId'] = array(
    'title' => t('Database Record ID'),
    'help' => t(''),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );*/
  $data['changelog']['recordId'] = array(
    'title' => t('recordId'),
    'help' => t('Database record ID'),
    'field' => array( 
      'click sortable' => TRUE,
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['changelog']['field'] = array(
    'title' => t('Field'),
    'help' => t(''),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['changelog']['oldvalue'] = array(
    'title' => t('Old Value'),
    'help' => t(''),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['changelog']['newvalue'] = array(
    'title' => t('New Value'),
    'help' => t(''),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['changelog']['additional'] = array(
    'title' => t('Additional Information'),
    'help' => t(''),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  ); 

  return $data;
}
