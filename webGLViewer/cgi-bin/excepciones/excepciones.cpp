// Implementacion de los metodos de ExcepcionCGI
#include <exception>
#include "lib/excepciones.h"

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
