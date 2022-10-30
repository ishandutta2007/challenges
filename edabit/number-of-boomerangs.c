/*

A boomerang is a V-shaped sequence that is either upright or upside down.
Specifically, a boomerang can be defined as: sub-array of length 3, with the first and last digits being the same and the middle digit being different.

Some boomerang examples:

[3, 7, 3], [1, -1, 1], [5, 6, 5]

Create a function that returns the total number of boomerangs in an array.

To illustrate:

[3, 7, 3, 2, 1, 5, 1, 2, 2, -2, 2]
// 3 boomerangs in this sequence:  [3, 7, 3], [1, 5, 1], [2, -2, 2]

Be aware that boomerangs can overlap, like so:

[1, 7, 1, 7, 1, 7, 1]
// 5 boomerangs (from left to right): [1, 7, 1], [7, 1, 7], [1, 7, 1], [7, 1, 7], and [1, 7, 1]

Examples

countBoomerangs([9, 5, 9, 5, 1, 1, 1]) ➞ 2

countBoomerangs([5, 6, 6, 7, 6, 3, 9]) ➞ 1

countBoomerangs([4, 4, 4, 9, 9, 9, 9]) ➞ 0

Notes

[5, 5, 5] (triple identical digits) is NOT considered a boomerang because the middle digit is identical to the first and last.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
boomerangs(int *a, size_t n)
{
	size_t i, c;

	if (n == 0)
		return 0;

	c = 0;
	for (i = 1; i < n - 1; i++) {
		if (a[i - 1] == a[i + 1] && a[i - 1] != a[i])
			c++;
	}
	return c;
}

int
main(void)
{
	int a1[] = {9, 5, 9, 5, 1, 1, 1};
	int a2[] = {5, 6, 6, 7, 6, 3, 9};
	int a3[] = {4, 4, 4, 9, 9, 9, 9};
	int a4[] = {5, 9, 5, 9, 5};
	int a5[] = {4, 4, 4, 8, 4, 8, 4};
	int a6[] = {2, 2, 2, 2, 2, 2, 3};
	int a7[] = {2, 2, 2, 2, 3, 2, 3};
	int a8[] = {1, 2, 1, 1, 1, 2, 1};
	int a9[] = {5, 1, 1, 1, 1, 4, 1};
	int a10[] = {3, 7, 3, 2, 1, 5, 1, 2, 2, -2, 2};
	int a11[] = {1, 7, 1, 7, 1, 7, 1};
	int a12[] = {5, 5, 5};

	assert(boomerangs(a1, nelem(a1)) == 2);
	assert(boomerangs(a2, nelem(a2)) == 1);
	assert(boomerangs(a3, nelem(a3)) == 0);
	assert(boomerangs(a4, nelem(a4)) == 3);
	assert(boomerangs(a5, nelem(a5)) == 3);
	assert(boomerangs(a6, nelem(a6)) == 0);
	assert(boomerangs(a7, nelem(a7)) == 2);
	assert(boomerangs(a8, nelem(a8)) == 2);
	assert(boomerangs(a9, nelem(a9)) == 1);
	assert(boomerangs(a10, nelem(a10)) == 3);
	assert(boomerangs(a11, nelem(a11)) == 5);
	assert(boomerangs(a12, nelem(a12)) == 0);
	assert(boomerangs(NULL, 0) == 0);

	return 0;
}
