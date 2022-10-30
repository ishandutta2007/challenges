/*

The national flag of Bangladesh is bottle green in color and rectangular in size with the length (L) to width ratio of 10:6.
It bears a red circle on the background of green. It maintains the length (L) to radius ratio of 5:1 (If the length is 10 then width should be 6 and radius should be 2).
The color in the background represents the greenery of Bangladesh while the red circle symbolizes the rising sun and the sacrifice of lives in our freedom fight.

Input

First line of input will contain the number of test cases, T ≤ 100. Then there follows T lines, each
containing a positive integer L ≤ 1000, representing length of the flag.

Output

For each test case output is a line with two space separated real numbers containing exactly two digits
after decimal point. Two numbers represent the area of red and green portion respectively.
Note: Pi is considered to be arccos(−1).

Sample Input
1
10

Sample Output
12.57 47.43

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

void
areas(double l, double *ca, double *ra)
{
	double w, r;

	w = l * 0.6;
	r = l * 0.2;
	*ra = M_PI * r * r;
	*ca = (l * w) - *ra;
}

void
test(double l, double rra, double rca)
{
	static const double eps = 1e-2;

	double ca, ra;

	areas(l, &ca, &ra);
	printf("%.2f %.2f\n", ca, ra);
	assert(fabs(rca - ca) < eps);
	assert(fabs(rra - ra) < eps);
}

int
main(void)
{
	test(10, 12.57, 47.43);

	return 0;
}
