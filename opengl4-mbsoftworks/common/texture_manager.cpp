#include "lib.h"

TextureManager &TextureManager::get_instance()
{
	static TextureManager texture_manager;
	return texture_manager;
}

int TextureManager::add_texture(const char *key, const char *name, bool mipmaps)
{
	Texture texture;
	auto ret = texture.load(name, mipmaps);
	if (ret < 0)
		return ret;
	textures[key] = texture;
	return 0;
}

bool TextureManager::contains_texture(const char *key)
{
	return textures.count(key) > 0;
}

void TextureManager::release()
{
	for (auto it = textures.begin(); it != textures.end(); it++)
		it->second.release();
	textures.clear();
}

const char *TextureManager::contains_texture_with_path(const char *filepath)
{
	for (auto &kv : textures)
	{
		auto &key = kv.first;
		auto &texture = kv.second;
		if (!strcmp(texture.filepath, filepath))
			return key.c_str();
	}

	return "";
}
