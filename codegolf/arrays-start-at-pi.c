/*

Your task is to take an array of numbers and a real number and return the value at that point in the array.
Arrays start at π and are counted in π intervals. Thing is, we're actually going to interpolate between elements given the "index".
As an example:

Index:    1π   2π   3π   4π   5π   6π
Array: [ 1.1, 1.3, 6.9, 4.2, 1.3, 3.7 ]
Because it's π, we have to do the obligatory trigonometry, so we'll be using cosine interpolation using the following formula:

cos(imodπ)+12∗(α−β)+β

where:

i is the input "index"
α is the value of the element immediately before the "index"
β is the value of the element immediately after the "index"
cos takes its angle in radians
Example
Given [1.3, 3.7, 6.9], 5.3:

Index 5.3 is between 1π and 2π, so 1.3 will be used for before and 3.7 will be used for after. Putting it into the formula, we get:

cos(5.3modπ)+12∗(1.3-3.7)+3.7

Which comes out to 3.165

Notes
Input and output may be in any convenient format
You may assume the input number is greater than π and less than array length * π
You may assume the input array will be at least 2 elements long.
Your result must have at least two decimal points of precision, be accurate to within 0.05, and support numbers up to 100 for this precision/accuracy. (single-precision floats are more than sufficient to meet this requirement)
Happy Golfing!

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
interpolate(double *a, ssize_t n, double m)
{
	ssize_t i;
	double r;

	if (n == 0)
		return 0;

	i = m / (2 * M_PI);
	if (i < 0)
		return a[0];
	if (i >= n)
		return a[n - 1];

	r = (cos(fmod(m, M_PI)) + 1) * 0.5;
	r *= (a[i] - a[i + 1]);
	r += a[i + 1];
	return r;
}

void
test(double *a, ssize_t n, double m, double r)
{
	double p;

	p = interpolate(a, n, m);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-3);
}

int
main(void)
{
	double a1[] = {1.3, 3.7, 6.9};

	test(a1, nelem(a1), 5.3, 3.165);
	return 0;
}
