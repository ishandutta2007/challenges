/*

GreatCircle.java

This exercise demonstrates the use of the double data type and Java’s Math library.
The great circle distance is the shortest distance between two points on the surface of a sphere if you are constrained to travel along the surface.
Write a program GreatCircle.java that takes four double command-line arguments x1, y1, x2, and y2 (the latitude and longitude, in degrees, of two points on the surface of the earth)
and prints the great circle distance (in nautical miles) between them. Use the following formula, which is derived from the spherical law of cosines:

distance = 60 * acos(sin(x1)sin(x2)+cos(x1)cos(x2)cos(y1-y2))

This formula uses degrees, whereas Java's trigonometric functions use radians.
Use Math.toRadians() and Math.toDegrees() to convert between the two.
For reference, a nautical mile (approximately 1.151 regular miles) is 1/60 of a degree of an arc along a meridian of the Earth,
and this is the reason for the 60 in the formula.

Examples:

> java-introcs GreatCircle 40.35 74.65 48.87 -2.33      // Princeton to Paris
3185.1779271158425 nautical miles

> java-introcs GreatCircle 48.87 -2.33 40.35 74.65      // Paris to Princeton
3185.1779271158425 nautical miles

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define deg2rad(x) ((x)*M_PI / 180)
#define rad2deg(x) ((x)*180 / M_PI)

double
distance(double x1, double y1, double x2, double y2)
{
	double u1, v1, u2, v2;

	u1 = deg2rad(x1);
	v1 = deg2rad(y1);
	u2 = deg2rad(x2);
	v2 = deg2rad(y2);
	return 60 * rad2deg(acos(sin(u1) * sin(u2) + cos(u1) * cos(u2) * cos(v2 - v1)));
}

int
main(int argc, char *argv[])
{
	if (argc != 5) {
		fprintf(stderr, "usage: x1 y1 x2 y2\n");
		return 1;
	}
	printf("%.13f nautical miles\n", distance(atof(argv[1]), atof(argv[2]), atof(argv[3]), atof(argv[4])));
	return 0;
}
