/*

Create a function that performs an even-odd transform to an array, n times. Each even-odd transformation:

    Adds two (+2) to each odd integer.
    Subtracts two (-2) to each even integer.

Examples

evenOddTransform([3, 4, 9], 3) ➞ [9, -2, 15]
// Since [3, 4, 9] => [5, 2, 11] => [7, 0, 13] => [9, -2, 15]

evenOddTransform([0, 0, 0], 10) ➞ [-20, -20, -20]

evenOddTransform([1, 2, 3], 1) ➞ [3, 0, 5]

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
evenodd(int *a, size_t n, unsigned m)
{
	size_t i;

	for (i = 0; i < n; i++)
		a[i] += (a[i] & 1) ? 2 * m : -2 * m;
}

void
test(int *a, int *b, size_t n, unsigned m)
{
	evenodd(a, n, m);
	assert(memcmp(a, b, n * sizeof(*a)) == 0);
}

int
main(void)
{
	int a1[] = { 3, 4, 9 };
	int a2[] = { 0, 0, 0 };
	int a3[] = { 1, 2, 3 };
	int a4[] = { 55, 90, 830 };

	int b1[] = { 9, -2, 15 };
	int b2[] = { -20, -20, -20 };
	int b3[] = { 3, 0, 5 };
	int b4[] = { 59, 86, 826 };

	test(a1, b1, nelem(a1), 3);
	test(a2, b2, nelem(a2), 10);
	test(a3, b3, nelem(a3), 1);
	test(a4, b4, nelem(a4), 2);

	return 0;
}
