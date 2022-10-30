#ifndef _STATIC_MESH_INDEXED_3D_H_
#define _STATIC_MESH_INDEXED_3D_H_

class StaticMeshIndexed3D : public StaticMesh3D
{
public:
	void release();

	VBO indices; // Our VBO wrapper class holding indices data
	int num_vertices; // Holds the total number of generated vertices
	int num_indices; // Holds the number of generated indices used for rendering
	int primitive_restart_index; // Index of primitive restart
};

#endif