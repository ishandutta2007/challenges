/*

Given an array of numbers, representing the height of a mountain in certain intervals, return whether this mountain is scalable.

A mountain can be considered scalable if each number is within 5 units of the next number in either direction.

Examples

isScalable([1, 2, 4, 6, 7, 8]) ➞ true

isScalable([40, 45, 50, 45, 47, 52]) ➞ true

isScalable([2, 9, 11, 10, 18, 21]) ➞ false

Notes

The array may start at any number and can be any length.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
scalable(int *a, size_t n)
{
	size_t i;

	for (i = 1; i < n; i++) {
		if (abs(a[i] - a[i - 1]) > 5)
			return false;
	}
	return true;
}

int
main(void)
{
	int a1[] = {1, 2, 4, 6, 7, 8};
	int a2[] = {40, 45, 50, 48, 47, 52};
	int a3[] = {2, 9, 11, 10, 18, 21};
	int a4[] = {200, 200, 200, 200};
	int a5[] = {30, 29, 24, 19, 16, 11};
	int a6[] = {22, 22, 22, 29, 29, 29, 29};

	assert(scalable(a1, nelem(a1)) == true);
	assert(scalable(a2, nelem(a2)) == true);
	assert(scalable(a3, nelem(a3)) == false);
	assert(scalable(a4, nelem(a4)) == true);
	assert(scalable(a5, nelem(a5)) == true);
	assert(scalable(a6, nelem(a6)) == false);

	return 0;
}
