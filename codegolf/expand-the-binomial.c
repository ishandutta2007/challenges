/*

Challenge

Given three numbers a, b, and n, you must expand (a+bx)^n in ascending powers of x up to x^3.

Binomial Expansion
Note that this method is an approximation

The binomial expansion works like so:

(a + bx)^n = a^n(1 + bx/a)^n
           = a^n(1 + n(bx/a) + n(n -1)(bx/a)^2/2! + n(n-1)(n-1)(bx/a)^3/3!)

Which simplifies down to an expression in the form

α+βx+γx2+δx3 Where α, β, γ and δ are constants which you must calculate.

These constants should be given to at least 3 decimal places where appropriate (i.e. 1.2537 should be output instead of 1.25, but 1.2 can be output if the answer is exactly 1.2).

You must then output these four constants in a list (in order as they appear in the final equation). This list may be separated however you wish.

Input
The inputs a and b will be integers in the range -100 to 100 inclusive where a≠0.

n will be given to one decimal place and will be in the range −2≤n≤2
Examples
a = 1, b = 6, n = -1.0
1, -6, 36, -216
a = 3, b = 2, n = 2.0
9, 12, 4, 0
a = 5, b = 4, n = 0.3
1.621, 0.389, -0.109, 0.049
Winning
The shortest code in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

void
expand(double a, double b, double n, double r[4])
{
	double p, u;

	p = pow(a, n);
	u = b / a;
	r[0] = p;
	r[1] = p * n * u;
	r[2] = p * ((n * (n - 1)) / 2) * u * u;
	r[3] = p * ((n * (n - 1) * (n - 2)) / 6) * u * u * u;
}

void
test(double a, double b, double n, double r[4])
{
	double p[4];
	int i;

	expand(a, b, n, p);
	printf("%f %f %f %f\n", p[0], p[1], p[2], p[3]);
	for (i = 0; i < 4; i++)
		assert(fabs(p[i] - r[i]) < 1e-3);
}

int
main(void)
{
	double r1[] = {1, -6, 36, -216};
	double r2[] = {9, 12, 4, 0};
	double r3[] = {1.621, 0.389, -0.109, 0.049};

	test(1, 6, -1, r1);
	test(3, 2, 2, r2);
	test(5, 4, 0.3, r3);

	return 0;
}
