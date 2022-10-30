/*

A tetrahedral number is is a figurate number that represents a pyramid with a triangular base and three sides.

Write a program to find the base of the tetrahedron that contains an input number of balls.

example: 169179692512835000 balls

taken from programmingpraxis.com

*/

#include <assert.h>
#include <math.h>

typedef unsigned long long uvlong;

uvlong
tet(uvlong n)
{
	return n * (n + 1) * (n + 2) / 6;
}

// https://programmingpraxis.com/2011/09/13/tetrahedral-numbers/2/
uvlong
solve(uvlong n)
{
	uvlong lo, hi, mid;

	if (n == 0)
		return 0;

	lo = 0;
	hi = sqrt(n);
	while (hi - lo != 1) {
		mid = lo + (hi - lo) / 2;
		if (tet(mid) < n)
			lo = mid;
		else
			hi = mid;
	}
	return hi;
}

int
main(void)
{
	assert(solve(169179692512835000ULL) == 1005000ULL);

	return 0;
}
