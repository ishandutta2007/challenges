/*

Introduction

I found this question that was closed because it was unclear, yet it was a nice idea. I'll do my best to make this into a clear challenge.

The Riemann Zeta function is a special function that is defined as the analytical continuation of

enter image description here

to the complex plane. There are many equivalent formulas for it which makes it interesting for code golf.
Challenge

Write a program that takes 2 floats as input (the real and imaginary part of a complex number) and evaluates the Riemann Zeta function at that point.

Rules

    Input and output via console OR function input and return value
    Built in complex numbers are not allowed, use floats (number, double, ...)
    No mathematical functions except + - * / pow log and real valued trig functions (if you want to integrate, use the gamma function, ... you must include this functions definition in the code)
    Input: 2 floats
    Output: 2 floats
    Your code must contain value that gives theoretically arbitrary precision when made arbitrary large/small
    The behaviour at input 1 is not important (this is the only pole of this function)

Shortest code in bytes wins!
Example Input and Output

Input:

    2, 0

Output:

    1.6449340668482266, 0

Input:

    1, 1

Output:

    0.5821580597520037, -0.9268485643308071

Input:

    -1, 0

Output:

    -0.08333333333333559, 0

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

long
binomial(long n, long k)
{
	long i, c;

	if (k < 0 || k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;

	k = min(k, n - k);
	c = 1;
	for (i = 0; i < k; i++)
		c = c * (n - i) / (i + 1);
	return c;
}

double complex
harmonic(long m)
{
	double complex r;
	long n;

	r = 0;
	for (n = 1; n <= m; n++)
		r += 1.0 / n;
	return r;
}

// https://mathworld.wolfram.com/RiemannZetaFunction.html (formula 21)
// the zeta function definition converges too slowly for finite precision
// use an identity that converges faster
double complex
zeta(double complex s)
{
	double complex r, v;
	long c, k, n, m;

	m = 50;

	if (s == 1)
		return harmonic(m);

	r = 0;
	for (n = 0; n <= m; n++) {
		v = 0;
		c = 1;
		for (k = 0; k <= n; k++) {
			v += c * binomial(n, k) * cpow(k + 1, -s);
			c = -c;
		}
		r += v / cpow(2, n + 1);
	}
	r *= 1 / (1 - cpow(2, 1 - s));

	return r;
}

void
test(double complex s, double complex r)
{
	static const double eps = 1e-8;

	double complex p;

	p = zeta(s);
	printf("%f %f\n", creal(p), cimag(p));
	assert(fabs(creal(p) - creal(r)) < eps);
	assert(fabs(cimag(p) - cimag(r)) < eps);
}

int
main(void)
{
	test(2, 1.6449340668482266);
	test(1 + I, 0.5821580597520037 - 0.9268485643308071 * I);
	test(-1, -0.08333333333333559);

	return 0;
}
