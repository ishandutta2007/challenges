/*

A logarithm is kind of like reverse exponents. There is a base and a number in a logarithm. The point of a logarithm is to find out what power you have to raise the base to get the number next to the base. For example:

log base 5 of 25 = x

This is the same thing as saying 5 to the xth power is 25, which is 2 (so x would be 2). Using this example, your function must take the 5 and 25 and somehow get 2.
Examples

logarithm(5, 25) ➞ 2

logarithm(2, 64) ➞ 6

logarithm(2, 4) ➞ 2

Notes

    Check Resources if you need more help with logarithms.
    All inputs are integers and the bases are less than 10.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
logarithm(int x, int y)
{
	if (x == y)
		return 1;
	return log10(y) / log10(x);
}

int
main(void)
{
	assert(logarithm(5, 25) == 2);
	assert(logarithm(2, 64) == 6);
	assert(logarithm(2, 4) == 2);
	assert(logarithm(7, 49) == 2);
	assert(logarithm(1, 1) == 1);
	assert(logarithm(12, 144) == 2);
	assert(logarithm(2, 4) == 2);

	return 0;
}
