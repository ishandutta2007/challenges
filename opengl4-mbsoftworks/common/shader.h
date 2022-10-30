#ifndef _SHADER_H_
#define _SHADER_H_

class Shader
{
public:
	int load(const char *name, GLenum kind);
	void release();

	bool getLinesFromFile(const string &fileName, vector<string> &result, bool isReadingIncludedFile = false);

	GLuint id;
	GLenum type;
};

#endif
