#include "lib.h"

Vec3f Cube::vertices[36] = {
	// Front face
	{ -0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, -0.5f, 0.5f },
	{ 0.5f, -0.5f, 0.5f },
	{ -0.5f, -0.5f, 0.5f },
	{ -0.5f, 0.5f, 0.5f },
	// Back face
	{ 0.5f, 0.5f, -0.5f },
	{ -0.5f, 0.5f, -0.5f },
	{ -0.5f, -0.5f, -0.5f },
	{ -0.5f, -0.5f, -0.5f },
	{ 0.5f, -0.5f, -0.5f },
	{ 0.5f, 0.5f, -0.5f },
	// Left face
	{ -0.5f, 0.5f, -0.5f },
	{ -0.5f, 0.5f, 0.5f },
	{ -0.5f, -0.5f, 0.5f },
	{ -0.5f, -0.5f, 0.5f },
	{ -0.5f, -0.5f, -0.5f },
	{ -0.5f, 0.5f, -0.5f },
	// Right face
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, -0.5f },
	{ 0.5f, -0.5f, -0.5f },
	{ 0.5f, -0.5f, -0.5f },
	{ 0.5f, -0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	// Top face
	{ -0.5f, 0.5f, -0.5f },
	{ 0.5f, 0.5f, -0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ -0.5f, 0.5f, 0.5f },
	{ -0.5f, 0.5f, -0.5f },
	// Bottom face
	{ -0.5f, -0.5f, 0.5f },
	{ 0.5f, -0.5f, 0.5f },
	{ 0.5f, -0.5f, -0.5f },
	{ 0.5f, -0.5f, -0.5f },
	{ -0.5f, -0.5f, -0.5f },
	{ -0.5f, -0.5f, 0.5f },
};

Vec2f Cube::texcoords[6] = {
	{ 0.0f, 1.0f },
	{ 1.0f, 1.0f },
	{ 1.0f, 0.0f },
	{ 1.0f, 0.0f },
	{ 0.0f, 0.0f },
	{ 0.0f, 1.0f },
};

Vec3f Cube::normals[6] = {
	{ 0.0f, 0.0f, 1.0f }, // Front face
	{ 0.0f, 0.0f, -1.0f }, // Back face
	{ -1.0f, 0.0f, 0.0f }, // Left face
	{ 1.0f, 0.0f, 0.0f }, // Right face
	{ 0.0f, 1.0f, 0.0f }, // Top face
	{ 0.0f, -1.0f, 0.0f }, // Bottom face
};

void Cube::init(bool has_position, bool has_texcoords, bool has_normals)
{
	StaticMesh3D::init(has_position, has_texcoords, has_normals);
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	auto num_vertices = 36;
	auto vertex_byte_size = get_vertex_byte_size();
	vbo.create(vertex_byte_size * num_vertices);
	vbo.bind();

	if (has_position)
		vbo.add(vertices, sizeof(Vec3f) * num_vertices);

	if (has_texcoords)
	{
		for (auto i = 0; i < 6; i++)
			vbo.add(texcoords, sizeof(Vec2f) * 6);
	}

	if (has_normals)
	{
		for (auto i = 0; i < 6; i++)
			vbo.add(&normals[i], sizeof(Vec3f), 6);
	}

	vbo.upload(GL_STATIC_DRAW);
	set_vertex_attrib_pointers(num_vertices);
}

void Cube::render_faces(int mask)
{
	glBindVertexArray(vao);

	if (mask & Cube::FRONT_FACE)
		glDrawArrays(GL_TRIANGLES, 0, 6);
	if (mask & Cube::BACK_FACE)
		glDrawArrays(GL_TRIANGLES, 6, 6);
	if (mask & Cube::LEFT_FACE)
		glDrawArrays(GL_TRIANGLES, 12, 6);
	if (mask & Cube::RIGHT_FACE)
		glDrawArrays(GL_TRIANGLES, 18, 6);
	if (mask & Cube::TOP_FACE)
		glDrawArrays(GL_TRIANGLES, 24, 6);
	if (mask & Cube::BOTTOM_FACE)
		glDrawArrays(GL_TRIANGLES, 30, 6);
}

void Cube::render()
{
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Cube::render_points()
{
	glBindVertexArray(vao);
	glDrawArrays(GL_POINTS, 0, 36);
}
