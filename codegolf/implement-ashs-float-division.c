/*

Ash has a bit of an interesting float division algorithm. It's designed to never return NaN, and things like signed zero and infinity need to be handled.

How it works:

Assume the inputs are positive for the rules below. One input being negative will always result in the output being negative, and both being negative will result in a positive output.

    Zero divided by anything is 0
    Anything other than 0 divided by 0 is Infinity
    Anything other than Infinity divided by Infinity is 0
    Infinity divided by anything other than Infinity is Infinity
    Infinity divided by Infinity is 1
    All other division works as normal

I/O:

For languages with floats that support signed zero and positive/negative infinity, floats are an accepted I/O format.
For others, using a string is allowed. You can use any reasonable format in this string, and you can represent the infinities with anything that can't be confused with another number (such as I, ∞, inf, or :().

Input will always be two floats in your chosen representation, and output will be a single one. Floating point errors and large numbers being represented as Infinity are allowed.

Test cases:

0 / 0                   0
0 / 1                   0
0 / 8                   0
0 / Infinity            0
0 / -0                 -0
0 / -1                 -0
0 / -8                 -0
0 / -Infinity          -0
-0 / 0                 -0
-0 / 1                 -0
-0 / 8                 -0
-0 / Infinity          -0
-0 / -0                 0
-0 / -1                 0
-0 / -8                 0
-0 / -Infinity          0
1 / 0                   Infinity
8 / 0                   Infinity
Infinity / 0            Infinity
1 / -0                 -Infinity
8 / -0                 -Infinity
Infinity / -8          -Infinity
-1 / 0                 -Infinity
-8 / 0                 -Infinity
-Infinity / 0          -Infinity
-1 / -0                 Infinity
-8 / -0                 Infinity
-Infinity / -0          Infinity
Infinity / 1            Infinity
Infinity / 8            Infinity
Infinity / -1          -Infinity
Infinity / -8          -Infinity
-Infinity / 1          -Infinity
-Infinity / 8          -Infinity
-Infinity / -1          Infinity
-Infinity / -8          Infinity
Infinity / Infinity     1
Infinity / -Infinity   -1
-Infinity / Infinity   -1
-Infinity / -Infinity   1
1 / 1                   1
1 / 8                   0.125
1 / Infinity            0
1 / -1                 -1
1 / -8                 -0.125
1 / -Infinity          -0
-1 / 1                 -1
-1 / 8                 -0.125
-1 / Infinity          -0
-1 / -1                 1
-1 / -8                 0.125
-1 / -Infinity          0
8 / 1                   8
8 / 8                   1
8 / Infinity            0
8 / -1                 -8
8 / -8                 -1
8 / -Infinity          -0
-8 / 1                 -8
-8 / 8                 -1
-8 / Infinity          -0
-8 / -1                 8
-8 / -8                 1
-8 / -Infinity          0
1 / 0.125               8
0.1 / 0.2               0.5
10 / -3                 -3.333333
1 / 0.0000000000000001  10000000000000000

Other:

This is code-golf, so shortest answer in bytes (per language) wins!

*/

#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
ashdiv(double x, double y)
{
	double r;

	r = 0;
	if (x == 0)
		r = 0;
	else if (y == 0)
		r = INFINITY;
	else if (isinf(x) && isinf(y))
		r = 1;
	else if (isinf(x))
		r = INFINITY;
	else if (isinf(y))
		r = 0;
	else
		return x / y;

	if (signbit(x))
		r = -r;
	if (signbit(y))
		r = -r;

	return r;
}

int
main(void)
{
	static const double tab[][3] = {
	    {0, 0, 0},
	    {0, 1, 0},
	    {0, 8, 0},
	    {0, INFINITY, 0},
	    {0, -0, -0},
	    {0, -1, -0},
	    {0, -8, -0},
	    {0, -INFINITY, -0},
	    {-0, 0, -0},
	    {-0, 1, -0},
	    {-0, 8, -0},
	    {-0, INFINITY, -0},
	    {-0, -0, 0},
	    {-0, -1, 0},
	    {-0, -8, 0},
	    {-0, -INFINITY, 0},
	    {1, 0, INFINITY},
	    {8, 0, INFINITY},
	    {INFINITY, 0, INFINITY},
	    {1, -0.0, -INFINITY},
	    {8, -0.0, -INFINITY},
	    {INFINITY, -8, -INFINITY},
	    {-1, 0.0, -INFINITY},
	    {-8, 0.0, -INFINITY},
	    {-INFINITY, 0.0, -INFINITY},
	    {-1, -0.0, INFINITY},
	    {-8, -0.0, INFINITY},
	    {-INFINITY, -0.0, INFINITY},
	    {INFINITY, 1, INFINITY},
	    {INFINITY, 8, INFINITY},
	    {INFINITY, -1, -INFINITY},
	    {INFINITY, -8, -INFINITY},
	    {-INFINITY, 1, -INFINITY},
	    {-INFINITY, 8, -INFINITY},
	    {-INFINITY, -1, INFINITY},
	    {-INFINITY, -8, INFINITY},
	    {INFINITY, INFINITY, 1},
	    {INFINITY, -INFINITY, -1},
	    {-INFINITY, INFINITY, -1},
	    {-INFINITY, -INFINITY, 1},
	    {1, 1, 1},
	    {1, 8, 0.125},
	    {1, INFINITY, 0},
	    {1, -1, -1},
	    {1, -8, -0.125},
	    {1, -INFINITY, -0},
	    {-1, 1, -1},
	    {-1, 8, -0.125},
	    {-1, INFINITY, -0},
	    {-1, -1, 1},
	    {-1, -8, 0.125},
	    {-1, -INFINITY, 0},
	    {8, 1, 8},
	    {8, 8, 1},
	    {8, INFINITY, 0},
	    {8, -1, -8},
	    {8, -8, -1},
	    {8, -INFINITY, -0},
	    {-8, 1, -8},
	    {-8, 8, -1},
	    {-8, INFINITY, -0},
	    {-8, -1, 8},
	    {-8, -8, 1},
	    {-8, -INFINITY, 0},
	    {1, 0.125, 8},
	    {0.1, 0.2, 0.5},
	    {10, -3, -3.333333},
	    {1, 0.0000000000000001, 10000000000000000},
	};

	double x, y, z, r;
	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		x = tab[i][0];
		y = tab[i][1];
		z = tab[i][2];
		r = ashdiv(x, y);
		printf("%f %f | %f %f\n", x, y, r, z);
	}

	return 0;
}
