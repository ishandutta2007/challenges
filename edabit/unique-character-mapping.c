/*

Write a function that returns a character mapping from a word.
Examples

characterMapping("abcd") ➞ [0, 1, 2, 3]

characterMapping("abb") ➞ [0, 1, 1]

characterMapping("babbcb") ➞ [0, 1, 0, 0, 2, 0]

characterMapping("hmmmmm") ➞ [0, 1, 1, 1, 1, 1]

Notes

    Start your counter at 0, and increment by 1 each time you encounter a new character.
    Identical characters should share the same number.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t *
charmap(const char *s)
{
	size_t i, j, k, l, *m;
	size_t h[256];

	l = strlen(s);
	m = calloc(l + 1, sizeof(*m));
	if (!m)
		return NULL;

	memset(h, 0, sizeof(h));
	for (i = k = 0; i < l; i++) {
		j = s[i] & 0xff;
		if (!h[j])
			h[j] = ++k;
		m[i] = h[j] - 1;
	}
	return m;
}

void
test(const char *s, size_t *r, size_t n)
{
	size_t *p;

	p = charmap(s);
	assert(p);
	assert(!memcmp(p, r, sizeof(*r) * n));
	free(p);
}

int
main(void)
{
	size_t m1[] = {0, 1, 2, 3};
	size_t m2[] = {0, 1, 1};
	size_t m3[] = {0, 1, 0, 0, 2, 0};
	size_t m4[] = {0, 0, 0, 1, 1};
	size_t m5[] = {0, 1, 2, 2, 1, 2};
	size_t m6[] = {0, 1, 2, 0, 0, 3};
	size_t m7[] = {0, 1, 2, 3, 4, 5, 5};
	size_t m8[] = {0, 1, 2, 2, 3, 4, 5};
	size_t m9[] = {0, 1, 2, 3, 2, 4};
	size_t m10[] = {0, 1, 0, 1, 0, 1};
	size_t m11[] = {0, 1, 1, 1, 1, 1};

	test("abcd", m1, nelem(m1));
	test("abb", m2, nelem(m2));
	test("babbcb", m3, nelem(m3));
	test("aaabb", m4, nelem(m4));
	test("abccbc", m5, nelem(m5));
	test("fluffy", m6, nelem(m6));
	test("madness", m7, nelem(m7));
	test("buttery", m8, nelem(m8));
	test("canine", m9, nelem(m9));
	test("hohoho", m10, nelem(m10));
	test("hmmmmm", m11, nelem(m11));
	test("", NULL, 0);

	return 0;
}
