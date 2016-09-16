cmake_minimum_required (VERSION 2.6)
project (imprimir_datos_json)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# Se configuran los directorios de los elementos compilados en cmake
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

message("Directorios de archivos de cabecera incluidos...")
message("-----------------------------------------------")  

# add the executable
add_executable(imprimir_datos_json imprimir_datos_json.cpp)
