// CGI BIN que es llamado por ajax desde conversorJs y enlaza la funcionalidad
// del resto de los scripts pcd_to_* (necesarios para generar la estructura que
// requiere el plugin de webGL_viewer).

// En caso de error retorna un json con un codigo de error que la siguiente forma:
//
// Content-Type: application/json; charset=UTF-8
// {
// 'estado':'400',
// 'datos': {},
// 'error':'URL malformada.Numero incorrecto de parametros'
// }


// Se incluye la definicion de la cabecera donde se definen los metodos de impresion
// de cabeceras http
#include "lib/conversorCgi.h"
extern int errno ;

// Verifica si la query string tiene solo los parametros necesarios
bool estaCadenaLimpia(const char* data){
	char* nombreCarpetaNube=(char*)malloc(MAX_CADENA);
	bool result = true;
	if(data == NULL || sscanf(data,CAMPO_QUERY_STRING,nombreCarpetaNube) != CANTIDAD_PARAM_QUERY_STRING)
		throw ExcepcionCGI("URL malformada.Numero incorrecto de parametros",COD_ERRORES_GENERALES);
	return result;
}

void imprimirErrorJson(char* msg,int codigo){
// data = {"estado": 200 | 400, "datos": {"csv_info":...
// 				"csv_nube": ... ,
// 				"imagen": ...},
// 				"error":"MENSAJE DE TIPO DE ERRROR"
// }
	std::cout << "Content-Type: application/json; charset=UTF-8\r\n\r\n";
	std::cout << "{" << std::endl;
	std::cout << "'estado':" << "'" << codigo << "'" << "," << std::endl;
	std::cout << "'datos': " << "{" <<  "}" << "," << std::endl;
	std::cout << "'error':" << "'"<< msg << "'" << std::endl;
	std::cout << "}" << std::endl;
}


// Escanea el directorio, comprueba que exista un .pcd en el directorio 
// y retorna el nombre del archivo de nube de puntos(.pcd).

char* obtenerNombreArchivoPuntos(char* dir){
	// std::cout << "Directorio raiz de pcd es: " << dir << std::endl;
	char* cad= (char *)malloc(MAX_CADENA);
	DIR *dp;
    struct dirent *entry;
    if((dp = opendir(dir)) == NULL){
    	char* err= (char *)malloc(MAX_CADENA);
    	strcpy(err,"No se pudo abrir directorio ");
    	strcat(err,dir);
    	throw ExcepcionCGI(err,COD_ERRORES_GENERALES);
    }
        
	// Se verifica que exista un archivo .pcd
  	chdir(dir);
    bool existePcdEnDir=false;
    while(!existePcdEnDir){
    	if ((entry = readdir(dp)) == NULL)
    		throw ExcepcionCGI("No existe archivo .pcd almacenado en servidor",COD_ERROR_PCD_INEXISTENTE);
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
	umask(000);
	int res = mkdir(url ,S_IRWXU | S_IRWXG | S_IRWXO );
	if (res != 0 && errno != EEXIST)
		throw ExcepcionCGI("Error de permisos en el servidor",COD_ERROR_IMAGEN_INEXISTENTE);
	// Se establece de nuevo el valor de la mascara a su valor por defecto
	umask(022);
}

void copiar_archivo(FILE* fuente,FILE* destino){
	char buffer[MAX_BUFFER];
	int cantBytes;

	// Si no ocurrio un error al leer
	while( (cantBytes = fread(buffer,MAX_BUFFER,1,fuente) )>0){
		fwrite(buffer,MAX_BUFFER,1,destino);
	}
	fclose(fuente);
	fclose(destino);

}


// Este metodo copia una imagen por defecto, desde una ubicacion por default,
// para cada carpeta en la nube de puntos.
// 
// NOTA: Ver si generar una imagen .png para el thumbnail desde el .pcd 
// cambiando el pipeline de la captura del .pcd, para que funcione
// con nubes de punto PointCloud<PointXYZRGB>.
char* generar_imagen(char* nombreCarpetaNube){
	char* imgDef = (char*)malloc(MAX_CADENA);
	strcpy(imgDef,PATH_IMG_DEFAULT);
	append_string(imgDef,"/");
	append_string(imgDef,(char*) NOMBRE_IMG_DEFAULT);

	char buffer[MAX_CADENA];
	FILE* fuente;
	FILE* destino;
	fuente = fopen(imgDef, "rb");
	/* Si se puede escribir, se copia a destino. Si existe no se hace nada,
		ya que retorna otro tipo de error (Error EEXIST) y no es necesario
		sobreescribirla. */
	if(fuente !=NULL){
		char* imgNueva = (char*)malloc(MAX_CADENA);
		strcpy(imgNueva,PATH_MULTIMEDIA);
		append_string(imgNueva,"/");
		append_string(imgNueva,nombreCarpetaNube);
		append_string(imgNueva,"/");
		append_string(imgNueva,PATH_CSV_POR_DEFECTO);
		append_string(imgNueva,"/");
		append_string(imgNueva,(char*) NOMBRE_IMG_DEFAULT);
		// std::cout << std::endl;
		// std::cout << "Archivo fuente abierto! Imagen nueva: "<< imgNueva << std::endl;
		// std::cout << std::endl;
		destino = fopen(imgNueva,"wb");
		if (destino == NULL)
			throw ExcepcionCGI("Error al escribir la imagen",COD_ERROR_IMAGEN_INEXISTENTE);	
		
		copiar_archivo(fuente,destino);
	}else{
		throw ExcepcionCGI("Error al leer la imagen por default",COD_ERROR_IMAGEN_INEXISTENTE);
	}
	return (char*)NOMBRE_IMG_DEFAULT;
}



// Agrega la URL raiz de los pcd 
// (carpeta general donde se guardan las subcarpetas para la falla)
// en el servidor al path local de una archivo(.csv o .png) y retorna la url completa. 
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


void append_string(char* destino,char* fuente){
	// // std::cout << "Long. destino: " << strlen(destino) << std::endl;
	// // std::cout << "Long. fuente: " << strlen(fuente) << std::endl;
	// // std::cout << std::endl;
	char arrTmp[MAX_CADENA];
	strcpy(arrTmp,destino);
	int tamanio_buffer_destino = sizeof arrTmp;

	// // std::cout << "tamanio_buffer_destino: " << tamanio_buffer_destino << std::endl;
	// // std::cout << std::endl;
	
	if ( (strlen(destino)-1) + strlen(fuente) > tamanio_buffer_destino){
		throw ExcepcionCGI("Tamanio de URL insuficiente",COD_ERRORES_GENERALES);
		return;
	}
	strncat(destino,fuente,strlen(fuente));
	// // std::cout << strncat(destino,fuente,strlen(fuente)) << std::endl;
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
		data = getenv("QUERY_STRING");
		estaCadenaLimpia(data);
		// Se extrae la url de la carpeta de la nube puntos
		char carpetaCsvs[MAX_CADENA]="";
		char nombreCarpetaNube[MAX_CADENA]="";
		// char pcFile[MAX_CADENA]="";
		char imgFile[MAX_CADENA]="";

		sscanf(data,CAMPO_QUERY_STRING,nombreCarpetaNube);
		
		 // Se arma la URL completa de la carpeta donde se almacenaran todos los archivos
		 // generados.
		strcpy(carpetaCsvs,PATH_MULTIMEDIA);
		append_string(carpetaCsvs,"/");
		append_string(carpetaCsvs,nombreCarpetaNube);
		append_string(carpetaCsvs,"/");
		append_string(carpetaCsvs,PATH_CSV_POR_DEFECTO);
		// std::cout << "6 carpetaCsvs: "<< carpetaCsvs << std::endl;
		// std::cout << "6 nombreCarpetaNube: "<< nombreCarpetaNube << std::endl;
		// std::cout << std::endl;

		// Se crea el directorio de los csv si no existe. 
		crear_directorio(carpetaCsvs);

		// Se obtiene el nombre del pcd en su carpeta y la url completa segun
		// el nombre del archivo del tipo de falla.
		char* carpetaRaizPcd=(char *)malloc(MAX_CADENA);
		char* nombrePcd=(char *)malloc(MAX_CADENA);

		strcpy(carpetaRaizPcd,PATH_MULTIMEDIA);	
		append_string(carpetaRaizPcd,"/");
		append_string(carpetaRaizPcd,nombreCarpetaNube);
		// std::cout << "2 carpetaRaizPcd: "<< carpetaRaizPcd << std::endl;
		// std::cout << std::endl;
		

		strcpy(nombrePcd, obtenerNombreArchivoPuntos(carpetaRaizPcd));
		char* pcGenerado=(char*) malloc(MAX_CADENA);
		strcpy(pcGenerado,generarCsv(nombrePcd,nombreCarpetaNube,carpetaRaizPcd,carpetaCsvs));		
	
		// Se copia una imagen por defecto para el thumbnail que se muestra para
		// la imagen, y se genera la URL de la misma. 
		char* imgGenerada=(char *)malloc(MAX_CADENA);
		imgGenerada = generar_imagen(nombreCarpetaNube);

		// Se arma la URL de la carpeta raiz y se pasa esto en un campo a parte
		// de los nombres de los archivos
		char* urlTmpCompleto = (char *)malloc(MAX_CADENA);
		char* tmp1=(char *)malloc(MAX_CADENA);
		strcpy(tmp1,nombreCarpetaNube);
		append_string(tmp1,"/");
		append_string(tmp1,PATH_CSV_POR_DEFECTO);
		append_string(tmp1,"/");
		urlTmpCompleto = construirUrl(tmp1);

		imprimir_json(pcGenerado,imgGenerada,urlTmpCompleto);

	}catch (ExcepcionCGI& e){
		imprimirErrorJson(e.mostrar(),e.codigo_error());
		result = ERROR;
	}catch (std::exception& e){
		imprimirErrorJson("Error interno del servidor",COD_ERRORES_GENERALES);
		result = ERROR;
	}
	return result;
}




