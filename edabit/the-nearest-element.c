/*

Given an array of integers arr, implement a function that returns the index of the number nearest to the given value n.
If two numbers equally distant from n are found, the function will return the greatest of them.

Examples

nearestElement(10, [1, 100, 1000]) ➞ 0
// 1 is the number nearest to 10.

nearestElement(50, [100, 49, 51]) ➞ 2
// 49 and 51 are equally distant from 50, with 51 being the greatest.

nearestElement(-20, [-50, -10, -30]) ➞ 1
// -10 and -30 are equally distant from -20, with -10 being the greatest.

Notes

Integers in arr will always be unique.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
nearest(int v, int *a, size_t n)
{
	size_t i, j;
	int u, w;

	if (n == 0)
		return 0;

	u = abs(v - a[0]);
	j = 0;
	for (i = 1; i < n; i++) {
		w = abs(v - a[i]);
		if (w < u || (w == u && a[i] > a[j])) {
			u = w;
			j = i;
		}
	}
	return j;
}

int
main(void)
{
	int a1[] = {1, 100, 1000};
	int a2[] = {100, 49, 51};
	int a3[] = {-50, -10, -30};
	int a4[] = {80, 60, 40};
	int a5[] = {47, 49, 73, 51, 44, 41};
	int a6[] = {0, -2, 3, 2, -1};
	int a7[] = {88, 99, 101, 108, 97, 98, 36};
	int a8[] = {13, 86, -49, -51, 8, 0};

	assert(nearest(10, a1, nelem(a1)) == 0);
	assert(nearest(50, a2, nelem(a2)) == 2);
	assert(nearest(-20, a3, nelem(a3)) == 1);
	assert(nearest(100, a4, nelem(a4)) == 0);
	assert(nearest(48, a5, nelem(a5)) == 1);
	assert(nearest(1, a6, nelem(a6)) == 3);
	assert(nearest(100, a7, nelem(a7)) == 2);
	assert(nearest(-50, a8, nelem(a8)) == 2);

	return 0;
}
