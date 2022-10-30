#include "lib.h"

void VBO::create(unsigned reserved)
{
	glGenBuffers(1, &id);
	buffer.reserve(reserved > 0 ? reserved : 1024);
	printf("Created VBO object %u with initial reserved size %zu\n", id, buffer.capacity());
}

void VBO::bind(GLenum kind)
{
	type = kind;
	glBindBuffer(type, id);
}

void VBO::add(void *data, size_t size, int repeat)
{
	auto ptr = (unsigned char *)data;
	for (auto i = 0; i < repeat; i++)
	{
		for (size_t n = 0; n < size; n++)
			buffer.push_back(ptr[n]);
	}
}

void VBO::upload(GLenum usage)
{
	glBufferData(type, buffer.size(), &buffer[0], usage);
	buffer.resize(0);
}

void VBO::release()
{
	glDeleteBuffers(1, &id);
}
