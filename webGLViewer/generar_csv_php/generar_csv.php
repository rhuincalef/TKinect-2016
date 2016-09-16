<?php

// URL ejecucion:
// http://localhost/webGLViewer/generar_csv_php/generar_csv.php.

// Genera un csv llamado "info.csv" con infomracion leida desde la BD.
// Agregar la parte de consulta a la BD con code igniter antes de llamar a
// generar_csv.php y obtener los paramtros $_GET[] ($_GET['titulo'],$_GET['descripcion'])
class GeneradorCsv{

	 function generar($titulo,$descripcion) {
		$data_array = array ( array ($titulo,$descripcion) );

		$csv = "title,meta \n"; //Column headers
		foreach ($data_array as $record){
			$csv.= $record[0].','.$record[1]."\n"; //Append data to csv
		}
		$csv_handler = fopen ("info.csv",'w');
		fwrite ($csv_handler,$csv);
		fclose ($csv_handler);
		echo 'Data saved to csvfile.csv';
	} 
}

$g = new GeneradorCsv();

$g->generar("Archivo de prueba prueba6.pcd","Captura propia ");
echo "<h1>Generado csv</h1>";
?>