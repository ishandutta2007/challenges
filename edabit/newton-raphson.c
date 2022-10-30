/*

Create a function that finds a root of a polynomial curve. Do this using the Newton-Raphson method.

    Your input will be an array of coefficients for a 3rd order polynomial: c(0)*x^3 + c(1)*x^2 + c(2)*x + c(3)
    Round your answer to three decimal places (nearest 0.001). Choose x = 0.0 as an initial guess. Twenty iterations of the algorithm are sufficient for accuracy.
    The Newton-Raphson method uses the generic derivative df/dx. This can be calculated analytically for a polynomial, or numerically using a small step of dx (such as 0.0001). See the Resources tab for more info.

*/

#include <stdio.h>

double
newtonraphson(double c[4])
{
	static const int N = 20;
	double x, f, df;
	int i;

	x = 0;
	for (i = 0; i < N; i++) {
		f = (c[0] * x * x * x) + (c[1] * x * x) + (c[2] * x) + c[3];
		df = (3 * c[0] * x * x) + (2 * c[1] * x) + c[2];
		if (df == 0)
			break;
		x = x - f / df;
	}
	return x;
}

int
main(void)
{
	double c1[4] = {0.0, -0.1, -0.2, 0.3};
	double c2[4] = {-0.1, 0.4, 0.1, -0.8};
	double c3[4] = {0.2, -0.6, 1.5, -2.7};
	double c4[4] = {-1.4, -0.9, -1.0, 5.2};
	double c5[4] = {2.4, 0.1, -4.6, 8.2};
	double c6[4] = {0.0, 0.0, -1.0, 2.0};
	double c7[4] = {-0.4, 3.8, 0.7, -5.5};

	printf("%.3f\n", newtonraphson(c1));
	printf("%.3f\n", newtonraphson(c2));
	printf("%.3f\n", newtonraphson(c3));
	printf("%.3f\n", newtonraphson(c4));
	printf("%.3f\n", newtonraphson(c5));
	printf("%.3f\n", newtonraphson(c6));
	printf("%.3f\n", newtonraphson(c7));

	return 0;
}
