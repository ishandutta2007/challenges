/*

Write a function that accepts base (decimal), height (decimal) and shape ("triangle", "parallelogram")
as input and calculates the area of that shape.
Examples

areaShape(2, 3, "triangle") ➞ 3

areaShape(8, 6, "parallelogram") ➞ 48

areaShape(2.9, 1.3, "parallelogram") ➞ 3.77

Notes

    Area of a triangle is 0.5 * b * h
    Area of a parallelogram is b * h

*/

#include <assert.h>
#include <string.h>
#include <math.h>

double
areashape(double b, double h, const char *t)
{
	if (!strcmp(t, "triangle"))
		return 0.5 * b * h;
	else if (!strcmp(t, "parallelogram"))
		return b * h;
	return -1;
}

void
eq(double x, double y)
{
	assert(fabs(x - y) < 1e-10);
}

int
main(void)
{
	eq(areashape(2, 3, "triangle"), 3);
	eq(areashape(8, 6, "parallelogram"), 48);
	eq(areashape(0, 1, "triangle"), 0);
	eq(areashape(2.9, 1.3, "parallelogram"), 3.77);
	eq(areashape(0.01, 5, "triangle"), 0.025);

	return 0;
}
