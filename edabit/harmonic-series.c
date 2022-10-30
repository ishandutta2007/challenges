/*

In mathematics, the harmonic series is the divergent infinite series:

Alternative Text

Its name derives from the concept of overtones, or harmonics in music.

Create a function that, given a precision parameter, returns the value of the harmonic series.
Examples

harmonic(3) ➞ 1.833

harmonic(1) ➞ 1.0

harmonic(5) ➞ 2.283

Notes

Round the result to the third decimal place.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
harmonic(unsigned n)
{
	double v;
	unsigned i;

	v = 0;
	for (i = 1; i <= n; i++)
		v += 1.0 / i;
	return v;
}

void
eq(unsigned n, double r)
{
	assert(fabs(harmonic(n) - r) < 1e-3);
}

int
main(void)
{
	eq(3, 1.833);
	eq(1, 1.0);
	eq(5, 2.283);
	eq(10, 2.929);
	eq(12345, 9.998);
	eq(0, 0);
	eq(5000, 9.095);
	eq(2, 1.5);
	return 0;
}
