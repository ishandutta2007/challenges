/*

Given a number (positive, negative, or 0), return the logical negation (as a 1 or 0) of that number. Do so using only bitwise operators:

~, &, |, ^, >>, <<, +

Any of these characters / constructs are not allowed:

if, do, while, for, switch, -, ?, :, !, ||, &&, == , [,], functions

Examples

bitwiseLogicalNegation(1) ➞ 0

bitwiseLogicalNegation(5) ➞ 0

bitwiseLogicalNegation(0) ➞ 1

bitwiseLogicalNegation(3) ➞ 0

Notes

Use as few operators as possible for more of a challenge.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <limits.h>

int
lnot(unsigned x)
{
	return (~(x >> 1) + x) >> ((UINT_WIDTH << 1) + (~UINT_WIDTH));
}

int
main(void)
{
	unsigned i;

	assert(lnot(1) == 0);
	assert(lnot(5) == 0);
	assert(lnot(0) == 1);
	assert(lnot(3) == 0);
	for (i = 1; i < UINT_MAX; i++)
		assert(lnot(i) == 0);
	assert(lnot(UINT_MAX) == 0);

	return 0;
}
