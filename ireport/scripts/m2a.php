#!/usr/bin/php
<?
$dbh = mysql_connect('localhost','root','q$%^az');
mysql_select_db('information_schema',$dbh);

$query = "SELECT table_name ";
$query.= "FROM `TABLES` ";
$query.= "WHERE `TABLE_SCHEMA` = 'bamp_new' ";
$query.= "AND `TABLE_NAME` IN ('bamp_wild_fish_samples', 'bamp_wild_sampling_instances','bamp_wild_lice_details','bamp_farm_aggregate','bamp_farm_environment','bamp_farm_fish_data','bamp_farm_inventory','bamp_farm_sites')";
$result = mysql_query($query,$dbh);

echo 'function ireport_views_data(){'."\r\n\r\n";
echo '$data = array();'."\r\n\r\n";

while($row = mysql_fetch_assoc($result)){
  $query = "SELECT `column_name` as col, `data_type` as type, `character_maximum_length` as length, column_comment as comment ";
  $query.= "FROM `COLUMNS` ";
  $query.= "WHERE `table_name` = '". $row['table_name']."' ";
  $query.= "ORDER BY `ordinal_position` ASC ";
  $result2 = mysql_query($query,$dbh);

  echo "  ".'$data[\''.$row['table_name'].'\'][\'table\'] = array(\'group\' =>\'BAMP\', \'title\'=>\''.$row['table_name'].'\', \'help\' => \'\');'."\r\n\r\n";
  echo "  ".'$data[\''.$row['table_name'].'\'][\'table\'][\'base\'] = array('."\r\n";
  echo "    ".'\'field\' => \'id\','."\r\n";
  echo "    ".'\'title\' => t(\''.$row['table_name'].'\'),'."\r\n";
  echo "    ".'\'help\' => t(\''.$row['table_name'].' table\'),'."\r\n";
  echo "    ".'\'database\' => \'bamp_new\','."\r\n";
  echo "    ".'\'weight\' => -10,'."\r\n";
  echo "  ".');'."\r\n\r\n";

  while($row2 = mysql_fetch_assoc($result2)){
    $handler = $sort = $filter = $argument = null;
    switch(strtolower($row2['type'])){
      case 'float':
      case 'tinyint':
      case 'int':
        $handler = 'views_handler_field_numeric';
        $sort = 'views_handler_sort';
        $filter = 'views_handler_filter_numeric';
      break;

      case 'timestamp':
      case 'date':
        $handler = 'views_handler_field_date';
        $sort = 'views_handler_sort_date';
        $filter = 'views_handler_filter_date';
      break;

      default: 
        $handler = 'views_handler_field';
        $sort = 'views_handler_sort';
        $filter = 'views_handler_filter_string';
        $argument = 'views_handler_argument_string';
      break;
    }//end switch

    echo "  ".'$data[\''.$row['table_name'].'\'][\''.$row2['col'].'\'] = array('."\r\n";
    echo "    ".'\'title\' => t(\''.$row2['col'].'\'),'."\r\n";
    echo "    ".'\'help\' => t(\''.$row2['comment'].'\'),'."\r\n";
    echo "    ".'\'field\' => array('."\r\n";
    echo "      ".'\'handler\' => \''.$handler.'\','."\r\n"; 
    echo "      ".'\'click sortable\' => TRUE,'."\r\n";
    echo "    ".'),'."\r\n";
    echo "    ".'\'sort\' => array('."\r\n";
    echo "      ".'\'handler\' => \''.$sort.'\','."\r\n";
    echo "    ".'),'."\r\n";
    echo "    ".'\'filter\' => array('."\r\n";
    echo "      ".'\'handler\' => \''.$filter.'\','."\r\n";
    echo "    ".'),'."\r\n";
    if(!empty($argument)){
      echo "    ".'\'argument\' => array('."\r\n";
      echo "      ".'\'handler\' => \''.$argument.'\','."\r\n";
      echo "    ".'),'."\r\n";
    }//end if
    echo "  ".');'."\r\n"; 
  }//end while
}//end while


echo "\r\n\r\n";
echo "  ".'return $data;'."\r\n\r\n";
echo '}'."\r\n";


/*


function hook_views_data() {
  // The 'group' index will be used as a prefix in the UI for any of this
  // table's fields, sort criteria, etc. so it's easy to tell where they came
  // from.
  $data['example_table']['table']['group'] = t('Example table');

  // Define this as a base table. In reality this is not very useful for
  // this table, as it isn't really a distinct object of its own, but
  // it makes a good example.
  $data['example_table']['table']['base'] = array(
    'field' => 'nid',
    'title' => t('Example table'),
    'help' => t("Example table contains example content and can be related to nodes."),
    'weight' => -10,
  );

  // This table references the {node} table.
  // This creates an 'implicit' relationship to the node table, so that when 'Node'
  // is the base table, the fields are automatically available.
  $data['example_table']['table']['join'] = array(
    // Index this array by the table name to which this table refers.
    // 'left_field' is the primary key in the referenced table.
    // 'field' is the foreign key in this table.
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  // Next, describe each of the individual fields in this table to Views. For
  // each field, you may define what field, sort, argument, and/or filter
  // handlers it supports. This will determine where in the Views interface you
  // may use the field.

  // Node ID field.
  $data['example_table']['nid'] = array(
    'title' => t('Example content'),
    'help' => t('Some example content that references a node.'),
    // Because this is a foreign key to the {node} table. This allows us to
    // have, when the view is configured with this relationship, all the fields
    // for the related node available.
    'relationship' => array(
      'base' => 'node',
      'field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Example node'),
    ),
  );

  // Example plain text field.
  $data['example_table']['plain_text_field'] = array(
    'title' => t('Plain text field'),
    'help' => t('Just a plain text field.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
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

  // Example numeric text field.
  $data['example_table']['numeric_field'] = array(
    'title' => t('Numeric field'),
    'help' => t('Just a numeric field.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Example boolean field.
  $data['example_table']['boolean_field'] = array(
    'title' => t('Boolean field'),
    'help' => t('Just an on/off field.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Published'),
      'type' => 'yes-no',
      // use boolean_field = 1 instead of boolean_field <> 0 in WHERE statment
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Example timestamp field.
  $data['example_table']['timestamp_field'] = array(
    'title' => t('Timestamp field'),
    'help' => t('Just a timestamp field.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  return $data;
}
*/
?>
