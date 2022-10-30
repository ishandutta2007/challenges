/*

Introduction

An ellipsoid (Wikipedia / MathWorld) is a 3D object analogous to an ellipse on 2D. Its shape is defined by three principal semi-axes a,b,c:

x^2/a^2 + y^2/b^2 + z^2/c^2 = 1

Just like an ellipse, the volume of an ellipsoid is easy, but its surface area does not have an elementary formula. Even Ramanujan won't save you here.

The basic formula is given as the following:

S=2πc^2 + 2π*a*b/sinφ*(E(φ,k)sin2φ+F(φ,k)cos2φ) where cosφ=ca,k2=a2(b2−c2)b2(a2−c2),a≥b≥c

F and E

are incomplete elliptic integral of the first kind and second kind respectively. Note that the formula does not work for a sphere.

A good approximation can be found on this archived page, where Knud Thomsen developed a symmetrical formula of

S≈4π⎛⎝⎜apbp+bpcp+cpap3−k(1−27abc/(a+b+c)3)⎞⎠⎟1p

with empirical values of p=ln2ln(π/2) and k=3/32.

Challenge

Given the three principal semi-axes a,b,c of an ellipsoid, compute its surface area.

All three input values are guaranteed to be positive, and you can use any reasonable representation of a real number for input. Also, you may assume the three values are given in a certain order (increasing or decreasing).

The result must be within 0.1% (=10-3) relative error for the given test cases.
You can go for the exact formula (if your language has the necessary built-ins) or Thomsen's approximation, or you can go for numerical integration (extra brownie points if you succeed in this way).

Test cases

The true answer was calculated by feeding the corresponding ellipsoid equation into WolframAlpha.

a  b  c  => answer
------------------
1  1  1  => 12.5664
1  1  2  => 21.4784
1  2  2  => 34.6875
1  1  10 => 99.151
1  2  3  => 48.8821
1  10 10 => 647.22
1  3  10 => 212.00

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
elsa(double a, double b, double c)
{
	double ap, bp, cp, sc;
	double p, k;
	double n, d;

	p = log(2) / log(M_PI / 2);
	k = 3.0 / 32;

	ap = pow(a, p);
	bp = pow(b, p);
	cp = pow(c, p);
	sc = pow(a + b + c, 3);

	n = (ap * bp) + (bp * cp) + (cp * ap);
	d = 3 - (k * (1 - (27 * a * b * c / sc)));
	return 4 * M_PI * pow(n / d, 1.0 / p);
}

int
main(void)
{
	static const double tab[][4] = {
	    {1, 1, 1, 12.5664},
	    {1, 1, 2, 21.4784},
	    {1, 2, 2, 34.6875},
	    {1, 1, 10, 99.151},
	    {1, 2, 3, 48.8821},
	    {1, 10, 10, 647.22},
	    {1, 3, 10, 212.00},
	};

	double a, b, c, p, r;
	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		a = tab[i][0];
		b = tab[i][1];
		c = tab[i][2];

		p = elsa(a, b, c);
		r = tab[i][3];

		printf("%f %f\n", p, r);
		assert(fabs(p - r) < 1);
	}

	return 0;
}
