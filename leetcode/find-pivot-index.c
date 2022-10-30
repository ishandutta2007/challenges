/*

Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

Note:

    The length of nums will be in the range [0, 10000].
    Each element nums[i] will be an integer in the range [-1000, 1000].

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <inttypes.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

ssize_t
pivot(int *a, size_t n)
{
	size_t i;
	int l, r, t;

	l = r = t = 0;
	for (i = 0; i < n; i++)
		t += a[i];

	for (i = 0; i < n; i++) {
		if (l == t - l - a[i])
			return i;
		l += a[i];
	}
	return -1;
}

int
main(void)
{
	int a1[] = {1, 7, 3, 6, 5, 6};
	int a2[] = {1, 2, 3};

	printf("%zd\n", pivot(a1, nelem(a1)));
	printf("%zd\n", pivot(a2, nelem(a2)));

	return 0;
}
