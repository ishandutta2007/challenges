/*

Create a function that given a type of curve will generate an array containing a samples amount of numbers calculated from said curve.

It's easier to see with a visual representation:

If samples = 3 and curve = "pow", we would sample 3 points along the x axis [0, 0.5, 1] and figure out the value of y, in the case of the pow curve the values are [0, 0.25, 1].

Notes

    The available curves are linear, pow, sqrt as shown in the picture.
    All values returned must have a maximum of 2 decimals to avoid floating point problems in the tests.
    All values returned must be between 0 and 1 (inclusive).
    The samples parameter will always be ≥ 2.
    The samples are evenly distributed along the x axis.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double
linear(double x)
{
	return x;
}

double
square(double x)
{
	return x * x;
}

double *
samples(size_t n, const char *t)
{
	double (*f)(double);
	double *p;
	size_t i;

	if (n < 2)
		return NULL;

	if (!strcmp(t, "linear"))
		f = linear;
	else if (!strcmp(t, "pow"))
		f = square;
	else if (!strcmp(t, "sqrt"))
		f = sqrt;
	else
		return NULL;

	p = calloc(n, sizeof(*p));
	if (!p)
		return NULL;

	for (i = 0; i < n; i++)
		p[i] = f(i * 1.0 / (n - 1));
	return p;
}

void
print(double *p, size_t n)
{
	size_t i;

	printf("[");
	for (i = 0; i < n; i++) {
		printf("%.2f", p[i]);
		if (i + 1 < n)
			printf(", ");
	}
	printf("]\n");
}

void
test(size_t n, const char *t)
{
	double *p;

	p = samples(n, t);
	if (p)
		print(p, n);
	free(p);
}

int
main(void)
{
	test(2, "linear");
	test(3, "linear");
	test(11, "linear");

	test(4, "pow");
	test(5, "pow");
	test(11, "pow");

	test(6, "sqrt");
	test(7, "sqrt");
	test(11, "sqrt");

	return 0;
}
