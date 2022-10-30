/*

Write a function that finds the largest even number in a list. Return -1 if not found.
The use of built-in function max() and sorted() are prohibited.
Examples

largest_even([3, 7, 2, 1, 7, 9, 10, 13]) ➞ 10

largest_even([1, 3, 5, 7]) ➞ -1

largest_even([0, 19, 18973623]) ➞ 0

Notes

Consider using the modulo operator % or the bitwise and operator &.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
largesteven(int *a, size_t n)
{
	size_t i;
	int r;

	r = -1;
	for (i = 0; i < n; i++) {
		if ((a[i] & 1) == 0 && r < a[i])
			r = a[i];
	}
	return r;
}

int
main(void)
{
	int a1[] = { 3, 7, 2, 1, 7, 9, 10, 13 };
	int a2[] = { 1 };
	int a3[] = { 22 };
	int a4[] = { 13, 5, 7, 9 };
	int a5[] = { 3, 19, 18973623, 2 };
	int a6[] = { 1, 3, 5, 7 };
	int a7[] = { 0, 19, 18973623 };

	assert(largesteven(a1, nelem(a1)) == 10);
	assert(largesteven(a2, nelem(a2)) == -1);
	assert(largesteven(a3, nelem(a3)) == 22);
	assert(largesteven(a4, nelem(a4)) == -1);
	assert(largesteven(a5, nelem(a5)) == 2);
	assert(largesteven(a6, nelem(a6)) == -1);
	assert(largesteven(a7, nelem(a7)) == 0);

	return 0;
}
