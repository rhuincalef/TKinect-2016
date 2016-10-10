#include <boost/lexical_cast.hpp>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/common/centroid.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <regex>
#include <sys/stat.h>

// const int MAX_CADENA = 50;

// // const char* PC_FILE_DEFECTO = "pc.csv";

// // Directorio raiz en el servidor para el archivo .pcd especifico de una falla
// // (directorio donde se almacena "Multimedia").
// const std::string PATH_PCD_EN_SERVIDOR = "http://localhost/web/multimedia/";
// const std::string FORMATO_NUBE = 0;


#include "../../lib/shared.h"

std::string bool_cast(const bool b);
bool es_archivo_valido(std::string pathFile,std::string extension);
// char* generarCsv(char* pcdEntrada,char* pcFile, char* carpetaRaizPcd, char* carpetaCsv);


