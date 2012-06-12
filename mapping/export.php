<?php
require_once('dataHandler.class.php');
require('config.php');

//Connect to db
$dbh = mysql_connect($config['db']['host'],$config['db']['user'],$config['db']['pass']);

//Instantiate data handler class
$dh = new dataHandler();

//Set the filename
$filename = 'BAMP_GeoViewer_Export_-_'.$_POST['type'].'-'.date("m-d-y").'.csv';

//Get the data
$data = $dh->getCsvData(json_decode(urldecode($_POST['mapFilters'])), json_decode(urldecode($_POST['polygonPoints'])), $_POST['type']);

//run CSV to Excel (true = show column headers)
csvToExcelDownloadFromResult($data, true, $filename);

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//CSV to Excel Start - Do not change below this line//
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////

function setExcelContentType() {
    if(headers_sent())
        return false;
    header('Content-type: application/vnd.ms-excel');
    return true;
}

function setDownloadAsHeader($filename) {
    if(headers_sent())
        return false;
    header('Content-disposition: attachment; filename=' . $filename);
    return true;
}

function csvFromResult($stream, $result, $showColumnHeaders = true) {
    if($showColumnHeaders) {
        $columnHeaders = array();
        $nfields = mysql_num_fields($result);
        for($i = 0; $i < $nfields; $i++) {
            $field = mysql_fetch_field($result, $i);
            $columnHeaders[] = $field->name;
        }
        fputcsv($stream, $columnHeaders);
    }

    $nrows = 0;
    while($row = mysql_fetch_row($result)) {
        fputcsv($stream, $row);
        $nrows++;
    }

    return $nrows;
}

function csvFileFromResult($filename, $result, $showColumnHeaders = true) {
    $fp = fopen($filename, 'w');
    $rc = csvFromResult($fp, $result, $showColumnHeaders);
    fclose($fp);
    return $rc;
}

function csvToExcelDownloadFromResult($result, $showColumnHeaders = true, $asFilename = 'data.csv') {
    setExcelContentType();
    setDownloadAsHeader($asFilename);
    return csvFileFromResult('php://output', $result, $showColumnHeaders);
}
?>
