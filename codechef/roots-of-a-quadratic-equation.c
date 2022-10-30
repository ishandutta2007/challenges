/*

All submissions for this problem are available.
Write a program to take the values for A, B, C of a quadratic equation A∗X2+B∗X+C=0
and then find all the roots of the equation.
It is guaranteed that A ≠ 0 and that the equation has at least one real root.

*/
#include <stdio.h>
#include <math.h>

void
quadratic(double a, double b, double c, double *x1, double *x2)
{
	double d;

	d = sqrt(b * b - 4 * a * c);
	*x1 = (-b + d) / (2 * a);
	*x2 = (-b - d) / (2 * a);
}

void
solve(double a, double b, double c)
{
	double x1, x2;
	quadratic(a, b, c, &x1, &x2);
	printf("%lf\n%lf\n", x1, x2);
}

int
main(void)
{
	solve(1, -8, 15);
	return 0;
}
