/*

Create a function that returns the smallest number of letter removals so that two strings are anagrams of each other.

Notes

    An anagram is any string that can be formed by shuffling the characters of the original string. For example: baedc is an anagram of abcde.
    An empty string can be considered an anagram of itself.
    Characters won't be used more than once per string.

*/

#include <stdio.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

size_t
minrem(const char *s, const char *t)
{
	size_t i, r, h[2][256];

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++)
		h[0][s[i] & 0xff]++;
	for (i = 0; t[i]; i++)
		h[1][t[i] & 0xff]++;

	r = 0;
	for (i = 0; i < 256; i++)
		r += max(h[0][i], h[1][i]) - min(h[0][i], h[1][i]);
	return r;
}

int
main(void)
{
	printf("%zu\n", minrem("abcde", "cab"));
	printf("%zu\n", minrem("deafk", "kfeap"));
	printf("%zu\n", minrem("abc", "ghi"));
	printf("%zu\n", minrem("abcxyz", "ghixytz"));
	printf("%zu\n", minrem("", ""));
	printf("%zu\n", minrem("", "hwe32r"));
	return 0;
}
