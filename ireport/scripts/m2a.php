#!/usr/bin/php
<?
$dbh = mysql_connect('localhost','root','q$%^az');
mysql_select_db('information_schema',$dbh);

$query = "SELECT table_name ";
$query.= "FROM `TABLES` ";
$query.= "WHERE `TABLE_SCHEMA` = 'bamp_new' ";
$query.= "AND `TABLE_NAME` LIKE 'changelog'";
$result = mysql_query($query,$dbh);

while($row = mysql_fetch_assoc($result)){
  $query = "SELECT `column_name` as col, `data_type` as type, `character_maximum_length` as length, column_comment as comment ";
  $query.= "FROM `COLUMNS` ";
  $query.= "WHERE `table_name` = '". $row['table_name']."' ";
  $query.= "ORDER BY `ordinal_position` ASC ";
  $result2 = mysql_query($query,$dbh);
 
  echo '$data[\''.$row['table_name'].'\'][\'table\'] = array(\'group\' =>\'\', \'title\'=>\'\', \'help\' => \'\');'."\r\n\r\n";

  while($row2 = mysql_fetch_assoc($result2)){
    $handler = '';
    $sort = '';
    $filter = '';
    $argument = '';

    switch(strtolower($row2['type'])){
      case 'int':
        $handler = 'views_handler_field_numeric';
        $sort = 'views_handler_sort';
        $filter = 'views_handler_filter';
        $argument = 'views_handler_argument_numeric';
      break;
      
      case 'date':
        $handler = 'views_handler_field_date';
        $sort = 'views_handler_sort_date';
        $filter = 'views_handler_filter';
        $argument = 'views_handler_argument_date';
      break;

      default: 
        $handler = 'views_handler_field';
        $sort = 'views_handler_sort';
        $filter = 'views_handler_filter';
        $argument = 'views_handler_argument_string';
      break;
    }//end switch

    echo "  ".'$data[\''.$row['table_name'].'\'][\''.$row2['col'].'\'] = array('."\r\n";
    echo "    ".'\'title\' => t(\''.$row2['col'].'\'),'."\r\n";
    echo "    ".'\'help\' => t(\''.$row2['comment'].'\'),'."\r\n";
    echo "    ".'\'field\' => array('."\r\n";
    echo "      ".'\'handler\' => \''.$handler.'\','."\r\n"; 
    echo "    ".'),'."\r\n";
    echo "    ".'\'sort\' => array('."\r\n";
    echo "      ".'\'handler\' => \''.$sort.'\','."\r\n";
    echo "    ".'),'."\r\n";
    echo "    ".'\'filter\' => array('."\r\n";
    echo "      ".'\'handler\' => \''.$filter.'\','."\r\n";
    echo "    ".'),'."\r\n";
    echo "    ".'\'argument\' => array('."\r\n";
    echo "      ".'\'handler\' => \''.$argument.'\','."\r\n";
    echo "    ".'),'."\r\n";
    echo "  ".');'."\r\n"; 
  }//end while
}//end while
?>
