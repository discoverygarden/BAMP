<?php
/***********************************************************************
*Temporary file to return data from the server. This should be integrated
*into the .module file and use the drupal mysql functions.
************************************************************************/
require_once('dataHandler.class.php');

$dbh = mysql_connect('localhost','root','q$%^az');
$dh = new dataHandler();
$mapFilters = json_decode(urldecode($_POST['mapFilters']));
$mapShape = json_decode(urldecode($_POST['polygonPoints']));
$filename = 'BAMP_GeoViewer_Export_-_'.$_POST['type'].'-'.date("m-d-y").'.csv';
$data = $dh->getCsvData($mapFilters, json_decode($_POST['polygonPoints']), $_POST['type']);
csvToExcelDownloadFromResult($data, true, $filename);

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
