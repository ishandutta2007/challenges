/*

Write a function that returns true if it is possible to build a string with a particular scrabble hand.

Examples

canBuild("quavers", ["S", "U", "Q", "V", "A", "#", "#"]) ➞ true

canBuild("move", ["M", "U", "T", "V", "E", "J", "#"]) ➞ true

canBuild("move", ["M", "U", "T", "V", "E", "J", "S"]) ➞ false

canBuild("sharp", ["S", "K", "H", "#", "#", "F", "F"]) ➞ false

Notes

Hashtags "#" represent wild tiles.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
conv(int c)
{
	if (c == '#')
		return 0;
	if (isalpha(c))
		return tolower(c);
	return c & 0xff;
}

bool
buildable(const char *s, const char *t)
{
	size_t i, h[256];
	int c;

	memset(h, 0, sizeof(h));
	for (i = 0; t[i]; i++)
		h[conv(t[i])]++;

	for (i = 0; s[i]; i++) {
		c = conv(s[i]);
		if (h[c])
			h[c]--;
		else if (h[0])
			h[0]--;
		else
			return false;
	}
	return true;
}

int
main(void)
{
	assert(buildable("quavers", "SUQVA##") == true);
	assert(buildable("move", "MUTVEJ#") == true);
	assert(buildable("move", "MUTVEJS") == false);
	assert(buildable("sharp", "SKH##FF") == false);
	assert(buildable("banter", "NEBN#AT") == true);
	assert(buildable("snake", "SKENVJA") == true);
	assert(buildable("more", "MRIEUSF") == false);
	assert(buildable("talker", "##ZVPAK") == false);
	assert(buildable("talker", "##TTAAL") == false);
	assert(buildable("brain", "#SBBII#") == false);
	assert(buildable("##", "#SBBII#") == true);

	return 0;
}
