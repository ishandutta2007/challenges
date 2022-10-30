// https://www.freemancw.com/2012/06/opengl-cone-function/

#include "lib.h"

static Vec3f perp(Vec3f v)
{
	auto min = fabsf(v.x);
	auto axis = Vec3f(1, 0, 0);

	if (fabsf(v.y) < min)
	{
		min = fabsf(v.y);
		axis = Vec3f(0, 1, 0);
	}

	if (fabsf(v.z) < min)
		axis = Vec3f(0, 0, 1);

	return Vec3f::cross(v, axis);
}

void Cone::init(Vec3f directix, Vec3f apex, float height, float radius, int num_slices,
				bool has_positions, bool has_texcoords, bool has_normals)
{
	StaticMesh3D::init(has_positions, has_texcoords, has_normals);
	this->directix = directix;
	this->apex = apex;
	this->height = height;
	this->radius = radius;

	// Calculate and cache numbers of vertices
	num_vertices_side = num_slices + 1;
	num_vertices_bottom = num_slices + 1;
	num_vertices_total = num_vertices_side + num_vertices_bottom;

	// Generate VAO and VBO for vertex attributes
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	vbo.create(get_vertex_byte_size() * num_vertices_total);

	auto c = apex + (-directix * height);
	auto e0 = perp(directix);
	auto e1 = Vec3f::cross(e0, directix);
	auto anginc = radians(360.0 / num_slices);

	// calculate points around directrix
	vector<Vec3f> pts;
	for (auto i = 0; i <= num_slices; i++)
	{
		auto rad = anginc * i;
		auto p = c + (((e0 * cos(rad)) + (e1 * sin(rad))) * radius);
		pts.push_back(p);
	}

	if (has_positions)
	{
		// Sides
		// Created by connecting the apex to the sweeping/rotating directix axis
		vbo.add(&apex, sizeof(Vec3f));
		for (auto i = 0; i <= num_slices; i++)
			vbo.add(&pts[i], sizeof(Vec3f));

		// Bottom
		// Created by connecting the center point at the bottom circle to the sweeping/rotating directix axis
		vbo.add(&c, sizeof(Vec3f));
		for (auto i = num_slices; i >= 0; i--)
			vbo.add(&pts[i], sizeof(Vec3f));
	}
}

void Cone::render()
{
	glBindVertexArray(vao);

	// Render the sides
	glDrawArrays(GL_TRIANGLE_FAN, 0, num_vertices_side);

	// Render bottom cover
	glDrawArrays(GL_TRIANGLE_FAN, num_vertices_side, num_vertices_bottom);
}

void Cone::render_points()
{
	// Just render all points as they are stored in the VBO
	glBindVertexArray(vao);
	glDrawArrays(GL_POINTS, 0, num_vertices_total);
}
