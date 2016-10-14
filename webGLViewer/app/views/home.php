<?php
  // require('../../../FirePHP.class.php');
  // $firephp = FirePHP::getInstance(true);
  $firephp->fb("HEADERRRRRRRRRRRRRRRRRRRRRRRRRRR");
  include('header.php');
?>

  <a href="https://github.com/srv/pointcloud_web_viewer"><img style="position: absolute; top: 0; right: 0; border: 0;" src="https://camo.githubusercontent.com/38ef81f8aca64bb9a64448d0d70f1308ef5341ab/68747470733a2f2f73332e616d617a6f6e6177732e636f6d2f6769746875622f726962626f6e732f666f726b6d655f72696768745f6461726b626c75655f3132313632312e706e67" alt="Fork me on GitHub" data-canonical-src="https://s3.amazonaws.com/github/ribbons/forkme_right_darkblue_121621.png"></a>

  <!-- Top -->
  <div class="row">

    <div class="col-lg-8">
      <h1 style="font-size:50px;">SRV Pointclouds</h1><br />
      <p class="lead">List of 3D reconstructions performed by researchers of our group. Your browser must have <a href="http://get.webgl.org/" target="_blank">WebGL support</a> for proper display.</p>
    </div>

    <div class="col-lg-2 col-lg-offset-2">
      <div style="width:100%; height: 20px;"></div>
      <a title="SRV Group" href="http://srv.uib.es"><img class="img-responsive" src="img/logo.png" width="150"></a>
    </div>

  </div>


  <!-- Separator -->
  <div class="row" style="text-align:center;">
    <div class="col-lg-12 col-sm-12 col-xs-12">
      <hr>
    </div>
  </div>


  <!-- Parte personalizada desde este punto! -->

  <!-- Contenedor para el thumnail -->
  <div id = "containerThumnail" class="row"></div>

  <!-- Se carga el thumnail por javascript -->
  <?php
    // Se obtiene el idFalla
    $idFalla = $_GET['idfalla']; 
    $firephp->fb("En home.php, idfalla = ". $idFalla);
    $firephp->fb("");
    echo "<script type='text/javascript'>";
    echo "window.nameSpaceThumbnail.inicializar_thumnail('".$idFalla."');";
    // echo "window.nameSpaceCgi.transformarNubePtos( '". $idFalla. " ');"; 
    echo "</script>";

  ?>


  <!-- Fin de parte personalizada! -->



  <?php
  include('footer.php');
  ?>

  
  