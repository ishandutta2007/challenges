/*

Create a function that takes a number and return an array of three numbers: half of the number, quarter of the number and an eighth of the number.
Examples

halfQuarterEighth(6) ➞ [3, 1.5, 0.75]

halfQuarterEighth(22) ➞ [11, 5.5, 2.75]

halfQuarterEighth(25) ➞ [12.5, 6.25, 3.125]

Notes

The order of the array is: half, quarter, eighth.

*/

#include <stdio.h>

void
hqe(double x, double a[3])
{
	a[0] = x * 0.5;
	a[1] = x * 0.25;
	a[2] = x * 0.125;
}

void
test(double x)
{
	double a[3];

	hqe(x, a);
	printf("[%.3f, %.3f, %.3f]\n", a[0], a[1], a[2]);
}

int
main(void)
{
	test(6);
	test(22);
	test(25);
	test(18);
	test(98);
	test(14);
	return 0;
}
