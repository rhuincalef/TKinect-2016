// CGI BIN que es llamado por ajax desde conversorJs y enlaza la funcionalidad
// del resto de los scripts pcd_to_* (necesarios para generar la estructura que
// requiere el plugin de webGL_viewer).


// Se incluye la definicion de la cabecera donde se definen los metodos de impresion
// de cabeceras http
#include "lib/conversorCgi.h"



// Definicion de la excepcion
class ExcepcionCGI: public std::exception
{
	private:
		char* msg;

	public:
		ExcepcionCGI(char* msg1);
		char* mostrar();
 };

ExcepcionCGI::ExcepcionCGI(char* msg1){
	msg = msg1;
}

char* ExcepcionCGI::mostrar(){
	return msg;
}


// Verifica si la query string tiene solo los parametros necesarios
bool estaCadenaLimpia(const char* data){
	char* nombreCarpetaNube,pcFile,imgFile;
	char* urlCarpetaNube;
	bool result = true;
	if(data == NULL || sscanf(data,"nombreCarpetaNube=%s&pcFile=%s&imgFile=%s",nombreCarpetaNube,pcFile,imgFile) != 3 )
		throw ExcepcionCGI("URL malformada.Numero incorrecto de parametros");
	return result;
}

void imprimirErrorJson(char* msg){
// data = {"estado": 200 | 400, "datos": {"csv_info":...
// 				"csv_nube": ... ,
// 				"imagen": ...},
// 				"error":"MENSAJE DE TIPO DE ERRROR"
// }
	std::cout << "Content-Type: application/json; charset=UTF-8\r\n\r\n";
	std::cout << "{" << std::endl;
	std::cout << "'estado':" << "'" << 400 << "'" << "," << std::endl;
	std::cout << "'datos': " << "{" <<  "}" << "," << std::endl;
	std::cout << "'error':" << msg << std::endl;
	std::cout << "}" << std::endl;
}


// Escanea el directorio, comprueba que exista un .pcd en el directorio 
// y retorna el nombre del archivo de nube de puntos(.pcd).

char* obtenerNombreArchivoPuntos(char* dir){
	char* cad= (char *)malloc(MAX_CADENA);
	DIR *dp;
    struct dirent *entry;
    if((dp = opendir(dir)) == NULL){
    	char* err= (char *)malloc(MAX_CADENA);
    	strcpy(err,"Error: No se pudo abrir directorio: %s\n");
    	strcat(err,dir);
    	throw ExcepcionCGI(err);
    }
        
	// Se verifica que exista un archivo .pcd
  	chdir(dir);
    bool existePcdEnDir=false;
    while(!existePcdEnDir){
    	if ((entry = readdir(dp)) == NULL)
    		throw ExcepcionCGI("Error: Falta archivo .pcd en servidor");
    	// Si existe un archivo en el servidor se copia el nombre en un string,
    	// y se comprueba si su extension es la de un archivo de nube de puntos
    	// valido (.pcd)
    	// NOTA: "cad" se limpia completa cada vez que se emplea strcpy() y se
    	// sobreescribe con la nueva cadena.
    	strcpy(cad,entry->d_name);
    	std::string fn(cad);
    	if(fn.substr(fn.find_last_of(".") + 1) == EXTENSION_NUBE_PUNTOS) {
			existePcdEnDir = true;
		}
    }
	return cad;
}


void crear_directorio(const char* url){
  if (mkdir(url, 0777)){
    debug("Directorio existia!!");
  }else{
    debug("Directorio creado!");
  }
}


// TODO TERMINAR!!
char* generar_imagen(char* nombreCarpetaNube,char* imgFile){
	return imgFile;
}


// Agrega la URL en el servidor de un archivo y retorna el string de la misma
char* construirUrl(char* dir){
	char* tmp=(char *)malloc(MAX_CADENA);
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
// 
// Modo de ejecucion en el navegador con js --> 
// http://localhost/tkinect2016/webGLViewer/cgi-bin/main/build/conversorCgi?nombreCarpetaNube=pointcloud_1
int main(int argc, char const *argv[])
{
	int result=EXITO;
	try{
		char* data;
		
		// char* carpetaCsvs=(char *)malloc(MAX_CADENA);
		// data = getenv("QUERY_STRING");
	 
	 //  	estaCadenaLimpia(data);
		
		// // Se extrae la url de la carpeta de la nube puntos
		// char* nombreCarpetaNube=(char *)malloc(MAX_CADENA);
		// char* pcFile=(char *)malloc(MAX_CADENA);
		// char* imgFile=(char *)malloc(MAX_CADENA);
		// sscanf(data,"nombreCarpetaNube=%s&pcFile=%s&imgFile=%s",nombreCarpetaNube,pcFile,imgFile);


		// // Se arma la URL completa de la carpeta donde se almacenaran todos los archivos
		// // generados.
		// strcpy(carpetaCsvs,PATH_MULTIMEDIA);
		// strcat(carpetaCsvs,"/");
		// strcat(carpetaCsvs,nombreCarpetaNube);
		// strcat(carpetaCsvs,"/");
		// strcat(carpetaCsvs,PATH_CSV_POR_DEFECTO);

		// // Se crea el directorio de los csv si no existe o no, en caso contrario. 
		// crear_directorio(carpetaCsvs);

		// // Se obtiene el nombre del pcd en su carpeta y la url completa segun
		// // el nombre del archivo del tipo de falla.
		// char* carpetaRaizPcd=(char *)malloc(MAX_CADENA);
		// char* nombrePcd=(char *)malloc(MAX_CADENA);

		// strcpy(carpetaRaizPcd,PATH_MULTIMEDIA);	
		// strcpy(carpetaRaizPcd,"/");	
		// strcpy(carpetaRaizPcd,nombreCarpetaNube);
		// strcpy(nombrePcd, obtenerNombreArchivoPuntos(carpetaRaizPcd));
		
		// char* pcGenerado;
		// pcGenerado = generarCsv(nombrePcd,pcFile,carpetaRaizPcd,carpetaCsvs);
		
		// // Se arma la URL para cada csv generado en el servidor.
		// char* urlPcCsv,urlInfoCsv;
		// char *urlImg;

		// // Se genera la ruta local dentro de la carpeta del pcd.
		// // Por ej. pointcloud_1/pointcloud_1_pc.csv
		// char* tmp1=(char *)malloc(MAX_CADENA);
		// strcat(tmp1,PATH_CSV_POR_DEFECTO);
		// strcat(tmp1,"/");
		// strcat(tmp1,pcGenerado);
		// urlPcCsv = construirUrl(tmp1);


		// // TODO: Llamar a php generar_csv.php que genera el csv con la info de la BD!!
		// // 

		// // const char* infoGenerado,tmp2;
		// // infoGenerado = generar_csv_info(nombreCarpetaNube);
		// // strcpy(tmp2,PATH_CSV_POR_DEFECTO);
		// // strcat(tmp2,"/");
		// // strcat(tmp2,infoGenerado);
		// // urlInfoCsv = construirUrl(tmp2);

		// // TODO: Ver si llamar al script para generar el .png a partir de la nube de puntos

		// char* imgGenerada=(char *)malloc(MAX_CADENA);
		// imgGenerada = generar_imagen(nombreCarpetaNube,imgFile);
		// char* tmp3 = (char *)malloc(MAX_CADENA);
		// strcpy(tmp3,PATH_CSV_POR_DEFECTO);
		// strcat(tmp3,"/");
		// strcat(tmp3, imgGenerada);
		// urlImg = construirUrl(tmp3);

		// imprimir_json(urlPcCsv,urlImg);

	}catch (ExcepcionCGI& e){
    	imprimirErrorJson(e.mostrar());
    	result = ERROR;
	}catch (std::exception& e){
		imprimirErrorJson("Error interno del servidor");
		result= ERROR;
	};
	return result;
}




