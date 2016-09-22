
/**
 * Este script CGI se encarga de devolver una respuesta en formato JSON con HTTP
 *  que contenga la informacion de la ubicacion de los archivos csv,
 * necesarios para renderizar con webGL la nube de puntos en el navegador y,
 * la imagen de fondo de la falla. */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
* Este metodo retorna un <html> y acepta como parametros:
* -csv_nube: Archivo csv con los puntos obtenidos del archivo .pcd.
* -csv_info: Archivo csv con la informacion a mostrar del bache (altura,profunidad,criticidad).
* -imagen: Path de la imagen a mostrar por el plugin.
*	Ej. { "csv_nube" : "http://localhost/csv_temp/001.csv", 
*		  "csv_info" : "http://localhost/csv_temp/data.csv"
*		  "imagen" : "http://localhost/csv_temp/img.png" }
*
*/ 
void imprimir_json(const char* csv_nube,const char* csv_info, const char* imagen){
	cout << "{ \"csv_nube\" : " << csv_nube << "," << std::endl;
	cout << " \"csv_info\" : " << csv_info << "," << std::endl;
	cout << " \"imagen\" : " << imagen << std::endl;
	cout << " }"<< std::endl;
}


void imprimir_cabecera_http(){
	cout << "Content-type:application/json\r\n\r\n";
	cout << "<html>\n";
	cout << "<head>\n";
	cout << "<title>Solicitud de info CSV</title>\n";
	cout << "</head>\n";
	cout << "<body>\n";
}

void imprimir_footer(){
	cout << "</body>\n";
	cout << "</title>\n";
}


/*
* Main del script.
* Ej. de invocacion: ./imprimir_datos_json nube.csv info.csv imagen.png
*/
// int main(int argc, char **argv)
// {
// 	imprimir_cabecera_http();
// 	imprimir_json(argv[1],argv[2],argv[3]);
// 	imprimir_footer();
// 	return 0;
// }