
// Genera todos los archivos necesarios (csv,png,csv info) para renderizar 
// la nube con WebGL. Recibe nombreCarpetaNube que contiene el nombre de la
// carpeta de la falla (mismo nombre de la falla). Por ej: pointcloud_1.
// 
// Al terminar la peticion ajax, se recibe un json que tiene un campo de info con las url de los datos que 
// requiere el plugin y un campo de error que indica el tipo de error en 
// la cadena de conversion de los archivos.
// 		data = {"estado": 200 | 400, "datos": {"csv_nube": "http://host/pointcloud_1/pointcloud_1_pc.csv",
// 				"imagen": "http://host/pointcloud_1/pointcloud_1_pc.csv" },
// 				"error":"MENSAJE DE TIPO DE ERRROR"
// }
//

// Definicion de namespace con funcion anonima
(function(nameSpaceCgi,$,undefined){

	function transformarNubePtos(idFalla){
			$.ajax(
					url:"../../cgi-bin/main/build/conversorCgi.cgi?idFalla=" + idFalla,
					success:function(data,status,jqhxr){
								debug('Peticion a cgi-bin correcta!');
								var json_estado = JSON.parse(data);
								if (json_estado.estado == 400){
									debug("Ha ocurrido un error en el servidor -->");
									debug(json_estado.error);
									mostrar_error_thumnail(json_estado.error);
									return;
								}else if(json_estado.estado == 401){
									debug("Ha ocurrido un error en el servidor -->");
									debug(json_estado.error);
									mostrar_error_thumnail(json_estado.error);
									return;
								}else if(json_estado.estado == 402){
									debug("Ha ocurrido un error en el servidor -->");
									debug(json_estado.error);
									mostrar_error_thumnail(json_estado.error);
									return;
								}else{
									debug('Los datos capturados desde el server fueron -->');
									debug(json_estado.datos);
									debug('------------------------------------------------');
									generar_info_csv(nombreCarpetaNube,json_estado);
								}
								
					},
					error: function(data,status,jqhxr){
								debug('Error en la solicitud');
								mostrar_error_thumnail(errStatus);
							}
					);
	}

	// Se genera el csv requerido para mostrar como descripcion en el thumbnail.
	function generar_info_csv(idFalla,json_estado){
		$.ajax(
			url:"../../helpers/generar_csv.php?idFalla="+idFalla+"&raizTmp="+json_estado.raiz_tmp,
			success:function(data,status,jqhxr){
				if (json_estado.estado != 200) {
					debug("Error interno del servidor ");
					debug(json_estado.error);
					mostrar_error_thumnail(json_estado.error);
					return;
				}
				debug("Obtenido csv de informacion...");
				var json_final = json_estado;
				var json_csv = JSON.parse(data);
				json_final["path_csv"] = json_csv.path_csv;
				// Continuar por aca! para el caso de exito.



			},
			error:function(data,errStatus,jqhxr){
				debug('Error en la solicitud');
				mostrar_error_thumnail(errStatus);
			});
	}



	// TODO: CONTINUAR ACA, CONFIGURANDO EL ALERT!!!
	// Genera un alert para el thumnail
	function mostrar_error_thumnail(msgError){
		// Configuracion del alert
		$('#error-alert').attr("class","alert alert-danger alert-dismissible fade");
		// 


	}

}( window.nameSpaceCgi = window.nameSpaceCgi || {},jQuery));








