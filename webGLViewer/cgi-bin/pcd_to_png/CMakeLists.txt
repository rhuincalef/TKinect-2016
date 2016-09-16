cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(organizar_nube_pcd)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Se configuran los directorios de los elementos compilados en cmake
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

find_package(PCL 1.7 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (organizar_nube_pcd organizar_nube_pcd.cpp)
target_link_libraries (organizar_nube_pcd ${PCL_LIBRARIES})