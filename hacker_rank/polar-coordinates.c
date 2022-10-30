// You are given a complex z. Your task is to convert it to polar coordinates.
#include <stdio.h>
#include <math.h>
#include <complex.h>

void
cmplx2polar(complex double x)
{
	double r, p;

	r = cabs(x);
	p = carg(x);
	printf("(%lf + %lfi) -> r=%lf p=%lf\n", creal(x), cimag(x), r, p);
}

int
main(void)
{
	cmplx2polar(-1 + 0 * I);
	cmplx2polar(1 + 2 * I);
	cmplx2polar(5 + 2 * I);
	return 0;
}
