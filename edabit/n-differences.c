/*

Write a function that transforms an array into an array of its differences repeatedly until there exists only one element left. A difference is A[n+1] - A[n].

To illustrate:

[5, 1, 9, 3, 4, 0]

[-4, 8, -6, 1, -4] // 1 - 5 = 4; 9 - 1 = 8; 3 - 9 = -6; etc.

[12, -14, 7, -5]

[-26, 21, -12]

[47, -33]

-80

Examples

nDifferences([5, 1, 9, 3, 4, 0]) ➞ -80

nDifferences([1, 1, 1, 1]) ➞ 0

nDifferences([5, 8, 8]) ➞ -3

Notes

Each array will have at least two elements.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
ndiff(int *a, size_t n)
{
	int *p, r;
	size_t i;

	if (n < 2)
		return 0;

	p = calloc(n, sizeof(*p));
	if (!p)
		return 0;

	memcpy(p, a, sizeof(*p) * n);
	for (; n > 1; n--) {
		for (i = 1; i < n; i++)
			p[i - 1] = p[i] - p[i - 1];
	}
	r = p[0];
	free(p);

	return r;
}

int
main(void)
{
	int a1[] = { 5, 1, 9, 3, 4, 0 };
	int a2[] = { 8, 9, 2, 5, 4, 3, 3, 1, 6 };
	int a3[] = { 5, 1, 9, 6, 1, 7, 3, 4 };
	int a4[] = { 1, 1, 1, 1 };
	int a5[] = { 5, 9, 7, 3 };
	int a6[] = { 1, 5, 3, 9, 7 };
	int a7[] = { 5, 8, 8 };
	int a8[] = { 4, 0, 0, 0, 1 };
	int a9[] = { 3, 5 };

	assert(ndiff(a1, nelem(a1)) == -80);
	assert(ndiff(a2, nelem(a2)) == -94);
	assert(ndiff(a3, nelem(a3)) == 118);
	assert(ndiff(a4, nelem(a4)) == 0);
	assert(ndiff(a5, nelem(a5)) == 4);
	assert(ndiff(a6, nelem(a6)) == -30);
	assert(ndiff(a7, nelem(a7)) == -3);
	assert(ndiff(a8, nelem(a8)) == 5);
	assert(ndiff(a9, nelem(a9)) == 2);

	return 0;
}
