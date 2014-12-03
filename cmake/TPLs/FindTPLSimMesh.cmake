INCLUDE(TribitsTplDeclareLibraries)

TRIBITS_TPL_FIND_INCLUDE_DIRS_AND_LIBRARIES( SimMesh
  REQUIRED_HEADERS MeshSim.h SimPartitionedMesh.h
  REQUIRED_LIBS_NAMES SimPartitionedMesh-mpi SimMeshing SimMeshTools SimPartitionWrapper-${SIM_MPI}
)

