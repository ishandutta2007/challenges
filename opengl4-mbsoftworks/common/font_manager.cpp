#include "lib.h"

FontManager &FontManager::get_instance()
{
	static FontManager font_manager;
	return font_manager;
}

int FontManager::load(const char *key, const char *name, int pixel_size)
{
	Font font;
	font.init();
	auto ret = font.load(name, pixel_size);
	if (ret < 0)
		return ret;

	fonts[key] = font;
	return 0;
}

void FontManager::release()
{
	for (auto it = fonts.begin(); it != fonts.end(); it++)
		it->second.release();
}