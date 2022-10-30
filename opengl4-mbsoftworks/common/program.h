#ifndef _PROGRAM_H_
#define _PROGRAM_H_

class Program
{
public:
	void create();
	void attach(Shader &shader);
	int link();
	void use();
	void release();

	Uniform &operator[](const string &name);
	void set_model_and_normal_matrix(const Mat4f &mat);

	GLuint get_uniform_block_index(const string &name);
	void bind_uniform_block(const string &name, GLuint binding_point);

	void set_transform_feedback_recorded_variables(const vector<string> &recorded_variables_names,
												   const GLenum buffer_mode = GL_INTERLEAVED_ATTRIBS) const;

	GLuint id;
	map<string, Uniform> uniforms;
};

#endif
