/*

Given an array of integers, find the length of the longest range of consecutive integers that are contained in the sorted version of the array.

Here's an illustrative example. Consider the array:

[4, 9, 10, 5, 17, 3, 8, 11, 1, 12, 18, 20]

... which, after sorting, becomes:

[1, 3, 4, 5, 8, 9, 10, 11, 12, 17, 18, 20]

The longest consecutive subsequence is now clearly [8, 9, 10, 11, 12], which has length 5.
Examples

maxConsec([4, 9, 10, 5, 17, 3, 8, 11, 1, 12, 18, 20]) ➞ 5
// After sorting array becomes [1, 2, 4, 5, 8, 9, 10, 11, 12, 17, 18, 20]
// Longest consecutive subsequence is [8, 9, 10, 11, 12], which has length 5

maxConsec([14, 13, 7, 1, 4, 12, 3, 7, 7, 12, 11, 5, 7]) ➞ 4
// After sorting get [1, 3, 4, 5, 7, 7, 7, 7, 11, 12, 12, 13, 14]
// Longest consecutive subsequence is [11, 12, 13, 14], which has length 4

maxConsec([13, 3, 8, 5, 5, 2, 13, 6, 14, 2, 11, 4, 10, 8, 1, 9]) ➞ 6
// After sorting get [1, 2, 2, 3, 4, 5, 5, 6, 8, 8, 9, 10, 11, 13, 13, 14]
// Longest consecutive subsequence is [1, 2, 3, 4, 5, 6], which has length 6

Notes

As in the 2nd and 3rd examples, the given array is allowed to include repeated elements, but such repetitions are ignored when finding the longest range of consecutive elements.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

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

size_t
maxcon(int *a, size_t n)
{
	size_t i, j, r;

	if (n == 0)
		return 0;

	qsort(a, n, sizeof(*a), cmp);
	r = j = 1;
	for (i = 0; i < n - 1; i++) {
		if (a[i] + 1 == a[i + 1])
			j++;
		else if (a[i] != a[i + 1])
			j = 1;
		if (r < j)
			r = j;
	}

	return r;
}

int
main(void)
{
	int a1[] = {4, 9, 10, 5, 17, 3, 8, 11, 1, 12, 18, 20};
	int a2[] = {14, 13, 7, 1, 4, 12, 3, 7, 7, 12, 11, 5, 7};
	int a3[] = {13, 3, 8, 5, 5, 2, 1, 13, 8, 6, 14, 2, 11, 4, 10, 8, 1, 10, 9};
	int a4[] = {1, 4, 14, 9, 7, 9, 3, 13, 7, 4, 14, 11, 14, 8, 1, 11, 0, 1};
	int a5[] = {2, 3, 7, 2, 14, 4, 7, 3, 10, 2, 8, 7, 14, 9, 5, 7, 3};
	int a6[] = {1, 1, 14, 8, 11, 13, 0, 3, 9, 6, 11, 4, 10, 12, 5, 2, 13, 13, 10, 3, 7, 12, 14, 0, 0, 10, 6, 12};
	int a7[] = {11, 10, 13, 6, 10, 14, 4, 0, 12, 9, 13, 2, 3, 13, 4, 3, 10};

	assert(maxcon(a1, nelem(a1)) == 5);
	assert(maxcon(a2, nelem(a2)) == 4);
	assert(maxcon(a3, nelem(a3)) == 6);
	assert(maxcon(a4, nelem(a4)) == 3);
	assert(maxcon(a5, nelem(a5)) == 4);
	assert(maxcon(a6, nelem(a6)) == 15);
	assert(maxcon(a7, nelem(a7)) == 6);

	return 0;
}
