#ifndef _STATIC_MESH_3D_
#define _STATIC_MESH_3D_

class StaticMesh3D
{
public:
	void init(bool has_positions, bool has_texcoords, bool has_normals);
	void release();

	int get_vertex_byte_size();
	void set_vertex_attrib_pointers(int num_vertices);

	virtual void render() = 0;

	bool has_positions;
	bool has_texcoords;
	bool has_normals;

	GLuint vao;
	VBO vbo;
};

#endif