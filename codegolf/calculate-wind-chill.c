/*

The Australian Apparent Temperature (aka, wind chill) in °C AT is given by this algorithm from the Australian Bureau of Meterology (wp, source):

enter image description here

AT = Ta + (0.33 * e) - (.7 * ws) - 4.0

Where:

Ta = Dry bulb temperature (°C)

e = Water vapour pressure (hPa)

ws = Wind speed (m/s) (at an elevation of 10 meters)

The water vapour pressure in hectoPascals e is given by this algorithm:

enter image description here

e = (rh / 100) * 6.105 * exp( ( 17.27 * Ta ) / ( 237.7 + Ta ) )
Where:

Ta = Dry bulb temperature (°C)

rh = Relative humidity [%]

exp represents the exponential function

The domain of:

Ta is -273.15°C to 2e7°C.

e is the real numbers

ws is 0 m/s to 2e7 m/s

rh is 0% to 100%

For inputs outside these domains, your code can do anything, including give the right answer.

Output
Given a dry bulb temperature in °C, a wind speed in metres / second, and a relative humidity in %, your code should give the Apparent Temperature in °C, accurate to 0.1°C.

Assuming your platform or language can represent reals, for correct functions correct_func,

enter image description here

or in C, fabsl( correct_func(Ta, rH, ws) - expected ) < 0.1.

Test cases
1 value for Ta, rh, ws -> output

0 -> -4
2 -> -3.35346
4 -> -2.69275
6 -> -2.01507
8 -> -1.31719
10 -> -0.595428
12 -> 0.154404
14 -> 0.937065
16 -> 1.75793
18 -> 2.62308
20 -> 3.5393
22 -> 4.51423
24 -> 5.55638
26 -> 6.67525
28 -> 7.88137
30 -> 9.18643

49, 99, 67 -> 36.268
Repl.it for any test case: https://repl.it/H9xL/0

You can use a builtin function for the exponential function, ex, if you like.

This is code-golf, so the shortest code wins!

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
windchill(double T, double r, double V)
{
	return 0.0201465 * r * exp(1727 * T / (100 * T + 23770)) + T - (0.7 * V) - 4;
}

void
test(double T, double r, double V, double wr)
{
	double w;

	w = windchill(T, r, V);
	printf("%f\n", w);
	assert(fabs(w - wr) < 1e-1);
}

int
main(void)
{
	test(0, 0, 0, -4);
	test(2, 2, 2, -3.35346);
	test(4, 4, 4, -2.69275);
	test(6, 6, 6, -2.01507);
	test(8, 8, 8, -1.31719);
	test(10, 10, 10, -0.595428);
	test(12, 12, 12, 0.154404);
	test(14, 14, 14, 0.937065);
	test(16, 16, 16, 1.75793);
	test(18, 18, 18, 2.62308);
	test(20, 20, 20, 3.5393);
	test(22, 22, 22, 4.51423);
	test(24, 24, 24, 5.55638);
	test(26, 26, 26, 6.67525);
	test(28, 28, 28, 7.88137);
	test(30, 30, 30, 9.18643);

	return 0;
}
