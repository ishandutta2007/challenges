#include "lib.h"

void Cylinder::init(float radius, int num_slices, float height,
					bool has_positions, bool has_texcoords, bool has_normals)
{
	StaticMesh3D::init(has_positions, has_texcoords, has_normals);
	this->radius = radius;
	this->num_slices = num_slices;
	this->height = height;

	// Calculate and cache numbers of vertices
	num_vertices_side = (num_slices + 1) * 2;
	num_vertices_top_bottom = num_slices + 2;
	num_vertices_total = num_vertices_side + num_vertices_top_bottom * 2;

	// Generate VAO and VBO for vertex attributes
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	vbo.create(get_vertex_byte_size() * num_vertices_total);

	// Pre-calculate sines / cosines for given number of slices
	auto slice_angle_step = 2.0f * M_PI / num_slices;
	auto current_slice_angle = 0.0f;
	vector<float> sines, cosines;
	for (auto i = 0; i <= num_slices; i++)
	{
		sines.push_back(sin(current_slice_angle));
		cosines.push_back(cos(current_slice_angle));

		// Update slice angle
		current_slice_angle += slice_angle_step;
	}

	if (has_positions)
	{
		// Pre-calculate X and Z coordinates
		vector<float> x;
		vector<float> z;
		for (auto i = 0; i <= num_slices; i++)
		{
			x.push_back(cosines[i] * radius);
			z.push_back(sines[i] * radius);
		}

		// Add cylinder side vertices
		for (auto i = 0; i <= num_slices; i++)
		{
			auto top_position = Vec3f{ x[i], height / 2.0f, z[i] };
			auto bottom_position = Vec3f{ x[i], -height / 2.0f, z[i] };
			vbo.add(&top_position, sizeof(Vec3f));
			vbo.add(&bottom_position, sizeof(Vec3f));
		}

		// Add top cylinder cover
		auto top_center_position = Vec3f{ 0.0f, height / 2.0f, 0.0f };
		vbo.add(&top_center_position, sizeof(Vec3f));
		for (auto i = 0; i <= num_slices; i++)
		{
			auto top_position = Vec3f{ x[i], height / 2.0f, z[i] };
			vbo.add(&top_position, sizeof(Vec3f));
		}

		// Add bottom cylinder cover
		auto bottom_center_position = Vec3f{ 0.0f, -height / 2.0f, 0.0f };
		vbo.add(&bottom_center_position, sizeof(Vec3f));
		for (auto i = 0; i <= num_slices; i++)
		{
			auto bottom_position = Vec3f{ x[i], -height / 2.0f, -z[i] };
			vbo.add(&bottom_position, sizeof(Vec3f));
		}
	}

	if (has_texcoords)
	{
		// Pre-calculate step size in texture coordinate U
		// I have decided to map the texture twice around cylinder, looks fine
		const auto slice_texture_step_u = 2.0f / num_slices;

		auto current_slice_texcoord_u = 0.0f;
		for (auto i = 0; i <= num_slices; i++)
		{
			Vec2f txc1 = Vec2f{ current_slice_texcoord_u, 1.0f };
			Vec2f txc0 = Vec2f{ current_slice_texcoord_u, 0.0f };
			vbo.add(&txc1, sizeof(Vec2f));
			vbo.add(&txc0, sizeof(Vec2f));

			// Update texture coordinate of current slice
			current_slice_texcoord_u += slice_texture_step_u;
		}

		// Generate circle texture coordinates for cylinder top cover
		auto top_bottom_center_texcoord = Vec2f{ 0.5f, 0.5f };
		vbo.add(&top_bottom_center_texcoord, sizeof(Vec2f));
		for (auto i = 0; i <= num_slices; i++)
		{
			Vec2f txc = { top_bottom_center_texcoord.x + sines[i] * 0.5f, top_bottom_center_texcoord.y + cosines[i] * 0.5f };
			vbo.add(&txc, sizeof(Vec2f));
		}

		// Generate circle texture coordinates for cylinder bottom cover
		vbo.add(&top_bottom_center_texcoord, sizeof(Vec2f));
		for (auto i = 0; i <= num_slices; i++)
		{
			Vec2f txc = { top_bottom_center_texcoord.x + sines[i] * 0.5f, top_bottom_center_texcoord.y - cosines[i] * 0.5f };
			vbo.add(&txc, sizeof(Vec2f));
		}
	}

	if (has_normals)
	{
		for (auto i = 0; i <= num_slices; i++)
		{
			auto nrm = Vec3f{ cosines[i], 0.0f, sines[i] };
			vbo.add(&nrm, sizeof(Vec3f));
			vbo.add(&nrm, sizeof(Vec3f));
		}

		// Add normal for every vertex of cylinder top cover
		for (auto i = 0; i < num_vertices_top_bottom; i++)
		{
			auto nrm = Vec3f{ 0, 1, 0 };
			vbo.add(&nrm, sizeof(Vec3f));
		}

		// Add normal for every vertex of cylinder bottom cover
		for (auto i = 0; i < num_vertices_top_bottom; i++)
		{
			auto nrm = Vec3f{ 0, -1, 0 };
			vbo.add(&nrm, sizeof(Vec3f));
		}
	}

	vbo.bind();
	vbo.upload(GL_STATIC_DRAW);
	set_vertex_attrib_pointers(num_vertices_total);
}

void Cylinder::render()
{
	glBindVertexArray(vao);

	// Render cylinder side first
	glDrawArrays(GL_TRIANGLE_STRIP, 0, num_vertices_side);

	// Render top cover
	glDrawArrays(GL_TRIANGLE_FAN, num_vertices_side, num_vertices_top_bottom);

	// Render bottom cover
	glDrawArrays(GL_TRIANGLE_FAN, num_vertices_side + num_vertices_top_bottom, num_vertices_top_bottom);
}

void Cylinder::render_points()
{
	// Just render all points as they are stored in the VBO
	glBindVertexArray(vao);
	glDrawArrays(GL_POINTS, 0, num_vertices_total);
}