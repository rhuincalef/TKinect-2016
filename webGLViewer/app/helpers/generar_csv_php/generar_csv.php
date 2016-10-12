<?php

// Agregar la parte de consulta a la BD con code igniter antes de llamar a
// generar_csv.php y obtener los paramtros $_GET[] ($_GET['titulo'],$_GET['descripcion'])

require_once("GeneradorCsv.php");

$g = new GeneradorCsv();
// $carpetaFalla = $_GET['nombreCarpetaNube'];
// URL para debugging
// http://localhost/tkinect2016/webGLViewer/app/helpers/generar_csv_php/generar_csv.php?idFalla=pointcloud_1&raizTmp=http://localhost/tkinect2016/webGLViewer/data/pointcloud_1/csv_temp/
// http://localhost/tkinect2016/webGLViewer/app/helpers/generar_csv_php/generar_csv.php?idFalla=pointcloud_1&raizTmp=http%3A%2F%2Flocalhost%2Ftkinect2016%2FwebGLViewer%2Fdata%2Fpointcloud_1%2Fcsv_temp%2F

$idFalla = $_GET['idFalla'];
$carpetaFalla = $_GET['raizTmp'];
$g->generar($idFalla,$carpetaFalla);

?>