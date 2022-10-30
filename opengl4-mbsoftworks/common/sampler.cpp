#include "lib.h"

void Sampler::create()
{
	glGenSamplers(1, &id);
	set_repeat(true);
}

void Sampler::bind(int unit)
{
	glBindSampler(unit, id);
}

void Sampler::set_repeat(bool repeat)
{
	auto param = repeat ? GL_REPEAT : GL_CLAMP_TO_EDGE;
	glSamplerParameteri(id, GL_TEXTURE_WRAP_S, param);
	glSamplerParameteri(id, GL_TEXTURE_WRAP_T, param);
}

void Sampler::release()
{
	glDeleteSamplers(1, &id);
}

void Sampler::set_magnification_filter(MagnificationFilter filter)
{
	auto pname = GL_TEXTURE_MAG_FILTER;
	auto param = GL_NEAREST;
	if (filter == MAG_FILTER_BILINEAR)
		param = GL_LINEAR;

	glSamplerParameteri(id, pname, param);
}

void Sampler::set_minification_filter(MinificationFilter filter)
{
	auto pname = GL_TEXTURE_MIN_FILTER;
	auto param = GL_NEAREST;
	if (filter == MIN_FILTER_BILINEAR)
		param = GL_LINEAR;
	else if (filter == MIN_FILTER_NEAREST_MIPMAP)
		param = GL_NEAREST_MIPMAP_NEAREST;
	else if (filter == MIN_FILTER_BILINEAR_MIPMAP)
		param = GL_LINEAR_MIPMAP_NEAREST;
	else if (filter == MIN_FILTER_TRILINEAR)
		param = GL_LINEAR_MIPMAP_LINEAR;

	glSamplerParameteri(id, pname, param);
}