/*

Description:

An international shipping company is trying to figure out how to manufacture various types of containers. Given a volume they want to figure out the dimensions of various shapes that would all hold the same volume.
Input:

A volume in cubic meters.
Output:

Dimensions of containers of various types that would hold the volume. The following containers are possible.

    Cube

    Ball (Sphere)

    Cylinder

    Cone

Example Input:

27
Example Output:

 Cube: 3.00m width, 3.00m, high, 3.00m tall
 Cylinder: 3.00m tall, Diameter of 3.38m
 Sphere: 1.86m Radius
 Cone: 9.00m tall, 1.69m Radius

Some Inputs to test.

27, 42, 1000, 2197

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

void
cube(double v)
{
	double a;

	a = cbrt(v);
	printf("Cube: %.2fm width, %.2fm high, %.2f tall\n", a, a, a);
}

void
cylinder(double v)
{
	double h, r;

	h = cbrt(v);
	r = sqrt(v / (M_PI * h));
	printf("Cylinder: %.2fm tall, diameter of %.2fm\n", h, 2 * r);
}

void
sphere(double v)
{
	double r;

	r = cbrt(v * 3 / (4 * M_PI));
	printf("Sphere: %.2fm radius\n", r);
}

void
cone(double v)
{
	double h, r;

	h = v / 3;
	r = sqrt((v * 3) / (M_PI * h));
	printf("Cone: %.2fm tall, %.2fm radius\n", h, r);
}

void
dimension(double v)
{
	cube(v);
	cylinder(v);
	sphere(v);
	cone(v);
	printf("\n");
}

int
main(void)
{
	dimension(27);
	dimension(42);
	dimension(1000);
	dimension(2197);

	return 0;
}
