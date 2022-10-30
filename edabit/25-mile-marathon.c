/*

Mary wants to run a 25-mile marathon. When she attempts to sign up for the marathon, she notices the sign-up sheet doesn't directly state the marathon's length. Instead, the marathon's length is listed in small, different portions. Help Mary find out how long the marathon actually is.

Return true if the marathon is 25 miles long, otherwise, return false.
Examples

marathonDistance([1, 2, 3, 4]) ➞ false

marathonDistance([1, 9, 5, 8, 2]) ➞ true

marathonDistance([-6, 15, 4]) ➞ true

Notes

    Items in the array will always be integers.
    Items in the array may be negative or positive, but since negative distance isn't possible, find a way to convert negative integers into positive integers.
    Return false if the arguments are empty or not provided.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
marathondist(int *a, size_t n)
{
	size_t i;
	int d;

	d = 0;
	for (i = 0; i < n; i++)
		d += abs(a[i]);
	return d == 25;
}

int
main(void)
{
	int a1[] = { 1, 2, 3, 4 };
	int a2[] = { -6, 15, 4 };
	int a3[] = { 1, 9, 5, 8, 2 };
	int a4[] = { 9, 7, 6, 5 };
	int a5[] = { 4, 6, 8, 9, -4 };
	int a6[] = { -20, 9, -10, -11 };
	int a7[] = { -9, 15, 1 };

	assert(marathondist(a1, nelem(a1)) == false);
	assert(marathondist(a2, nelem(a2)) == true);
	assert(marathondist(a3, nelem(a3)) == true);
	assert(marathondist(a4, nelem(a4)) == false);
	assert(marathondist(a5, nelem(a5)) == false);
	assert(marathondist(a6, nelem(a6)) == false);
	assert(marathondist(a7, nelem(a7)) == true);
	assert(marathondist(a7, 0) == false);

	return 0;
}
