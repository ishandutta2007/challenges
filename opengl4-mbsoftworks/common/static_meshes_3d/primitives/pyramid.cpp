#include "lib.h"

Vec3f Pyramid::vertices[12] = {
	// Front face
	{ 0.0f, 0.5f, 0.0f },
	{ -0.5f, -0.5f, 0.5f },
	{ 0.5f, -0.5f, 0.5f },
	// Back face
	{ 0.0f, 0.5f, 0.0f },
	{ 0.5f, -0.5f, -0.5f },
	{ -0.5f, -0.5f, -0.5f },
	// Left face
	{ 0.0f, 0.5f, 0.0f },
	{ -0.5f, -0.5f, -0.5f },
	{ -0.5f, -0.5f, 0.5f },
	// Right face
	{ 0.0f, 0.5f, 0.0f },
	{ 0.5f, -0.5f, 0.5f },
	{ 0.5f, -0.5f, -0.5f },
};

Vec2f Pyramid::texcoords[3] = {
	{ 0.5f, 1.0f },
	{ 0.0f, 0.0f },
	{ 1.0f, 0.0f },
};

void Pyramid::init(bool has_positions, bool has_texcoords, bool has_normals)
{
	StaticMesh3D::init(has_positions, has_texcoords, has_normals);
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	const int num_vertices = 12;
	int vertex_byte_size = get_vertex_byte_size();
	vbo.create(vertex_byte_size * num_vertices);
	vbo.bind();

	if (has_positions)
		vbo.add(vertices, sizeof(Vec3f) * num_vertices);

	if (has_texcoords)
	{
		for (auto i = 0; i < 4; i++)
			vbo.add(texcoords, sizeof(Vec2f) * 3);
	}

	if (has_normals)
	{
		for (auto i = 0; i < 4; i++)
		{
			auto &pa = vertices[i * 3];
			auto &pb = vertices[i * 3 + 1];
			auto &pc = vertices[i * 3 + 2];
			auto va = pb - pa;
			auto vb = pc - pa;
			auto cp = Vec3f::normalize(Vec3f::cross(va, vb));
			vbo.add(&cp, sizeof(Vec3f), 3);
		}
	}

	vbo.upload(GL_STATIC_DRAW);
	set_vertex_attrib_pointers(num_vertices);
}

void Pyramid::render()
{
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 12);
}

void Pyramid::render_points()
{
	glBindVertexArray(vao);
	glDrawArrays(GL_POINTS, 0, 12);
}