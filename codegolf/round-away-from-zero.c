/*

Round away from zero

Inspired by Round towards zero.

Given a number input via any reasonable method, round the number "away from zero" - positive numbers round up, and negative numbers round down.

If you intend to take the input as a string (via STDIN, for example), you should be able to handle numbers with or without the decimal point. If you take it as a number, it should at least be able to handle floating-point precision (double precision not required) or rational numbers.

You can output a floating-point number with the decimal point (e.g. 42.0) if desired. (Or even have some test cases output floating-point and some output integer, if it makes your answer shorter.)

Standard loopholes are not allowed, etc etc.
Test cases

-99.9 => -100
-33.5 => -34
-7    => -7
-1.1  => -2
0     => 0
2.3   => 3
8     => 8
99.9  => 100
42.0  => 42
-39.0 => -39

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
roundz(double x)
{
	return (x < 0) ? floor(x) : ceil(x);
}

int
main(void)
{
	static const double itab[] = {
	    -99.9,
	    -33.5,
	    -7,
	    -1.1,
	    0,
	    2.3,
	    8,
	    99.9,
	    42.0,
	    -39.0,
	};
	static const int otab[] = {
	    -100,
	    -34,
	    -7,
	    -2,
	    0,
	    3,
	    8,
	    100,
	    42,
	    -39,
	};

	size_t i;
	int r;

	for (i = 0; i < nelem(itab); i++) {
		r = roundz(itab[i]);
		printf("%f -> %d %d\n", itab[i], r, otab[i]);
		assert(r == otab[i]);
	}

	return 0;
}
