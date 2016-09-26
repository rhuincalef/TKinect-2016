<?php

/*
 *---------------------------------------------------------------
 * CONFIGURATION
 *---------------------------------------------------------------
 *
 * Different variables to be configured
 */




// EJEMPLO DE INVOCACION DEL SCRIPT
// http://localhost/tkinect2016/webGLViewer/index.php?idfalla=pointcloud_1


// The directory where your pointclouds are saved
define("DATAFOLDER", "data");

// The filenames of the pointclouds
// NOTA IMPORTANTE: METODO DE INVOCACION es -->
// localhost/index.php?idfalla=pointcloud_1
// de esta forma se definen los nombres de los archivos que seran usados
// para leer cada falla.
// * Se supone que con este metodo las fallas se almacenan en una carpeta
// con el mismo nombre de la falla y del archivo .pcd. 
// Por ej. pointcloud_1/pointcloud_1.pcd 



$nombrePc=$_REQUEST['idfalla'];."_pc.csv"
$nombreInfo=$_REQUEST['idfalla']."_info.csv";
$nombreImg=$_REQUEST['idfalla'].."_img.csv";

define("PCFILE", $nombrePc);
define("PCINFO", $nombreInfo);
define("PCIMG", $nombreImg);

// Can be development or production
define("ENVIRONMENT", "development");

// The development url
define("DEVELURL", "http://localhost/tkinect2016/webGLViewer/");
// define("DEVELURL", "http://localhost/data/pointcloud_1/webGLViewer/");

// The production url
// define("PRODURL", "http://localhost/data/pointcloud_1/webGLViewer");

require('FirePHP.class.php');
$firephp = FirePHP::getInstance(true);



/*
 *---------------------------------------------------------------
 * URL PARSER
 *---------------------------------------------------------------
 *
 * Parses the url and load the correct page.
 */

// Parse the url
include('app/helpers/url.php');
$pathInfo = parsePath($firephp);


$firephp->fb('$pathInfo obtenido -->');
$firephp->fb($pathInfo);
$firephp->fb("");

if (sizeof($pathInfo['call_parts']) > 0) {
  $page = $pathInfo['call_parts'][0];
  $firephp->fb('$page es:');
  $firephp->fb($page);
  $firephp->fb("");
  switch ($page) {
    case 'view':
      $firephp->fb("entre por view");
      $pcFolder = (isset($_REQUEST['c']) ? $_REQUEST['c'] : null);
      include('app/views/viewer.php');
      break;
    case '404':
      $firephp->fb("entre por 404");
      include('app/views/404.php');
      break;
    default:
      $firephp->fb("entre por default");
      include('app/views/home.php');
      break;
  }
}
else {
  include('app/views/home.php');
}

?>