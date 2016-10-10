#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string.h>


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


	char str1[12];
	char str2[10];
	strcpy(str1,"12345678");
	strcpy(str2,"ABC");

	std::cout << "str1: "<< str1<< std::endl;
	std::cout << "str2: "<< str2<< std::endl;
	append_string(str1,str2,sizeof str1);

	std::cout << "Luego de append... "<< std::endl;
	std::cout << "str1: "<< str1 << std::endl;
	std::cout << "str2: "<< str2 << std::endl;
	return 0;
}