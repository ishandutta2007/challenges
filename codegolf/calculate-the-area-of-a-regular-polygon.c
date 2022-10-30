/*

Given an integer, n, where 3 <= n < 2^32, calculate the area of a regular n-gon with an apothem of 1; the formula for which is n * tan(π / n). For those that don't know what the apothem is:

    The apothem of a regular polygon is a line segment from the center to the midpoint of one of its sides.

Output the area of the n-gon as a floating point with no less than 8 decimal places.
Test cases

3
5.1961524227

6
3.4641016151

10
3.2491969623

20
3.1676888065

99
3.1426476062

1697
3.1415962425

15000
3.1415926995

Note: The test cases above include 2 more digits than you are required to output.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

double
area(double n)
{
	if (n < 3)
		return 0;
	return n * tan(M_PI / n);
}

void
test(double n, double r)
{
	double p;

	p = area(n);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-8);
}

int
main(void)
{
	test(3, 5.1961524227);
	test(6, 3.4641016151);
	test(10, 3.2491969623);
	test(20, 3.1676888065);
	test(99, 3.1426476062);
	test(1697, 3.1415962425);
	test(15000, 3.1415926995);

	return 0;
}
