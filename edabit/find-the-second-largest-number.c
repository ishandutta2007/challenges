/*

Create a function that takes an array of numbers and returns the second largest number.
Examples

secondLargest([10, 40, 30, 20, 50]) ➞ 40

secondLargest([25, 143, 89, 13, 105]) ➞ 105

secondLargest([54, 23, 11, 17, 10]) ➞ 23

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
secondlargest(int *a, size_t n)
{
	size_t i;
	int x, y;

	x = y = INT_MIN;
	for (i = 0; i < n; i++) {
		if (y < a[i]) {
			x = y;
			y = a[i];
		} else if (x < a[i])
			x = a[i];
	}
	return x;
}

int
main(void)
{
	int a1[] = { 10, 40, 30, 20, 50 };
	int a2[] = { 25, 143, 89, 13, 105 };
	int a3[] = { 54, 23, 11, 17, 10 };
	int a4[] = { 513, 211, 131, 417, 11 };
	int a5[] = { 63, 44, 11, 22, 33, 66, 65 };

	assert(secondlargest(a1, nelem(a1)) == 40);
	assert(secondlargest(a2, nelem(a2)) == 105);
	assert(secondlargest(a3, nelem(a3)) == 23);
	assert(secondlargest(a4, nelem(a4)) == 417);
	assert(secondlargest(a5, nelem(a5)) == 65);

	return 0;
}
