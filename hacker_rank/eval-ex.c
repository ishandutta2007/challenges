// Evaluate e^x using the first 10 terms of taylor series expansion
// Print to 4 decimal places
#include <stdio.h>

double
ex(double x)
{
	double s, a, b;
	int i;

	a = x;
	b = 1;
	s = 1;
	for (i = 1; i <= 9; i++) {
		s += x / b;
		x *= a;
		b *= (i + 1);
	}
	return s;
}

int
main(void)
{
	printf("%.4lf\n", ex(20));
	printf("%.4lf\n", ex(5));
	printf("%.4lf\n", ex(0.5));
	printf("%.4lf\n", ex(-0.5));
	return 0;
}
