#include "lib.h"

void Program::create()
{
	id = glCreateProgram();
}

void Program::attach(Shader &shader)
{
	glAttachShader(id, shader.id);
}

int Program::link()
{
	glLinkProgram(id);
	int status;
	glGetProgramiv(id, GL_LINK_STATUS, &status);
	if (!status)
	{
		char buf[2048];
		int len;
		glGetProgramInfoLog(id, sizeof(buf), &len, buf);
		printf("Failed to link shader program: %s\n", buf);
		return -1;
	}

	return 0;
}

void Program::use()
{
	glUseProgram(id);
}

void Program::release()
{
	glDeleteProgram(id);
}

Uniform &Program::operator[](const string &name)
{
	if (uniforms.count(name) == 0)
		uniforms[name] = Uniform(name, this);
	return uniforms[name];
}

void Program::set_model_and_normal_matrix(const Mat4f &mat)
{
	auto nrm = Mat3f::transpose(Mat3f::inverse(Mat4f::mat3(mat)));
	(*this)["matrices.modelMatrix"] = mat;
	(*this)["matrices.normalMatrix"] = nrm;
}

GLuint Program::get_uniform_block_index(const string &name)
{
	return glGetUniformBlockIndex(id, name.c_str());
}

void Program::bind_uniform_block(const string &name, GLuint binding_point)
{
	auto block_index = get_uniform_block_index(name);
	glUniformBlockBinding(id, block_index, binding_point);
}

void Program::set_transform_feedback_recorded_variables(const vector<string> &recorded_variables_names, const GLenum buffer_mode) const
{
	vector<const char *> recorded_variables_names_ptrs;
	for (const auto &recorded_variables_name : recorded_variables_names)
		recorded_variables_names_ptrs.push_back(recorded_variables_name.c_str());
	glTransformFeedbackVaryings(id, static_cast<GLsizei>(recorded_variables_names_ptrs.size()), recorded_variables_names_ptrs.data(), buffer_mode);
}
