// Constantes globales compartidas por otros modulos
#ifndef INCLUIDO_MAX_CADENA
	#define INCLUIDO_MAX_CADENA
	const int MAX_CADENA = 150;
#else
	extern int MAX_CADENA;
#endif

// const char* PC_FILE_DEFECTO = "pc.csv";

// Directorio raiz en el servidor para el archivo .pcd especifico de una falla
// (directorio donde se almacena "Multimedia").
#ifndef INCLUIDO_PATH_PCD
	#define INCLUIDO_PATH_PCD
	const std::string PATH_PCD_EN_SERVIDOR = "http://localhost/web/multimedia/";
#else
	extern std::string PATH_PCD_EN_SERVIDOR;
#endif

// Se define una macro que indica al preprocesador que defina la constante
// en MAIN y en el resto de los modulos utilice extern (hecho en shared.h)
#ifndef INCLUIDO_FORMATO_COMPARTIDO
	#define INCLUIDO_FORMATO_COMPARTIDO
	const int FORMATO_NUBE = 0;
#else
	extern int FORMATO_NUBE;
#endif


// Metodos necesarios por varios modulos
void imprimir_json(char* csv_nube, char* imagen);
void debug(std::string msg);
char* generarCsv(char* pcdEntrada,char* nombreCarpetaNube, char* carpetaRaizPcd,char* carpetaCsv);
void append_string(char* destino,char* fuente);

