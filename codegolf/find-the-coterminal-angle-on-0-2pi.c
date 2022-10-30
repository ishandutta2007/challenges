/*

This challenge is very simple:

Given an angle measure in degrees or radians (your choice), output the angle between 0 and 2π non-inclusive [0º, 360º) that is coterminal with it.
Input

A positive or negative angle measure. You can pick if you want to take it in degrees or in radians.
Output

The angle on [0, 2π) that is coterminal with the input angle. If you take the input in degrees, the output must also be in degrees; if you take it in radians, the output must be in radians too. The coterminal angle is essentially a the angle mod 360°.
Examples (in degrees)

745 -> 25
1728 -> 288
90 -> 90
0 -> 0
360 -> 0
-50 -> 310
-543.21 -> 176.79

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

double
coterminal(double x)
{
	double r;

	r = fmod(x, 360);
	if (r < 0)
		r += 360;
	return r;
}

int
main(void)
{
	printf("%f\n", coterminal(745));
	printf("%f\n", coterminal(1728));
	printf("%f\n", coterminal(90));
	printf("%f\n", coterminal(0));
	printf("%f\n", coterminal(360));
	printf("%f\n", coterminal(-50));
	printf("%f\n", coterminal(-543.21));

	return 0;
}
