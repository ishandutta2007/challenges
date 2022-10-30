/*

Mubashir needs your help in a simple task.

Given a array of integers arr and an integer k, find the lowest positive integer x so that exactly k elements of the given array are less than or equal to x.
Return null if the condition does not match.

See below examples for a better understanding:

Examples

lessEqual([3, 7, 6, 1, 10, 3, 20], 4) ➞ 6
// 1, 3, 3, 6 = 4 elements
// All elements are less than or equal to 6

lessEqual([3, 7, 6, 1, 10, 3, 20], 2) ➞ null
// 1, 3 = 2 elements
// Not possible to return 3 because we have another 3 in the array

lessEqual([3, 7, 5, 1, 10, 3, 20], 4) ➞ 5
// 1, 3, 3, 5 = 4 elements
// All elements are less than or equal to 5

lessEqual([10, 15, 20, 25], 0) ➞ 1
// k = 0

Notes

    All numbers of the given array and k will be ≥ 0.
    Understanding the description of this challenge is the hardest part.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

int
cmp(const void *a, const void *b)
{
	vlong x, y;

	x = *(vlong *)a;
	y = *(vlong *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

ssize_t
leq(vlong *a, ssize_t n, ssize_t k)
{
	if (n <= 0)
		return -1;

	qsort(a, n, sizeof(*a), cmp);

	if (k >= n)
		return a[n - 1];
	if (k == 0)
		return (a[0] == 1) ? -1 : 1;
	return (a[k] == a[k - 1]) ? -1 : a[k - 1];
}

int
main(void)
{
	vlong a1[] = {3, 7, 6, 1, 10, 3, 20};
	vlong a2[] = {3, 7, 6, 1, 10, 3, 20};
	vlong a3[] = {1, 1, 2, 3, 4};
	vlong a4[] = {1, 1, 2, 3, 4};
	vlong a5[] = {1, 1, 2, 3, 4};
	vlong a6[] = {10, 15, 20, 25};
	vlong a7[] = {2, 2, 2, 3, 5, 7, 8};
	vlong a8[] = {3, 7, 5, 1, 10, 3, 20};
	vlong a9[] = {3, 7, 5, 1, 10, 3, 20};
	vlong a10[] = {1};
	vlong a11[] = {2};
	vlong a12[] = {1000000000ll};
	vlong a13[] = {1000000000ll, 1000000000ll, 1000000000ll, 1000000000ll};
	vlong a14[] = {1, 3, 3, 4, 5};
	vlong a15[] = {1000000000ll};
	vlong a16[] = {100000000ll, 100000000ll};
	vlong a17[] = {3, 4, 5, 6, 7};

	assert(leq(a1, nelem(a1), 4) == 6);
	assert(leq(a2, nelem(a2), 2) == -1);
	assert(leq(a3, nelem(a3), 3) == 2);
	assert(leq(a4, nelem(a4), 2) == 1);
	assert(leq(a5, nelem(a5), 1) == -1);
	assert(leq(a6, nelem(a6), 0) == 1);
	assert(leq(a7, nelem(a7), 2) == -1);
	assert(leq(a8, nelem(a8), 2) == -1);
	assert(leq(a9, nelem(a9), 4) == 5);
	assert(leq(a10, nelem(a10), 0) == -1);
	assert(leq(a11, nelem(a11), 0) == 1);
	assert(leq(a12, nelem(a12), 1) == 1000000000ll);
	assert(leq(a13, nelem(a13), 4) == 1000000000ll);
	assert(leq(a14, nelem(a14), 3) == 3);
	assert(leq(a15, nelem(a15), 1) == 1000000000ll);
	assert(leq(a16, nelem(a16), 2) == 100000000ll);
	assert(leq(a17, nelem(a17), 0) == 1);

	return 0;
}
