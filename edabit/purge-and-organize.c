/*

Given an array of numbers, write a function that returns an array that...

    Has all duplicate elements removed.
    Is sorted from least to greatest value.

Examples

uniqueSort([1, 2, 4, 3]) ➞ [1, 2, 3, 4]

uniqueSort([1, 4, 4, 4, 4, 4, 3, 2, 1, 2]) ➞ [1, 2, 3, 4]

uniqueSort([6, 7, 3, 2, 1]) ➞ [1, 2, 3, 6, 7]

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	double x, y;

	x = *(double *)a;
	y = *(double *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

size_t
uniqsort(double *a, size_t n)
{
	size_t i, j, k;

	if (n == 0)
		return 0;

	qsort(a, n, sizeof(*a), cmp);
	for (i = j = 0; i < n; i = k) {
		k = i + 1;
		while (k < n && a[i] == a[k])
			k++;
		a[j++] = a[i];
	}
	return j;
}

void
test(double *a, size_t na, double *b, size_t nb)
{
	size_t n;

	n = uniqsort(a, na);
	assert(n == nb);
	assert(memcmp(a, b, sizeof(*b) * nb) == 0);
}

int
main(void)
{
	double a1[] = { 1, 2, 4, 3 };
	double b1[] = { 1, 2, 3, 4 };

	double a2[] = { 1, 4, 4, 4, 4, 4, 3, 2, 1, 2 };
	double b2[] = { 1, 2, 3, 4 };

	double a3[] = { 6, 7, 3, 2, 1 };
	double b3[] = { 1, 2, 3, 6, 7 };

	double a4[] = { 1, 5, 8, 2, 3, 4, 4, 4, 10 };
	double b4[] = { 1, 2, 3, 4, 5, 8, 10 };

	double a5[] = { 1, 2, 5, 4, 7, 7, 7 };
	double b5[] = { 1, 2, 4, 5, 7 };

	double a6[] = { 7, 6, 5, 4, 3, 2, 1, 0, 1 };
	double b6[] = { 0, 1, 2, 3, 4, 5, 6, 7 };

	double a7[] = { 3, 6, 5, 4, 3, 27, 1, 100, 1 };
	double b7[] = { 1, 3, 4, 5, 6, 27, 100 };

	double a8[] = { -9, -3.1414, -87, 8, -4.323827, -3.1415, -3.1415 };
	double b8[] = { -87, -9, -4.323827, -3.1415, -3.1414, 8 };

	test(a1, nelem(a1), b1, nelem(b1));
	test(a2, nelem(a2), b2, nelem(b2));
	test(a3, nelem(a3), b3, nelem(b3));
	test(a4, nelem(a4), b4, nelem(b4));
	test(a5, nelem(a5), b5, nelem(b5));
	test(a6, nelem(a6), b6, nelem(b6));
	test(a7, nelem(a7), b7, nelem(b7));
	test(a8, nelem(a8), b8, nelem(b8));

	return 0;
}
