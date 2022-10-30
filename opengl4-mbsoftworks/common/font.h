#ifndef _FONT_H_
#define _FONT_H_

class Font
{
public:
	static const int TEXTURE_SIZE = 512;

	void init();
	void release();

	int load(const char *name, int pixel_size);

	void print(float x, float y, const char *fmt, ...);

	Vec4f color;
	float pixel_size;
	stbtt_bakedchar cdata[128];

	Texture texture;
	GLuint vao;
	VBO vbo;
};

#endif