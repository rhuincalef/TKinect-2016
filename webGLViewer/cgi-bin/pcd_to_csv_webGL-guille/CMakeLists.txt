# Instalacion de librerias vtk para Ubuntu -->
# sudo apt-get -y install tcl-vtk python-vtk libvtk-java 

#Ejecucion del script para transformar un .pcd en .csv
#./generar_csv_desde_pcd prueba6.pcd 0 salida.csv


cmake_minimum_required (VERSION 2.6)
project (generar_csv_desde_pcd)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


#Se buscan las configuraciones para PCL en el proyecto.
find_package(PCL 1.7 REQUIRED)


include_directories("${PCL_INCLUDE_DIRS}")
message("Valor de variable PCL_INCLUDE_DIRS es --> ")
message("${PCL_INCLUDE_DIRS}")
message("")


link_directories(${PCL_LIBRARY_DIRS})
message("Valor de variable PCL_LIBRARY_DIRS es --> ")
message("${PCL_LIBRARY_DIRS}")
message("")

add_definitions(${PCL_DEFINITIONS})

# Se configuran los directorios de los elementos compilados en cmake
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)



# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")


# Se agrega el directorio de busqueda de cmake para que busque
# con find_package() la configuracion(cargada en PCLConfig.cmake)
set(PCL_DIR "/usr/share/pcl-1.7/")
include_directories("${PCL_DIR}")

message("Directorios de archivos de cabecera incluidos...")
message("-----------------------------------------------") 

 
# add the executable
add_executable(generar_csv_desde_pcd generar_csv_desde_pcd.cpp)
target_link_libraries(generar_csv_desde_pcd ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES})
