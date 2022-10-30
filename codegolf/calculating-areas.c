/*

The smallest code that gives the area between the curve p(x) = a0 + a1*x + a2*x2 + ..., the line y = 0, the line x = 0 and the line x = C

(i.e. something like this: wanted area)

You can assume that p(x) >= 0 for x < C (bonus points if your code works for negative values of p(x)).

Input

C, a0, a1, ...

Output

a real number - the area

Example 1:

input: 2, 0, 1
output: 2.0

Example 2:

input: 3.0, 0, 0.0, 2
output: 18

UPDATE:

    C > 0 is also assumed
    the area is between the curve, y=0, x=C and x = 0
    the input can be a list of any form; not necessarily comma separated.
    the output can be a real of any form (thus, '18' is a valid output, as is '18.0')

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
area(double C, double *a, size_t n)
{
	double r, x;
	size_t i;

	r = 0;
	x = C;
	for (i = 0; i < n; i++) {
		r += a[i] * x / (i + 1);
		x *= C;
	}
	return r;
}

void
test(double C, double *a, size_t n, double r)
{
	double p;

	p = area(C, a, n);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-8);
}

int
main(void)
{
	double a1[] = {0, 1};
	double a2[] = {0, 0, 2};

	test(2, a1, nelem(a1), 2);
	test(3, a2, nelem(a2), 18);

	return 0;
}
