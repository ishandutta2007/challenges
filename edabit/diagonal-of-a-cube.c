/*

Create a function that takes the volume of a cube and returns the length of the cube's main diagonal, rounded to two decimal places.

Examples

cubeDiagonal(8) ➞ 3.46

cubeDiagonal(343) ➞ 12.12

cubeDiagonal(1157.625) ➞ 18.19

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define SQRT3 1.732050807568877293527446341505872366942805253810380628055806

double
diagonal(double v)
{
	return SQRT3 * cbrt(v);
}

void
eq(double x, double y)
{
	assert(fabs(x - y) < 1e-2);
}

int
main(void)
{
	eq(diagonal(8), 3.46);
	eq(diagonal(343), 12.12);
	eq(diagonal(1157.625), 18.19);
	eq(diagonal(12), 3.97);
	eq(diagonal(1), 1.73);
	eq(diagonal(48), 6.29);
	eq(diagonal(1728), 20.78);

	return 0;
}
