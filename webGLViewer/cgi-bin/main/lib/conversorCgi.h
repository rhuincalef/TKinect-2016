#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include "../../pcd_to_json_script/lib/imprimir_datos_json.h"
#include "../../pcd_to_csv_webGL-guille/lib/generar_csv_desde_pcd.h"

// Path por defecto para los archivos en multimedia.
// TODO: Reemplazar esto por el directorio de multimedia cuando se integre todo
// a la aplicacion web.
const char* PATH_MULTIMEDIA = "/var/www/html/tkinect2016/webGLViewer/data";

// Subfijos por defecto para los archivos de csv a generar y la imagen.
// const std::string SUB_PC_CSV_DEFECTO = "_pc.csv"
// const std::string SUB_INFO_CSV_DEFECTO = "_info.csv"
// const std::string SUB_IMAGEN_DEFECTO = "_img.png"

const char* PROTO = "http://";
const char* HOST= "localhost";
const char* PATH_SERVER_ROOT_PCD = "tkinect2016/webGLViewer/data";
// Carpeta por defecto donde se agrupan los csv de datos.
const char* PATH_CSV_POR_DEFECTO = "csv_temp";

const int ERROR = 1;
const int EXITO = 0;


bool estaCadenaLimpia(const char* data);
void imprimirErrorJson(const char* msg);
char* obtenerNombreArchivoPuntos(char* dir);
char* construirUrl(char* dir);
// const char* generar_csv_info(const char* nombreCarpetaNube);
char* generar_imagen(char* nombreCarpetaNube,char* imgFile);
void crear_directorio(const char* url);


