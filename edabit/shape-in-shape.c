/*

For math class, Matt needs to find out if a shape can fit inside another shape, based solely on their area. The only problem is, HE SUCKS AT MATH! He has asked you, his older brother, to make a program that will answer all his math questions.

Write a function that takes two shapes, with different inputs, and returns true if the second shape has an area smaller than the first.

The inputs will be in a standardized format per shape:

    "Circle, radius"
    "Triangle, Base, Height"
    "Rectangle, Width, Length (if different than Width) "
    "Pentagon, Side"

Notes

Remember, the first item in each string will be the name of the shape, and all relevant data will be provided following said name.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <math.h>

double
area(const char *s)
{
	double x[2];

	if (sscanf(s, "Circle, %lf", &x[0]) == 1)
		return M_PI * x[0] * x[0];

	if (sscanf(s, "Triangle, %lf, %lf", &x[0], &x[1]) == 2)
		return x[0] * x[1] / 2;

	if (sscanf(s, "Rectangle, %lf, %lf", &x[0], &x[1]) == 2)
		return x[0] * x[1];

	if (sscanf(s, "Rectangle, %lf", &x[0]) == 1)
		return x[0] * x[0];

	if (sscanf(s, "Pentagon, %lf", &x[0]) == 1)
		return sqrt(5 * (5 + 2 * sqrt(5))) * x[0] * x[0] / 4;

	return 0;
}

int
shapeinshape(const char *a, const char *b)
{
	return area(a) > area(b);
}

int
main(void)
{
	printf("%d\n", shapeinshape("Circle, 3", "Rectangle, 3, 14"));
	printf("%d\n", shapeinshape("Circle, 5", "Rectangle, 3, 14"));
	printf("%d\n", shapeinshape("Triangle, 5, 5", "Circle, 2"));
	printf("%d\n", shapeinshape("Triangle, 10, 5", "Circle, 2"));
	printf("%d\n", shapeinshape("Circle, 10", "Pentagon, 10"));
	printf("%d\n", shapeinshape("Pentagon, 10", "Circle, 10"));
	return 0;
}
