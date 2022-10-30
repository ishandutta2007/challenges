#ifndef _TEXTURE_H_
#define _TEXTURE_H_

class Texture
{
public:
	int create(unsigned char *data, int width, int height, int bpp, bool mipmap = false);
	int load(const char *path, bool mipmaps = true);
	void bind(int unit = 0);
	void release();

	GLuint id;
	int width;
	int height;
	int bpp;

	char filepath[PATH_MAX];
};

#endif