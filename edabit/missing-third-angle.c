/*

You are given 2 out of 3 of the angles in a triangle, in degrees.

Write a function that classifies the missing angle as either "acute", "right", or "obtuse" based on its degrees.

An acute angle is less than 90 degrees.
A right angle is exactly 90 degrees.
An obtuse angle is greater than 90 degrees (but less than 180 degrees).

For example: missing_angle(11, 20) should return "obtuse",
since the missing angle would be 149 degrees, which makes it obtuse.

Notes

The sum of angles of any triangle is always 180 degrees.

*/

#include <stdio.h>

const char *
missangle(int a, int b)
{
	int c;

	c = 180 - (a + b);
	if (c < 90)
		return "acute";
	if (c == 90)
		return "right";
	return "obtuse";
}

int
main(void)
{
	printf("%s\n", missangle(27, 59));
	printf("%s\n", missangle(135, 11));
	printf("%s\n", missangle(45, 45));
	printf("%s\n", missangle(45, 15));
	printf("%s\n", missangle(31, 100));
	printf("%s\n", missangle(35, 55));
	return 0;
}
