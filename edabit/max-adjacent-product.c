/*

Given an array of integers, find the pair of adjacent elements that have the largest product and return that product.

Examples

adjacentProduct([3, 6, -2, -5, 7, 3] ) ➞ 21

adjacentProduct([5, 6, -4, 2, 3, 2, -23]) ➞ 30

adjacentProduct([0, -1, 1, 24, 1, -4, 8, 10]) ➞ 80

Notes

Each array has at least two elements.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
adjacent(int *a, size_t n)
{
	size_t i;
	int r;

	if (n == 0)
		return 0;
	if (n == 1)
		return a[0];

	r = a[0] * a[1];
	for (i = 1; i < n - 1; i++)
		r = max(r, a[i] * a[i + 1]);
	return r;
}

int
main(void)
{
	int a1[] = {3, 6, -2, -5, 7, 3};
	int a2[] = {5, 6, -4, 2, 3, 2, -23};
	int a3[] = {0, -1, 1, 24, 1, -4, 8, 10};
	int a4[] = {1, 0, 1, 0, 1000};
	int a5[] = {-23, 4, -3, 8, -12};
	int a6[] = {-1, -2};

	assert(adjacent(a1, nelem(a1)) == 21);
	assert(adjacent(a2, nelem(a2)) == 30);
	assert(adjacent(a3, nelem(a3)) == 80);
	assert(adjacent(a4, nelem(a4)) == 0);
	assert(adjacent(a5, nelem(a5)) == -12);
	assert(adjacent(a6, nelem(a6)) == 2);

	return 0;
}
