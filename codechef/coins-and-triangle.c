/*

Chef belongs to a very rich family which owns many gold mines. Today, he brought N gold coins and decided to form a triangle using these coins. Isn't it strange?

Chef has a unusual way of forming a triangle using gold coins, which is described as follows:

    He puts 1 coin in the 1st row.
    then puts 2 coins in the 2nd row.
    then puts 3 coins in the 3rd row.
    and so on as shown in the given figure.

Chef is interested in forming a triangle with maximum possible height using at most N coins. Can you tell him the maximum possible height of the triangle?

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

int
form(int n)
{
	double l;
	quadratic(1, 1, -2 * n, &l, &l);
	return (int)l;
}

int
main(void)
{
	printf("%d\n", form(3));
	printf("%d\n", form(5));
	printf("%d\n", form(7));
	printf("%d\n", form(5050));
	printf("%d\n", form(21));
	printf("%d\n", form(25));
	return 0;
}
