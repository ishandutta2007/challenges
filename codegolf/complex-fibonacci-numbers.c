/*

The Binet formula is a closed form expression for the n'th Fibonacci number:

Fn=(ϕn−(1−ϕ)n)/sqrt(5)

where ϕ=1+5√2
is the golden ratio. This formula works even when n

is negative or rational, and so can be a basis to calculating "complex Fibonacci numbers".

For example, by setting n=12, we can calculate F12

as:

F12=15–√(1+5–√2−−−−−−−√−1−5–√2−−−−−−−√)≈0.56886−0.35158i

You are to take a floating point, −10≤n≤10
with up to 3 decimals after the point, and output Fn accurate to at least 5 decimal places.
You may either round or truncate, so long as it is consistent.
You may also choose to input as a rational number if you wish, or as a (numerator, denominator) pair.
You may also choose whether integers should be suffixed with .0 or not, so long as it is consistent across all 21 integer inputs.

As the output will be a complex number in all but 21 cases, you may output in any reasonable format for such a type, including outputting as a (real, imag) pair. For the integer inputs, the imaginary part will be 0.
You may choose whether to output the imaginary part in this case (and returning an integer or float is perfectly fine).

This is code-golf, so the shortest code in bytes wins

Test cases

These all round their output, rather than truncate.


  n       Re(Fn)     Im(Fn)
-10      -55         0
  1        1         0
 -7       13         0
  3        2         0
  0.5      0.56886  -0.35158
  5.3      5.75045   0.02824
  7.5     16.51666   0.01211
 -1.5      0.21729  -0.92044
 -9.06    34.37587  -6.55646
  9.09    35.50413   0.00157
 -2.54     0.32202   1.50628
  5.991    7.96522   0.00071
 -6.033   -8.08507   0.84377
  8.472   26.36619  -0.00756

And a script to output all possible outputs in the same format (gets cut off on TIO due to the length).

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double complex
cfib(double complex n)
{
	double complex phi = (1 + sqrt(5)) / 2;
	double complex psi = (1 - sqrt(5)) / 2;
	return (cpow(phi, n) - cpow(psi, n)) / sqrt(5);
}

int
main(void)
{
	static const double complex tab[][2] = {
	    {-10, -55},
	    {1, 1},
	    {-7, 13},
	    {3, 2},
	    {0.5, 0.56886 - 0.35158 * I},
	    {5.3, 5.75045 + 0.02824 * I},
	    {7.5, 16.51666 + 0.01211 * I},
	    {-1.5, 0.21729 - 0.92044 * I},
	    {-9.06, 34.37587 - 6.55646 * I},
	    {9.09, 35.50413 + 0.00157 * I},
	    {-2.54, 0.32202 + 1.50628 * I},
	    {5.991, 7.96522 + 0.00071 * I},
	    {-6.033, -8.08507 + 0.84377 * I},
	    {8.472, 26.36619 - 0.00756 * I},
	};
	static const double eps = 1e-5;

	double complex u, v;
	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		u = tab[i][1];
		v = cfib(tab[i][0]);
		printf("%.6f: %.6f %.6f\n", creal(tab[i][0]), creal(v), cimag(v));
		assert(creal(u - v) < eps);
		assert(cimag(u - v) < eps);
	}

	return 0;
}
