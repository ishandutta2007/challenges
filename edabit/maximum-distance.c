/*

Write a function that takes fuel (liters), fuelUsage (liters/100km), passengers, airConditioner (boolean) and returns maximum distance that car can travel.

    fuel is the number of liters of fuel in the fuel tank.
    fuelUsage is basic fuel consumption per 100 km (with the driver inside only).
    Every additional passenger is increasing basic fuel consumption by 5%.
    If the air conditioner is ON true, its increasing total (not basic) fuel consumption by 10%.

Examples

totalDistance(70.0, 7.0, 0, false) ➞ 1000.0

totalDistance(36.1, 8.6, 3, true) ➞ 331.83

totalDistance(55.5, 5.5, 5, false) ➞ 807.3

Notes

    fuel and fuelUsage are always greater than 1.
    passengers are always greater or equal to 0.
    The tolerance of the returned value is 0.1.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

double
distance(double f, double u, double p, bool ac)
{
	double r;

	r = f / (u * (1 + 0.05 * p)) * 100;
	if (ac)
		r /= 1.10;
	return r;
}

void
test(double f, double u, double p, bool ac, double r)
{
	double v;

	v = distance(f, u, p, ac);
	printf("%.2f\n", v);
	assert(fabs(v - r) < 1e-1);
}

int
main(void)
{
	test(70.0, 7.0, 0, false, 1000.0);
	test(50.0, 7.0, 3, true, 564.65);
	test(55.5, 5.5, 5, false, 807.3);
	test(36.1, 8.6, 3, true, 331.83);
	test(71.9, 12.1, 1, false, 565.9);
	test(11.0, 11.0, 0, false, 100.0);
	test(55.5, 5.5, 5, false, 807.27);
	test(300.0, 25.0, 11, true, 703.8);

	return 0;
}
