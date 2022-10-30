/*

Task:

Given sample index, x, calculate sample value f(x) of triangular wave, with period of 4 samples and amplitude 1. Offset can be negative and sample value could be either {0, 1, -1}.

Test cases:
   -5 -> -1
   -4 -> 0
   -3 -> 1
   -2 -> 0
   -1 -> -1
    0 -> 0
    1 -> 1
    2 -> 0
    3 -> -1
    4 -> 0
    5 -> 1

Personally I know two approaches in C - the first is using lookup table, the second is using conditional instructions.
For brownie points, could you impress me with a pure "math" approach? (I mean a pure functional approach, e.g. not using conditional instructions or using memory for LUT.)
But this is not an restriction. If you can't, or your language does not support it - just post any solution

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

int
triangle(int x)
{
	static const int tab[] = {0, 1, 0, -1};

	return tab[mod(x, nelem(tab))];
}

int
main(void)
{
	static const int tab[][2] = {
	    {-5, -1},
	    {-4, 0},
	    {-3, 1},
	    {-2, 0},
	    {-1, -1},
	    {0, 0},
	    {1, 1},
	    {2, 0},
	    {3, -1},
	    {4, 0},
	    {5, 1},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(triangle(tab[i][0]) == tab[i][1]);
	return 0;
}
