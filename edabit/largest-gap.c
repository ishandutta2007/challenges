/*

Given an array of integers, return the largest gap between the sorted elements of the array.

For example, consider the array:

[9, 4, 26, 26, 0, 0, 5, 20, 6, 25, 5]

... in which, after sorting, the array becomes:

[0, 0, 4, 5, 5, 6, 9, 20, 25, 26, 26]

... so that we now see that the largest gap in the array is between 9 and 20 which is 11.
Examples

largestGap([9, 4, 26, 26, 0, 0, 5, 20, 6, 25, 5]) ➞ 11
// After sorting: [0, 0, 4, 5, 5, 6, 9, 20, 25, 26, 26]
// Largest gap between 9 and 20 is 11

largestGap([14, 13, 7, 1, 4, 12, 3, 7, 7, 12, 11, 5, 7]) ➞ 4
// After sorting: [1, 3, 4, 5, 7, 7, 7, 7, 11, 12, 12, 13, 14]
// Largest gap between 7 and 11 is 4

largestGap([13, 3, 8, 5, 5, 2, 13, 6, 14, 2, 11, 4, 10, 8, 1, 9]) ➞ 2
// After sorting: [1, 2, 2, 3, 4, 5, 5, 6, 8, 8, 9, 10, 11, 13, 13, 14]
// Largest gap between 6 and 8 is 2

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;

	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

int
largestgap(int *a, size_t n)
{
	size_t i;
	int r;

	qsort(a, n, sizeof(*a), cmp);

	r = 0;
	for (i = 1; i < n; i++)
		r = max(r, a[i] - a[i - 1]);
	return r;
}

int
main(void)
{
	int a1[] = {9, 4, 26, 26, 0, 0, 5, 20, 6, 25, 5};
	int a2[] = {14, 13, 7, 1, 4, 12, 3, 7, 7, 12, 11, 5, 7};
	int a3[] = {13, 3, 8, 5, 5, 2, 13, 6, 14, 2, 11, 4, 10, 8, 1, 9};
	int a4[] = {21, 28, 0, 5, 11, 6, 17, 25, 2, 19};
	int a5[] = {26, 17, 4, 25, 29, 26, 8, 30, 4, 20, 2, 7, 29, 7, 20, 30, 23, 5};
	int a6[] = {12, 13, 17, 20, 23, 25, 29, 26, 12, 7, 9};

	assert(largestgap(a1, nelem(a1)) == 11);
	assert(largestgap(a2, nelem(a2)) == 4);
	assert(largestgap(a3, nelem(a3)) == 2);
	assert(largestgap(a4, nelem(a4)) == 6);
	assert(largestgap(a5, nelem(a5)) == 9);
	assert(largestgap(a6, nelem(a6)) == 4);

	return 0;
}
