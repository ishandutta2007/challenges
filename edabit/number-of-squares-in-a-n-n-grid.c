/*

Create a function that calculates the number of different squares in an n * n square grid. Check the Resources tab.
Examples

numberSquares(2) ➞ 5

numberSquares(4) ➞ 30

numberSquares(5) ➞ 55

Notes

    Input is a positive integer.
    Square pyramidal number.

*/

#include <assert.h>
#include <stdio.h>

unsigned
nsq(unsigned n)
{
	return n * (n + 1) * (2 * n + 1) / 6;
}

int
main(void)
{
	assert(nsq(2) == 5);
	assert(nsq(4) == 30);
	assert(nsq(5) == 55);
	assert(nsq(9) == 285);
	assert(nsq(10) == 385);
	assert(nsq(11) == 506);
	assert(nsq(15) == 1240);

	return 0;
}
