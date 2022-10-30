/*

Watson likes to challenge Sherlock's math ability. He will provide a starting and ending value describing a range of integers.
Sherlock must determine the number of square integers within that range, inclusive of the endpoints
(note that a square integer is an integer which is the square of an integer, e.g. 1, 4, 9, 16, 25, 36, 49).

For example, the range is a=24 and b=49, inclusive. There are three square integers in the range: 25, 36 and 49.

Complete the squares function that returns an integer representing the number of square integers in the inclusive range from a to b.
Examples

squares(3, 9) ➞ 2

squares(17, 24) ➞ 0

squares(1, 10000000) ➞ 31622

Notes

Your solution must solve each problem in 1 second or less.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

unsigned long
squares(unsigned long a, unsigned long b)
{
	unsigned long x, y;
	double i, u;

	x = u = sqrt(a);
	y = sqrt(b);
	return y - x + (modf(u, &i) == 0);
}

int
main(void)
{
	assert(squares(35ul, 70ul) == 3ul);
	assert(squares(100ul, 1000ul) == 22ul);
	assert(squares(3ul, 9ul) == 2ul);
	assert(squares(17ul, 24ul) == 0ul);
	assert(squares(433ul, 100000ul) == 296ul);
	assert(squares(1ul, 1000000000ul) == 31622ul);
	assert(squares(89784519ul, 103811134ul) == 713ul);
	assert(squares(50979851ul, 733216221ul) == 19937ul);

	return 0;
}
