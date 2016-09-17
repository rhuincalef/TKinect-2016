<?php

// URL ejecucion:
// http://localhost/webGLViewer/generar_csv_php/generar_csv.php.

// Genera un csv llamado "info.csv" con infomracion leida desde la BD.
// Agregar la parte de consulta a la BD con code igniter antes de llamar a
// generar_csv.php y obtener los paramtros $_GET[] ($_GET['titulo'],$_GET['descripcion'])

class GeneradorCsv{

	 function generar($data,$carpetaFalla) {

		$data_array = array ( $data );
		// $data_array = array ( array ($titulo,$descripcion) );

		$csv = "Nombre,Descripcion,Profundidad,Diametro\n"; //Column headers
		foreach ($data_array as $record){
			$csv.= $record[0].','.$record[1].','.$record[2].','.$record[3]."\n"; //Append data to csv
		}

		$server_path = $_SERVER['DOCUMENT_ROOT'].'/tkinect2016/webGLViewer/data/pointcloud_1';
		$csv_handler = fopen ($server_path.'/'."test22.csv",'w');
		// $csv_handler = fopen ($carpetaFalla.'/'."test.csv",'w');
		fwrite ($csv_handler,$csv);
		fclose ($csv_handler);

		//  { "pathCsv": "http://localhost/tkinect2016/data/pointcloud_1/test.csv" }
		$json = array('pathCsv' => $carpetaFalla.'/'."test22.csv" ); 
		echo json_encode($json);
	} 

}

$g = new GeneradorCsv();
$carpetaFalla = $_GET['carpeta'];
$g->generar(array("Archivo de prueba prueba6.pcd","Captura validada","7 cm","12 cm"),$carpetaFalla);

?>