// Directorio raiz en el servidor para el archivo .pcd especifico de una falla
// (directorio donde se almacena "Multimedia").
const std::string PATH_PCD_EN_SERVIDOR = "http://localhost/web/multimedia/";
// Carpeta por defecto donde se agrupan los csv de datos.
const std::string PATH_CSV_POR_DEFECTO = "csv_temp/";

void generarCsv(const char* pcdEntrada, const char* pathCompletoPcd);

