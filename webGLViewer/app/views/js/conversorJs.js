
// Genera todos los archivos necesarios (csv,png,csv info) para renderizar 
// la nube con WebGL.
// Recibe la URL que contiene el directorio data/<NOMBRE-NUBE-PTOS> 
// (ej:...data/pointcloud_1)
// 
// Se recibe un json que tiene un campo de info con las url de los datos que 
// requiere el plugin y un campo de error que indica el tipo de error en 
// la cadena de conversion de los archivos.
// 		data = {"estado": 200 | 400, "datos": {"csv_info":...
// 				"csv_nube": ... ,
// 				"imagen": ...},
// 				"error":"MENSAJE DE TIPO DE ERRROR"
// }
// 

function transformarNubePtos(nombreCarpetaNube){
		$.ajax(
				url:"../../cgi-bin/conversorCgi?nombreCarpetaNube=" +nombreCarpetaNube,
				success:function(data,status,jqhxr){
							debug('Peticion a cgi-bin correcta!');
							var json_estado = JSON.parse(data);
							if (json_estado.estado == 400){
								debug(json_estado.error);
								return;
							}
							debug('Los datos capturados desde el server fueron -->');
							debug(json_estado.datos);
							debug('------------------------------------------------');
							// CONTINUAR POR ACA!!!
				},
				error: function(data,status,jqhxr){
							debug('Error en la SOLICITUD CGI-BIN');
						}
				);
}





