<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="en">
  <head>
    <meta http-equiv="content-type" content="text/html; charset=UTF-8">
    <meta charset="utf-8">
    <title>SRV Pointclouds</title>
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">
    <link href="<?php echo 'http://'.$_SERVER['HTTP_HOST'].'/tkinect2016/webGLViewer/css/bootstrap.min.css'; ?>" rel="stylesheet">
    <link href="<?php echo 'http://'.$_SERVER['HTTP_HOST'].'/tkinect2016/webGLViewer/css/style.css'; ?>" rel="stylesheet">
    
    <!--[if lt IE 9]>
      <script src="//html5shim.googlecode.com/svn/trunk/html5.js"></script>
    <![endif]-->
    <script src="http://ajax.googleapis.com/ajax/libs/jquery/2.0.2/jquery.min.js"></script>
    <script src="<?php echo 'http://'.$_SERVER['HTTP_HOST'].'/tkinect2016/webGLViewer/js/bootstrap.min.js';?>"></script>

    <!-- Carga de las librerias -->
    <script src="//ajax.googleapis.com/ajax/libs/jquery/2.0.2/jquery.min.js"></script>
    <script src="<?php echo 'http://'.$_SERVER['HTTP_HOST'].'/tkinect2016/webGLViewer/js/bootstrap.min.js';?>" ></script>
    <script src="<?php echo 'http://'.$_SERVER['HTTP_HOST'].'/tkinect2016/webGLViewer/js/webgl-detector.js';?>"></script>
    <script src="<?php echo 'http://'.$_SERVER['HTTP_HOST'].'/tkinect2016/webGLViewer/js/three.min.js';?>"></script>
    <script src="<?php echo 'http://'.$_SERVER['HTTP_HOST'].'/tkinect2016/webGLViewer/js/papaparse.min.js';?>"></script>
    
    <script src="<?php echo 'http://'.$_SERVER['HTTP_HOST'].'/tkinect2016/webGLViewer/js/notify/bootstrap-notify.js';?>"></script>



    <!-- Se cargan las librerias para la generacion de la imagen y 
    la descripcion del thumnail. -->
    <link rel="stylesheet" type="text/css" href="app/views/js/errorThumbnail.css">
    <script type='text/javascript' src="app/views/js/conversorJs.js" ></script>
    <script type="text/javascript" src ="app/views/js/thumnailFalla.js" ></script>
  
  </head> 

<body>

<div class="container">