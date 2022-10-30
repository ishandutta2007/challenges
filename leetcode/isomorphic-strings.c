/*

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool
isomorphic(const char *s, const char *t)
{
	size_t a[256], b[256], i;
	char h[256], g[256];
	int x, y;

	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(h, 0, sizeof(h));
	memset(g, 0, sizeof(g));
	for (i = 0; s[i] && t[i]; i++) {
		x = s[i] & 0xff;
		y = t[i] & 0xff;
		if (!a[x])
			h[x] = y;
		if (!b[y])
			g[y] = x;
		if (++a[x] != ++b[y] || h[x] != y || g[y] != x)
			return false;
	}
	return !s[i] && !t[i];
}

int
main(void)
{
	assert(isomorphic("egg", "add") == true);
	assert(isomorphic("foo", "bar") == false);
	assert(isomorphic("paper", "title") == true);
	assert(isomorphic("aba", "baa") == false);
	assert(isomorphic("ab", "ca") == true);
	assert(isomorphic("approximate", "tooxaezptom") == false);
	assert(isomorphic("ab ", "to") == false);

	return 0;
}
