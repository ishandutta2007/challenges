/*

Given a list of integers lst, return the sum of all the integers that have an even index, multiplied by the integer at the last index.

If the sequence is empty, you should return 0.

Examples

even_last([2, 3, 4, 5]) ➞ 30
# numbers at even index = 2, 4
# number at last index = 5
# 2*5 + 4*5 = 10 + 20 = 30

even_last([1, 3, 3, 1, 10]) ➞ 140

even_last([]) ➞ 0

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
evenlast(int *a, size_t n)
{
	size_t i;
	int r;

	if (n == 0)
		return 0;

	r = a[0];
	for (i = 2; i < n; i += 2)
		r += a[i];
	r *= a[n - 1];
	return r;
}

int
main(void)
{
	int a1[] = {2, 3, 4, 5};
	int a2[] = {2, 2, 2, 2};
	int a3[] = {1, 3, 3, 1, 10};
	int a4[] = {-11, 3, 3, 1, 10};

	assert(evenlast(a1, nelem(a1)) == 30);
	assert(evenlast(NULL, 0) == 0);
	assert(evenlast(a2, nelem(a2)) == 8);
	assert(evenlast(a3, nelem(a3)) == 140);
	assert(evenlast(a4, nelem(a4)) == 20);

	return 0;
}
