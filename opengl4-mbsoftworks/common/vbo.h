#ifndef _VBO_H_
#define _VBO_H_

class VBO
{
public:
	void create(unsigned reserved = 0);
	void bind(GLenum kind = GL_ARRAY_BUFFER);
	void add(void *data, size_t size, int repeat = 1);
	void upload(GLenum usage);
	void release();

	GLuint id;
	int type;
	vector<unsigned char> buffer;
};

#endif
