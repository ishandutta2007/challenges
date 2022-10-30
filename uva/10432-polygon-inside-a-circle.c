/*

Consider a polygon of equal sides inside a circle as shown in the figure below.
Figure: The regular polygon inside a circle
Given the radius of the circle and number of sides. You have to find the area of the polygon.

Input
In each line there will be two numbers indicating the radius r (0 < r < 20000) and the number of sides
of the polygon n (2 < n < 20000) respectively. Input is terminated by EOF.

Output
Output the area in each line. The number must be rounded to the third digit after the decimal point.

Sample Input
2 2000
10 3000

Sample Output
12.566
314.159

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

double
area(double r, double n)
{
	return (r * r * n * sin((2 * M_PI) / n)) / 2;
}

void
test(double r, double n, double a)
{
	double p;

	p = area(r, n);
	printf("%f\n", p);
	assert(fabs(p - a) < 1e-3);
}

int
main(void)
{
	test(2, 2000, 12.566);
	test(10, 3000, 314.159);

	return 0;
}
