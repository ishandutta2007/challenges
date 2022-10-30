/*

Write a function containing an expression, in terms of n, for the nth term of the sequence that has the following first six terms:

2, 6, 13, 23, 36, 52 ...and the sequence continues.

Examples

seq(1) ➞ 2

seq(2) ➞ 6

seq(6) ➞ 52

Notes

The parameter n is always >= 0.

*/

#include <assert.h>

// https://oeis.org/A143689
unsigned
seq(unsigned n)
{
	return (3 * n * n - n + 2) / 2;
}

int
main(void)
{
	assert(seq(1) == 2);
	assert(seq(2) == 6);
	assert(seq(0) == 1);
	assert(seq(18) == 478);
	assert(seq(27) == 1081);
	assert(seq(6) == 52);
	assert(seq(99) == 14653);

	return 0;
}
