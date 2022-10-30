/*

Create a function that takes in two arrays and returns true if the second array follows the first array by one element, and false otherwise.
In other words, determine if the second array is the first array shifted to the right by 1.

Examples

simonSays([1, 2], [5, 1]) ➞ true

simonSays([1, 2], [5, 5]) ➞ false

simonSays([1, 2, 3, 4, 5], [0, 1, 2, 3, 4]) ➞ true

simonSays([1, 2, 3, 4, 5], [5, 5, 1, 2, 3]) ➞ false

Notes

    Both input arrays will be of the same length, and will have a minimum length of 2.
    The values of the 0-indexed element in the first array and the n-1th indexed element in the second array do not matter.

*/

#include <assert.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
simonsays(int *a, int *b, size_t n)
{
	return memcmp(a, b + 1, sizeof(*a) * (n - 1)) == 0;
}

int
main(void)
{
	int a1[] = { 1, 2 };
	int b1[] = { 5, 1 };

	int a2[] = { 1, 2 };
	int b2[] = { 5, 5 };

	int a3[] = { 1, 2, 3, 4, 5 };
	int b3[] = { 0, 1, 2, 3, 4 };

	int a4[] = { 1, 2, 3, 4, 5 };
	int b4[] = { 5, 5, 1, 2, 3 };

	int a5[] = { 1, 2, 3 };
	int b5[] = { 0, 1, 2 };

	assert(simonsays(a1, b1, nelem(a1)) == 1);
	assert(simonsays(a2, b2, nelem(a2)) == 0);
	assert(simonsays(a3, b3, nelem(a3)) == 1);
	assert(simonsays(a4, b4, nelem(a4)) == 0);
	assert(simonsays(a5, b5, nelem(a5)) == 1);

	return 0;
}
