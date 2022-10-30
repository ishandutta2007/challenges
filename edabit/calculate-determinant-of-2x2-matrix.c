// Create a function to calculate the determinant of a 2 x 2 matrix.
// The determinant of the following matrix is: ad - bc
#include <stdio.h>

double
det2(double m[2][2])
{
	return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

int
main(void)
{
	double a[2][2] = {{1, 2}, {3, 4}};
	printf("%lf\n", det2(a));

	double b[2][2] = {{5, 3}, {3, 1}};
	printf("%lf\n", det2(b));

	double c[2][2] = {{1, 1}, {1, 1}};
	printf("%lf\n", det2(c));

	double d[2][2] = {{1, 1}, {1, 0}};
	printf("%lf\n", det2(d));

	return 0;
}
