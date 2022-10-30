/*

Given the side length x find the area of a hexagon.

Formula to find the area of a hexagon
Examples

1 ➞ 2.6

2 ➞ 10.4

3 ➞ 23.4

Notes

Return null if the side length given is not a positive integer

Round to the nearest tenth

*/

#include <assert.h>
#include <math.h>

#define SQRT3 1.732050807568877293527446341505872366942805253810380628055806

double
hexarea(double x)
{
	return (x >= 0) ? (3 * SQRT3 * x * x / 2) : 0;
}

void
test(double x, double r)
{
	assert(fabs(hexarea(x) - r) <= 1e-1);
}

int
main(void)
{
	test(1, 2.6);
	test(2, 10.4);
	test(3, 23.4);
	test(4, 41.6);
	test(5, 65);
	test(0, 0);
	test(-1, 0);

	return 0;
}
