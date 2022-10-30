/*

Create a function that takes an array of numbers and returns only the even values.
Examples

NoOdds([1, 2, 3, 4, 5, 6, 7, 8]) ➞ [2, 4, 6, 8]

NoOdds([43, 65, 23, 89, 53, 9, 6]) ➞ [6]

NoOdds([718, 991, 449, 644, 380, 440]) ➞ [718, 644, 380, 440]

Notes

    Return all even numbers in the order they were given.
    All test cases contain valid numbers ranging from 1 to 3000.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
noodds(unsigned *a, size_t n)
{
	size_t i, j;

	for (i = j = 0; i < n; i++) {
		if (!(a[i] & 1))
			a[j++] = a[i];
	}
	return j;
}

void
test(unsigned *a, size_t n, unsigned *b)
{
	size_t m;

	m = noodds(a, n);
	assert(memcmp(a, b, m * sizeof(*b)) == 0);
}

int
main(void)
{
	unsigned a1[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	unsigned a2[] = { 43, 65, 23, 89, 53, 9, 6 };
	unsigned a3[] = { 718, 991, 449, 644, 380, 440 };
	unsigned a4[] = { 148, 6, 16, 85 };
	unsigned a5[] = { 9, 49, 23 };
	unsigned a6[] = { 34, 43, 32, 49, 40 };
	unsigned a7[] = { 1232, 1990, 1284, 1391, 1958 };
	unsigned a8[] = { 2766, 2651, 2373, 2916, 2397, 2539 };
	unsigned a9[] = { 53, 65, 52, 62, 59 };
	unsigned a10[] = { 393, 156, 14, 166, 129, 246 };

	unsigned b1[] = { 2, 4, 6, 8 };
	unsigned b2[] = { 6 };
	unsigned b3[] = { 718, 644, 380, 440 };
	unsigned b4[] = { 148, 6, 16 };
	unsigned b5[] = { 0 };
	unsigned b6[] = { 34, 32, 40 };
	unsigned b7[] = { 1232, 1990, 1284, 1958 };
	unsigned b8[] = { 2766, 2916 };
	unsigned b9[] = { 52, 62 };
	unsigned b10[] = { 156, 14, 166, 246 };

	test(a1, nelem(a1), b1);
	test(a2, nelem(a2), b2);
	test(a3, nelem(a3), b3);
	test(a4, nelem(a4), b4);
	test(a5, nelem(a5), b5);
	test(a6, nelem(a6), b6);
	test(a7, nelem(a7), b7);
	test(a8, nelem(a8), b8);
	test(a9, nelem(a9), b9);
	test(a10, nelem(a10), b10);

	return 0;
}
