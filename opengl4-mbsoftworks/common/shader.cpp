#include "lib.h"

int Shader::load(const char *name, GLenum kind)
{
	printf("Loading shader %s\n", name);

	vector<string> lines;
	if (!getLinesFromFile(name, lines))
		return -1;

	const char **src = new const char *[lines.size()];
	for (size_t i = 0; i < lines.size(); i++)
		src[i] = lines[i].c_str();

	type = kind;
	id = glCreateShader(type);
	glShaderSource(id, lines.size(), src, NULL);
	glCompileShader(id);

	int status;
	glGetShaderiv(id, GL_COMPILE_STATUS, &status);
	if (!status)
	{
		char buf[2048];
		int len;
		glGetShaderInfoLog(id, sizeof(buf), &len, buf);
		printf("Failed to compile shader: %s", buf);
		return -1;
	}

	delete[] src;

	return 0;
}

void Shader::release()
{
	glDeleteShader(id);
}

bool Shader::getLinesFromFile(const string &fileName, vector<string> &result, bool isReadingIncludedFile)
{
	ifstream file(fileName);

	if (!file.good())
	{
		printf("Shader file %s not found!\n", fileName.c_str());
		return false;
	}

	string startDirectory;
	char slashCharacter = '/';
	auto normFileName = string_utils::normalizeSlashes(fileName, slashCharacter);

	ssize_t slashIndex = -1;
	for (ssize_t i = fileName.size() - 1; i >= 0; i--)
	{
		if (fileName[i] == slashCharacter)
		{
			slashIndex = i;
			slashCharacter = fileName[i];
			break;
		}
	}

	startDirectory = fileName.substr(0, slashIndex + 1);

	// Get all lines from a file

	string line;
	bool isInsideIncludePart = false;

	while (getline(file, line))
	{
		line += "\n"; // getline does not keep newline character
		stringstream ss(line);
		string firstToken;
		ss >> firstToken;
		if (firstToken == "#include")
		{
			string includeFileName;
			ss >> includeFileName;
			if (includeFileName.size() > 0 && includeFileName[0] == '\"' && includeFileName[includeFileName.size() - 1] == '\"')
			{
				includeFileName = string_utils::normalizeSlashes(includeFileName.substr(1, includeFileName.size() - 2), slashCharacter);
				string directory = startDirectory;
				vector<std::string> subPaths = string_utils::split(includeFileName, slashCharacter);
				string sFinalFileName = "";
				for (const string &subPath : subPaths)
				{
					if (subPath == "..")
						directory = string_utils::upOneDirectory(directory, slashCharacter);
					else
					{
						if (sFinalFileName.size() > 0)
							sFinalFileName += slashCharacter;
						sFinalFileName += subPath;
					}
				}
				getLinesFromFile(directory + sFinalFileName, result, true);
			}
		}
		else if (firstToken == "#include_part")
			isInsideIncludePart = true;
		else if (firstToken == "#definition_part")
			isInsideIncludePart = false;
		else if (!isReadingIncludedFile || (isReadingIncludedFile && isInsideIncludePart))
			result.push_back(line);
	}

	file.close();

	return true;
}