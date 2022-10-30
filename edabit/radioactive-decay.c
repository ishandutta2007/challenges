/*

A half life is the amount of time for half of a radioactive substance to decay.

    After 1 half life, 50% of a substance will be left.
    After 2 half lives, 25% of a substance will be left.
    After 3 half lives, 12.5% of a substance will be left, etc...

Create a function which calculates the remaining mass and the number of years that it took for the substance to decay. You will be given:

    The mass of the substance.
    The time in years for a halflife to elapse.
    The number of half lives.

Worked Example

halflife_calculator(1000, 5730, 2) ➞ [250, 11460]

# There are 2 half lives, so the mass decays from 1000 to 500, then from 500 to 250.
# Each halflife is 5730 years, and since there were 2, it took 11460 years in total.

Examples

halflife_calculator(1600, 6, 3) ➞ [200, 18]

halflife_calculator(13, 500, 1) ➞ [6.5, 500]

halflife_calculator(100, 35, 5) ➞ [3.125, 175]

Notes

    Round the final mass to three decimal places.
    All inputs are positive numbers.
    Return the final mass first, then the number of years.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

void
halflife(double m, double y, unsigned n, double r[2])
{
	r[0] = m / pow(2, n);
	r[1] = y * n;
}

void
test(double m, double y, unsigned n, double r[2])
{
	static const double eps = 1e-3;
	double p[2];

	halflife(m, y, n, p);
	assert(fabs(r[0] - p[0]) < eps);
	assert(fabs(r[1] - p[1]) < eps);
}

int
main(void)
{
	test(1000, 5730, 2, (double[]){250, 11460});
	test(1600, 6, 3, (double[]){200, 18});
	test(13, 500, 1, (double[]){6.5, 500});
	test(100, 35, 5, (double[]){3.125, 175});
	test(11037, 53, 6, (double[]){172.453, 318});

	return 0;
}
