cmake_minimum_required (VERSION 2.6)
project (conversorCgi.cgi)
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#Se buscan las configuraciones para PCL en el proyecto.
find_package(PCL 1.7 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# Se configuran los directorios de los elementos compilados en cmake
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)


# Se incluye el directorio lib/ para que se busque el archivo de cabecera.
include_directories("${PROJECT_BINARY_DIR}")


# Se agrega el directorio de busqueda de cmake para que busque
# con find_package() la configuracion(cargada en PCLConfig.cmake)
set(PCL_DIR "/usr/share/pcl-1.7/")
include_directories("${PCL_DIR}")

message("Directorios de archivos de cabecera incluidos...")
message("-----------------------------------------------") 



#Se agrega info de debugging para el script cgi.
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -w")


# Se incluyen la libreria de pcd_to_csv para ser compilada con el main
include_directories("../pcd_to_csv_webGL-guille/lib")
add_library(pcd_to_csv STATIC "../pcd_to_csv_webGL-guille/generar_csv_desde_pcd.cpp")


# Se incluyen la libreria de imprimir_datos_json para ser compilada con el main
include_directories("../pcd_to_json_script/lib")
add_library(pcd_to_json STATIC "../pcd_to_json_script/imprimir_datos_json.cpp")


# Se incluyen la libreria con definicion de excepciones
include_directories("../excepciones/lib")
add_library(excepciones STATIC "../excepciones/excepciones.cpp")


# TODO: AGREGAR EL CODIGO QUE GENERA LA IMAGEN ACA COMO LIBRERIA!!!
# Se incluyen la libreria de pcd_to_csv para ser compilada con el main
#include_directories("../pcd_to_csv_webGL-guille/lib")
#add_library(pcd_to_csv "../pcd_to_csv_webGL-guille/generar_csv_desde_pcd.cpp")


# add the executable
add_executable(conversorCgi.cgi conversorCgi.cpp)


# Se vincula la libreria que genera el .csv a partir del .pcd 
target_link_libraries(pcd_to_csv ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES})

target_link_libraries(conversorCgi.cgi ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES}  pcd_to_csv  pcd_to_json excepciones)


