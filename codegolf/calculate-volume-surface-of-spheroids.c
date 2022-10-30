/*

I want to write a function golf(C, A) that takes the height (C = 2*c) and the width (A = 2*a) of an oblate (left image) or prolate (right image) spheroid or a sphere as parameters and returns the volume V and the surface area S of the shape as tuple.
The output must be rounded to two decimal places.

image from wikipedia to clarify axis names

All input and output numbers are floating point decimals.
The input numbers (A and C) are guaranteed to be greater than 0 and lower than 100.

Here are some example calls of the function (golf(C, A)) in Python 3 and the expected outputs given as test cases:

golf(4, 2)  # expected output (8.38, 21.48)
golf(2, 2)  # expected output (4.19, 12.57)
golf(2, 4)  # expected output (16.76, 34.69)

The challenge requires my code to be smaller than 150 characters.

I could not manage to solve it myself yet, my best solution in Python 3 still takes 220 characters:

from math import * 
def golf(C,A):
 c,a,V=C/2,A/2,pi/6*A*A*C;F=c*c/a**2;E=sqrt(1-(F if a>c else 1/F));S=4*pi*a*a if a==c else 2*pi*a*a*(1+(((1-E**2)/E)*atanh(E)if a>c else(c/(a*E))*asin(E)))
 return round(V,2),round(S,2)

The necessary formulas are taken from Wikipedia: Spheroid, here's a summary:

surface area oblate spheroid
surface area prolate spheroid

Vall spheroids = 4 π/3 a²c = π/6 A²C as A=2a and C=2c.

This challenge was originally from checkio.org and got refactored into a code-golf challenge for empireofcode.com.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

void
vsa(double C, double A, double *V, double *S)
{
	double a, c, e;
	double u, v;

	c = C / 2;
	a = A / 2;
	u = fmin(a, c);
	v = fmax(a, c);
	e = sqrt(1 - (u * u) / (v * v));

	*V = 4.0 / 3 * M_PI * a * a * c;
	if (c < a)
		*S = 2 * M_PI * a * a * (1 + ((1 - e * e) / e) * atanh(e));
	else if (c > a)
		*S = 2 * M_PI * a * a * (1 + (c / (a * e)) * asin(e));
	else
		*S = 4 * M_PI * a * a;
}

void
test(double C, double A, double VR, double SR)
{
	static const double eps = 1e-2;
	double V, S;

	vsa(C, A, &V, &S);
	printf("%f %f\n", V, S);
	assert(fabs(V - VR) < eps);
	assert(fabs(S - SR) < eps);
}

int
main(void)
{
	test(4, 2, 8.38, 21.48);
	test(2, 2, 4.19, 12.57);
	test(2, 4, 16.76, 34.69);

	return 0;
}
