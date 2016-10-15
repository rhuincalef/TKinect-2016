#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string.h>


#define MAX_BUFFER 100
#define MAX_CADENA 200

void append_string(char* destino,char* fuente,int tamanio_buffer){
	std::cout << "Destino long.: " << strlen(destino) << std::endl;
	std::cout << "Fuente long.: " << strlen(fuente) << std::endl;
	
	if ( (strlen(destino)-1) + strlen(fuente) > tamanio_buffer){
		std::cout << "Error!" << std::endl;
		return;
	}
	std::cout << strncat(destino,fuente,strlen(fuente)) << std::endl;
	// return destino;
}

void copiar_archivo(FILE* fuente,FILE* destino){
	char* buffer= (char*) malloc(sizeof(char) * MAX_BUFFER);
	int cantBytes;
	// Si no ocurrio un error al leer
	while(1){
		if (feof(fuente)){
			// std::cout << "Alcanzado fin de archivo!" << std::endl;
			break;
		}
		cantBytes += fread(buffer,1,MAX_BUFFER,fuente);
		// std::cout << "Leidos  " << cantBytes << " bytes." << std::endl;
		fwrite(buffer,MAX_BUFFER,1,destino);
	}
	fclose(fuente);
	fclose(destino);
	free(buffer);
}


int main(int argc, char const *argv[])
{
	// char* str1=(char*)malloc(40);
	// char* str2=(char*)malloc(40);
	// strcpy(str1,"hola mundo msmsmmamammamamammamamamaksmdkamdsak");
	// std::cout << "primera copia: "<< str1<< std::endl;
	// strcpy(str1,"hola mundo");
	// std::cout << "segunda copia: "<< str1<< std::endl;
	// const std::string PATH_PCD_EN_SERVIDOR = "http://localhost/web/multimedia/";
	// std::cout << "Fin1: "<< str1<< std::endl;
	// const char* FORMATO_NUBE = 0;


	// char str1[12];
	// char str2[10];
	// strcpy(str1,"12345678");
	// strcpy(str2,"ABC");

	// std::cout << "str1: "<< str1<< std::endl;
	// std::cout << "str2: "<< str2<< std::endl;
	// append_string(str1,str2,sizeof str1);

	// std::cout << "Luego de append... "<< std::endl;
	// std::cout << "str1: "<< str1 << std::endl;
	// std::cout << "str2: "<< str2 << std::endl;

	FILE* fuente;
	FILE* destino;
	fuente = fopen("default.png", "rb");
	/* Si se puede escribir, se copia a destino. Si existe no se hace nada,
		ya que retorna otro tipo de error (Error EEXIST) y no es necesario
		sobreescribirla. */
	if(fuente !=NULL){
		char* imgNueva = (char*)malloc(MAX_CADENA);
		strcpy(imgNueva, "nueva.png");
		destino = fopen(imgNueva,"wb");
		if (destino == NULL){
			std::cout << "Error al abrir destino. "<< std::endl;
			fclose(fuente);
		}
		copiar_archivo(fuente,destino);
	}else{
		std::cout << "Error al abrir destino. "<< std::endl;	
	}
	return 0;
}