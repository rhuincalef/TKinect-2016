#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

// Escanea el directorio y obtiene el nombre del archivo de nube de puntos(.pcd).
char* obtenerNombreArchivoPuntos(const char* dir){
	char* cad =(char *) malloc(15);
	DIR *dp;
    struct dirent *entry;
    if((dp = opendir(dir)) == NULL) {
        fprintf(stderr,"cannot open directory: %s\n", dir);
    }else{
    	std::cout <<"2" <<std::endl;
		chdir(dir);
	    if ((entry = readdir(dp)) != NULL){
	    	std::cout <<"3" <<std::endl;
	    	std::cout <<"d->entry_name= "<< entry->d_name <<std::endl;
			strcpy(cad,entry->d_name);
			std::cout << "Cadena tiene: "<< cad << std::endl;
			std::cout <<"4" <<std::endl;
	    }
		std::cout <<"5" <<std::endl;
    }
	return cad;
}


int main(int argc, char const *argv[])
{	
	std::cout <<"1" <<std::endl;
	const char* c = ".";
	char* result;
	// char* result=(char *) malloc(15);;
	result=obtenerNombreArchivoPuntos(c);
	// strcpy(result,obtenerNombreArchivoPuntos(c));
	std::cout << "6" << std::endl;
	std::cout << result << std::endl;


	return 0;
}