/*

A company makes triangle-shaped ornaments for the upcoming holidays.
Each ornament is tied at one of its corners to a rod using a string of unknown length.
Multiple of these ornaments may be attached to the same rod.
These ornaments should be able to swing (rotate around the axis formed by the string) without interfering with each other.

Write a program that computes the minimum required length for the rod, given a list of triangles!

Input

The input consists of a single test case. The first line contains one integer N (0<N≤100), denoting the number of triangles.
The next N lines each contain three integers A,B,C denoting the lengths of the three sides of each triangle.
The triangle will hang from the corner between sides A and B. You are guaranteed that A,B,C form a triangle that has an area that is strictly greater than zero.

Output

Output the required length L such that all triangles can be hung from the rod, no matter how long or short each triangle’s string is. No triangle should swing beyond the rod’s ends.
You may ignore the thickness of each ornament, the width of the string and you may assume that the string is attached exactly to the triangle’s end point.

Your answer should be accurate to within an absolute or relative error of 10^-4.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
swap(double *x, double *y)
{
	double t;

	t = *y;
	*y = *x;
	*x = t;
}

double
rodlength(int t[][3], size_t n)
{
	double a2, b2, c2;
	double a, b, c;
	double r, x;
	size_t i;

	r = 0;
	for (i = 0; i < n; i++) {
		a = t[i][0];
		b = t[i][1];
		c = t[i][2];
		if (a == b) {
			r += c;
			continue;
		}

		if (a < b)
			swap(&a, &b);

		a2 = a * a;
		b2 = b * b;
		c2 = c * c;
		x = a2 - b2;
		r += sqrt(c2 - (x * x) / ((2 * a2) + (2 * b2) - c2));
	}
	return r;
}

void
test(int t[][3], size_t n, double r)
{
	double p;

	p = rodlength(t, n);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-12);
}

int
main(void)
{
	int t1[][3] = {
	    {3, 3, 3},
	    {4, 4, 5},
	};

	int t2[][3] = {
	    {3, 3, 3},
	    {4, 5, 4},
	};

	int t3[][3] = {
	    {7, 20, 14},
	    {7, 14, 20},
	    {14, 20, 7},
	};

	test(t1, nelem(t1), 8);
	test(t2, nelem(t2), 6.843530573929037);
	test(t3, nelem(t3), 20.721166413503266);

	return 0;
}
