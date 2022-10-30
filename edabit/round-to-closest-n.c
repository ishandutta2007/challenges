/*

Creates a function that takes two integers, num and n, and returns an integer which is divisible by n and is the closest to num. If there are two numbers equidistant from num and divisible by n, select the larger one.
Examples

roundNumber(33, 25) ➞ 25

roundNumber(46, 7) ➞ 49

roundNumber(133, 14) ➞ 140

Notes

n will always be a positive number.

*/

#include <assert.h>
#include <math.h>

unsigned
roundnum(unsigned x, unsigned n)
{
	return round(x * 1.0 / n) * n;
}

int
main(void)
{
	assert(roundnum(33, 25) == 25);
	assert(roundnum(46, 7) == 49);
	assert(roundnum(133, 14) == 140);
	assert(roundnum(34, 25) == 25);
	assert(roundnum(54, 8) == 56);
	assert(roundnum(65, 10) == 70);
	assert(roundnum(6247, 163) == 6194);
	assert(roundnum(532, 12) == 528);
	assert(roundnum(642234, 1523) == 642706);
	assert(roundnum(5123, 10) == 5120);
	assert(roundnum(96623443, 7650) == 96627150);
	assert(roundnum(125123, 520) == 125320);
	assert(roundnum(12121212, 144) == 12121200);

	return 0;
}
