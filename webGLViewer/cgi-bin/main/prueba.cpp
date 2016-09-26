#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string.h>


int main(int argc, char const *argv[])
{
	char* str1=(char*)malloc(40);
	char* str2=(char*)malloc(40);
	strcpy(str1,"hola mundo msmsmmamammamamammamamamaksmdkamdsak");
	std::cout << "primera copia: "<< str1<< std::endl;
	strcpy(str1,"hola mundo");
	std::cout << "segunda copia: "<< str1<< std::endl;


	return 0;
}