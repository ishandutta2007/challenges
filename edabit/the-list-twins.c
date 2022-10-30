/*

Create a function that given a list, it returns the index where if split in two-subarrays
(last element of the first array has index of (foundIndex-1)), the sum of them are equal.

Examples

twins([10, 20, 30, 5, 40, 50, 40, 15]) ➞ 5
# foundIndex 5 : [10+20+30+5+40]=[50+40+15]

twins([1, 2, 3, 4, 5, 5]) ➞ 4
# [1, 2, 3, 4] [5, 5]

twins([3, 3]) ➞ 1

Notes

Return only the foundIndex, not the divided list.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
twins(unsigned *a, size_t n)
{
	unsigned u, v;
	size_t i;

	v = 0;
	for (i = 0; i < n; i++)
		v += a[i];

	u = 0;
	for (i = 0; i < n; i++) {
		u += a[i];
		if (u == v / 2)
			return i + 1;
		if (u > v / 2)
			break;
	}
	return n;
}

int
main(void)
{
	unsigned a1[] = {1, 2, 3, 4, 5, 5};
	unsigned a2[] = {3, 3};
	unsigned a3[] = {10, 20, 30, 5, 40, 50, 40, 15};
	unsigned a4[] = {3, 4, 6, 7, 6};

	assert(twins(a1, nelem(a1)) == 4);
	assert(twins(a2, nelem(a2)) == 1);
	assert(twins(a3, nelem(a3)) == 5);
	assert(twins(a4, nelem(a4)) == 3);

	return 0;
}
