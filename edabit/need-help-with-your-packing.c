/*

You arrive at the supermarket checkout and you've only got a limited number of shopping bags with you.
Miser that you are, you hate buying extra bags when you've got dozens at home that you forgot to bring with you!!
Can you fit all your shopping into the bags you've got with you?

Each bag can carry a maximum of 10kg and each item you've purchased weighs between 1 and 10kg.

Create a function that takes two parameters, a list of the weights of each item and the number of bags you are carrying.
Return True if there are enough bags to contain all the items, otherwise False.

Example

CanFit(new int[] { 2, 1, 2, 5, 4, 3, 6, 1, 1, 9, 3, 2 }, 4) ➞ True
// Bag 1 = [2, 1, 2, 5] (10kg)
// Bag 2 = [4, 3, 3] (10kg)
// Bag 3 = [6, 2, 1, 1] (10kg)
// Bag 4 = [9] (9kg)

CanFit(new int[] { 2, 7, 1, 3, 3, 4, 7, 4, 1, 8, 2 ], 4) ➞ False
// Bag 1 = [2, 8] (10kg)
// Bag 2 = [3, 7] (10kg)
// Bag 3 = [2, 4, 4] (10kg)
// Bag 4 = [7, 3] (10kg)
// two 1kg items left over!

Notes

    All weights will be integers between 1 and 10kg inclusive
    Items can be packed in any order
    There may be more than one way to fit all the items in the available bags

Based on an easier challenge How Many Boxes? by @zatoichi49.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	unsigned x, y;

	x = *(unsigned *)a;
	y = *(unsigned *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

bool
fit(unsigned *a, size_t n, unsigned b)
{
	size_t i, j, k;
	unsigned v;

	if (n == 0)
		return true;

	qsort(a, n, sizeof(*a), cmp);
	j = 0;
	k = n;
	for (i = 0; i < b; i++) {
		v = 10;
		while (k > 0 && v >= a[k - 1])
			v -= a[--k];
		while (j < k && a[j] <= v)
			v -= a[j++];

		if (j >= k)
			return true;
	}
	return false;
}

int
main(void)
{
	unsigned a1[] = {2, 1, 2, 5, 4, 3, 6, 1, 1, 9, 3, 2};
	unsigned a2[] = {7, 1, 2, 6, 1, 2, 3, 5, 9, 2, 1, 2, 5};
	unsigned a3[] = {2, 7, 1, 3, 3, 4, 7, 4, 1, 8, 2};
	unsigned a4[] = {1, 3, 3, 3, 2, 1, 1, 9, 7, 10, 8, 6, 1, 2, 9};
	unsigned a5[] = {4, 1, 2, 3, 5, 5, 1, 9};
	unsigned a6[] = {3, 1, 2, 7, 2, 6, 1};
	unsigned a7[] = {4, 4, 4, 4, 4};
	unsigned a8[] = {5, 4, 3, 2, 2, 2, 2};
	unsigned a9[] = {4, 6, 1, 9, 6, 1, 1, 9, 2, 9};
	unsigned a10[] = {2, 2, 10, 10, 1, 5, 2};
	unsigned a11[] = {9, 6, 2, 3, 1, 2, 4, 8, 3, 1, 3};
	unsigned a12[] = {2, 5, 1, 6, 2, 9, 5, 2, 1, 6, 1, 6, 6, 1};
	unsigned a13[] = {2, 5, 1, 6, 2, 9, 5, 2, 1, 6, 1, 6, 6, 1};
	unsigned a14[] = {1, 2, 3, 2, 6, 4, 1};
	unsigned a15[] = {1, 1, 2, 1, 2, 10, 2, 2, 5, 1, 5};
	unsigned a16[] = {8, 3, 2, 1, 1, 2, 1, 3, 2, 1};
	unsigned a17[] = {10};

	assert(fit(a1, nelem(a1), 4) == true);
	assert(fit(a2, nelem(a2), 5) == true);
	assert(fit(a3, nelem(a3), 4) == false);
	assert(fit(a4, nelem(a4), 8) == true);
	assert(fit(a5, nelem(a5), 3) == true);
	assert(fit(a6, nelem(a6), 3) == true);
	assert(fit(a7, nelem(a7), 2) == false);
	assert(fit(a8, nelem(a8), 2) == false);
	assert(fit(a9, nelem(a9), 5) == true);
	assert(fit(a10, nelem(a10), 4) == true);
	assert(fit(a11, nelem(a11), 4) == false);
	assert(fit(a12, nelem(a12), 5) == false);
	assert(fit(a13, nelem(a13), 6) == true);
	assert(fit(a14, nelem(a14), 2) == true);
	assert(fit(a15, nelem(a15), 4) == true);
	assert(fit(a16, nelem(a16), 3) == true);
	assert(fit(a17, nelem(a17), 1) == true);
	assert(fit(NULL, 0, 0) == true);

	return 0;
}
