#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/impl/point_types.hpp>
#include <stdint.h>
// #include <pcl/filters/filter.h>
#include <vector>
#include <limits>

// Esta clase recibe un .pcd como parametro y genera un .pcd que se encuentra
// organizado. Este pcd se empleara en generar_imagen_png.cpp.
// 
//  Ej. ./organizar_nube_pcd pcd_entrada.pcd pcd_salida.pcd 600 500.




// Cadena de prueba con un pcd adaptado.
// Prueba con rgb:
// cd /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/pcl-pcl-1.7.2rc2.1/bin;
// ./pcl_pcd2png --field rgb /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/build/prueba6_adaptado.pcd nuevo.png

// Prueba con normales:
// ./pcl_pcd2png --field normal /home/rodrigo/TESINA-2016-KINECT/pruebasPCLWebGL/pcd_to_png/obtener_normales_de_pcd/pcd_normales.pcd 2.png

const int DEFAULT_IMG_WIDTH = 600;
const int DEFAULT_IMG_HEIGHT = 500;
// const int DEFAULT_IMG_WIDTH = 640;
// const int DEFAULT_IMG_HEIGHT = 480;



int main (int argc, char** argv)
{
  std::cout << "hola!" << std::endl;
  
  pcl::PointCloud<pcl::PointXYZ> cloud,cloud_tmp;
  pcl::PointCloud<pcl::PointXYZRGB> cloud_rgb;
  std::vector<int> v;
  
  const char* nube_entrada = argv[1];
  const char* nube_salida = argv[2];

  std::cout << "hola2" << std::endl;
  pcl::io::loadPCDFile(nube_entrada,cloud);
  std::cout << "Se leyo la nube de entrada" << std::endl;
  
  // // Se organizan las dimensiones de la nube para que se pueda generar
  // // una imagen a partir de ella.
  // cloud.width    = 640;
  // cloud.height   = 480;
  // cloud.is_dense = false;
  // // cloud.is_dense = true;

  // cloud.points.resize (cloud.width * cloud.height);
  // std::cout << "width:" << cloud.width << std::endl;
  // std::cout << "height:" << cloud.height << std::endl;

  // Se genera un color rojo para cada punto RGB en la nube
  uint8_t r = 255, g = 0, b = 0;    // Example: Red color
  std::cout << "COLORES GENERADOS"<<std::endl;
  uint32_t rgb = ((uint32_t)r << 16 | (uint32_t)g << 8 | (uint32_t)b); 

  int a = 0;
  const int MAX_PRINTS = 5;
  for (int i = 0; i < cloud.points.size(); ++i)
  {
      if (a >= MAX_PRINTS)
      {
        std::cout << "iteracion:" << a << std::endl;
      }
      if ( !pcl_isnan(cloud.points[i].x) && !pcl_isnan(cloud.points[i].y) && !pcl_isnan(cloud.points[i].z))
      {
          pcl::PointXYZRGB p;
          p.x = cloud[i].x;
          p.y = cloud[i].y;
          p.z = cloud[i].z;
          p.rgb = *reinterpret_cast<float*>(&rgb);
          cloud_rgb.push_back(p);
      } 
  }
  std::cout << "Fuera del for!" << "tamanio: " << cloud_rgb.points.size()<<std::endl;
  // // Se organizan las dimensiones de la nube para que se pueda generar
  // // una imagen a partir de ella.
  cloud_rgb.is_dense = false;
  cloud_rgb.width    = DEFAULT_IMG_WIDTH;
  cloud_rgb.height   = DEFAULT_IMG_HEIGHT;

  std::cout << "Antes del if" << std::endl;
  std::cout << "cantdad: "<< argc << std::endl;
  // if (argc == 5){
  //   cloud_rgb.width = (uint32_t)argv[3];
  //   cloud_rgb.height = (uint32_t)argv[4];
  // }

  cloud_rgb.points.resize (cloud_rgb.width * cloud_rgb.height);
  std::cout << "width:" << cloud_rgb.width << std::endl;
  std::cout << "height:" << cloud_rgb.height << std::endl;

  if (cloud_rgb.points.size() > 0)
  {
    std::cout << "Archivo " << nube_salida << " generado correctamente(" << cloud_rgb.points.size() << ")" << std::endl;
    pcl::io::savePCDFileBinaryCompressed(nube_salida,cloud_rgb);
  }

  return (0);
  


  // // for (size_t i = 0; i < cloud.points.size (); ++i)
  // // {
  // //   cloud.points[i].x = 1024 * rand () / (RAND_MAX + 1.0f);
  // //   cloud.points[i].y = 1024 * rand () / (RAND_MAX + 1.0f);
  // //   cloud.points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);
  // // }

  // // pcl::io::savePCDFileASCII ("test_pcd.pcd", cloud);
  // // std::cerr << "Saved " << cloud.points.size () << " data points to test_pcd.pcd." << std::endl;

  // // for (size_t i = 0; i < cloud.points.size (); ++i)
  // //   std::cerr << "    " << cloud.points[i].x << " " << cloud.points[i].y << " " << cloud.points[i].z << std::endl;

}
