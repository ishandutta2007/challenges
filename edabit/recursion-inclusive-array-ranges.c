/*

Write a function that, given the start startNum and end endNum values, return an array containing all the numbers inclusive to that range. See examples below.
Examples

inclusiveArray(1, 5) ➞ [1, 2, 3, 4, 5]

inclusiveArray(2, 8) ➞ [2, 3, 4, 5, 6, 7, 8]

inclusiveArray(10, 20) ➞ [10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]

inclusiveArray(17, 5) ➞ [17]

IMPORTANT

    The use of IntStream.range and IntStream.rangeClosed is totally unacceptable, hence, recursion is the very purpose of this challenge.

Notes

    The numbers in the array are sorted in ascending order.
    If startNum is greater than endNum, return an array with the higher value. See example #4.
    You are expected to solve this challenge via a recursive approach.
    An iterative version of this challenge can be found via this link
    A collection of challenges in recursion can be found via this link.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
inclusive(int a, int b, int *p)
{
	*p = a;
	if (a < b)
		inclusive(a + 1, b, p + 1);
}

void
test(int a, int b, int *r, size_t n)
{
	int p[128];

	inclusive(a, b, p);
	assert(!memcmp(p, r, sizeof(*r) * n));
}

int
main(void)
{
	int a1[] = {1, 2, 3, 4, 5};
	int a2[] = {2, 3, 4, 5, 6, 7, 8};
	int a3[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	int a4[] = {17};
	int a5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};
	int a6[] = {24};
	int a7[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66};
	int a8[] = {9};
	int a9[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

	test(1, 5, a1, nelem(a1));
	test(2, 8, a2, nelem(a2));
	test(10, 20, a3, nelem(a3));
	test(17, 5, a4, nelem(a4));
	test(1, 41, a5, nelem(a5));
	test(24, 17, a6, nelem(a6));
	test(11, 66, a7, nelem(a7));
	test(9, 3, a8, nelem(a8));
	test(6, 16, a9, nelem(a9));

	return 0;
}
