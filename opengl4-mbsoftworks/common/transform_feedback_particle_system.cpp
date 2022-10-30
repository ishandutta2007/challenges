#include "lib.h"

int TransformFeedbackParticleSystem::init(int max_particles)
{
	this->max_particles = max_particles;
	add_recorded_int("outType", false);
	add_recorded_vec3("outPosition", true);

	if (!initialize_shaders_and_recorded_variables())
		return -1;

	generate_opengl_objects();

	return 0;
}

void TransformFeedbackParticleSystem::render_particles()
{
	prepare_render_particles();

	glBindVertexArray(render_vao[read_buffer_index]);
	glDrawArrays(GL_POINTS, 1, num_particles - 1);
}

void TransformFeedbackParticleSystem::update_particles(float dt)
{
	// Calculate write buffer index
	const auto write_buffer_index = 1 - read_buffer_index;

	// Prepare update of particles
	prepare_update_particles(dt);

	// Bind transform feedback object, VAO for updating particles and tell OpenGL where to store recorded data
	glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, transform_feedback_id);
	glBindVertexArray(update_vao[read_buffer_index]);
	glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 0, particles_vbo[write_buffer_index]);

	// Update particles with special update shader program and also observe how many particles have been written
	// Discard rasterization - we don't want to render this, it's only about updating
	glEnable(GL_RASTERIZER_DISCARD);
	glBeginQuery(GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN, num_particles_id);
	glBeginTransformFeedback(GL_POINTS);
	glDrawArrays(GL_POINTS, 0, num_particles);
	glEndTransformFeedback();
	glEndQuery(GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN);
	glGetQueryObjectiv(num_particles_id, GL_QUERY_RESULT, &num_particles);

	// Swap read / write buffers for the next frame
	read_buffer_index = write_buffer_index;

	// Unbind transform feedback and restore normal rendering (don't discard anymore)
	glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, 0);
	glDisable(GL_RASTERIZER_DISCARD);
}

void TransformFeedbackParticleSystem::add_recorded_int(const string &name, bool needed_for_rendering)
{
	recorded_variables.push_back({ name, GL_INT, 1, needed_for_rendering });
}

void TransformFeedbackParticleSystem::add_recorded_float(const string &name, bool needed_for_rendering)
{
	recorded_variables.push_back({ name, GL_FLOAT, 1, needed_for_rendering });
}

void TransformFeedbackParticleSystem::add_recorded_vec3(const string &name, bool needed_for_rendering)
{
	recorded_variables.push_back({ name, GL_FLOAT, 3, needed_for_rendering });
}

void TransformFeedbackParticleSystem::calc_billboarding_vectors(Vec3f view, Vec3f up)
{
	billboard_horizontal_vector = Vec3f::normalize(Vec3f::cross(view, up));
	billboard_vertical_vector = Vec3f::normalize(Vec3f::cross(view, -billboard_horizontal_vector));
}

GLsizei TransformFeedbackParticleSystem::calculate_particle_byte_size()
{
	GLsizei size = 0;
	for (auto &r : recorded_variables)
		size += r.get_byte_size();
	return size;
}

vector<string> TransformFeedbackParticleSystem::get_recorded_variables_names() const
{
	vector<string> recorded_variables_names;

	for (auto &r : recorded_variables)
		recorded_variables_names.push_back(r.name);

	return recorded_variables_names;
}

GLsizei TransformFeedbackParticleSystem::RecordedVariable::get_byte_size()
{
	if (type == GL_INT)
		return count * sizeof(int32_t);
	else if (type == GL_FLOAT)
		return count * sizeof(float);

	throw runtime_error("Unsupported GL data type for transform feedback particle system!");
}

void TransformFeedbackParticleSystem::RecordedVariable::enable_and_setup_vertex_attrib_pointer(GLuint index, GLsizei stride, GLsizeiptr byteOffset)
{
	glEnableVertexAttribArray(index);
	if (type == GL_INT)
	{
		// If OpenGL type is an integer or consists of integers, the glVertexAttribIPointer must be called (notice the I letter)
		glVertexAttribIPointer(index, count, type, stride, (const GLvoid *)byteOffset);
	}
	else
	{
		// If OpenGL type is float or consists of floats, the glVertexAttribPointer must be called
		glVertexAttribPointer(index, count, type, GL_FALSE, stride, (const GLvoid *)byteOffset);
	}
}

void TransformFeedbackParticleSystem::generate_opengl_objects()
{
	glGenTransformFeedbacks(1, &transform_feedback_id);
	glGenQueries(1, &num_particles_id);

	// Gather some constants
	const auto particle_byte_size = calculate_particle_byte_size();
	GLsizeiptr buffer_byte_size = particle_byte_size * max_particles;
	const int32_t initial_generator_type = PARTICLE_TYPE_GENERATOR;

	// Generate two VBOs - one serves as source of data (read buffer) and one is written to (write buffer)
	glGenBuffers(2, particles_vbo);
	for (auto i = 0; i < 2; i++)
	{
		glBindBuffer(GL_ARRAY_BUFFER, particles_vbo[i]);
		glBufferData(GL_ARRAY_BUFFER, buffer_byte_size, NULL, GL_DYNAMIC_DRAW);
		if (i == 0)
		{
			// Initialize first (read buffer) with one particle that is a generator
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(int32_t), &initial_generator_type);
		}
	}

	printf("Created VBOs for particle system with IDs [%d %d] and size %zu\n", particles_vbo[0], particles_vbo[1], buffer_byte_size);

	// Set up VAOs for updating of particles
	glGenVertexArrays(2, update_vao);
	for (auto i = 0; i < 2; i++)
	{
		glBindVertexArray(update_vao[i]);
		glBindBuffer(GL_ARRAY_BUFFER, particles_vbo[i]);

		GLsizeiptr byte_offset = 0;
		size_t j = 0;
		for (auto &r : recorded_variables)
		{
			r.enable_and_setup_vertex_attrib_pointer(j, particle_byte_size, byte_offset);
			byte_offset += r.get_byte_size();
			j += 1;
		}
	}

	// Set up VAOs for rendering of particles
	glGenVertexArrays(2, render_vao);
	for (auto i = 0; i < 2; i++)
	{
		glBindVertexArray(render_vao[i]);
		glBindBuffer(GL_ARRAY_BUFFER, particles_vbo[i]);

		GLsizeiptr byte_offset = 0;
		size_t j = 0;
		for (auto &r : recorded_variables)
		{
			// Enable vertex attribute only if it's needed for rendering
			// Some properties (like type of particle or velocity might not be needed)
			if (r.needed_for_rendering)
				r.enable_and_setup_vertex_attrib_pointer(j, particle_byte_size, byte_offset);

			byte_offset += r.get_byte_size();
			j += 1;
		}
	}

	// Initialize read buffer index and initial number of particles
	read_buffer_index = 0;
	num_particles = 1;
}

Vec3f TransformFeedbackParticleSystem::generate_random_number_generator_seed()
{
	static random_device rd;
	static mt19937 generator(rd());
	uniform_real_distribution<float> seed_distribution(-10.0f, 10.0f);

	return { seed_distribution(generator), seed_distribution(generator), seed_distribution(generator) };
}

void TransformFeedbackParticleSystem::release()
{
	glDeleteTransformFeedbacks(1, &transform_feedback_id);
	glDeleteQueries(1, &num_particles_id);
	glDeleteVertexArrays(2, render_vao);
	glDeleteVertexArrays(2, update_vao);
	glDeleteBuffers(2, particles_vbo);
}