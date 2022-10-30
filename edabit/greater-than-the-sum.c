/*

For each number in an array, check if that number is greater than the sum of all numbers that appear before it in the array.
If all numbers in the array pass this test, return true. Return false otherwise.

Notes

The first number in any array will always pass the test.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
gts(int *a, size_t n)
{
	size_t i;
	int s;

	if (n < 2)
		return 1;

	s = a[0];
	for (i = 1; i < n; i++) {
		if (!(a[i] > s))
			return 0;
		s += a[i];
	}
	return 1;
}

int
main(void)
{
	int a1[] = { 2, 3, 7, 13, 28 };
	int a2[] = { 1, 2, 4, 6, 13 };
	int a3[] = { 1, -2, 11, 26 };
	int a4[] = { 5, 8, 18, 32, 67, 131, 265, 529, 1056, 2115 };
	int a5[] = { 8, 29, 62, 115, 232 };
	int a6[] = { 5, 7, 15, 52, 88, 173, 346, 686, 1393, 2765 };
	int a7[] = { 1, 25, 35, 74, 159, 305, 623 };
	int a8[] = { 21, 40, 58, 134, 250 };
	int a9[] = { 9, 32, 60, 107, 223, 442, 894, 1782, 3564 };
	int a10[] = { 4, 26, 51, 103, 204, 412, 821, 1638, 3257 };
	int a11[] = { 16, 35, 51, 120 };
	int a12[] = { -4, 1, 2, 14, 9, 44, 67, 131, 286 };
	int a13[] = { 1, 4, 6, 14, 26, 56, 112 };
	int a14[] = { 1, 18, 25, 42, 82, 188 };
	int a15[] = { 13, 23, 36, 97, 186, 369, 728 };
	int a16[] = { 8, 30, 44, 97 };
	int a17[] = { 8, 31, 39, 102, 176, 363, 732, 1455, 2917, 5840 };
	int a18[] = { 9, 10, 20, 43 };
	int a19[] = { 25, 34, 68, 128, 262 };
	int a20[] = { 18, 34, 77, 129, 270, 544, 1075, -2148 };
	int a21[] = { 14, 34, 70, 123, 263, 506 };
	int a22[] = { 24, 29, 58, 115, 236, 468, 950, 1905, 3787, 7575 };

	assert(gts(a1, nelem(a1)) == 1);
	assert(gts(a2, nelem(a2)) == 0);
	assert(gts(a3, nelem(a3)) == 0);
	assert(gts(a4, nelem(a4)) == 1);
	assert(gts(a5, nelem(a5)) == 1);
	assert(gts(a6, nelem(a6)) == 0);
	assert(gts(a7, nelem(a7)) == 1);
	assert(gts(a8, nelem(a8)) == 0);
	assert(gts(a9, nelem(a9)) == 1);
	assert(gts(a10, nelem(a10)) == 0);
	assert(gts(a11, nelem(a11)) == 0);
	assert(gts(a12, nelem(a12)) == 0);
	assert(gts(a13, nelem(a13)) == 1);
	assert(gts(a14, nelem(a14)) == 0);
	assert(gts(a15, nelem(a15)) == 0);
	assert(gts(a16, nelem(a16)) == 1);
	assert(gts(a17, nelem(a17)) == 0);
	assert(gts(a18, nelem(a18)) == 1);
	assert(gts(a19, nelem(a19)) == 1);
	assert(gts(a20, nelem(a20)) == 0);
	assert(gts(a21, nelem(a21)) == 1);
	assert(gts(a22, nelem(a22)) == 1);

	return 0;
}
