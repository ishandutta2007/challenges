/*

Mubashir needs your help in a simple task.

Create a function which takes a number n and return its decimal part.

Examples

decimal_part(1.2) ➞ 0.2

decimal_part(-3.73) ➞ 0.73

decimal_part(10) ➞ 0

Notes

    Don't forget to return the result.
    If you get stuck on a challenge, find help in the Resources tab.
    If you're really stuck, unlock solutions in the Solutions tab.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
decimal(double x)
{
	double i, f;

	f = modf(x, &i);
	if (x < 0)
		f = -f;
	return f;
}

void
test(double x, double r)
{
	assert(fabs(decimal(x) - r) < 1e-8);
}

int
main(void)
{
	test(-3.73, 0.73);
	test(10, 0);
	test(-1.2, 0.2);
	test(4.5, 0.5);
	test(85824.5254243, 0.5254243);
	test(122.111111111, 0.111111111);
	test(-12.315346346, 0.315346346);
	test(5.01231, 0.01231);

	return 0;
}
