#ifndef _TEXTURE_MANAGER_H_
#define _TEXTURE_MANAGER_H_

class TextureManager
{
public:
	static TextureManager &get_instance();

	int add_texture(const char *key, const char *name, bool mipmap = true);
	bool contains_texture(const char *key);
	const char *contains_texture_with_path(const char *filepath);

	void release();

	map<string, Texture> textures;
};

#endif