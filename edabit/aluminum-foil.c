/*

Aluminum foil has a thickness of 0.025mm. A roll is formed by tightly winding it around a tube with an outside diameter of 4cm.
Given the length of the foil in cm, write a function that returns the diameter of the roll in cm measured at its thickest point. Round the result to four places.

Examples

foil(0) ➞ 4.0

foil(50) ➞ 4.02

foil(4321) ➞ 5.4575

foil(10000) ➞ 6.9175

Notes

N/A

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

// https://math.la.asu.edu/~rich/puzzles/prob002s.html
// L = n*l
// d = pi*(R*r - r*r)/[n*l - pi*(R - r)]
// solve for R
// R = (-d*pi + sqrt(pi*(4*L*d + d**2*pi + 4*d*pi*r + 4*pi*r**2)))/(2*pi)
// diameter of the thickest point = 2*R
double
foil(double L)
{
	static const double pi = M_PI;
	double d, r;

	d = 0.0025;
	r = 2.0;
	return (-d * pi + sqrt(pi * (4 * L * d + d * d * pi + 4 * d * pi * r + 4 * pi * r * r))) / pi;
}

void
test(double L, double r)
{
	assert(fabs(foil(L) - r) < 1e-2);
}

int
main(void)
{
	test(0, 4.0);
	test(6, 4.0025);
	test(7, 4.005);
	test(12, 4.005);
	test(13, 4.0075);
	test(1000, 4.3825);
	test(4321, 5.4575);
	test(7777, 6.385);
	test(10000, 6.9175);
	test(123456, 20.2275);

	return 0;
}
