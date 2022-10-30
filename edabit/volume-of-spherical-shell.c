/*

The volume of a spherical shell is the difference between the enclosed volume of the outer sphere and the enclosed volume of the inner sphere:

V = 4/3*pi*(R^3 - r^3)

Create a function that takes r1 and r2 as arguments and returns the volume of a spherical shell rounded to the nearest thousandth.

Notes

The inputs are always positive numbers. r1 could be the inner radius or the outer radius, don't return a negative number.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

double
volshell(double r1, double r2)
{
	return 4.0 * M_PI * fabs(r2 * r2 * r2 - r1 * r1 * r1) / 3.0;
}

int
main(void)
{
	printf("%.3lf\n", volshell(17, 36));
	printf("%.3lf\n", volshell(3, 4));
	printf("%.3lf\n", volshell(1, 90));
	printf("%.3lf\n", volshell(12.5, 19));
	printf("%.3lf\n", volshell(3, 800));
	printf("%.3lf\n", volshell(16.128, 16.256));
	printf("%.3lf\n", volshell(3, 3));
	printf("%.3lf\n", volshell(4, 3));
	printf("%.3lf\n", volshell(36, 17));
	printf("%.3lf\n", volshell(18, 96));
	printf("%.3lf\n", volshell(1, 7));
	printf("%.3lf\n", volshell(7, 2));
	printf("%.3lf\n", volshell(100, 50));
	printf("%.3lf\n", volshell(40, 36));
	return 0;
}
