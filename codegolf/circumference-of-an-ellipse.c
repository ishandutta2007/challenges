/*

Challenge

Unlike the circumference of a circle (which is as simple as 2πr), the circumference of an ellipse is hard.

Given the semi-major axis a and semi-minor axis b of an ellipse (see the image below, from Wikipedia), calculate its circumference.

By definition, you can assume 0<b≤a for input values. The output value must be within 10−6 relative error from the expected answer for the given test cases.

enter image description here

Standard code-golf rules apply. The shortest code in bytes wins.

Formulas

Relevant information can be found on Wikipedia and MathWorld.
C is the value of the circumference; e and h are helper values.
The last two are Ramanujan's approximations, the first of which (the crossed-out one) does not meet the error requirements.
The second approximation formula (Equation 5) barely does (verification) for up to a=5b (which is also the upper limit of the test cases, so you can use it for your answer).

e=√1−b2a2
C=4aE(e)=4a∫π/20√1−e2sin2θdθ
C=2πa(1−∞∑n=1((2n−1)!!(2n)!!)2e2n2n−1)
h=(a−b)2(a+b)2
C=π(a+b)(1+∞∑n=1((2n−1)!!2nn!)2hn(2n−1)2)
C=π(a+b)∞∑n=0(1/2n)2hn
C≈π(3(a+b)−√(3a+b)(a+3b))
C≈π(a+b)(1+3h10+√4−3h)

Test cases

All the values for C (circumference) are calculated using Equation 4 with 1000 terms, and presented with 10 significant figures.

a     b     C
1     1     6.283185307
1.2   1     6.925791195
1.5   1     7.932719795
2     1     9.688448220
3     1     13.36489322
5     1     21.01004454
20    10    96.88448220
123   45    556.6359936

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef double (*function)(double, void *);

double
simpson(function f, void *ud, double begin, double end, int n)
{
	int i = 0, j;
	double ret = 0;
	double delta = (end - begin) / n;

	ret += f(begin, ud);

	for (j = 1; j < n; j++) {
		ret += (4 - (i << 1)) * f(begin + j * delta, ud);
		i = (i + 1) & 1;
	}
	ret += f(end, ud);
	ret *= (delta / 3);
	return ret;
}

double
E(double t, void *ud)
{
	double e, s;

	e = *(double *)ud;
	s = sin(t);
	return sqrt(1 - e * e * s * s);
}

double
circumference(double a, double b)
{
	double e;

	if (a == 0)
		return 0;

	e = sqrt(1 - (b * b) / (a * a));
	return 4 * a * simpson(E, &e, 0, M_PI / 2, 50);
}

int
main(void)
{
	static const double tab[][3] = {
	    {1, 1, 6.283185307},
	    {1.2, 1, 6.925791195},
	    {1.5, 1, 7.932719795},
	    {2, 1, 9.688448220},
	    {3, 1, 13.36489322},
	    {5, 1, 21.01004454},
	    {20, 10, 96.88448220},
	    {123, 45, 556.6359936},
	};

	double a, b, c, r;
	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		a = tab[i][0];
		b = tab[i][1];
		r = tab[i][2];
		c = circumference(a, b);
		printf("%f %f %f %f\n", a, b, c, r);
		assert(fabs(c - r) < 1e-7);
	}

	return 0;
}
