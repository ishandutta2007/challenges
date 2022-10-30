/*

Create a function that returns an Earned Run Average (ERA). An ERA is calculated by multiplying 9 by the quotient of Earned Runs Allowed er divided by ip Innings Pitched.

In baseball statistics, innings are represented with a fractional part of .1 (1/3) or .2 (2/3) to represent the number of outs in an inning.
A whole number or a number with a fractional part of .0 represents a full inning with three outs. Check the Resources tab for a deeper explanation.
Examples

era(22, 99) ➞ 2.00

era(23, 99.1) ➞ 2.08

era(24, 99.2) ➞ 2.17

Notes

    ERA is represented with a scale of 2: 2.08
    For 1/3 and 2/3, use a scale of 2.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
era(double er, double ip)
{
	return 9 * er / ip;
}

void
eq(double x, double y)
{
	assert(fabs(x - y) < 1e-2);
}

int
main(void)
{
	eq(era(22, 99), 2);
	eq(era(23, 99.1), 2.08);
	eq(era(24, 99.2), 2.17);
	return 0;
}
