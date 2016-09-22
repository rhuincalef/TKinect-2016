// CGI BIN que es llamado por ajax desde conversorJs y enlaza la funcionalidad
// del resto de los scripts pcd_to_* (necesarios para generar la estructura que
// requiere el plugin de webGL_viewer).

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>


// Se incluye la definicion de la cabecera donde se definen los metodos de impresion
// de cabeceras http
#include "../pcd_to_json_script/imprimir_datos_json.h"
#include "../pcd_to_csv_webGL-guille/generar_csv_desde_pcd.h"


// Path por defecto para los archivos en multimedia.
// TODO: Reemplazar esto por el directorio de multimedia cuando se integre todo
// a la aplicacion web.
const std::string PATH_MULTIMEDIA = "/var/www/html/tkinect2016/webGLViewer/data" 

const std::string HOST= "localhost"
const std::string PATH_SERVER = "tkinect2016/webGLViewer/data"



// Verifica si una cadena tiene solo los parametros necesarios
bool estaCadenaLimpia(const char* argv){
	char *data;
	char *urlCarpetaNube;
	data = getenv("QUERY_STRING");
	bool result = true;
	if(data == NULL || sscanf(data,"urlCarpetaNube=%ld",urlCarpetaNube)!=1)
		result = false;
	return result;
}

void imprimirErrorJson(const char* msg){
// data = {"estado": 200 | 400, "datos": {"csv_info":...
// 				"csv_nube": ... ,
// 				"imagen": ...},
// 				"error":"MENSAJE DE TIPO DE ERRROR"
// }
	imprimir_cabecera_http();
	std::cout << "{" << std::endl;
	std::cout << "'estado':" << "'" << 400 << "'" << "," << std::endl;
	std::cout << "'datos': " << "{" <<  "}" << "," << std::endl;
	std::cout << "'error':" << msg << std::endl;
	std::cout << "}" << std::endl;
	imprimir_footer();
}


// Escanea el directorio y obtiene el nombre del archivo de nube de puntos.
char* obtenerArchivoPuntos(std::string dir){
	const char* cad;
	DIR *dp;
    struct dirent *entry;
    if((dp = opendir(dir)) == NULL) {
        fprintf(stderr,"cannot open directory: %s\n", dir);
        return;
    }
    chdir(dir);
    if ((entry = readdir(dp)) != NULL)
		strcpy(cad,entry->d_name);
	return cad;
}


char* construirUrl(const char* dir){
	const char* tmp;
	strcpy(tmp,"http://");
	strcat(tmp,HOST);
	strcat(tmp,"/");
	strcat(tmp,PATH_SERVER);
	strcat(tmp,"/");
	return tmp;
}


// Este script recibe como unico argumento el nombre de la carpeta de la nube
// de puntos en la carpeta multimedia del servidor. 

// Modo de ejecucion en con js --> 
// ./conversorCgi pointcloud_1
int main(int argc, char const *argv[])
{
	if (!estaCadenaLimpia(argv[1]))
		imprimirErrorJson();

	// Se extrae la url de la carpeta de la nube puntos
	const char* nombreCarpetaNube;
	data = getenv("QUERY_STRING");
	sscanf(data,"nombreCarpetaNube=%ld",nombreCarpetaNube);

	// Se obtiene el nombre del pcd en su carpeta y la url completa segun
	// el nombre del pointcloud_1
	const char* nombrePcd,pathCompletoPcd;
	strcpy(pathCompletoPcd,PATH_MULTIMEDIA);
	strcat(pathCompletoPcd,"/");
	strcat(pathCompletoPcd,nombreCarpetaNube);

	nombrePcd = obtenerArchivoPuntos(pathCompletoPcd);
	generarCsv(nombrePcd,pathCompletoPcd);


	// TODO: Ver que hacer con urlImg.
	const char* urlPcCsv,urlInfoCsv,urlImg;
	urlPcCsv = construirUrl(pathCompletoPcd);
	urlInfoCsv = construirUrl(pathCompletoPcd);

	imprimir_cabecera_http();
	imprimir_json(pathPcCsv,urlInfoCsv,urlImg);
	imprimir_footer();

	return 0;
}




