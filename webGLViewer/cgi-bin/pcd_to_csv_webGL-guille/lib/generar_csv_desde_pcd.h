#include <boost/lexical_cast.hpp>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/common/centroid.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <regex>
#include <sys/stat.h>



#include "../../lib/shared.h"


#ifndef INCLUIDO_SUBFIJO_CSV
	#define INCLUIDO_SUBFIJO_CSV
	char* SUBFIJO_CSV_POR_DEFECTO = "_pc.csv";
#else
	extern SUBFIJO_CSV_POR_DEFECTO; 
#endif
std::string bool_cast(const bool b);
bool es_archivo_valido(std::string pathFile,std::string extension);


