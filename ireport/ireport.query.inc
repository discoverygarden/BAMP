<?php
// $Id$


function ireport_report_list() {
  $sql = "SELECT display_options FROM views_display WHERE display_plugin = 'page'";  

  $limit = 20;
  $header = array(
    array('data' => t('Title'), 'field' => 'display_title', 'sort' => 'asc'),
    array('data' => t('Description'), 'field' => 'company'),
    array('data' => t('View Report'), 'field' => 'city')
  );
  $result = db_query($sql);
  $rows = array();
  while($row = $result->fetchAssoc()) {
    $display_options = unserialize($row['display_options']);
    $title = $display_options['menu']['title'];
    $description = $display_options['menu']['description'];
    $link = l('View Report', $display_options['path']);

    $rows[] = array($title, $description, $link);
  }
  if (!$rows) {
    $rows[] = array(array('data' => t('No client accounts created yet.'), 'colspan' => 3));
  }

  $output = theme('table', array(
    'header' => $header, 
    'rows' => $rows,
  ));

  return $output;
}
