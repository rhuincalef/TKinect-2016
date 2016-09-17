      <!-- Se escribe el listener del boton, enviando la carpeta donde se deben almacenar
     los datos de la falla -->
    <?php 
          echo "<script>";
          echo '$("#boton-info").on("click", function () {';
          echo 'var $btn = $(this).button("loading");';
          echo "debug('clickeado!!');";
          echo "limpiar_container();";      
          $url_falla = 'http://'.$_SERVER['HTTP_HOST'].'/'.'tkinect2016/webGLViewer/'.$_GET['datafolder'].'/'.$_GET['pcFolder'];
          echo "generar_propiedades_falla_csv(". "'".$url_falla."'" .");";
          echo "});";    
          echo "</script>";
    ?>
