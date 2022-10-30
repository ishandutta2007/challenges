/*

Write a function that takes in two floating-point numbers s and p and returns two floating-point numbers [x, y],
where x + y = s and x * y = p. Round x and y to three decimal places.

If there are multiple solutions, return the solution with the lesser x (or lesser y, if the x values are equal).

Imaginary/complex number solutions are not allowed. If no real-valued solutions exist, return null.

Examples

sumAndProduct(2, -15) ➞ [-3.0, 5.0]

sumAndProduct(144, 144) ➞ [1.007, 142.993]

sumAndProduct(-42.7, 144.5) ➞ [-38.994, -3.706]

sumAndProduct(10, 30) ➞ null

Notes

To solve this problem, consider setting up a system of two equations and solving for x and y.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
quadratic(double a, double b, double c, double r[2])
{
	double d, s;

	d = b * b - 4 * a * c;
	if (d < 0)
		return d;

	s = sqrt(d);
	r[0] = (-b + s) / (2.0 * a);
	r[1] = (-b - s) / (2.0 * a);
	return d;
}

double *
sumproduct(double s, double p, double r[2])
{
	return (quadratic(-1, s, -p, r) >= 0) ? r : NULL;
}

void
test(double s, double p, double r[2])
{
	static const double eps = 1e-3;
	double u[2];

	if (!sumproduct(s, p, u))
		assert(r == NULL);
	else {
		assert(fabs(r[0] - u[0]) < eps);
		assert(fabs(r[1] - u[1]) < eps);
	}
}

int
main(void)
{
	double r1[] = {-3.0, 5.0};
	double r2[] = {1.007, 142.993};
	double r3[] = {-38.994, -3.706};
	double r4[] = {-18.385, 5.385};
	double r5[] = {1.112, 1109.888};
	double r6[] = {0.901, 1233.099};
	double r7[] = {17.0, 17.0};
	double r8[] = {-13.3, -13.3};
	double r9[] = {-5.0, 5.0};
	double r10[] = {-25.0, 0.0};
	double r11[] = {0.0, 25.0};
	double r12[] = {0.0, 0.0};

	test(2, -15, r1);
	test(144, 144, r2);
	test(-42.7, 144.5, r3);
	test(10, 30, NULL);
	test(-11, 33, NULL);
	test(-13, -99, r4);
	test(1111, 1234, r5);
	test(1234, 1111, r6);
	test(34, 289, r7);
	test(-26.6, 176.89, r8);
	test(0, -25, r9);
	test(0, 25, NULL);
	test(-25, 0, r10);
	test(25, 0, r11);
	test(0, 0, r12);

	return 0;
}
