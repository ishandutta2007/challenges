#ifndef _STATIC_MESH_2D_
#define _STATIC_MESH_2D_

class StaticMesh2D
{
public:
	void init(bool has_positions, bool has_texcoords);
	void release();

	int get_vertex_byte_size();
	void set_vertex_attrib_pointers(int num_vertices);

	virtual void render() = 0;

	bool has_positions;
	bool has_texcoords;
	GLuint vao;
	VBO vbo;
};

#endif