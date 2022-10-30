/*

Return true if the sum of ASCII values of the first string is same as the sum of ASCII values of the second string, otherwise return false.
Examples

sameAscii("a", "a") ➞ true

sameAscii("AA", "B@") ➞ true

sameAscii("EdAbIt", "EDABIT") ➞ false

Notes

If you need some help with ASCII codes, check the Recources tab for an image of all ASCII codes used in this challenge.

*/

#include <assert.h>
#include <stdio.h>

int
sameascii(const char *s, const char *t)
{
	size_t i, x, y;

	x = y = 0;
	for (i = 0; s[i]; i++)
		x += s[i];
	for (i = 0; t[i]; i++)
		y += t[i];
	return x == y;
}

int
main(void)
{
	assert(sameascii("a", "a") == 1);
	assert(sameascii("A", "a") == 0);
	assert(sameascii("!", "g") == 0);
	assert(sameascii("aAAAaaAA", "~~~aa,") == 1);
	assert(sameascii("aUGSIGHIhiSJGijs", "~~~~~~~~~FF,") == 0);
	assert(sameascii("~~Tga2", "{}[]()I") == 1);

	return 0;
}
