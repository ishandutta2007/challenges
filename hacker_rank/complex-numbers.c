/*

For this challenge, you are given two complex numbers, and you have to print the result of their
addition, subtraction, multiplication, division and modulus operations.

The real and imaginary precision part should be correct up to two decimal places.

*/
#include <stdio.h>
#include <complex.h>

void
carith(complex x, complex y)
{
	complex r = x + y;
	printf("%.2f%+.2fi\n", creal(r), cimag(r));

	r = x - y;
	printf("%.2f%+.2fi\n", creal(r), cimag(r));

	r = x * y;
	printf("%.2f%+.2fi\n", creal(r), cimag(r));

	r = cabs(x) + 0 * I;
	printf("%.2f%+.2fi\n", creal(r), cimag(r));

	r = cabs(y) + 0 * I;
	printf("%.2f%+.2fi\n", creal(r), cimag(r));
}

int
main(void)
{
	carith(2 + I, 5 + 6 * I);
	return 0;
}
