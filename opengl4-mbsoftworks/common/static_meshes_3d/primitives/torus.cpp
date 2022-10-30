#include "lib.h"

void Torus::init(int main_segments, int tube_segments, float main_radius, float tube_radius,
				 bool has_positions, bool has_texcoords, bool has_normals)
{
	StaticMeshIndexed3D::init(has_positions, has_texcoords, has_normals);
	this->main_segments = main_segments;
	this->tube_segments = tube_segments;
	this->main_radius = main_radius;
	this->tube_radius = tube_radius;

	// Calculate and cache counts of vertices and indices
	num_vertices = (main_segments + 1) * (tube_segments + 1);
	primitive_restart_index = num_vertices;
	num_indices = (main_segments * 2 * (tube_segments + 1)) + main_segments - 1;

	// Generate VAO and VBOs for vertex attributes and indices
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	vbo.create(get_vertex_byte_size() * num_vertices);
	indices.create(sizeof(GLuint) * num_indices);

	// Precalculate steps in radians for main segment and tube segment
	auto main_segment_angle_step = radians(360.0f / float(main_segments));
	auto tube_segment_angle_step = radians(360.0f / float(tube_segments));

	if (has_positions)
	{
		auto current_main_segment_angle = 0.0f;
		for (auto i = 0; i <= main_segments; i++)
		{
			// Calculate sine and cosine of main segment angle
			auto sin_main_segment = sin(current_main_segment_angle);
			auto cos_main_segment = cos(current_main_segment_angle);
			auto current_tube_segment_angle = 0.0f;
			for (auto j = 0; j <= tube_segments; j++)
			{
				// Calculate sine and cosine of tube segment angle
				auto sin_tube_segment = sin(current_tube_segment_angle);
				auto cos_tube_segment = cos(current_tube_segment_angle);

				// Calculate vertex position on the surface of torus
				auto surface_position = Vec3f{
					(main_radius + tube_radius * cos_tube_segment) * cos_main_segment,
					(main_radius + tube_radius * cos_tube_segment) * sin_main_segment,
					tube_radius * sin_tube_segment,
				};

				vbo.add(&surface_position, sizeof(Vec3f));

				// Update current tube angle
				current_tube_segment_angle += tube_segment_angle_step;
			}

			// Update main segment angle
			current_main_segment_angle += main_segment_angle_step;
		}
	}

	if (has_texcoords)
	{
		// Precalculate steps in texture coordinates for main segment and tube segment
		// I have decided to map the texture twice around main segments and once around tube segmens
		auto main_segment_texture_step = 2.0f / float(main_segments);
		auto tube_segment_texture_step = 1.0f / float(tube_segments);

		auto current_main_segment_texcoord_v = 0.0f;
		for (auto i = 0; i <= main_segments; i++)
		{
			auto current_tube_segment_texcoord_u = 0.0f;
			for (auto j = 0; j <= tube_segments; j++)
			{
				// Calculate texture coordinate and add it to the buffer
				auto texcoord = Vec2f{ current_tube_segment_texcoord_u, current_main_segment_texcoord_v };
				vbo.add(&texcoord, sizeof(Vec2f));
				// Update texture coordinate of tube segment
				current_tube_segment_texcoord_u += tube_segment_texture_step;
			}

			// Update texture coordinate of main segment
			current_main_segment_texcoord_v += main_segment_texture_step;
		}
	}

	if (has_normals)
	{
		auto current_main_segment_angle = 0.0f;
		for (auto i = 0; i <= main_segments; i++)
		{
			// Calculate sine and cosine of main segment angle
			auto sin_main_segment = sin(current_main_segment_angle);
			auto cos_main_segment = cos(current_main_segment_angle);
			auto current_tube_segment_angle = 0.0f;
			for (auto j = 0; j <= tube_segments; j++)
			{
				// Calculate sine and cosine of tube segment angle
				auto sin_tube_segment = sin(current_tube_segment_angle);
				auto cos_tube_segment = cos(current_tube_segment_angle);

				auto normal = Vec3f{
					cos_main_segment * cos_tube_segment,
					sin_main_segment * cos_tube_segment,
					sin_tube_segment,
				};
				vbo.add(&normal, sizeof(Vec3f));

				// Update current tube angle
				current_tube_segment_angle += tube_segment_angle_step;
			}

			// Update main segment angle
			current_main_segment_angle += main_segment_angle_step;
		}
	}

	// Finally, generate indices for rendering
	GLuint current_vertex_offset = 0;
	for (auto i = 0; i < main_segments; i++)
	{
		for (auto j = 0; j <= tube_segments; j++)
		{
			auto via = current_vertex_offset;
			indices.add(&via, sizeof(GLuint));
			auto vib = current_vertex_offset + tube_segments + 1;
			indices.add(&vib, sizeof(GLuint));
			current_vertex_offset++;
		}

		// Don't restart primitive, if it's last segment, rendering ends here anyway
		if (i != main_segments - 1)
			indices.add(&primitive_restart_index, sizeof(GLuint));
	}

	vbo.bind();
	vbo.upload(GL_STATIC_DRAW);
	set_vertex_attrib_pointers(num_vertices);

	indices.bind(GL_ELEMENT_ARRAY_BUFFER);
	indices.upload(GL_STATIC_DRAW);
}

void Torus::render()
{
	glBindVertexArray(vao);
	// Enable primitive restart, because we're rendering several triangle strips (for each main segment)
	glEnable(GL_PRIMITIVE_RESTART);
	glPrimitiveRestartIndex(primitive_restart_index);

	// Render torus using precalculated indices
	glDrawElements(GL_TRIANGLE_STRIP, num_indices, GL_UNSIGNED_INT, 0);

	// Disable primitive restart, we won't need it now
	glDisable(GL_PRIMITIVE_RESTART);
}

void Torus::render_points()
{
	glBindVertexArray(vao);

	// Render torus points only
	glDrawArrays(GL_POINTS, 0, num_vertices);
}
