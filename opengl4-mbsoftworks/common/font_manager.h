#ifndef _FONT_MANAGER_H_
#define _FONT_MANAGER_H_

class FontManager
{
public:
	static FontManager &get_instance();

	int load(const char *key, const char *name, int pixel_size);

	void release();

	map<string, Font> fonts;
};

#endif