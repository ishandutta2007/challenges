#include "lib.h"

void UBO::create(size_t size, GLenum usage)
{
	// Generate buffer ID, bind it immediately and reserve space for it
	glGenBuffers(1, &id);
	glBindBuffer(GL_UNIFORM_BUFFER, id);
	glBufferData(GL_UNIFORM_BUFFER, size, NULL, usage);

	// Mark that the buffer has been created and store its size
	this->size = size;
}

void UBO::bind()
{
	glBindBuffer(GL_UNIFORM_BUFFER, id);
}

void UBO::set(size_t off, void *data, size_t len)
{
	glBufferSubData(GL_UNIFORM_BUFFER, off, len, data);
}

void UBO::set_binding_point(GLuint binding_point)
{
	glBindBufferBase(GL_UNIFORM_BUFFER, binding_point, id);
}

void UBO::release()
{
	glDeleteBuffers(1, &id);
}