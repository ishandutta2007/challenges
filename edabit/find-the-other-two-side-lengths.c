/*

Given the shortest side of a 30° by 60° by 90° triangle you have to find out the other 2 sides, (return the longest side, medium-length side).
Examples

otherSides(1) ➞ [2.0, 1.73]

otherSides(12) ➞ [24.0, 20.0]

otherSides(2) ➞ [4.0, 3.46]

otherSides(3) ➞ [6.0, 5.2]

Notes

    30° by 60° by 90° triangles always follow this rule, let's say the shortest side length is x units, the hypotenuse would be 2x units and the other side would be x * root3 units.
    The results in the Tests are rounded up to 2 decimal places.
    Return the result as an array.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define SQRT3 1.732050807568877293527446341505872366942805253810380628055806

void
othersides(double s, double r[2])
{
	r[0] = s * 2;
	r[1] = s * SQRT3;
}

void
test(double s, double r[2])
{
	static const double eps = 1e-2;
	double v[2];

	othersides(s, v);
	assert(fabs(v[0] - r[0]) < eps);
	assert(fabs(v[1] - r[1]) < eps);
}

int
main(void)
{
	test(1, (double[]){2.0, 1.73});
	test(12, (double[]){24.0, 20.78});
	test(2, (double[]){4.0, 3.46});
	test(3, (double[]){6.0, 5.2});
	test(1, (double[]){2, 1.73});
	test(5, (double[]){10, 8.66});
	test(7, (double[]){14, 12.12});
	test(17, (double[]){34, 29.44});

	return 0;
}
