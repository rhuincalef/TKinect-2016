<?php
// Genera un csv generico <ALGO>_info.csv que tiene el titulo de la falla y la descripcion que se muestra en el thumbnail. Donde <ALGO> es el nombre de la 
// carpeta de la falla que se pasa como idFalla.

require_once("../../views/FirePHP.class.php");
require_once("ExcepcionPHP.php");

class GeneradorCsv{

	// Constantes del generador csv.
	const SUBFIJO_CSV_DEFECTO = "_info.csv";
	const COD_EXITO = 200;
	const COD_ERROR = 400;
	
	function imprimirErrorJson($msg,$codigo){
		$json = array( 'estado' => $codigo, 'error' => $msg );
		echo json_encode($json);
	}


	function generar($idFalla,$pathCarpetaFalla) {
		
		$firephp = FirePHP::getInstance(true);
		$firephp->fb( "En generar...");
		$firephp->fb( self::SUBFIJO_CSV_DEFECTO);
		$RAIZ_SERVIDOR = $_SERVER['DOCUMENT_ROOT'];
		// Retorna "localhost".
		$HOST = $_SERVER['HTTP_HOST'];
		$firephp->fb('$HOST:');
		$firephp->fb($HOST);
		// /var/www/html
		$firephp->fb('$RAIZ_SERVIDOR');
		$firephp->fb($RAIZ_SERVIDOR);
		try {


			$partes_url = explode($HOST,$pathCarpetaFalla);
			// http://
			$PROTO = $partes_url[0];
		 	$PATH_CSV = $partes_url[1];
		 	if ($PROTO == NULL || $PATH_CSV == NULL)
		 		throw new ExcepcionPHP('URL no valida',self::COD_ERROR);

		 	$firephp->fb( '$partes_url');
		 	$firephp->fb( $partes_url);
		 	$firephp->fb( $PROTO);
		 	// /tkinect2016/webGLViewer/data/pointcloud_1/csv_temp/
		 	$firephp->fb( $PATH_CSV);
		 	
			//Nota: Se podria mostrar en la descripcion del thumbnail el tipo de falla de la que se trata.
		 	// NOTA csv: Primer linea titulo, Segunda linea descripcion
			$descripcion_falla = "Hoyo";
			$lista = array( array($idFalla),
									array($descripcion_falla)
									);			
			$tmp = $RAIZ_SERVIDOR.$PATH_CSV.$idFalla.self::SUBFIJO_CSV_DEFECTO;
			$firephp->fb("tmp -->");
			$firephp->fb($tmp);
			$csv_handler = fopen ($tmp,'w');
			$firephp->fb("VALOR HANDLER -->");
			$firephp->fb($csv_handler);
			foreach ($lista as $campos) {
 			   fputcsv($csv_handler, $campos);
			}
			fclose ($csv_handler);

			//  { "path_csv": "http://localhost/tkinect2016/data/pointcloud_1/test.csv" }
			// $json = array('path_csv' => $PROTO.$HOST."/".$json."/".$archivo_info_defecto );
			$str=$PROTO.$HOST.$PATH_CSV.$idFalla.self::SUBFIJO_CSV_DEFECTO;
			$firephp->fb("str -->");
			$firephp->fb($str);
			$json = array( 'estado'=>self::COD_EXITO, 'path_csv' => $str ); 
			echo json_encode($json);

		} catch (ExcepcionPHP $e) {
				$this->imprimirErrorJson($e->getMessage(),$e->getCode());
				// $this->imprimirErrorJson($e->mensaje(),$e->codigo());
		}catch (Exception $e) {
				$this->imprimirErrorJson("Error interno de servidor en generacion de csv");
		}
	 	
	}
}

?>