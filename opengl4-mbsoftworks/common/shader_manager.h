#ifndef _SHADER_MANAGER_H_
#define _SHADER_MANAGER_H_

class ShaderManager
{
public:
	static ShaderManager &get_instance();

	int add_shader(const char *key, const char *file, GLenum type);
	int make_program(const char *key, vector<string> shaders);
	int make_program_with_feedback(const char *key, vector<string> shaders,
								   vector<string> recorded_variables,
								   GLenum buffer_mode = GL_INTERLEAVED_ATTRIBS);

	void release();

	map<string, Shader> shaders;
	map<string, Program> programs;
};

#endif
