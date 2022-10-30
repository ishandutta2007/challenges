/*

Bangladesh whitewashed New Zealand in the three-match one day international series defeating the visitors by four wickets in the last and final match in Narayanganj.
The Tigers scored 309 runs in 49.2 overs for the loss of six wickets at the Khan Shaheb Osman Ali Stadium in Fatullah.
The most remarkable was the performance from the batsman of tiger side. Mominul, Nasir, Naeem, Mushfiq all showed tremendous batting performance.
People call them little masters. They are clever enough to find a quick boundary.
Here we have to do a little task for our busy little masters.
We have to find out the length of the shortest and longest boundary distance from the batsman.
We know the radius of the circular stadium and the position of the batsman.
Center of the stadium is always the origin (0, 0).
Boundary means the perimeter of the circular field.

Input

Input starts with an integer T (≤ 100), denoting the number of test cases.
Each case starts with a line containing three integers x, y, r (0 ≤ x, y, r ≤ 1000).
(x, y) denotes the coordinate of the batsman. And r denotes the radius of the stadium.
You can safely assume that coordinate of the batsman will not be out of the stadium.

Output

For each case, print the shortest and longest boundary distance.
Show exactly 2 digits after decimal point, properly rounded.
See the samples for exact formatting.

Sample Input
3
0 0 100
3 4 10
5 0 5

Sample Output
100.00 100.00
5.00 15.00
0.00 10.00

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

void
boundary(double x, double y, double r, double *s, double *l)
{
	double z;

	z = hypot(x, y);
	*s = r - z;
	*l = r + z;
}

void
test(double x, double y, double r, double rs, double rl)
{
	static const double eps = 1e-2;

	double s, l;

	boundary(x, y, r, &s, &l);
	printf("%.2f %.2f\n", s, l);
	assert(fabs(rs - s) < eps);
	assert(fabs(rl - l) < eps);
}

int
main(void)
{
	test(0, 0, 100, 100, 100);
	test(3, 4, 10, 5, 15);
	test(5, 0, 5, 0, 10);

	return 0;
}
