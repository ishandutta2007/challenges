// Given a square matrix, calculate the absolute difference between the sums of its diagonals.
#include <stdio.h>
#include <math.h>

double
diagdiff(double *a, size_t n)
{
	double s1, s2;
	size_t i;

	s1 = 0;
	s2 = 0;
	for (i = 0; i < n; i++) {
		s1 += a[i * n + i];
		s2 += a[i * n + (n - i - 1)];
	}
	return fabs(s1 - s2);
}

int
main(void)
{
	double a[3][3] = {
	    {1, 2, 3},
	    {4, 5, 6},
	    {9, 8, 9},
	};
	double b[4][4] = {
	    {1, 0, 0, 0},
	    {0, 1, 0, 0},
	    {0, 0, 1, 0},
	    {0, 0, 0, 1},
	};
	double r;

	r = diagdiff(&a[0][0], 3);
	printf("%lf\n", r);

	r = diagdiff(&b[0][0], 4);
	printf("%lf\n", r);

	return 0;
}
