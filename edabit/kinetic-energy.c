/*

Kinetic energy can be calculated with the following formula:

https://edabit-challenges.s3.amazonaws.com/kenen.png

KE = 1/2mv²

    m is mass in kg
    v is velocity in m/s
    KE is kinetic energy in J

Return the Kinetic Energy in Joules, given the mass and velocity. For the purposes of this challenge, round answers to the nearest integer.
Examples

kineticEnergy(60, 3) ➞ 270

kineticEnergy(45, 10) ➞ 2250

kineticEnergy(63.5, 7.35) ➞ 1715

Notes

Expect only positive numbers for inputs.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
kinetic(double m, double v)
{
	return 0.5 * m * v * v;
}

void
test(double m, double v, double r)
{
	assert(fabs(kinetic(m, v) - r) < 1);
}

int
main(void)
{
	test(60, 3, 270);
	test(45, 10, 2250);
	test(63.5, 7.35, 1715);
	test(0, 7.35, 0);
	test(88.4, 0, 0);
	test(3.333, 5.4, 49);

	return 0;
}
