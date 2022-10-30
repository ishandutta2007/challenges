/*

Write a program/function that finds the amount of fuel needed to escape Earth's gravity well given the exhaust velocity of the fuel and the amount of mass to transport using the Tsiolkovsky rocket equation:
Δv=v_exhaust / ln(m_start/m_mend)
where

Δv is the change in velocity from start to finish (in this case, escape velocity is about 11.2 km/s, so you will use that)
vexhaust is the exhaust speed of the fuel (you will be given this)
mstart is the starting mass of the ship (i.e. including fuel)
mend is the ending mass of the ship (i.e. excluding fuel) (you will also be given this)
Equivalently, you have to calculate mstart−mend, which is the mass of the fuel.

The mass you need to get away from Earth will be given in kg*, and the exhaust speed in km/s with precision in the tenths. Return the mass of fuel in kg*. You can take input in any acceptable format, including (but not limited to):

Mass as integer, exhaust speed as double/float
Mass as integer, exhaust speed as integer representing tenths (for example, 24 would represent 2.4)
Mass as string, exhaust speed as string
Output at least with precision to the integer, and in any reasonable format (integer, float, string). Standard loopholes apply. Scoring is shortest answer per language wins, as is standard code-golf.

Sample implementation in Python:

import math

DELTA_V = 11.2

def fuel(mass: int, exhaust_speed: float) -> float:
    ratio = math.exp(DELTA_V / exhaust_speed) # m_start / m_end
    return mass * (ratio - 1)
Try it online!

Test cases (note that they aren't exact):

(0, 1) -> 0
(1, 2.4) -> 105.34267539816554
(100, 2.4) -> 10534.267539816554
(100, 100) -> 11.851286064504517
(1000, 4) -> 15444.646771097048
(597, 4) -> 9220.454122344938
(597, 4.2) -> 7994.973908804485

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
fuel(int mass, double exhaust_speed)
{
	static const double DELTA_V = 11.2;

	double ratio;

	ratio = exp(DELTA_V / exhaust_speed);
	return mass * (ratio - 1);
}

void
test(int mass, double exhaust_speed, double result)
{
	double value;

	value = fuel(mass, exhaust_speed);
	printf("%f\n", value);
	assert(fabs(result - value) < 1e-8);
}

int
main(void)
{
	test(0, 1, 0);
	test(1, 2.4, 105.34267539816554);
	test(100, 2.4, 10534.267539816554);
	test(100, 100, 11.851286064504517);
	test(1000, 4, 15444.646771097048);
	test(597, 4, 9220.454122344938);
	test(597, 4.2, 7994.973908804485);

	return 0;
}
