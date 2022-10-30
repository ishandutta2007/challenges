/*

Write a function that returns the number of times you must carry a digit when you sum together two integers.

Examples

carryDigits(36, 135) ➞ 1
// You carry the 1 when you sum 6 and 5 together.

carryDigits(671, 329) ➞ 3

carryDigits(1111, 3333) ➞ 0

carryDigits(53214, 56905) ➞ 3

Notes

Count all carry operations (even those on leading digits).

*/

#include <assert.h>

unsigned long
carries(unsigned long x, unsigned long y)
{
	unsigned long c, v, r;

	r = c = 0;
	while (x && y) {
		v = (x % 10) + (y % 10) + c;
		c = (v >= 10);
		r += c;
		x /= 10;
		y /= 10;
	}
	return r;
}

int
main(void)
{
	assert(carries(36, 135) == 1);
	assert(carries(671, 329) == 3);
	assert(carries(1111, 3333) == 0);
	assert(carries(4, 5268) == 1);
	assert(carries(53214ul, 16905ul) == 2);
	assert(carries(53214ul, 56905ul) == 3);
	assert(carries(515, 4) == 0);
	assert(carries(515, 90) == 1);
	assert(carries(63223ul, 70000ul) == 1);

	return 0;
}
