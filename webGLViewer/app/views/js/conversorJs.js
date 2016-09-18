//  Este archivo realiza las peticiones ajax a los scripts cgi-bin
$.ajax(
	url:"../../cgi-bin/conversorCgi",
	success:function(data,status,jqhxr){
				debug("Peticion a cgi-bin correcta!");
	},
	error: function(data,status,jqhxr){
				debug("Error en la SOLICITUD CGI-BIN");
			}
	);




