#include "lib.h"

Vec3f PlainGround::vertices[4] = {
	{ -200.0f, 0.0f, -200.0f }, // Left-back point
	{ -200.0f, 0.0f, 200.0f }, // Left-front point
	{ 200.0f, 0.0f, -200.0f }, // Right-back point
	{ 200.0f, 0.0f, 200.0f }, // Right-front point
};

Vec2f PlainGround::texcoords[4] = {
	{ 0.0f, 20.0f },
	{ 0.0f, 0.0f },
	{ 20.0f, 20.0f },
	{ 20.0f, 0.0f },
};

void PlainGround::init(bool has_position, bool has_texcoord, bool has_normals)
{
	StaticMesh3D::init(has_position, has_texcoord, has_normals);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	const int num_vertices = 4;
	int vertex_byte_size = get_vertex_byte_size();
	vbo.create(vertex_byte_size * num_vertices);
	vbo.bind();

	if (has_position)
		vbo.add(vertices, sizeof(vertices));

	if (has_texcoord)
		vbo.add(texcoords, sizeof(texcoords));

	if (has_normals)
	{
		auto normal = Vec3f{ 0.0f, 1.0f, 0.0f };
		vbo.add(&normal, sizeof(normal), num_vertices);
	}

	vbo.upload(GL_STATIC_DRAW);
	set_vertex_attrib_pointers(num_vertices);
}

void PlainGround::render()
{
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}