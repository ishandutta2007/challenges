/*

This is a reverse coding challenge. Normally you're given explicit directions with how to create a function.
Here, you must generate your own function to satisfy the relationship between the inputs and outputs.

Your task is to create a function that, when fed the inputs below, produce the sample outputs shown.

Examples

"hello" ➞ [4, 1, 3, 3, 1]

"maybe" ➞ [4, 2, 1, 3, 1]

"hopeless" ➞ [0, 7, 0, 5, 4, 5, 3, 3]

"higher" ➞ [2, 3, 1, 2, 5, 0]

"movement" ➞ [5, 7, 6, 5, 5, 5, 6, 4]

Notes

If you get stuck, see Comments for a hint.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
mystery(const char *s, size_t *p)
{
	size_t i, n;

	n = strlen(s);
	for (i = 0; s[i]; i++)
		p[i] = s[i] % n;
	return n;
}

void
test(const char *s, size_t *r, size_t nr)
{
	size_t p[128];
	size_t np;

	np = mystery(s, p);
	assert(np == nr);
	assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main(void)
{
	size_t r1[] = {4, 1, 3, 3, 1};
	size_t r2[] = {4, 2, 1, 3, 1};
	size_t r3[] = {0, 7, 0, 5, 4, 5, 3, 3};
	size_t r4[] = {2, 3, 1, 2, 5, 0};
	size_t r5[] = {5, 7, 6, 5, 5, 5, 6, 4};

	test("hello", r1, nelem(r1));
	test("maybe", r2, nelem(r2));
	test("hopeless", r3, nelem(r3));
	test("higher", r4, nelem(r4));
	test("movement", r5, nelem(r5));

	return 0;
}
