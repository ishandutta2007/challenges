/*

Measuring the area of a certain shape is an important part of certain geometric problems.
When the shape becomes complex it often becomes very difficult to measure the area of that geometric shape.
In some of these cases some randomized algorithms helps us immensely to find the area roughly.
In this problem we will find such an area with randomized algorithm.
Look at the picture on the right.
ABCD is a square whose sides are a.
A circle is drawn (1/4 th of a circle I should say) considering A as its center.
Its radius is a. Three similar circles are drawn considering B, C, D as centers.
Using an algorithm based on random numbers (The random number generator may be biased) you will have to find the area of the striped region.
The idea is that you will be given N pairs of random coordinates within the rectangle.
If M of them are within the striped region then the approximate area of the striped region A = M ∗ a ∗ a/N.
You are to find the approximate area using this concept.

Input

The input file contains several sets of inputs. The description of each set is given below.
The first line of each set contains two integers N (N can always be written in the form 10^k where k is a non-negative integer less than 6), a (100 > a ≥ 10).
Each of the next N lines contains two floating point numbers, which indicates the coordinate of a point.
These floating-point numbers always have seven digits after the decimal point and the coordinates are always within the rectangle.
Points just on the boundaries of the striped region are considered within the striped region. Points just outside are considered out of the striped region and vice versa.
Assume that the lower left corner of the rectangle is (0, 0) and top right corner is (a, a) as shown in the figure above.
Input is terminated by a set whose N is zero.

Output

For each of input you should produce one line of output. This line should contain the area of the striped
region according to the formula specified above. Your answer must be exact and no floating-point errors
will be tolerated. That means precision of calculation must be infinite or precision error must be zero.
Output numbers should always have five digits after the decimal point.

Sample Input
1 10
5.0000000 5.0000000
0 0

Sample Output
100.00000

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	double x, y;
} Point;

double
distance(double x1, double x2, double y1, double y2)
{
	return hypot(x1 - x2, y1 - y2);
}

bool
inside(double x, double y, double z)
{
	if (distance(0, x, 0, y) > z)
		return false;
	if (distance(z, x, 0, y) > z)
		return false;
	if (distance(z, x, z, y) > z)
		return false;
	if (distance(0, x, z, y) > z)
		return false;
	return true;
}

double
area(Point *p, size_t n, double z)
{
	size_t i;
	double c;

	c = 0;
	for (i = 0; i < n; i++) {
		if (inside(p[i].x, p[i].y, z))
			c++;
	}
	return (c * z * z) / n;
}

void
test(Point *p, size_t n, double z, double r)
{
	double u;

	u = area(p, n, z);
	printf("%f\n", u);
	assert(fabs(u - r) < 1e-6);
}

int
main(void)
{
	Point p1[] = {{5, 5}};

	test(p1, nelem(p1), 10, 100);
	return 0;
}
