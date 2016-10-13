// Constantes de Javascript
(function(namespaceCargaJs,$,undefined){
	var HOST= "localhost";
	var PHPFOLDER = "/tkinect2016/webGLViewer/app/helpers/generar_csv_php/generar_csv.php";

	function configurar_info_falla(){
		// Configuracion del alert
		$('#error-alert').attr("class","alert alert-danger alert-dismissible fade");

		// Confinguracion del boton
		$('#boton-info').attr('data-loading-text',"Cargando info...");	

	}

	// Invoca al generador.php que retorna un json al .csv que escribio.
	function generar_propiedades_falla_csv(carpetaFalla){
		// Se llama a un .php que genere un csv con las propiedades que se mostraran en la falla
		$.get("http://"+HOST+PHPFOLDER+"?carpeta="+carpetaFalla,function(data){
			// El php genera un csv en un directorio por defecto y retorna un JSON
			// con la URL del csv en el servidor.
			//  { "pathCsv": "http://localhost/tkinect2016/data/pointcloud_1/test.csv" }

			var json = JSON.parse(data);
			debug("La url obtenida es -->");
			debug(json.pathCsv);
			debug("");
			cargar_cvs_falla(json.pathCsv);
		});
	}

	// Funcion de debugging.
	function debug(msg){
		console.log(msg);
	}

	// Declaracion y ejecucion de funcion de js
	// var json_csv;
	// var NOMBRE_CSV_INFO_FALLA = "test.csv";
	

	// Funcion para el parseo de CSV
	// function cargar_cvs_falla(url){
	// 	// var PATH_CSV = "js/tablaCVS/lib/test.csv"; 
	// 	Papa.parse(url, {
	// 		download: true,
	// 		complete: function(data)
	// 		{
	// 			debug("CSV Parseado!!");
	// 			debug(data);
	// 			json = transformar_a_json(data.data);
	// 			debug("El json obtenido fue: ");
	// 			debug(json);
	// 			generar_datos_falla(json);
	// 			setTimeout(function(){
	// 				$('#boton-info').button('reset');
	// 			}, 3000);
	// 		},
	// 		error: function(data)
	// 		{
	// 			debug("mdamdkamdkasm");
	// 			$('#error-alert').attr('style','display:inline;');
	// 			$('#error-alert').attr("class","alert alert-danger alert-dismissible in");
	// 			setTimeout(function(){
	// 				$('#error-alert').attr("class","alert alert-danger alert-dismissible fade");
	// 				}, 3000);
	// 			$('#boton-info').button('reset');
	// 		}
	// 	});
	// }

	// Elegir la primera linea con el nombre de las propiedades
	// y la segunda con los valores de las propiedades y produce un json
	// function transformar_a_json(data){
	// 	debug("Los datos obtenidos son: ");
	// 	debug(data);
	// 	nombresPropiedades=data[0];
	// 	valoresPropiedades=data[1];
	// 	result = {};
	// 	for (var i = 0; i < nombresPropiedades.length; i++) {
	// 			result[ nombresPropiedades[i] ] = valoresPropiedades[i];
	// 	};
	// 	return result;
	// }

	// Muestra la informacion de una falla en un componente de Bootstrap
	// a partir de un json
	// function generar_datos_falla(data_json){
	// 	$('#datos-falla').append('<dl id="tablaHorizontal" class="dl-horizontal" style="position:absolute;left:65%;top:17%;"></dl>');
	// 	$.each(data_json, function(key,valorProp){
	// 		var nombreProp = key.toString();
	// 	 	// Agregar las filas para cada elemento del json.
	// 	 	$('#tablaHorizontal').append('<dt>'+nombreProp+'</dt>');
	// 	 	$('#tablaHorizontal').append('<dd>'+valorProp+'</dd>');
	// 	});
	// }

	// function limpiar_container(){
	// 	$('#tablaHorizontal').remove();
	// }

}(window.namespaceCargaJs = window.cargaJs || {},jQuery) );



