/*

Create a function that takes an array of numbers and returns the sum of the two lowest positive numbers.
Examples

sumTwoSmallestNums([19, 5, 42, 2, 77]) ➞ 7

sumTwoSmallestNums([10, 343445353, 3453445, 3453545353453]) ➞ 3453455

sumTwoSmallestNums([2, 9, 6, -1]) ➞ 8

sumTwoSmallestNums([879, 953, 694, -847, 342, 221, -91, -723, 791, -587]) ➞ 563

sumTwoSmallestNums([3683, 2902, 3951, -475, 1617, -2385]) ➞ 4519

Notes

    Don't count negative numbers.
    Floats and empty arrays will not be used in any of the test cases.

*/

#include <assert.h>
#include <stdio.h>
#include <inttypes.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

intmax_t
sumtsn(intmax_t *a, size_t n)
{
	intmax_t x, y;
	size_t i;

	x = y = INTMAX_MIN;
	for (i = 0; i < n; i++) {
		if (a[i] < 0)
			continue;

		if (a[i] < x || x < 0) {
			y = x;
			x = a[i];
		} else if (a[i] < y || y < 0)
			y = a[i];
	}

	if (x < 0 || y < 0)
		return -1;
	return x + y;
}

int
main(void)
{
	intmax_t a1[] = { 19, 5, 42, 2, 77 };
	intmax_t a2[] = { 10, INTMAX_C(343445353), INTMAX_C(3453445), INTMAX_C(3453545353453) };
	intmax_t a3[] = { 2, 9, 6, -1 };
	intmax_t a4[] = { 879, 953, 694, -847, 342, 221, -91, -723, 791, -587 };
	intmax_t a5[] = { 3683, 2902, 3951, -475, 1617, -2385 };
	intmax_t a6[] = { 280, 134, 108 };
	intmax_t a7[] = { 280, 134, 108, 1 };
	intmax_t a8[] = { 321, 406, -176 };
	intmax_t a9[] = { 1, 1, 1, 1 };
	intmax_t a10[] = { -1, -1, 1, 1 };

	assert(sumtsn(a1, nelem(a1)) == INTMAX_C(7));
	assert(sumtsn(a2, nelem(a2)) == INTMAX_C(3453455));
	assert(sumtsn(a3, nelem(a3)) == INTMAX_C(8));
	assert(sumtsn(a4, nelem(a4)) == INTMAX_C(563));
	assert(sumtsn(a5, nelem(a5)) == INTMAX_C(4519));
	assert(sumtsn(a6, nelem(a6)) == INTMAX_C(242));
	assert(sumtsn(a7, nelem(a7)) == INTMAX_C(109));
	assert(sumtsn(a8, nelem(a8)) == INTMAX_C(727));
	assert(sumtsn(a9, nelem(a9)) == INTMAX_C(2));
	assert(sumtsn(a10, nelem(a10)) == INTMAX_C(2));

	return 0;
}
