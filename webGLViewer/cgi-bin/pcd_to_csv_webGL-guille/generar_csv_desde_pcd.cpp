#include "lib/generar_csv_desde_pcd.h"

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
    // std::cout << "[PointCloudToWebgl:] Opening file " << input_cloud_ << std::endl;

    // Init the cloud
    pcl::PointCloud<pcl::PointXYZRGB> cloud;

    // Read point cloud
    if (cloud_format_ == 0)
    {
      // NO RGB
      pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_xyz (new pcl::PointCloud<pcl::PointXYZ>);
      if (pcl::io::loadPCDFile<pcl::PointXYZ> (input_cloud_, *cloud_xyz) == -1) //* load the file
      {
        // std::cout << "[PointCloudToWebgl:] Couldn't read file " << input_cloud_ << std::endl;
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
        // std::cout << "[PointCloudToWebgl:] Couldn't read file " << input_cloud_ << std::endl;
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
    // std::cout << "[PointCloudToWebgl:] Saving webgl file to " << output_cloud_ << std::endl;
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
    // std::cout << "[PointCloudToWebgl:] Saved!" << std::endl;
  }

  private:
  std::string input_cloud_;
  std::string output_cloud_;
  int cloud_format_;
};



void debug(std::string msg){
  // std::cout << msg << std::endl;
  // std::cout << "" << std::endl;
}


std::string bool_cast(const bool b) {
    std::ostringstream ss;
    ss << std::boolalpha << b;
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
char* generarCsv(char* pcdEntrada,char* nombreCarpetaNube, char* carpetaRaizPcd,
                    char* carpetaCsv){
  using namespace std;

  // Se arma el nombre del csv de salida correspondiente usando el nombre de
  // la carpeta raiz del .pcd
  char nombreCSVSalida[MAX_CADENA];
  strcpy(nombreCSVSalida,nombreCarpetaNube);
  append_string(nombreCSVSalida,SUBFIJO_CSV_POR_DEFECTO);


  // Se genera la ruta completa del csv de salida.
  char* pathCsvSalida=(char *)malloc(MAX_CADENA);
  strcpy(pathCsvSalida,carpetaCsv);
  append_string(pathCsvSalida,"/");
  append_string(pathCsvSalida,nombreCSVSalida);


  // Se genera la ruta completa con el .pcd que se convertira.
  char* pathPcdEntrada=(char *)malloc(MAX_CADENA);
  strcpy(pathPcdEntrada,carpetaRaizPcd);
  append_string(pathPcdEntrada,"/");
  append_string(pathPcdEntrada,pcdEntrada);

  // Read inputs
  std::string input_cloud(pathPcdEntrada);
  std::string output_cloud(pathCsvSalida);
  // int cloud_format = boost::lexical_cast<int>(FORMATO_NUBE);

  // Convert
  PointCloudToWebgl converter(input_cloud,FORMATO_NUBE, output_cloud);
  // PointCloudToWebgl converter(input_cloud,cloud_format, output_cloud);
  converter.convert();
  return nombreCSVSalida;

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
//     // std::cout << "Usage: " << argv[0] << " INPUT_PCD FORMAT OUTPUT_CSV" << std::endl;
//     // std::cout << "  Example: " << argv[0] << " input_cloud.pcd 0 output_cloud.csv" << std::endl;
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

