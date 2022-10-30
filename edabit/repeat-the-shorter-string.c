/*

Write a function that repeats the shorter string until it is equal to the length of the longer string.
Examples

lengthen("abcdefg", "ab") ➞ "abababa"

lengthen("ingenius", "forest") ➞ "forestfo"

lengthen("clap", "skipping") ➞ "clapclap"

Notes

    Both strings will differ in length.
    Both strings will contain at least one character.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

char *
lengthen(const char *s, const char *r, char *b)
{
	size_t i, j, k, l, m, n;
	const char *p;

	n = strlen(s);
	m = strlen(r);
	l = max(n, m);
	k = min(n, m);
	p = (n < m) ? s : r;

	if (n == 0 || m == 0) {
		b[0] = '\0';
		return b;
	}

	for (i = j = 0; i < l; i++)
		b[j++] = p[i % k];
	b[j] = '\0';

	return b;
}

int
main(void)
{
	char b[80];

	assert(strcmp(lengthen("abcdefg", "ab", b), "abababa") == 0);
	assert(strcmp(lengthen("ingenius", "forest", b), "forestfo") == 0);
	assert(strcmp(lengthen("skipping", "clap", b), "clapclap") == 0);
	assert(strcmp(lengthen("k", "champagne", b), "kkkkkkkkk") == 0);
	assert(strcmp(lengthen("DUH", "champagne", b), "DUHDUHDUH") == 0);

	return 0;
}
