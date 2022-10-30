/*

A train has a maximum capacity of $n passengers overall, which means each carriage's capacity will share an equal proportion of the maximum capacity.

Create a function which returns the index of the first carriage which holds 50% or less of its maximum capacity. If no such carriage exists, return -1.
Worked Example

findASeat(200, [35, 23, 18, 10, 40]) ➞ 2

// There are 5 carriages which each have a maximum capacity of 40 (200 / 5 = 40).
// Index 0's carriage is too full (35 is 87.5% of the maximum).
// Index 1's carriage is too full (23 is 57.5% of the maximum).
// Index 2's carriage is good enough (18 is 45% of the maximum).
// Return 2.

Examples

findASeat(20, [3, 5, 4, 2]) ➞ 3

findASeat(1000, [50, 20, 80, 90, 100, 60, 30, 50, 80, 60]) ➞ 0

findASeat(200, [35, 23, 40, 21, 38]) ➞ -1

Notes

    This means if a train can hold 200 passengers, and has 5 carriages, then that means each carriage can hold a maximum of 40 passengers each.
    All carriage numbers will be positive integers, which will be able to divide evenly.
    Remember to return -1 if no carriage is empty enough.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

ssize_t
findseat(unsigned t, unsigned *a, size_t n)
{
	size_t i;
	unsigned c;

	if (n == 0)
		return -1;

	c = t / n;
	for (i = 0; i < n; i++) {
		if (a[i] * 2 <= c)
			return i;
	}
	return -1;
}

int
main(void)
{
	unsigned a1[] = {3, 5, 4, 2};
	unsigned a2[] = {50, 20, 80, 90, 100, 60, 30, 50, 80, 60};
	unsigned a3[] = {35, 23, 40, 21, 38};
	unsigned a4[] = {35, 23, 18, 10, 40};
	unsigned a5[] = {6, 3, 7};
	unsigned a6[] = {1839, 0, 0};

	assert(findseat(20, a1, nelem(a1)) == 3);
	assert(findseat(1000, a2, nelem(a2)) == 0);
	assert(findseat(200, a3, nelem(a3)) == -1);
	assert(findseat(200, a4, nelem(a4)) == 2);
	assert(findseat(21, a5, nelem(a5)) == 1);
	assert(findseat(11037, a6, nelem(a6)) == 0);

	return 0;
}
