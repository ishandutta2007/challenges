#ifndef _UBO_H_
#define _UBO_H_

class UBO
{
public:
	static const int MATRICES{ 0 };
	static const int POINT_LIGHTS{ 1 };

	void create(size_t size, GLenum usage = GL_STREAM_DRAW);
	void bind();
	void set(size_t off, void *data, size_t len);
	void set_binding_point(GLuint binding_point);
	void release();

	GLuint id;
	size_t size;
};

#endif