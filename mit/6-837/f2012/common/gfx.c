#include "lib.h"

GLuint
load_shader(const char *name, GLenum type)
{
	GLint id;
	const char *src;
	char buf[1024];
	int status, len;

	src = read_file(name, NULL);
	if (!src)
		fatal("Failed to read shader file %s: %s", name, strerror(errno));

	id = glCreateShader(type);
	glShaderSource(id, 1, &src, NULL);
	glCompileShader(id);
	glGetShaderiv(id, GL_COMPILE_STATUS, &status);
	if (!status) {
		glGetShaderInfoLog(id, sizeof(buf), &len, buf);
		fatal("Failed to compile shader: %s", buf);
	}

	free((void *)src);
	return id;
}