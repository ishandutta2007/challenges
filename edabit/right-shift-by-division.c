/*

The right shift operation is similar to floor division by powers of two.

Sample calculation using the right shift operator ( >> ):

80 >> 3 = floor(80/2^3) = floor(80/8) = 10
-24 >> 2 = floor(-24/2^2) = floor(-24/4) = -6
-5 >> 1 = floor(-5/2^1) = floor(-5/2) = -3

Write a function that mimics (without the use of >>) the right shift operator and returns the result from the two given integers.
Examples

shiftToRight(80, 3) ➞ 10

shiftToRight(-24, 2) ➞ -6

shiftToRight(-5, 1) ➞ -3

shiftToRight(4666, 6) ➞ 72

shiftToRight(3777, 6) ➞ 59

shiftToRight(-512, 10) ➞ -1

Notes

    There will be no negative values for the second parameter y.
    This challenge is more like recreating of the right shift operation, thus, the use of the operator directly is prohibited.
    Alternatively, you can solve this challenge via recursion.
    A recursive version of this challenge can be found via this link.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
rsh(int n, unsigned s)
{
	int m, r;

	m = n < 0;
	for (r = 0; s > 0; s--) {
		r += (n & 1);
		n /= 2;
	}
	if (r)
		n -= m;
	return n;
}

int
main(void)
{
	static const int itab[][2] = {
	    {80, 3},
	    {-24, 2},
	    {-5, 1},
	    {38, 0},
	    {192, 4},
	    {4666, 6},
	    {3777, 6},
	    {1024, 5},
	    {-512, 10},
	};
	static const int otab[] = {
	    10,
	    -6,
	    -3,
	    38,
	    12,
	    72,
	    59,
	    32,
	    -1,
	};

	size_t i;

	for (i = 0; i < nelem(itab); i++)
		assert(rsh(itab[i][0], itab[i][1]) == otab[i]);

	return 0;
}
