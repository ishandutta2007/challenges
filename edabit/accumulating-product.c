/*

Create a function that takes an array and returns an array of the accumulating product.
Examples

accumulatingProduct([1, 2, 3, 4]) ➞ [1, 2, 6, 24]
// [1, 2, 6, 24] can be written as [1, 1 x 2, 1 x 2 x 3, 1 x 2 x 3 x 4]

accumulatingProduct([1, 5, 7]) ➞ [1, 5, 35]

accumulatingProduct([1, 0, 1, 0]) ➞ [1, 0, 0, 0]

accumulatingProduct([]) ➞ []

Notes

An empty array should return an empty array [].

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int *
accumulate(int *a, size_t n)
{
	size_t i;
	int *p;

	p = calloc(n + 1, sizeof(*p));
	if (!p)
		return NULL;

	if (n == 0)
		return p;

	p[0] = a[0];
	for (i = 1; i < n; i++)
		p[i] = p[i - 1] * a[i];
	return p;
}

void
test(int *a, int *b, size_t n)
{
	int *p;

	p = accumulate(a, n);
	assert(p);
	assert(memcmp(p, b, n * sizeof(*p)) == 0);
	free(p);
}

int
main(void)
{
	int a1[] = { 1, 2, 3, 4 };
	int b1[] = { 1, 2, 6, 24 };

	int a2[] = { 5, 10, 1, 1 };
	int b2[] = { 5, 50, 50, 50 };

	int a3[] = { 1, 5, 7 };
	int b3[] = { 1, 5, 35 };

	int a4[] = { 1, 0, 1, 0 };
	int b4[] = { 1, 0, 0, 0 };

	int a5[] = { 1 };
	int b5[] = { 1 };

	int a6[] = { 1, 2, 2, 2, 2, 2, 2 };
	int b6[] = { 1, 2, 4, 8, 16, 32, 64 };

	int a7[] = { 1, 1, 1, 1, 1, 1, 1 };
	int b7[] = { 1, 1, 1, 1, 1, 1, 1 };

	test(a1, b1, nelem(a1));
	test(a2, b2, nelem(a2));
	test(a3, b3, nelem(a3));
	test(a4, b4, nelem(a4));
	test(a5, b5, nelem(a5));
	test(a6, b6, nelem(a6));
	test(a7, b7, nelem(a7));
	test(a7, b7, 0);

	return 0;
}
