/*

A fulcrum of an array is an integer such that all elements to the left of it and all elements to the right of it sum to the same value. Write a function that finds the fulcrum of an array.

To illustrate:

findFulcrum([3, 1, 5, 2, 4, 6, -1]) ➞ 2
// Since [3, 1, 5] and [4, 6, -1] both sum to 9

Examples

findFulcrum([1, 2, 4, 9, 10, -10, -9, 3]) ➞ 4

findFulcrum([9, 1, 9]) ➞ 1

findFulcrum([7, -1, 0, -1, 1, 1, 2, 3]) ➞ 0

findFulcrum([8, 8, 8, 8]) ➞ -1

Notes

    If the fulcrum does not exist, return -1 (see example #4).
    Exclude the leftmost and rightmost elements when computing the fulcrum (it doesn't make sense to sum zero values).
    If an array has multiple fulcrums, return the one that occurs first.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
fulcrum(int *a, size_t n)
{
	size_t i;
	int x, y;

	x = y = 0;
	for (i = 0; i < n; i++)
		x += a[i];

	for (i = 0; i < n; i++) {
		x -= a[i];
		if (x == y && i > 0 && i + 1 < n)
			return a[i];
		y += a[i];
	}
	return -1;
}

int
main(void)
{
	int a1[] = { 3, 1, 5, 2, 4, 6, -1 };
	int a2[] = { 1, 2, 4, 9, 10, -10, -9, 3 };
	int a3[] = { 9, 1, 9 };
	int a4[] = { 7, -1, 0, -1, 1, 1, 2, 3 };
	int a5[] = { 8, 8, 8, 8 };
	int a6[] = { 9, 3, 4, 8, 1 };
	int a7[] = { 1, -1, 10, 5, -4, -1 };

	assert(fulcrum(a1, nelem(a1)) == 2);
	assert(fulcrum(a2, nelem(a2)) == 4);
	assert(fulcrum(a3, nelem(a3)) == 1);
	assert(fulcrum(a4, nelem(a4)) == 0);
	assert(fulcrum(a5, nelem(a5)) == -1);
	assert(fulcrum(a6, nelem(a6)) == -1);
	assert(fulcrum(a7, nelem(a7)) == 10);

	return 0;
}
