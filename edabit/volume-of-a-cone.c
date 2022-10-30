/*

Create a function that takes the height and radius of a cone as arguments and returns the volume of the cone.
See the resources tab for the formula.

Notes

Return approximate answer by rounding the answer to the nearest hundredth.
Use JavaScript's PI property, don't fall for 3.14 ;-)
If the cone has no volume, return 0.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

double
conevolume(double h, double r)
{
	return M_PI * r * r * h / 3;
}

int
main(void)
{
	printf("%.2lf\n", conevolume(3, 2));
	printf("%.2lf\n", conevolume(15, 6));
	printf("%.2lf\n", conevolume(18, 0));
	printf("%.2lf\n", conevolume(100, 2));
	printf("%.2lf\n", conevolume(1, 1));
	printf("%.2lf\n", conevolume(0, 30));
	return 0;
}
