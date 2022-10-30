#include "lib.h"

ShaderManager &ShaderManager::get_instance()
{
	static ShaderManager shader_manager;
	return shader_manager;
}

int ShaderManager::add_shader(const char *key, const char *file, GLenum type)
{
	Shader shader;
	auto ret = shader.load(file, type);
	if (ret < 0)
		return ret;

	shaders[key] = shader;
	return 0;
}

int ShaderManager::make_program(const char *key, vector<string> shaders)
{
	return make_program_with_feedback(key, shaders, {});
}

int ShaderManager::make_program_with_feedback(const char *key, vector<string> shaders,
											  vector<string> recorded_variables,
											  GLenum buffer_mode)
{
	Program program;
	program.create();

	for (auto &shkey : shaders)
		program.attach(this->shaders[shkey]);

	if (recorded_variables.size() > 0)
		program.set_transform_feedback_recorded_variables(recorded_variables, buffer_mode);

	auto ret = program.link();
	if (ret < 0)
		return ret;

	programs[key] = program;
	return 0;
}

void ShaderManager::release()
{
	for (auto it = shaders.begin(); it != shaders.end(); it++)
		it->second.release();
	for (auto it = programs.begin(); it != programs.end(); it++)
		it->second.release();

	shaders.clear();
	programs.clear();
}