/*

Mubashir was walking through a straight street with exactly n identical houses on both sides. House numbers in the street look like this:

1 |   | 6

3 |   | 4

5 |   | 2

He noticed that Even numbered houses increase on the right while Odd numbered houses decrease on the left.

Create a function that takes a house number house and length of the street n and returns the house number on the opposite side.
Examples

oppositeHouse(1, 3) ➞ 6

oppositeHouse(2, 3) ➞ 5

oppositeHouse(3, 5) ➞ 8

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

uvlong
opposite(uvlong h, uvlong n)
{
	uvlong i, r;

	if (n == 0 || h / 2 > n)
		return 0;

	if (h & 1) {
		i = (h - 1) / 2;
		r = 2 * n - 2 * i;
	} else {
		i = n - h / 2;
		r = 2 * i + 1;
	}
	return r;
}

int
main(void)
{
	assert(opposite(1, 3) == 6);
	assert(opposite(3, 3) == 4);
	assert(opposite(2, 3) == 5);
	assert(opposite(3, 5) == 8);
	assert(opposite(7, 11) == 16);
	assert(opposite(10, 22) == 35);
	assert(opposite(20, 3400) == 6781);
	assert(opposite(9, 26) == 44);
	assert(opposite(20, 10) == 1);
	assert(opposite(23633656673ull, 310027696726ull) == 596421736780ull);
	assert(opposite(6, 3) == 1);
	assert(opposite(6, 0) == 0);
	assert(opposite(7, 3) == 0);

	return 0;
}
