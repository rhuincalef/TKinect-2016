// Definicion de la excepcion principal.
#ifndef INCLUIDAS_EXCEPCION_CGI
#define INCLUIDAS_EXCEPCION_CGI
class ExcepcionCGI: public std::exception {
	private:
		char* msg;
		int codigo;

	public:
		ExcepcionCGI(char* msg1,int codigo1);
		char* mostrar();
		int codigo_error();
 };
#endif
