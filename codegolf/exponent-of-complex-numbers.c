/*

Given two integers, which may be negative, zero, or positive, a and b (taken in any reasonable format, including inputting a plain complex number), convert it to a + bi where i is the imaginary number (square root of negative one).
Then, raise it to the power of a third (positive integer) input variable, c as to (a + bi)c.
You should then end up with something like d + ei. You must then output, or return, d and e in any reasonable format (including outputting a plain complex number).

Input and output may be taken or outputted in any order.

Examples:

5, 2, 2 -> 21, 20
1, 4, 2 -> -15, 8
-5, 0, 1 -> -5, 0

*/

#include <stdio.h>
#include <complex.h>

void
test(double complex x, double complex c)
{
	double complex r;

	r = cpow(x, c);
	printf("%f%+fi\n", creal(r), cimag(r));
}

int
main(void)
{
	test(5 + 2 * I, 2);
	test(1 + 4 * I, 2);
	test(-5, 1);
	return 0;
}
