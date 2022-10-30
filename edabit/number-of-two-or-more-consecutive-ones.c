/*

Create a function that counts the number of blocks of two or more adjacent 1s in an array.
Examples

countOnes([1, 0, 0, 1, 1, 0, 1, 1, 1]) ➞ 2
// Two instances: [1, 1] (middle) and [1, 1, 1] (end)

countOnes([1, 0, 1, 0, 1, 0, 1, 0]) ➞ 0

countOnes([1, 1, 1, 1, 0, 0, 0, 0]) ➞ 1

countOnes([0, 0, 0]) ➞ 0

Notes

    A single 1 by itself (surrounded by a zero on its left and right), does not count towards the total (see first example).
    Each input will contain only zeroes and ones.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
ones(int *a, size_t n)
{
	size_t i, j, c;

	c = 0;
	for (i = j = 0; i < n; i++) {
		if (a[i] != 1) {
			c += (j > 1);
			j = 0;
		} else
			j++;
	}
	c += (j > 1);

	return c;
}

int
main(void)
{
	int a1[] = { 1, 1, 1, 1, 1 };
	int a2[] = { 1, 1, 1, 1, 0 };
	int a3[] = { 0, 0, 0, 0, 0 };
	int a4[] = { 1, 0, 0, 0, 0 };
	int a5[] = { 1, 0, 1, 0, 1 };
	int a6[] = { 1, 0, 0, 0, 1, 0, 0, 1, 1, 0 };
	int a7[] = { 1, 1, 0, 1, 1, 0, 0, 1, 1 };
	int a8[] = { 1, 0, 0, 1, 1, 0, 0, 1, 1 };
	int a9[] = { 1, 0, 1, 1, 1, 0, 1, 1, 1 };
	int a10[] = { 1, 0, 1, 0, 1, 0, 1, 0 };
	int a11[] = { 1, 1, 1, 1, 0, 0, 0, 0 };
	int a12[] = { 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1 };

	assert(ones(a1, nelem(a1)) == 1);
	assert(ones(a2, nelem(a2)) == 1);
	assert(ones(a3, nelem(a3)) == 0);
	assert(ones(a4, nelem(a4)) == 0);
	assert(ones(a5, nelem(a5)) == 0);
	assert(ones(a6, nelem(a6)) == 1);
	assert(ones(a7, nelem(a7)) == 3);
	assert(ones(a8, nelem(a8)) == 2);
	assert(ones(a9, nelem(a9)) == 2);
	assert(ones(a10, nelem(a10)) == 0);
	assert(ones(a11, nelem(a11)) == 1);
	assert(ones(a12, nelem(a12)) == 3);

	return 0;
}
