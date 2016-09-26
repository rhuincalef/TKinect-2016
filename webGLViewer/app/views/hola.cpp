#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <iomanip>


void imprimir_cabecera_http(){
	std::cout << "Content-type:application/json\r\n\r\n";
	std::cout << "<html>\n";
	std::cout << "<head>\n";
	std::cout << "<title>Solicitud de info CSV</title>\n";
	std::cout << "</head>\n";
	std::cout << "<body>\n";
}

void imprimir_footer(){
	std::cout << "</body>\n";
	std::cout << "</title>\n";
}


int main(int argc, char const *argv[])
{
	imprimir_cabecera_http();
	char* data;
	char* nombre;
	data = getenv("QUERY_STRING");
	sscanf(data,"nombre=%s",nombre);

	std::cout << "{ 'nombre' : "<<  nombre << "," << std::endl;
	std::cout << " 'apellido' :"<< "HF" << "}" << std::endl;
	imprimir_footer();	
	return 0;
}