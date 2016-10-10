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


// Definicion de la excepcion principal.
class ExcepcionCGI: public std::exception
{
	private:
		char* msg;
		int codigo;

	public:
		ExcepcionCGI(char* msg1,int codigo1);
		char* mostrar();
		int codigo_error();
 };

ExcepcionCGI::ExcepcionCGI(char* msg1,int codigo1){
	msg = msg1;
	codigo = codigo1;
}

char* ExcepcionCGI::mostrar(){
	return msg;
}

int ExcepcionCGI::codigo_error(){
	return codigo;
}


// Verifica si la query string tiene solo los parametros necesarios
bool estaCadenaLimpia(const char* data){
	char* nombreCarpetaNube=(char*)malloc(MAX_CADENA);
	bool result = true;
	std::cout << "estaCadenaLimpia()" << std::endl;
	if(data == NULL || sscanf(data,"nombreCarpetaNube=%s",nombreCarpetaNube) != CANTIDAD_PARAM_QUERY_STRING)
		throw ExcepcionCGI("URL malformada.Numero incorrecto de parametros",COD_ERRORES_GENERALES);
	std::cout << "sali!" << std::endl;
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
	std::cout << "Directorio raiz de pcd es: " << dir << std::endl;
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
	std::cout << "La url para crear el dir temporal es: "<< url << std::endl;
	mkdir(url, 0777);
  // std::cout << "Directorio a crear: "<< url << std::endl;
  // if (mkdir(url, 0777)){
  //   debug("Directorio existia!!");
  // }else{
  //   debug("Directorio creado!");
  // }
}



void copiar_archivo(int fuente,int destino){
	char buffer[MAX_BUFFER];
	int cantBytes;
	// Si no ocurrio un error al leer
	while ( (cantBytes = read(fuente,buffer,MAX_BUFFER-1)) != -1) {
		// Se cierra el arreglo con el caracter terminador.
		buffer[cantBytes] = '\0';
		if (write(destino,buffer,MAX_BUFFER-1) == -1){
			close(fuente);
			close(destino);
			throw ExcepcionCGI("Error: Escritura de imagen en el servidor",COD_ERRORES_GENERALES);
		}
	}
	if (cantBytes == -1 ){
		close(fuente);
		close(destino);
		throw ExcepcionCGI("Error: Lectura de imagen en el servidor",COD_ERRORES_GENERALES);
	}
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
	strcpy(imgDef,"/");
	strcat(imgDef,NOMBRE_IMG_DEFAULT);
	int fuente = open(imgDef, O_RDONLY, S_IRUSR | S_IWUSR);
	/* Si se puede escribir, se copia a destino. Si existe no se hace nada,
		ya que retorna otro tipo de error (Error EEXIST) y no es necesario
		sobreescribirla. */
	if(fuente == 0){
		char* imgNueva = (char*)malloc(MAX_CADENA);
		strcpy(imgNueva,PATH_MULTIMEDIA);
		strcpy(imgNueva,"/");
		strcat(imgNueva,nombreCarpetaNube);
		strcpy(imgNueva,"/");
		strcat(imgNueva,NOMBRE_IMG_DEFAULT);
		int destino = open(imgNueva, O_RDWR | O_EXCL, S_IRUSR | S_IWUSR);
		copiar_archivo(fuente,destino);
	}else if (fuente == EACCES) {
		close(fuente);
		throw ExcepcionCGI("Error: Permisos en el servidor",COD_ERRORES_GENERALES);
	}
	return (char*)NOMBRE_IMG_DEFAULT;
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


void append_string(char* destino,char* fuente,int tamanio_buffer_destino){
	if ( (strlen(destino)-1) + strlen(fuente) > tamanio_buffer_destino){
		throw ExcepcionCGI("Tamanio de URL insuficiente",COD_ERRORES_GENERALES);
		return;
	}
	strncat(destino,fuente,strlen(fuente));
	// std::cout << strncat(destino,fuente,strlen(fuente)) << std::endl;
}


// Este script recibe como unico argumento el nombre de la carpeta de la nube
// de puntos en la carpeta multimedia del servidor. 
// 
// Modo de ejecucion en el navegador con js --> 
// http://localhost/tkinect2016/webGLViewer/cgi-bin/main/build/conversorCgi?nombreCarpetaNube=pointcloud_1
int main(int argc, char const *argv[])
{
	std::cout << "Salida!!!!!!!" << std::endl; 
	int result=EXITO;
	try{
		char* data;
		std::cout << "1" << std::endl;
		data = getenv("QUERY_STRING");
		estaCadenaLimpia(data);
		
		// Se extrae la url de la carpeta de la nube puntos
		char carpetaCsvs[MAX_CADENA]="";
		char nombreCarpetaNube[MAX_CADENA]="";
		char pcFile[MAX_CADENA]="";
		char imgFile[MAX_CADENA]="";

		// BACKUP
		// char carpetaCsvs[MAX_CADENA];
		// char nombreCarpetaNube[MAX_CADENA];
		// char pcFile[MAX_CADENA];
		// char imgFile[MAX_CADENA];
		sscanf(data,"nombreCarpetaNube=%s",nombreCarpetaNube);
				
		 // Se arma la URL completa de la carpeta donde se almacenaran todos los archivos
		 // generados.
		strcpy(carpetaCsvs,PATH_MULTIMEDIA);
		std::cout << "2 nombreCarpetaNube: "<< nombreCarpetaNube << std::endl;
		std::cout << "2 carpetaCsvs: "<< carpetaCsvs << std::endl;
		std::cout << std::endl;

		// strcat(carpetaCsvs,"/");
		append_string(carpetaCsvs,"/",sizeof carpetaCsvs);
		std::cout << "3 nombreCarpetaNube: "<< nombreCarpetaNube << std::endl;
		std::cout << "3 carpetaCsvs: "<< carpetaCsvs << std::endl;
		std::cout << std::endl;
		
		// strcat(carpetaCsvs,nombreCarpetaNube);
		append_string(carpetaCsvs,nombreCarpetaNube,sizeof carpetaCsvs);
		std::cout << "4 nombreCarpetaNube: "<< nombreCarpetaNube << std::endl;
		std::cout << "4 carpetaCsvs: "<< carpetaCsvs << std::endl;
		std::cout << "Tamanio: " << strlen(carpetaCsvs) << std::endl;
		// std::cout << std::endl;

		// strcat(carpetaCsvs,"/");
		append_string(carpetaCsvs,"/",sizeof carpetaCsvs);
		std::cout << "5 carpetaCsvs: "<< carpetaCsvs << std::endl;
		std::cout << "5 nombreCarpetaNube: "<< nombreCarpetaNube << std::endl;
		std::cout << std::endl;
		// strcat(carpetaCsvs,PATH_CSV_POR_DEFECTO);
		append_string(carpetaCsvs,PATH_CSV_POR_DEFECTO,sizeof carpetaCsvs);
		std::cout << "6 carpetaCsvs: "<< carpetaCsvs << std::endl;
		std::cout << "6 nombreCarpetaNube: "<< nombreCarpetaNube << std::endl;
		std::cout << std::endl;

		// Se crea el directorio de los csv si no existe. 
		// crear_directorio(carpetaCsvs);


		// // Se obtiene el nombre del pcd en su carpeta y la url completa segun
		// // el nombre del archivo del tipo de falla.
		// char* carpetaRaizPcd=(char *)malloc(MAX_CADENA);
		// char* nombrePcd=(char *)malloc(MAX_CADENA);

		// strcpy(carpetaRaizPcd,PATH_MULTIMEDIA);	
		// strcat(carpetaRaizPcd,"/");	
		// strcat(carpetaRaizPcd,nombreCarpetaNube);

		// strcpy(nombrePcd, obtenerNombreArchivoPuntos(carpetaRaizPcd));
		
		// char* pcGenerado;
		// pcGenerado = generarCsv(nombrePcd,pcFile,carpetaRaizPcd,carpetaCsvs);
		
		// // Se arma la URL para cada csv generado en el servidor.
		// char* urlPcCsv,urlInfoCsv;
		// char *urlImg;

		// // Se genera la ruta local dentro de la carpeta del pcd.
		// // Por ej. pointcloud_1/pointcloud_1_pc.csv
		// char* tmp1=(char *)malloc(MAX_CADENA);
		// strcpy(tmp1,PATH_CSV_POR_DEFECTO);
		// strcat(tmp1,"/");
		// strcat(tmp1,pcGenerado);
		// urlPcCsv = construirUrl(tmp1);

		// // Se copia una imagen por defecto para el thumbnail que se muestra para
		// // la imagen, y se genera la URL de la misma. 
		// char* imgGenerada=(char *)malloc(MAX_CADENA);
		// imgGenerada = generar_imagen(nombreCarpetaNube);
		// char* tmp3 = (char *)malloc(MAX_CADENA);
		// strcpy(tmp3,PATH_CSV_POR_DEFECTO);
		// strcat(tmp3,"/");
		// strcat(tmp3, imgGenerada);
		// urlImg = construirUrl(tmp3);

		// imprimir_json(urlPcCsv,urlImg);

	}catch (ExcepcionCGI& e){
		imprimirErrorJson(e.mostrar(),e.codigo_error());
		result = ERROR;
	}catch (std::exception& e){
		imprimirErrorJson("Error interno del servidor",COD_ERRORES_GENERALES);
		result= ERROR;
	}
	return result;
	
}




