/*

Write a function that takes two arrays (arr1 and arr2) and an int n, and returns true if the second array is equal to the first array shifted by n positions. Otherwise, return false.
Examples

circularShift([1, 2, 3, 4], [3, 4, 1, 2], 2) ➞ true

circularShift([1, 1], [1, 1], 6) ➞ true

circularShift([0, 1, 2, 3, 4, 5], [3, 4, 5, 2, 1, 0], 3) ➞ false

Notes

    The two arrays will be of the same length.
    n can be a negative value.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
circularshift(int *a, int *b, ssize_t n, ssize_t m)
{
	ssize_t i, j;

	for (i = 0; i < n; i++) {
		j = (m + i) % n;
		if (j < 0)
			j += n;
		if (a[i] != b[j])
			return false;
	}
	return true;
}

int
main(void)
{
	int a1[] = { 1, 2, 3, 4 };
	int b1[] = { 3, 4, 1, 2 };

	int a2[] = { 1, 1 };
	int b2[] = { 1, 1 };

	int a3[] = { 0, 1, 2, 3, 4, 5 };
	int b3[] = { 3, 4, 5, 2, 1, 0 };

	int a4[] = { 0, 1, 2, 3 };
	int b4[] = { 1, 2, 3, 1 };

	int a5[] = { 1, 2, 1 };
	int b5[] = { 1, 2, 1 };

	int a6[] = { 5, 7, 2, 3 };
	int b6[] = { 2, 3, 5, 7 };

	assert(circularshift(a1, b1, nelem(a1), 2) == true);
	assert(circularshift(a2, b2, nelem(a2), 6) == true);
	assert(circularshift(a3, b3, nelem(a3), 3) == false);
	assert(circularshift(a4, b4, nelem(a4), 1) == false);
	assert(circularshift(a5, b5, nelem(a5), 3) == true);
	assert(circularshift(a6, b6, nelem(a6), -2) == true);

	return 0;
}
