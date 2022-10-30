/*

A number sequence is as follows:

5, 100, 6, 200, 7, 400, 8, 800, 9, 1600, 10, 3200, ...

Given that 5 is at position 1, create a function that returns the number found at position num in the sequence.
Examples

littleBig(4) ➞ 200

littleBig(5) ➞ 7

littleBig(28) ➞ 819200

Notes

You can expect to be only given valid inputs.

*/

#include <assert.h>
#include <stdio.h>

unsigned long
littlebig(unsigned long n)
{
	if (n == 0)
		return 0;
	if (n & 1)
		return 5 + (n >> 1);
	return 100 * (1ul << ((n >> 1) - 1));
}

int
main(void)
{
	assert(littlebig(1) == 5);
	assert(littlebig(2) == 100);
	assert(littlebig(3) == 6);
	assert(littlebig(4) == 200);
	assert(littlebig(5) == 7);
	assert(littlebig(6) == 400);
	assert(littlebig(7) == 8);
	assert(littlebig(8) == 800);
	assert(littlebig(9) == 9);
	assert(littlebig(10) == 1600);
	assert(littlebig(11) == 10);
	assert(littlebig(12) == 3200);
	assert(littlebig(13) == 11);
	assert(littlebig(14) == 6400);
	assert(littlebig(15) == 12);
	assert(littlebig(16) == 12800);
	assert(littlebig(17) == 13);
	assert(littlebig(18) == 25600ul);
	assert(littlebig(19) == 14);
	assert(littlebig(20) == 51200ul);
	assert(littlebig(21) == 15);
	assert(littlebig(22) == 102400ul);
	assert(littlebig(23) == 16);
	assert(littlebig(24) == 204800ul);
	assert(littlebig(25) == 17);
	assert(littlebig(26) == 409600ul);
	assert(littlebig(27) == 18);
	assert(littlebig(28) == 819200ul);
	assert(littlebig(29) == 19);
	assert(littlebig(30) == 1638400ul);
	return 0;
}
