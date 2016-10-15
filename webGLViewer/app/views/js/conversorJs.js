
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


	debug = function (msg){
		console.log(msg);
	}

	nameSpaceCgi.transformarNubePtos = function (idFalla){
			$.ajax({
					url:"cgi-bin/main/build/conversorCgi.cgi?idFalla=" + idFalla,
					success:function(data,status,jqhxr){
								debug('Peticion a cgi-bin correcta!');
								debug(jqhxr.responseText);

								// var json_estado = JSON.parse(data.responseText);
								// var json_estado = data;
								var json_estado = JSON.parse(jqhxr.responseText);
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
									generar_info_csv(idFalla,json_estado);
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
	generar_info_csv = function(idFalla,json_estado){
		debug("json_estado.raiz_tmp = ");
		debug(json_estado.raiz_tmp);
		$.ajax({
			url:"app/helpers/generar_csv_php/generar_csv.php?idFalla="+idFalla+"&raizTmp="+json_estado.raiz_tmp,
			success:function(data,status,jqhxr){
				var json_info_csv = JSON.parse(jqhxr.responseText);
				if (json_info_csv.estado != 200) {
					debug("Error interno del servidor ");
					debug(json_info_csv.error);
					nameSpaceCgi.mostrar_error_thumnail(json_info_csv.error);
					return;
				}
				debug("Obtenido csv de informacion...");
				var json_final = json_estado;
				json_final["path_csv"] = json_info_csv.path_csv;

				// Peticiones del json.
				csv_nube = json_final["raiz_tmp"]+json_final["csv_nube"];
				imagen = json_final["raiz_tmp"]+json_final["imagen"];
				path_csv = json_final["path_csv"];
				
				// Se parsea el csv con la descripcion
				Papa.parse(path_csv, {
					download: true,
					complete: function(results, file) {
						mostrar_texto_thumnail(idFalla,results.data[0][0],
							results.data[1][0],imagen);
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

	// Configura el thumbnail para el caso de exito.
	mostrar_texto_thumnail = function(idFalla,titulo,descripcion,imagen){
		$("#descripcion").attr("class", "texto-exito");
		$("#descripcion").append("<h2>"+titulo+"</h2>");
		$("#descripcion").append("<h4>"+descripcion+"</h4>");
		$("#botonVisualizador").attr("style","display:inline;");
		$("#botonVisualizador").attr("href",
			"app/views/viewer.php?c=" + idFalla);
		$("#contBoton").attr("class","margen-boton");
		// $("#imagenThumb").attr("src","http://localhost/tkinect2016/webGLViewer/img/default.png");
		$("#imagenThumb").attr("src",imagen);

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
		$("#descripcion").attr("class","texto-error");
		$("#descripcion").append("Archivo no encontrado");
	}

}( window.nameSpaceCgi = window.nameSpaceCgi || {},jQuery));








