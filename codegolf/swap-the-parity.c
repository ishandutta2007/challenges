/*

Task

Given a positive integer n, output n+1 if n is odd, and output n-1 if n is even.
Input

A positive integer. You may assume that the integer is within the handling capability of the language.
Output

A positive integer, specified above.
Testcases

input output
    1      2
    2      1
    3      4
    4      3
    5      6
    6      5
    7      8
    8      7
  313    314
  314    313

Scoring

This is code-golf, so shortest answer in bytes wins.

*/

#include <assert.h>

int
parityswap(int n)
{
	return (n & 1) ? n + 1 : n - 1;
}

int
main(void)
{
	assert(parityswap(1) == 2);
	assert(parityswap(2) == 1);
	assert(parityswap(3) == 4);
	assert(parityswap(4) == 3);
	assert(parityswap(5) == 6);
	assert(parityswap(6) == 5);
	assert(parityswap(7) == 8);
	assert(parityswap(8) == 7);
	assert(parityswap(313) == 314);
	assert(parityswap(314) == 313);

	return 0;
}
