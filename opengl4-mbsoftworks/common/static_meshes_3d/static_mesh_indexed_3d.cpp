#include "lib.h"

void StaticMeshIndexed3D::release()
{
	StaticMesh3D::release();
	indices.release();
}