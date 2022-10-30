#include "lib.h"

void StaticMesh3D::init(bool has_positions, bool has_texcoords, bool has_normals)
{
	this->has_positions = has_positions;
	this->has_texcoords = has_texcoords;
	this->has_normals = has_normals;
}

void StaticMesh3D::release()
{
	glDeleteVertexArrays(1, &vao);
	vbo.release();
}

int StaticMesh3D::get_vertex_byte_size()
{
	int size = 0;
	if (has_positions)
		size += sizeof(Vec3f);

	if (has_texcoords)
		size += sizeof(Vec2f);

	if (has_normals)
		size += sizeof(Vec3f);

	return size;
}

void StaticMesh3D::set_vertex_attrib_pointers(int num_vertices)
{
	uint64_t offset = 0;
	if (has_positions)
	{
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vec3f), (void *)offset);

		offset += sizeof(Vec3f) * num_vertices;
	}

	if (has_texcoords)
	{
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vec2f), (void *)offset);

		offset += sizeof(Vec2f) * num_vertices;
	}

	if (has_normals)
	{
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vec3f), (void *)offset);

		offset += sizeof(Vec3f) * num_vertices;
	}
}