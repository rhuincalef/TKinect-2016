// Full example -->
// http://pointclouds.org/documentation/tutorials/greedy_projection.php

#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/gp3.h>

int
main (int argc, char** argv)
{
  // Load input file into a PointCloud<T> with an appropriate type
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PCLPointCloud2 cloud_blob;
  pcl::io::loadPCDFile ("prueba6.pcd", cloud_blob);
  pcl::fromPCLPointCloud2 (cloud_blob, *cloud);
  //* the data should be available in cloud

  // Normal estimation*
  pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> n;
  pcl::PointCloud<pcl::Normal>::Ptr normals (new pcl::PointCloud<pcl::Normal>);
  pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
  tree->setInputCloud (cloud);
  n.setInputCloud (cloud);
  n.setSearchMethod (tree);
  n.setKSearch (20);
  n.compute (*normals);
  //* normals should not contain the point normals + surface curvatures

  // Concatenate the XYZ and normal fields*
  pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals (new pcl::PointCloud<pcl::PointNormal>);
  pcl::concatenateFields (*cloud, *normals, *cloud_with_normals);
  //* cloud_with_normals = cloud + normals

  // Se guarda el pcd con las normales.

// // Se organizan las dimensiones de la nube para que se pueda generar
  // // una imagen a partir de ella.
  cloud_with_normals->width    = 640;
  cloud_with_normals->height   = 480;
  cloud_with_normals->is_dense = false;

  cloud_with_normals->points.resize (cloud_with_normals->width * cloud_with_normals->height);
  std::cout << "width:" << cloud_with_normals->width << std::endl;
  std::cout << "height:" << cloud_with_normals->height << std::endl;

  pcl::io::savePCDFileBinaryCompressed("pcd_normales.pcd",*cloud_with_normals);
  std::cout << "GUARDADO PCD!!!" << std::endl;

}

















	