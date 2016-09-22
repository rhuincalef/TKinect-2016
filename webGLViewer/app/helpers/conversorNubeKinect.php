<?php
//  Se escribe el codigo que importa el js que realiza las peticiones y se lo invoca 
// con el nombre de la carpeta donde se encuentra la nube de puntos. 
	echo "<script type='text/javascript' src='"."../views/js/conversorJs.js". "' ></script>";
	echo "<script>  transformarNubePtos( '". 'http://'.$_SERVER['HTTP_HOST'].'/'.'tkinect2016/webGLViewer/'.DATAFOLDER.'/'.$pcFolder. "' ); </script>";
?>