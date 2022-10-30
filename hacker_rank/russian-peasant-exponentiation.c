// implement russian peasant to calculate complex number exponentiation
// http://lafstern.org/matt/col3.pdf

#include <stdio.h>
#include <complex.h>

complex double
rexp(complex double x, int n, int m)
{
	complex double p;
	int a, b;

	while ((n & 1) == 0) {
		x *= x;
		n >>= 1;
	}
	p = x;
	for (n >>= 1; n > 0; n >>= 1) {
		x *= x;
		if ((n & 1) != 0)
			p *= x;
	}

	a = (int)(creal(p)) % m;
	b = (int)(cimag(p)) % m;
	if (a < 0)
		a += m;
	if (b < 0)
		b += m;
	return CMPLX(a, b);
}

int
main(void)
{
	complex v = rexp(CMPLX(2, 0), 9, 1000);
	printf("%.0lf + %.0lfi\n", creal(v), cimag(v));

	v = rexp(CMPLX(0, 1), 5, 10);
	printf("%.0lf + %.0lfi\n", creal(v), cimag(v));

	v = rexp(CMPLX(8, 2), 10, 1000000000);
	printf("%.0lf + %.0lfi\n", creal(v), cimag(v));

	return 0;
}
