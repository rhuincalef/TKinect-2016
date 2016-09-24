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

#include "lib/generar_csv_desde_pcd.h"

const char* PC_FILE_DEFECTO = "pc.csv"

class PointCloudToWebgl {

public:

  /**
   * Class constructor
   */
  PointCloudToWebgl(const std::string& input_cloud, const int& cloud_format,
      const std::string& output_cloud) :
    input_cloud_(input_cloud), cloud_format_(cloud_format), output_cloud_(output_cloud)
  {}

  /**
   * Convert the cloud
   */
  void convert()
  {
    std::cout << "[PointCloudToWebgl:] Opening file " << input_cloud_ << std::endl;

    // Init the cloud
    pcl::PointCloud<pcl::PointXYZRGB> cloud;

    // Read point cloud
    if (cloud_format_ == 0)
    {
      // NO RGB
      pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_xyz (new pcl::PointCloud<pcl::PointXYZ>);
      if (pcl::io::loadPCDFile<pcl::PointXYZ> (input_cloud_, *cloud_xyz) == -1) //* load the file
      {
        std::cout << "[PointCloudToWebgl:] Couldn't read file " << input_cloud_ << std::endl;
        return;
      }
      /*
      Ver si pertenece a PCL o ver alternativa.
      */
      copyPointCloud(*cloud_xyz, cloud);
    }
    else if (cloud_format_ == 1)
    {
      // RGB
      pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_xyzrgb (new pcl::PointCloud<pcl::PointXYZRGB>);
      if (pcl::io::loadPCDFile<pcl::PointXYZRGB> (input_cloud_, *cloud_xyzrgb) == -1) //* load the file
      {
        std::cout << "[PointCloudToWebgl:] Couldn't read file " << input_cloud_ << std::endl;
        return;
      }
      /*
      Ver si pertenece a PCL o ver alternativa.
      */
      copyPointCloud(*cloud_xyzrgb, cloud);
    }

    // Compute the cloud centroid
    Eigen::Vector4f centroid;
    pcl::compute3DCentroid(cloud, centroid);

    // Save int file
    std::cout << "[PointCloudToWebgl:] Saving webgl file to " << output_cloud_ << std::endl;
    /*
      Ver si pertenece a PCL o ver alternativa.
      - - - f_webgl  - -
    */
    std::fstream f_webgl(output_cloud_.c_str(), std::ios::out);
    for (unsigned int i=0; i<cloud.size(); i++)
    {
      int r = 224;
      int g = 224;
      int b = 224;
      if (cloud_format_ == 1)
      {
        r = (int)cloud[i].r;
        g = (int)cloud[i].g;
        b = (int)cloud[i].b;
      }
      f_webgl << cloud[i].x - centroid[0] << "," <<
                 cloud[i].y - centroid[1] << "," <<
                 cloud[i].z - centroid[2] << "," <<
                 r << "," <<
                 g << "," <<
                 b << std::endl;

    }
    f_webgl.close();
    std::cout << "[PointCloudToWebgl:] Saved!" << std::endl;
  }

  private:
  std::string input_cloud_;
  std::string output_cloud_;
  int cloud_format_;
};



void debug(std::string msg){
  std::cout << msg << std::endl;
  std::cout << "" << std::endl;
}


using namespace std;

void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

// Funcion para la division de cadenas
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

string bool_cast(const bool b) {
    ostringstream ss;
    ss << boolalpha << b;
    return ss.str();
}



// Este metodo acepta el path donde debe determinar si existe un archivo 
// de ese tipo.
bool es_archivo_valido(std::string pathFile,std::string extension){
  bool result = false;
  std::size_t found = pathFile.find(extension);
  // std::size_t found = pathFile.find(".csv");
  if (found != std::string::npos)
    result = true;
  debug("Comparado:");
  debug(pathFile);
  debug("Es archivo comparado un csv? :");
  debug(bool_cast(result)); 
  return result;
}



// Metodo principal que recibe el nombre del archivo .pcd, la carpeta donde reside este,
// y la carpeta donde se almacena el archivo de nube de puntos <IDFALLA>_pc.csv.
// Retorna el nombre del archivo .csv generado con el prefijo (ej. <IDFALLA>_pc.csv).
// 
const char* generarCsv(const char* pcdEntrada, const char* carpetaRaizPcd, const char* carpetaCsv){
  using namespace std;

  // Se genera el nombre del archivo csv con la nube de puntos por defecto.
  const char* nombreCsvSalida;
  strcpy(nombreCsvSalida,pcdEntrada);
  strcat(nombreCsvSalida,SUB_PC_CSV_DEFECTO);

  const char* pathCsvSalida;
  strcpy(pathCsvSalida,carpetaCsv);
  strcpy(pathCsvSalida,"/");
  strcpy(pathCsvSalida,nombreCsvSalida);
  

  const char* pathPcdEntrada;
  strcpy(pathPcdEntrada,carpetaRaizPcd);
  strcpy(pathPcdEntrada,"/");
  strcpy(pathPcdEntrada,pcdEntrada);

  // Read inputs
  std::string input_cloud(pathPcdEntrada);
  std::string output_cloud(pathCsvSalida);
  int cloud_format = boost::lexical_cast<int>(0);

  // Convert
  PointCloudToWebgl converter(input_cloud, FORMATO_NUBE, output_cloud);
  converter.convert();

  return nombreCsvSalida;

}


/**
 * Main entry point of the code.
 * Si se especifica un path para el csv de salida, se verifica la carpeta
 * y si no existe se la crea. 
 *
 *
 * Ej. de invocacion: ./pcd_to_csv prueba6.pcd 0 csv_temp/salida.csv
 *                    ./pcd_to_csv prueba6.pcd 0 salida.csv
 *
 */
// int main(int argc, char **argv)
// {
//   if (argc < 4)
//   {
//     std::cout << "Usage: " << argv[0] << " INPUT_PCD FORMAT OUTPUT_CSV" << std::endl;
//     std::cout << "  Example: " << argv[0] << " input_cloud.pcd 0 output_cloud.csv" << std::endl;
//     return 0;
//   }
//   using namespace std;
//   string out_csv_string = argv[3];

//   if (!esta_path_especificado(out_csv_string))
//   {
//     out_csv_string = PATH_CSV_POR_DEFECTO + out_csv_string;
//     debug("Path del directorio por defecto: ");
//     debug(out_csv_string);    
//     debug("-----------------------------------");
//   }

//   comprobar_directorio(out_csv_string);

//   // Read inputs
//   std::string input_cloud(argv[1]);
//   std::string output_cloud(argv[3]);
//   int cloud_format = boost::lexical_cast<int>(argv[2]);

//   // Convert
//   PointCloudToWebgl converter(input_cloud, cloud_format, output_cloud);
//   converter.convert();

//   return 0;
// }

