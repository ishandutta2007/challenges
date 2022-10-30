/*

Chef taught his brother Chefu about right angled triangle and its properties.
Chefu says that he has understood everything about right angled triangles.
Chef wants to check learning of his brother by asking the following question "Can you find a right angled triangle whose length of hypotenuse is H and its area is S?"

Chefu is confused how to solve it. I hope you are not. Please solve this by finding a right angled triangle with hypotenuse H and area S. If it not possible to do so, then output -1.

*/
#include <stdio.h>
#include <math.h>

int
quadratic(double a, double b, double c, double *x1, double *x2)
{
	double d;

	d = b * b - 4 * a * c;
	if (d < 0)
		return 0;
	d = sqrt(d);
	*x1 = (-b - d) / (2 * a);
	*x2 = (-b + d) / (2 * a);
	return 1;
}

/*

s = ab/2
a^2 + b^2 = h^2

s^2 = a^2b^2/4
a^2 = 4s^2/b^2
4s^2/(b^2) + b^2 = h^2

4s^2 + b^4 = h^2*b^2
b^4 - b^2h^2 + 4s^2 = 0 (quadratic equation)
since this is symmetrical for a and b, the 2 coefficients
of the quadratic equation corresponds to a and b

*/

void
find(double h, double s)
{
	double a, b;

	if (!quadratic(1, -h * h, 4 * s * s, &a, &b)) {
		printf("-1\n");
		return;
	}
	a = sqrt(a);
	b = sqrt(b);
	printf("%lf %lf %lf\n", a, b, h);
}

int
main(void)
{
	find(5, 6);
	find(6, 10);
	find(258303, 89837245228);
	find(616153, 77878145466);
	return 0;
}
