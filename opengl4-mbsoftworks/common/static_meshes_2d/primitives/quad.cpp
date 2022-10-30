#include "lib.h"

Vec2f Quad::vertices[4] = {
	{ 0.0f, 1.0f }, // Top-left point
	{ 0.0f, 0.0f }, // Bottom-left point
	{ 1.0f, 1.0f }, // Top-right point
	{ 1.0f, 0.0f }, // Bottom-right point
};

void Quad::init(bool has_positions, bool has_texcoords)
{
	StaticMesh2D::init(has_positions, has_texcoords);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	auto num_vertices = 4;
	auto vertex_byte_size = get_vertex_byte_size();
	vbo.create(vertex_byte_size * num_vertices);
	vbo.bind();

	if (has_positions)
		vbo.add(vertices, sizeof(Vec2f) * num_vertices);

	if (has_texcoords)
		vbo.add(vertices, sizeof(Vec2f) * num_vertices);

	vbo.upload(GL_STATIC_DRAW);
	set_vertex_attrib_pointers(num_vertices);
}

void Quad::render()
{
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}