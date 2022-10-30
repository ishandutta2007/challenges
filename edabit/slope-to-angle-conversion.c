/*

Given a slope of a line, calculate and return the value of the angle of line (relative to the y -axis). For example, a horizontal line would be 90 degrees.

Notes

    All values returned should be in degrees.
    All values returned should be rounded to the nearest whole number.
    The value to return must be strictly between 0 and 180.
    All inputs will be valid integer values.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

double
convert(int x)
{
	return atan(-x) * 180 / M_PI + 90;
}

int
main(void)
{
	printf("%.0f\n", convert(0));
	printf("%.0f\n", convert(1));
	printf("%.0f\n", convert(-1));
	printf("%.0f\n", convert(3));
	printf("%.0f\n", convert(100));
	printf("%.0f\n", convert(-20));
	return 0;
}
