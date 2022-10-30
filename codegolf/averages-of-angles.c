/*

Story, or why we are doing this.
None. This exercise is completely pointless ... unless you are Stephen Hawking.

The Challenge
Given a list of angles, find the average of those angles. For example the average of 91 degrees and -91 degrees is 180 degrees. You can use a program or function to do this.

Input
A list of degree values representing angle measures. You may assume that they will be integers. They can be inputted in any convenient format or provided as function arguments.

Output

The average of the inputted values. If there are more than one value found for the average, only one should be outputted. The average is defined as the value for which

Sum[j] angularDistance(average, angle)^2

is minimized. The output must be within the range of (-180, 180] and be accurate to at least two places behind the decimal point.

Examples:

> 1 3
2
> 90 -90
0 or 180
> 0 -120 120
0 or -120 or 120
> 0 810
45
> 1 3 3
2.33
> 180 60 -60
180 or 60 or -60
> 0 15 45 460
40
> 91 -91
180
> -89 89
0
As usual with codegolf, the submission with the least bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <float.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
full(double x)
{
	while (x < 0)
		x += 360;
	x = fmod(x, 360);
	return x;
}

double
half(double x)
{
	x = fmod(x, 360);
	if (x > 180)
		x -= 360;
	return x;
}

double
angle(int *a, size_t n, double s)
{
	double r, x, y;
	double m, v;
	size_t i;

	m = DBL_MAX;
	for (x = 0; x <= 360; x += s) {
		v = 0;
		for (i = 0; i < n; i++) {
			y = full(a[i]);
			v += (x - y) * (x - y);
		}
		if (v < m) {
			m = v;
			r = x;
		}
	}
	return half(r);
}

void
test(int *a, size_t n, double r)
{
	static const double eps = 1e-2;
	double p;

	p = angle(a, n, eps);
	printf("%.2f\n", p);
	assert(fabs(p - r) < eps);
}

int
main(void)
{
	int a1[] = {1, 3};
	int a2[] = {90, -90};
	int a3[] = {0, -120, 120};
	int a4[] = {0, 810};
	int a5[] = {1, 3, 3};
	int a6[] = {180, 60, -60};
	int a7[] = {0, 15, 45, 460};
	int a8[] = {91, -91};
	int a9[] = {-89, 89};

	test(a1, nelem(a1), 2);
	test(a2, nelem(a2), 180);
	test(a3, nelem(a3), 120);
	test(a4, nelem(a4), 45);
	test(a5, nelem(a5), 2.33);
	test(a6, nelem(a6), 180);
	test(a7, nelem(a7), 40);
	test(a8, nelem(a8), 180);
	test(a9, nelem(a9), 180);

	return 0;
}
