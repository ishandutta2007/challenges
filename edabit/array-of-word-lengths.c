/*

Create a function that takes an array of words and transforms it into an array of each word's length.
Examples

wordLengths(["hello", "world"]) ➞ [5, 5]

wordLengths(["Halloween", "Thanksgiving", "Christmas"]) ➞ [9, 12, 9]

wordLengths(["She", "sells", "seashells", "down", "by", "the", "seashore"]) ➞ [3, 5, 9, 4, 2, 3, 8]

Notes

    No test case will contain punctuation.
    Arrays can be of various lengths.

*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t *
wordlens(const char **s, size_t n)
{
	size_t i, *p;

	p = calloc(n, sizeof(*p));
	if (!p)
		return NULL;

	for (i = 0; i < n; i++)
		p[i] = strlen(s[i]);
	return p;
}

void
test(const char **s, size_t n, size_t *w)
{
	size_t *p;

	p = wordlens(s, n);
	assert(p && memcmp(p, w, sizeof(*w) * n) == 0);
	free(p);
}

int
main(void)
{
	const char *s1[] = { "hello", "world" };
	const char *s2[] = { "Halloween", "Thanksgiving", "Christmas" };
	const char *s3[] = { "She", "sells", "seashells", "down", "by", "the", "seashore" };
	const char *s4[] = { "Indiana", "Jones", "and", "the", "Temple", "of", "Doom" };
	const char *s5[] = { "Programming", "is", "fun" };

	size_t w1[] = { 5, 5 };
	size_t w2[] = { 9, 12, 9 };
	size_t w3[] = { 3, 5, 9, 4, 2, 3, 8 };
	size_t w4[] = { 7, 5, 3, 3, 6, 2, 4 };
	size_t w5[] = { 11, 2, 3 };

	test(s1, nelem(s1), w1);
	test(s2, nelem(s2), w2);
	test(s3, nelem(s3), w3);
	test(s4, nelem(s4), w4);
	test(s5, nelem(s5), w5);

	return 0;
}
