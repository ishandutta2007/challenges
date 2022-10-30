#ifndef _SAMPLER_H_
#define _SAMPLER_H_

enum MagnificationFilter
{
	MAG_FILTER_NEAREST, // Nearest filter for magnification
	MAG_FILTER_BILINEAR, // Bilinear filter for magnification
};

enum MinificationFilter
{
	MIN_FILTER_NEAREST, // Nearest filter for minification
	MIN_FILTER_BILINEAR, // Bilinear filter for minification
	MIN_FILTER_NEAREST_MIPMAP, // Nearest filter for minification, but on closest mipmap
	MIN_FILTER_BILINEAR_MIPMAP, // Bilinear filter for minification, but on closest mipmap
	MIN_FILTER_TRILINEAR, // Bilinear filter for minification on two closest mipmaps, then averaged
};

class Sampler
{
public:
	void create();
	void bind(int unit = 0);
	void set_repeat(bool repeat);
	void release();

	void set_magnification_filter(MagnificationFilter filter);
	void set_minification_filter(MinificationFilter filter);

	GLuint id;
};

#endif