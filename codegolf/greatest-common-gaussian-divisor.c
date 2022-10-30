/*

Gaussian integers are complex numbers x+yi such that x and y are both integers, and i^2=−1. The norm of a Gaussian integer N(a+bi) is defined as x^2+y^2=|x+yi|^2.

It is possible to define a Euclidean division for Gaussian integers, which means that it is possible to define a Euclidean algorithm to calculate a greatest common divisor for any two Gaussian integers.

Unfortunately, a Euclidean algorithm requires a well-defined modulo operation on complex numbers, which most programming languages don't have (e.g. Python, Ruby), meaning that such an algorithm fails.

Gaussian division

It is possible to define the division a/b=x+yi (where a and b are both Gaussian integers) as finding a quotient q and a remainder r such that

a=bq+r, and N(r)≤N(b)2

We can further limit this to q=m+ni, where −12<x−m≤12 and −12<y−n≤12, and r=b(x−m+(y−n)i)

From here, a Euclidean algorithm is possible: repeatedly replace (a,b)
by (b,r) until it reaches (d,0). d can then be called the greatest common divisor of a and b

Complex GCDs are not unique; if d=gcd(a,b), then d,−d,di,−di are all GCDs of a and b

You are to take 2 Gaussian integers a,b as input and output gcd(a,b). You may take input in any convenient method, and any reasonable format, including two complex numbers, two lists of pairs [x, y], [w, z] representing gcd(x+yi,w+zi) etc.
Additionally, the output format is equally lax.

You may output any of the 4 possible values for the GCD, and you don't need to be consistent between inputs.

If your language's builtin gcd

function already handles Gaussian integers, and so would trivially solve this challenge by itself, please add it to the Community Wiki of trivial answers below.

This is code-golf, so the shortest code in bytes wins.

Test cases

5+3i, 2-8i    -> 1+i
5+3i, 2+8i    -> 5+3i
1-9i,  -1-7i  -> 1+i
-1+0i, 2-10i  -> 1+0i  (outputting 1 here is also fine)
4+3i,  6-9i   -> 1+0i  (outputting 1 here is also fine)
-3+2i, -3+2i  -> 2+3i
-6+6i, 3+5i   -> 1+i
4+7i, -3-4i   -> 2+i
-3+4i, -6-2i  -> 1+2i
7-7i, -21+21i -> 7+7i


*/

#include <stdio.h>
#include <math.h>
#include <complex.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int r, i;
} cint;

#define ci(a, b) ((cint){a, b})

void
cswap(cint *a, cint *b)
{
	cint t;

	t = *a;
	*a = *b;
	*b = t;
}

cint
cadd(cint a, cint b)
{
	return ci(a.r + b.r, a.i + b.i);
}

cint
csub(cint a, cint b)
{
	return ci(a.r - b.r, a.i - b.i);
}

cint
cmul(cint a, cint b)
{
	return ci(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r);
}

cint
cconj(cint a)
{
	return ci(a.r, -a.i);
}

int
cnorm(cint a)
{
	return a.r * a.r + a.i * a.i;
}

double
cdistsq(double complex a, double complex b)
{
	double x, y;

	x = creal(a) - creal(b);
	y = cimag(a) - cimag(b);
	return x * x + y * y;
}

cint
clat(cint a, cint b)
{
	double complex c[4], m, p;
	double d, nd;
	cint x, y;
	int i;

	x = cmul(a, cconj(b));
	y = cmul(b, cconj(b));
	p = (x.r + x.i * I) * 1.0 / y.r;

	c[0] = floor(creal(p)) + floor(cimag(p)) * I;
	c[1] = floor(creal(p)) + ceil(cimag(p)) * I;
	c[2] = ceil(creal(p)) + floor(cimag(p)) * I;
	c[3] = ceil(creal(p)) + ceil(cimag(p)) * I;

	m = c[0];
	d = cdistsq(c[0], p);
	for (i = 1; i < 4; i++) {
		nd = cdistsq(c[i], p);
		if (nd <= d) {
			m = c[i];
			d = nd;
		}
	}

	return ci(creal(m), cimag(m));
}

int
ceq(cint a, cint b)
{
	return a.r == b.r && a.i == b.i;
}

// http://www.maths.surrey.ac.uk/hosted-sites/euclidean/gaussianintegers.html
// https://www.math.uci.edu/~ndonalds/math180b/6gaussian.pdf
// https://en.wikipedia.org/wiki/Gaussian_integer
cint
cgcd(cint a, cint b)
{
	cint r, q;

	if (cnorm(a) < cnorm(b))
		cswap(&a, &b);

	while (!ceq(b, ci(0, 0))) {
		q = clat(a, b);
		r = csub(a, cmul(b, q));

		a = b;
		b = r;
	}
	return a;
}

int
main(void)
{
	const cint tab[][2] = {
	    {ci(5, 3), ci(2, -8)},
	    {ci(5, 3), ci(2, 8)},
	    {ci(1, -9), ci(1, -7)},
	    {ci(-1, 0), ci(2, -10)},
	    {ci(4, 3), ci(6, -9)},
	    {ci(-3, 2), ci(-3, 2)},
	    {ci(-6, 6), ci(3, 5)},
	    {ci(4, 7), ci(-3, -4)},
	    {ci(-3, 4), ci(-6, 2)},
	    {ci(7, -7), ci(-21, 21)},
	};
	size_t i;
	cint a, b, c;

	for (i = 0; i < nelem(tab); i++) {
		a = tab[i][0];
		b = tab[i][1];
		c = cgcd(a, b);
		printf("gcd(%d%+di, %d%+di) = %d%+di\n", a.r, a.i, b.r, b.i, c.r, c.i);
	}

	return 0;
}
