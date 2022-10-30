#include "lib.h"

void Sphere::init(float radius, int num_slices, int num_stacks,
				  bool has_positions, bool has_texcoords, bool has_normals)
{
	StaticMeshIndexed3D::init(has_positions, has_texcoords, has_normals);
	this->radius = radius;
	this->num_slices = num_slices;
	this->num_stacks = num_stacks;

	// Cache count of vertices
	num_vertices = (num_stacks + 1) * (num_slices + 1);

	// Cache number of indices it takes to render body
	auto num_body_stacks = num_stacks - 2;
	auto num_body_primitive_restarts = max(0, num_body_stacks - 1);
	num_body_indices = 2 * num_body_stacks * (num_slices + 1) + num_body_primitive_restarts;

	// Cache count of pole indices
	num_pole_indices = num_slices * 3;

	// Cache offsets for sphere parts
	north_pole_index_offset = 0;
	body_index_offset = num_pole_indices;
	south_pole_index_offset = body_index_offset + num_body_indices;

	// Finally cache total number of indices and primitive restart index
	num_indices = 2 * num_pole_indices + num_body_indices;
	primitive_restart_index = num_vertices;

	// Generate VAO and VBOs for vertex attributes and indices
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	vbo.create(get_vertex_byte_size() * num_vertices);
	indices.create(sizeof(GLuint) * num_indices);

	// Pre-calculate sines / cosines for given number of slices
	auto slice_angle_step = 2.0f * M_PI / num_slices;
	auto current_slice_angle = 0.0f;
	vector<float> slice_sines, slice_cosines;
	for (auto i = 0; i <= num_slices; i++)
	{
		slice_sines.push_back(sin(current_slice_angle));
		slice_cosines.push_back(cos(current_slice_angle));

		// Update slice angle
		current_slice_angle += slice_angle_step;
	}

	// Pre-calculate sines / cosines for given number of stacks
	auto stack_angle_step = -M_PI / num_stacks;
	auto current_stack_angle = M_PI / 2.0f;
	vector<float> stack_sines, stack_cosines;
	for (auto i = 0; i <= num_stacks; i++)
	{
		stack_sines.push_back(sin(current_stack_angle));
		stack_cosines.push_back(cos(current_stack_angle));

		// Update stack angle
		current_stack_angle += stack_angle_step;
	}

	// Generate sphere vertex positions
	if (has_positions)
	{
		for (auto i = 0; i <= num_stacks; i++)
		{
			for (auto j = 0; j <= num_slices; j++)
			{
				auto x = radius * stack_cosines[i] * slice_cosines[j];
				auto y = radius * stack_sines[i];
				auto z = radius * stack_cosines[i] * slice_sines[j];
				auto pos = Vec3f{ x, y, z };
				vbo.add(&pos, sizeof(pos));
			}
		}
	}

	// Generate sphere texture coordinates
	if (has_texcoords)
	{
		for (auto i = 0; i <= num_stacks; i++)
		{
			for (auto j = 0; j <= num_slices; j++)
			{
				// There are many options out there to generate sphere texture coordinates
				// I have commented out some others here that work, some better, some worse
				// You can try them all out :)

				// float u = atan2(x, z) / (2.0f * glm::pi<float>());
				// float v = asin(y) / glm::pi<float>();

				// float u = 0.5f + asin(x) / glm::pi<float>();
				// float v = 0.5f + asin(y) / glm::pi<float>();

				// float u = 0.5f + x * 0.5f;
				// float v = 0.5f + y * 0.5f;

				float u = 1.0f - float(j) / num_slices;
				float v = 1.0f - float(i) / num_stacks;
				auto uv = Vec2f{ u, v };
				vbo.add(&uv, sizeof(uv));
			}
		}
	}

	// Generate sphere normals
	if (has_normals)
	{
		for (auto i = 0; i <= num_stacks; i++)
		{
			for (int j = 0; j <= num_slices; j++)
			{
				auto x = stack_cosines[i] * slice_cosines[j];
				auto y = stack_sines[i];
				auto z = stack_cosines[i] * slice_sines[j];
				auto pos = Vec3f{ x, y, z };
				vbo.add(&pos, sizeof(pos));
			}
		}
	}

	// Now that we have all vertex data, generate indices for north pole (triangles)
	for (int i = 0; i < num_slices; i++)
	{
		GLuint slice_index = i;
		GLuint next_slice_index = slice_index + num_slices + 1;
		indices.add(&slice_index, sizeof(slice_index));
		indices.add(&next_slice_index, sizeof(next_slice_index));
		next_slice_index += 1;
		indices.add(&next_slice_index, sizeof(next_slice_index));
	}

	// Then for body (triangle strip)
	GLuint current_vertex_index = num_slices + 1;
	for (int i = 0; i < num_body_stacks; i++)
	{
		// Primitive restart triangle strip from second body stack on
		if (i > 0)
			indices.add(&primitive_restart_index, sizeof(primitive_restart_index));

		for (int j = 0; j <= num_slices; j++)
		{
			GLuint slice_index = current_vertex_index + j;
			GLuint next_slice_index = current_vertex_index + num_slices + 1 + j;
			indices.add(&slice_index, sizeof(slice_index));
			indices.add(&next_slice_index, sizeof(next_slice_index));
		}

		current_vertex_index += num_slices + 1;
	}

	// And finally south pole (triangles again)
	GLuint before_last_stack_index_offset = num_vertices - 2 * (num_slices + 1);
	for (int i = 0; i < num_slices; i++)
	{
		GLuint slice_index = before_last_stack_index_offset + i;
		GLuint next_slice_index = slice_index + num_slices + 1;

		indices.add(&slice_index, sizeof(slice_index));
		slice_index += 1;
		indices.add(&slice_index, sizeof(slice_index));
		indices.add(&next_slice_index, sizeof(next_slice_index));
	}

	vbo.bind();
	vbo.upload(GL_STATIC_DRAW);
	set_vertex_attrib_pointers(num_vertices);

	indices.bind(GL_ELEMENT_ARRAY_BUFFER);
	indices.upload(GL_STATIC_DRAW);
}

void Sphere::render()
{
	glBindVertexArray(vao);

	glEnable(GL_PRIMITIVE_RESTART);
	glPrimitiveRestartIndex(primitive_restart_index);

	// Render north pole
	glDrawElements(GL_TRIANGLES, num_pole_indices, GL_UNSIGNED_INT, (void *)(sizeof(GLuint) * north_pole_index_offset));

	// Render body
	glDrawElements(GL_TRIANGLE_STRIP, num_body_indices, GL_UNSIGNED_INT, (void *)(sizeof(GLuint) * body_index_offset));

	// Render south pole
	glDrawElements(GL_TRIANGLES, num_pole_indices, GL_UNSIGNED_INT, (void *)(sizeof(GLuint) * south_pole_index_offset));

	// Disable primitive restart, we won't need it now
	glDisable(GL_PRIMITIVE_RESTART);
}

void Sphere::render_points()
{
	glBindVertexArray(vao);
	glDrawArrays(GL_POINTS, 0, num_vertices);
}