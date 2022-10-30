/*

Create a function that takes the values Dd (Dielectric Outer Diameter),
Dc (Inner Conductor Diameter) and er (Dielectric Constant) and calculates the Coaxial Cable Impedance.

Examples

impedanceCalculator(20.7, 2, 4) ➞ 70.0

impedanceCalculator(5.3, 1.2, 2.2) ➞ 60.0

impedanceCalculator(4.48, 1.33, 2.2) ➞ 50.0

Notes

    If you get stuck on a challenge, find help in the Resources tab.
    Round your result to one decimal place.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
impedance(double Dd, double Dc, double er)
{
	return 138.0 * log10(Dd / Dc) / sqrt(er);
}

void
test(double Dd, double Dc, double er, double r)
{
	static const double eps = 1e-0;
	double v;

	v = impedance(Dd, Dc, er);
	assert(fabs(v - r) < eps);
}

int
main(void)
{
	test(20.7, 2, 4, 70.0);
	test(5.3, 1.2, 2.2, 60.0);
	test(4.58, 1.33, 2.2, 50.0);
	test(40, 2.05, 2.2, 120.0);
	test(25.6, 4, 2.2, 75.0);
	return 0;
}
