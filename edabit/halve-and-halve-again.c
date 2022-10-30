/*

Given two integers a and b, return how many times a can be halved while still being greater than b.
Examples

halveCount(1324, 98) ➞ 3
// (1324 -> 662 -> 331 -> 165.5)

halveCount(624, 8) ➞ 6
// (624 -> 312 -> 156 -> 78 -> 39 -> 19.5 -> 9.75)

halveCount(1000, 3) ➞ 8
// (1000 -> 500 -> 250 -> 125 -> 62.5 -> 31.25 -> 15.625 -> 7.8125 -> 3.90625)

Notes

Integer a can be halved at least once.

*/

#include <assert.h>

unsigned
halvecount(unsigned a, unsigned b)
{
	double x, y;
	unsigned c;

	x = a;
	y = b;
	for (c = 0; x / 2 > y; c++)
		x /= 2;

	return c;
}

int
main(void)
{
	assert(halvecount(4123, 1) == 12);
	assert(halvecount(1891, 4) == 8);
	assert(halvecount(1756, 14) == 6);
	assert(halvecount(7764, 2) == 11);
	assert(halvecount(1118, 47) == 4);
	assert(halvecount(161, 79) == 1);
	assert(halvecount(8573, 35) == 7);
	assert(halvecount(4123, 1) == 12);
	assert(halvecount(1348, 60) == 4);
	assert(halvecount(7549, 31) == 7);
	assert(halvecount(4469, 5) == 9);
	assert(halvecount(1123, 98) == 3);
	assert(halvecount(8197, 85) == 6);
	assert(halvecount(1199, 56) == 4);
	assert(halvecount(8845, 4) == 11);
	assert(halvecount(606, 67) == 3);
	assert(halvecount(3375, 6) == 9);
	assert(halvecount(7085, 10) == 9);
	assert(halvecount(299, 5) == 5);
	assert(halvecount(1208, 82) == 3);
	assert(halvecount(3635, 73) == 5);
	assert(halvecount(2382, 3) == 9);
	assert(halvecount(320, 80) == 1);

	return 0;
}
