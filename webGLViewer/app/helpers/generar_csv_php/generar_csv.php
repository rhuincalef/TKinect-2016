<?php

// Agregar la parte de consulta a la BD con code igniter antes de llamar a
// generar_csv.php y obtener los paramtros $_GET[] ($_GET['titulo'],$_GET['descripcion'])


// Genera un csv generico <ALGO>_info.csv que tiene el titulo de la falla y la descripcion
// que se muestra en el thumbnail.
class GeneradorCsv{

	 function generar($data,$carpetaFalla,$archivo_info_defecto) {
		$PROTO = "http://";
		$HOST = "localhost";
		$PATH_CSV = "tkinect2016/webGLViewer/data/".$carpetaFalla."/csv_temp/";

		$data_array = array ( $data );
		$csv = "titulo,meta\n"; //Column headers
		foreach ($data_array as $record){
			// $csv.= $record[0].','.$record[1].','.$record[2].','.$record[3]."\n"; //Append data to csv
			$csv.=$record[0].','.$record[1]."\n";
		}
		$server_path = $_SERVER['DOCUMENT_ROOT'].'/tkinect2016/webGLViewer/data/'.$carpetaFalla."/csv_temp";
		$csv_handler = fopen ($server_path.'/'.$archivo_info_defecto,'w');
		fwrite ($csv_handler,$csv);
		fclose ($csv_handler);

		//  { "path_csv": "http://localhost/tkinect2016/data/pointcloud_1/test.csv" }
		$json = array('path_csv' => $PROTO.$HOST."/".$PATH_CSV."/".$archivo_info_defecto ); 
		echo json_encode($json);
	} 

}

$g = new GeneradorCsv();
$carpetaFalla = $_GET['nombreCarpetaNube'];
$archivo_info_defecto = $_GET['infoFile'];
$g->generar(array($archivo_info_defecto,$archivo_info_defecto),$carpetaFalla,
	$archivo_info_defecto);

?>