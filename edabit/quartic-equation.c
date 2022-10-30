/*

Create a function that returns the number of (real) solutions of ax^4+bx^2+c=0.
The function will take three arguments: a as the coefficient of x^4, b as the coefficient of x^2, and c as the constant term.

Examples

quartic_equation(1, -5, 4) ➞ 4

quartic_equation(4, 3, -1) ➞ 2

quartic_equation(1, 10, 9) ➞ 0

Notes

Hint: Try substitution t=x^2.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
quartic(int a, int b, int c)
{
	double z[2], sd;
	int d, i, r;

	d = b * b - 4 * a * c;
	if (d < 0)
		return 0;
	if (d == 0)
		return 1;

	sd = sqrt(d);
	z[0] = -b + sd;
	z[1] = -b - sd;

	r = 0;
	for (i = 0; i < 2; i++) {
		if (z[i] > 0)
			r += 2;
		else if (z[i] == 0)
			r += 1;
	}

	return r;
}

int
main(void)
{
	assert(quartic(1, -5, 4) == 4);
	assert(quartic(4, 3, -1) == 2);
	assert(quartic(1, 10, 9) == 0);
	assert(quartic(4, -11, 6) == 4);
	assert(quartic(6, 19, -7) == 2);
	assert(quartic(9, -4, 0) == 3);
	assert(quartic(1, 1, 0) == 1);

	return 0;
}
