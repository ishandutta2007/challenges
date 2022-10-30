#include "lib.h"

int Texture::create(unsigned char *data, int width, int height, int bpp, bool mipmaps)
{
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	auto internal_format = 0;
	auto format = 0;
	switch (bpp)
	{
	case 4:
		internal_format = format = GL_RGBA;
		break;
	case 3:
		internal_format = format = GL_RGB;
		break;
	case 1:
		internal_format = format = GL_DEPTH_COMPONENT;
		break;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, internal_format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	if (mipmaps)
		glGenerateMipmap(GL_TEXTURE_2D);

	this->width = width;
	this->height = height;
	this->bpp = bpp;

	auto err = glGetError();
	if (err)
		printf("GL texture error: %d\n", err);

	return 0;
}

int Texture::load(const char *name, bool mipmaps)
{
	printf("Loading texture %s\n", name);

	stbi_set_flip_vertically_on_load(1);
	auto data = stbi_load(name, &width, &height, &bpp, 0);
	if (!data)
	{
		printf("Failed to load texture: %s\n", name);
		return -1;
	}
	create(data, width, height, bpp, mipmaps);
	stbi_image_free(data);

	snprintf(filepath, sizeof(filepath), "%s", name);

	return 0;
}

void Texture::bind(int unit)
{
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::release()
{
	glDeleteTextures(1, &id);
}
