/*

Given an array of numbers, of any length, create a function which counts how many of those numbers pass the following criterea:

The first and last digits of a number must add to 10.

Examples

endsAddTo10([19, 46, 2098]) ➞ 3

endsAddTo10([33, 44, -55]) ➞ 1

endsAddTo10([]) ➞ 0

Notes

    All items in the array will be numbers.
    Ignore negative signs (see example #2).
    If given an empty array, return 0.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
ten(int x)
{
	char d[sizeof(x) * CHAR_BIT];
	size_t n;

	x = abs(x);
	for (n = 0; x; x /= 10)
		d[n++] = x % 10;
	return n >= 1 && d[0] + d[n - 1] == 10;
}

size_t
ends(int *a, size_t n)
{
	size_t i, r;

	r = 0;
	for (i = 0; i < n; i++)
		r += ten(a[i]);
	return r;
}

int
main(void)
{
	int a1[] = {19, 46, 2098};
	int a2[] = {33, 44, -55};
	int a3[] = {-91, 55, -33};
	int a4[] = {100, -10, 1, 3, 2, 5, 2};
	int a5[] = {19, 28, 37, 46, 55, 64, 73, 82, 91};
	int a6[] = {-19, -28, -37, -46, -55, -64, -73, -82, -91};

	assert(ends(a1, nelem(a1)) == 3);
	assert(ends(a2, nelem(a2)) == 1);
	assert(ends(NULL, 0) == 0);
	assert(ends(a3, nelem(a3)) == 2);
	assert(ends(a4, nelem(a4)) == 1);
	assert(ends(a5, nelem(a5)) == 9);
	assert(ends(a6, nelem(a6)) == 9);

	return 0;
}
