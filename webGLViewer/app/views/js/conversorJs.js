
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


	function debug(msg){
		console.log(msg);
	}

	nameSpaceCgi.transformarNubePtos = function (idFalla){
			$.ajax({
					url:"cgi-bin/main/build/conversorCgi.cgi?idFalla=" + idFalla,
					success:function(data,status,jqhxr){
								debug('Peticion a cgi-bin correcta!');
								debug(data.error);
								// var json_estado = JSON.parse(data.responseText);
								var json_estado = data;
								if (json_estado.estado == 400){
									debug("Ha ocurrido un error en el servidor -->");
									debug(json_estado.error);
									nameSpaceCgi.mostrar_error_thumnail(json_estado.error);
									return;
								}else if(json_estado.estado == 401){
									debug("Ha ocurrido un error en el servidor -->");
									debug(json_estado.error);
									nameSpaceCgi.mostrar_error_thumnail(json_estado.error);
									return;
								}else if(json_estado.estado == 402){
									debug("Ha ocurrido un error en el servidor -->");
									debug(json_estado.error);
									nameSpaceCgi.mostrar_error_thumnail(json_estado.error);
									return;
								}else{
									debug('Los datos capturados desde el server fueron -->');
									debug(json_estado.datos);
									debug('------------------------------------------------');
									generar_info_csv(nombreCarpetaNube,json_estado);
								}
								
					},
					error: function(data,textoErr,jqhxr){
								// a = '{"estado":402,"datos": {},"error":"Error al escribir la imagen"}';
								// JSON.parse(a);
								debug('Error en la solicitud 1-->');
								debug(data);
								var json1 = JSON.parse(data.responseText);
								nameSpaceCgi.mostrar_error_thumnail(json1.error);
							}
						});
	}

	// Se genera el csv requerido para mostrar como descripcion en el thumbnail.
	function generar_info_csv(idFalla,json_estado){
		$.ajax({
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
				// Peticiones del json.
				
				csv_nube = json_final["raiz_tmp"]+json_final["csv_nube"];
				imagen = json_final["raiz_tmp"]+json_final["imagen"];
				path_csv = json_final["path_csv"];
				$("#imagenThumb").attr("src",imagen);
				// Se parsea el csv con la descripcion
				Papa.parse(path_csv, {
					download: true,
					complete: function(results, file) {
						// {
						// 	data:   // array of parsed data
						// 	errors: // array of errors
						// 	meta:   // object with extra info
						// }
						console.log("Resultados parseados del csv");
						console.log(result[0]);
						console.log(result[1]);
						$("#descripcion").append(result[0],result[1]);
					},
					error: function(err, file, inputElem, reason){
						nameSpaceCgi.mostrar_error_thumnail("Error en PapaParse: "+err);
					} 
				});

			},
			error:function(data,status,jqhxr){
				debug('Error en la solicitud 2 -->');
				nameSpaceCgi.mostrar_error_thumnail(status);
			}
		});
	}


	// Genera un alert para el thumnail
	nameSpaceCgi.mostrar_error_thumnail = function (msgError){
		$.notify({
					title: '<strong>Error en el servidor: </strong>',
					message: msgError
				},
				{
					type: 'danger'
		});
		$("#imagenThumb").attr("src","app/views/res/errorInterno.png");
	}

}( window.nameSpaceCgi = window.nameSpaceCgi || {},jQuery));








