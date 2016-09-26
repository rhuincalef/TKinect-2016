#include <stdio.h>
#include <stdlib.h>
#include <iostream>




int main(int argc, char const *argv[])
{
	char* data;
	char nombre [50];
	data = getenv("QUERY_STRING");
	sscanf(data,"nombre=%s",nombre);
	
	std::cout << "Content-Type: application/json; charset=UTF-8\r\n\r\n";
	std::cout << "{ 'nombre' : '"<< nombre << "'," << std::endl;
	std::cout << " 'apellido' :"<< " 'HF' " << "}" << std::endl;	
	return 0;
}