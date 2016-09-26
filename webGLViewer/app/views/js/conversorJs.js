
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

	function transformarNubePtos(nombreCarpetaNube,nombrePc,nombreInfo,nombreImg){
			$.ajax(
					url:"../../cgi-bin/main/build/conversorCgi.cgi?nombreCarpetaNube=" +nombreCarpetaNube+
					"&pcFile="+nombrePc+"&imgFile="+nombreImg,
					success:function(data,status,jqhxr){
								debug('Peticion a cgi-bin correcta!');
								var json_estado = JSON.parse(data);
								if (json_estado.estado == 400){
									debug("Ha ocurrido un error en el servidor -->");
									debug(json_estado.error);
									return;
								}else{

									debug('Los datos capturados desde el server fueron -->');
									debug(json_estado.datos);
									debug('------------------------------------------------');
									generar_info_csv(nombreCarpetaNube,nombreInfo,json_estado);
								}
								
					},
					error: function(data,status,jqhxr){
								debug('Error en la SOLICITUD CGI-BIN');
							}
					);
	}

	function generar_info_csv(nombreCarpetaNube,nombreInfo,json_estado){
		$.ajax(
			url:"../../helpers/generar_csv.php?nombreCarpetaNube="+nombreCarpetaNube+"&infoFile="+nombreInfo,
			success:function(data,status,jqhxr){
				debug("Exito generando el csv...");
				var json1 = JSON.parse(data);
				var json_final = json_estado;
				json_final["path_csv"] = json1.path_csv;
				cargar_imagen_en_container(json_estado);				
			},
			error:function(data,status,jqhxr){
				debug("Error!!");
			});
	}


	// TODO: Ensamblar esta parte con la parte que lee los archivos pc.csv,
	// info.csv y imagen.png en Js!
	function cargar_imagen_en_container(json_estado){

	}

}( window.nameSpaceCgi = window.nameSpaceCgi || {},jQuery));








