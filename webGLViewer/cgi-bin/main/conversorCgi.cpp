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
#include "lib/conversorCgi.h"
#include "../pcd_to_json_script/imprimir_datos_json.h"
#include "../pcd_to_csv_webGL-guille/generar_csv_desde_pcd.h"



// Verifica si la query string tiene solo los parametros necesarios
bool estaCadenaLimpia(const char* data){
	char *urlCarpetaNube;
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


// Escanea el directorio y obtiene el nombre del archivo de nube de puntos(.pcd).
char* obtenerNombreArchivoPuntos(std::string dir){
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




// Metodo que obtiene la url completa en el servidor
// incluyendo la raiz de los .pcd, el .pcd particular
// para una peticion y la carpeta temporal donde se agruparan
// los cvs necesarios para la visualizacion con WebGL.
const char* obtener_path_servidor(std::string url_de_pcd_de_falla){
  // TODO: Descomentar con esto cuando se quiera probar el script
  // CGI en el servidor.
  // return PATH_PCD_EN_SERVIDOR+"/"+url_de_pcd_de_falla;

  // TODO: Comentar esto para probar local.
  char cwd[1024];
  std::string current_dir;
  if (getcwd(cwd, sizeof(cwd)) != NULL)
    current_dir = cwd;
  return (cwd+url_de_pcd_de_falla).c_str();
}




// Verifica si un directorio existe
int comprobar_directorio(std::string pathFile){
    debug("En comprobar direcorios");
    debug(pathFile);

    vector<string> elems;
    elems=split(pathFile,'/');
    // elems=split("hola/1.csv",'/');
    std::string url;
    std::string tmp;
    url.append("/");

    debug("Elementos parseados del string --> ");
    for (int i = 0; i < elems.size(); ++i)
    {
      if (!elems[i].empty() && !es_archivo_csv(elems[i]) )
      {
        tmp= elems[i] + "/";
        url.append(tmp);  
      }
    }
    debug("Ruta completa del archivo ");
    debug(url);

    crear_directorio(url);

    debug("-------------------------------------");
    debug("fin comprobar_directorio()");
  }



void crear_directorio(std::string url){
  const char* p = obtener_path_servidor(url); 
  debug("Directorio de trabajo actual -->");
  debug(p);
  if (mkdir(p, 0777)){
    debug("Directorio existia!!");
  }else{
    debug("Directorio creado!");
  }

}


// TODO TERMINAR!!
const char* generar_csv_info(const char* nombreCarpetaNube){


}
// TODO TERMINAR!!
const char* generar_imagen(const char* nombreCarpetaNube){
	return "1.png";
}


// Agrega la URL en el servidor de un archivo y retorna el string de la misma
char* construirUrl(const char* dir){
	const char* tmp;
	strcpy(tmp,PROTO);
	strcat(tmp,HOST);
	strcat(tmp,"/");
	strcat(tmp,PATH_SERVER_ROOT_PCD);
	strcat(tmp,"/");
	strcat(tmp,dir);
	return tmp;
}





// Este script recibe como unico argumento el nombre de la carpeta de la nube
// de puntos en la carpeta multimedia del servidor. 

// Modo de ejecucion en el navegador con js --> 
// http://localhost/tkinect2016/webGLViewer/cgi-bin/main/build/conversorCgi?nombreCarpetaNube=pointcloud_1
int main(int argc, char const *argv[])
{
	const char* data;
	const char* carpetaCsvs;
	data = getenv("QUERY_STRING");
	if (!estaCadenaLimpia(data)){
		imprimirErrorJson();
		return 1;
	}else{
		// Se extrae la url de la carpeta de la nube puntos
		const char* nombreCarpetaNube;
		sscanf(data,"nombreCarpetaNube=%ld",nombreCarpetaNube);


		// Se arma la URL completa de la carpeta donde se almacenaran todos los archivos
		// generados.
		strcpy(carpetaCsvs,PATH_MULTIMEDIA);
		strcat(carpetaCsvs,"/");
		strcat(carpetaCsvs,nombreCarpetaNube);
		strcat(carpetaCsvs,"/");
		strcat(carpetaCsvs,PATH_CSV_POR_DEFECTO);

		// Se crea el directorio de los csv si no existe o no, en caso contrario. 
		crear_directorio(carpetaCsvs);

		// Se obtiene el nombre del pcd en su carpeta y la url completa segun
		// el nombre del archivo del tipo de falla.
		const char* carpetaRaizPcd;
		strcpy(carpetaRaizPcd,PATH_MULTIMEDIA);	
		strcpy(carpetaRaizPcd,"/");	
		strcpy(carpetaRaizPcd,nombreCarpetaNube);
		nombrePcd = obtenerNombreArchivoPuntos(carpetaRaizPcd);
		const char* pcGenerado;
		pcGenerado = generarCsv(nombrePcd,carpetaRaizPcd,carpetaCsvs);

		
		// Se arma la URL para cada csv generado en el servidor.
		const char* urlPcCsv,urlInfoCsv,urlImg;

		// Se genera la ruta local dentro de la carpeta del pcd.
		// Por ej. pointcloud_1/pointcloud_1_pc.csv
		const char* tmp1;
		strcat(tmp1,PATH_CSV_POR_DEFECTO);
		strcat(tmp1,"/");
		strcat(tmp1,pcGenerado);
		urlPcCsv = construirUrl(tmp1);


		// TODO: Llamar a php generar_csv.php que genera el csv con la info de la BD!!
		// 

		const char* infoGenerado,tmp2;
		infoGenerado = generar_csv_info(nombreCarpetaNube);
		strcpy(tmp2,PATH_CSV_POR_DEFECTO);
		strcat(tmp2,"/");
		strcat(tmp2,infoGenerado);
		urlInfoCsv = construirUrl(tmp2);

		// TODO: Ver si llamar al script para generar el .png a partir de la nube de puntos

		const char* imgGenerada,tmp3;
		imgGenerada = generar_imagen(nombreCarpetaNube);
		strcpy(tmp3,PATH_CSV_POR_DEFECTO);
		strcat(tmp3,"/");
		strcat(tmp3, imgGenerada);
		urlImg= construirUrl(tmp3);

		imprimir_cabecera_http();
		imprimir_json(urlPcCsv,urlInfoCsv,urlImg);
		imprimir_footer();

		return 0;
	}
	return;
}




