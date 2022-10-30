/*

A quadratic equation a x² + b x + c = 0 has either 0, 1, or 2 distinct solutions for x. Given a, b and c, you should return the number of solutions to the equation.

Notes
    You do not have to calculate the solutions, just return how many there are.
    a will always be non-zero.

*/

#include <stdio.h>

int
solutions(int a, int b, int c)
{
	int d;

	d = b * b - 4 * a * c;
	if (d < 0)
		return 0;
	if (d == 0)
		return 1;
	return 2;
}

int
main(void)
{
	printf("%d\n", solutions(1, 0, -1));
	printf("%d\n", solutions(1, 0, 0));
	printf("%d\n", solutions(1, 0, 1));
	printf("%d\n", solutions(200, 420, 800));
	printf("%d\n", solutions(200, 420, -800));
	printf("%d\n", solutions(1000, 1000, 0));
	printf("%d\n", solutions(10000, 400, 4));
	return 0;
}
