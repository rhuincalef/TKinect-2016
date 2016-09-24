// Path por defecto para los archivos en multimedia.
// TODO: Reemplazar esto por el directorio de multimedia cuando se integre todo
// a la aplicacion web.
const std::string PATH_MULTIMEDIA = "/var/www/html/tkinect2016/webGLViewer/data" 

// Subfijos por defecto para los archivos de csv a generar y la imagen.
const std::string SUB_PC_CSV_DEFECTO = "_pc.csv"
const std::string SUB_INFO_CSV_DEFECTO = "_info.csv"
const std::string SUB_IMAGEN_DEFECTO = "_img.png"

const std::string PROTO = "http://"
const std::string HOST= "localhost"
const std::string PATH_SERVER_ROOT_PCD = "tkinect2016/webGLViewer/data"
// Carpeta por defecto donde se agrupan los csv de datos.
const std::string PATH_CSV_POR_DEFECTO = "csv_temp";


void imprimirErrorJson(const char* msg);
bool estaCadenaLimpia(const char* data);
char* obtenerArchivoPuntos(std::string dir);
char* construirUrl(const char* dir);
const char* obtener_path_servidor(std::string url_de_pcd_de_falla);


