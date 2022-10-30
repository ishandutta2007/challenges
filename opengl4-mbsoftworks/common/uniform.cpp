#include "lib.h"

Uniform::Uniform()
	: program(nullptr), location(-1)
{
}

Uniform::Uniform(const string &name, Program *program)
	: name(name), program(program)
{
	location = glGetUniformLocation(program->id, name.c_str());
	if (location == -1)
		printf("WARNING: Failed to get uniform with name: %s\n", name.c_str());
}

Uniform &Uniform::operator=(bool val)
{
	set(val);
	return *this;
}

void Uniform::set(bool val)
{
	set(val ? 1 : 0);
}

Uniform &Uniform::operator=(float val)
{
	set(val);
	return *this;
}

void Uniform::set(float val)
{
	glUniform1fv(location, 1, (GLfloat *)&val);
}

Uniform &Uniform::operator=(const vector<float> &vals)
{
	set(vals.data(), vals.size());
	return *this;
}

void Uniform::set(const float *vals, int count)
{
	glUniform1fv(location, count, (GLfloat *)vals);
}

Uniform &Uniform::operator=(int val)
{
	set(val);
	return *this;
}

void Uniform::set(int val)
{
	glUniform1iv(location, 1, (GLint *)&val);
}

Uniform &Uniform::operator=(const Vec3f &vect)
{
	set(vect);
	return *this;
}

void Uniform::set(const Vec3f &vect)
{
	glUniform3fv(location, 1, (GLfloat *)&vect);
}

Uniform &Uniform::operator=(const Vec4f &vect)
{
	set(vect);
	return *this;
}

void Uniform::set(const Vec4f &vect)
{
	glUniform4fv(location, 1, (GLfloat *)&vect);
}

Uniform &Uniform::operator=(const Mat3f &matrix)
{
	set(matrix);
	return *this;
}

void Uniform::set(const Mat3f &matrix)
{
	glUniformMatrix3fv(location, 1, GL_TRUE, (GLfloat *)&matrix);
}

Uniform &Uniform::operator=(const Mat4f &matrix)
{
	set(matrix);
	return *this;
}

void Uniform::set(const Mat4f &matrix)
{
	glUniformMatrix4fv(location, 1, GL_TRUE, (GLfloat *)&matrix);
}
