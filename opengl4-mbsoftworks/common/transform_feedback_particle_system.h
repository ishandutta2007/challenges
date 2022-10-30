#ifndef _TRANSFORM_FEEDBACK_PARTICLE_SYSTEM_H_
#define _TRANSFORM_FEEDBACK_PARTICLE_SYSTEM_H_

class TransformFeedbackParticleSystem
{
public:
	int init(int max_particles);
	void render_particles();
	void update_particles(float dt);

	void calc_billboarding_vectors(Vec3f view, Vec3f up);

	GLsizei calculate_particle_byte_size();

	virtual void release();

	virtual bool initialize_shaders_and_recorded_variables() = 0;
	virtual void prepare_update_particles(float dt) = 0;
	virtual void prepare_render_particles() = 0;

	Vec3f generate_random_number_generator_seed();

	void generate_opengl_objects();

	void add_recorded_int(const string &name, bool needed_for_rendering);
	void add_recorded_float(const string &name, bool needed_for_rendering);
	void add_recorded_vec3(const string &name, bool needed_for_rendering);

	vector<string> get_recorded_variables_names() const;

	struct RecordedVariable
	{
		string name;
		GLenum type;
		GLsizei count;
		bool needed_for_rendering;

		void enable_and_setup_vertex_attrib_pointer(GLuint index, GLsizei stride, GLsizeiptr byteOffset);
		GLsizei get_byte_size();
	};

	Vec3f billboard_horizontal_vector;
	Vec3f billboard_vertical_vector;

	vector<RecordedVariable> recorded_variables;

	GLuint transform_feedback_id;
	GLuint num_particles_id;

	GLuint particles_vbo[2];
	GLuint update_vao[2];
	GLuint render_vao[2];

	int max_particles;
	int num_particles;

	int read_buffer_index;

	const static int PARTICLE_TYPE_GENERATOR{ 0 }; // Represents generator particle
	const static int PARTICLE_TYPE_NORMAL{ 1 }; // Represents normal (non-generator) particle
};

#endif