#include <spr.h>
#include <apfMesh2.h>
#include <apfShape.h>
#include <gmi_null.h>
#include <gmi_mesh.h>
#include <apfMDS.h>
#include <PCU.h>
#include <lionPrint.h>
#include <pcu_util.h>
#include <cstdlib>

int main(int argc, char** argv)
{
  const char* exe = argv[0];
  char usage[1024];
  snprintf(usage, 1024, "%s <model.dmg> <in.smb> <out-vtk> \n", exe);
  PCU_ALWAYS_ASSERT_VERBOSE(argc==4, usage);
  const char* modelFile = argv[1];
  const char* meshFile = argv[2];
  const char* outFile = argv[3];
  MPI_Init(&argc,&argv);
  PCU_Comm_Init();
  lion_set_verbosity(1);
  gmi_register_null();
  gmi_register_mesh();
  apf::Mesh2* mesh = apf::loadMdsMesh(modelFile, meshFile);
  apf::Field* sigma = mesh->findField("sigma");
  apf::Field* sigma_star = spr::recoverField(sigma);
  (void)sigma_star;
//  apf::Field* f =
//    apf::createLagrangeField(mesh, "solution", apf::VECTOR, order);
//  apf::Field* eps = spr::getGradIPField(f, "eps", order);
//  apf::destroyField(f);
  writeVtkFiles(outFile,mesh);
  mesh->destroyNative();
  apf::destroyMesh(mesh);
  PCU_Comm_Free();
  MPI_Finalize();
}

