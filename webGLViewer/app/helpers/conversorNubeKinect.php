<?php
//  Se escribe el codigo que importa el js que realiza las peticiones y se lo invoca 
// con el nombre de la carpeta donde se encuentra la nube de puntos. 
	echo "<script type='text/javascript' src='"."../views/js/conversorJs.js". "' ></script>";
	echo "<script>  window.nameSpaceCgi.transformarNubePtos( '". $pcFolder . "','". PCFILE ."','".
	 "','".PCINFO ."','".PCIMG."' ); </script>";
?>