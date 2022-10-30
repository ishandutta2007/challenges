/*

Write a function that checks if two numbers are:

    Smaller than 0
    Greater than 0
    Exactly 0

Notes

Inputs will always be two numbers.

*/

#include <stdio.h>

int
sign(double x)
{
	if (x < 0)
		return -1;
	if (x == 0)
		return 0;
	return 1;
}

int
both(double a, double b)
{
	return sign(a) == sign(b);
}

int
main(void)
{
	printf("%d\n", both(6, 2));
	printf("%d\n", both(-6, -9));
	printf("%d\n", both(6, -2));
	printf("%d\n", both(0, 0));
	printf("%d\n", both(100, 1));
	printf("%d\n", both(-0, 0));
	printf("%d\n", both(-80, -5000));
	printf("%d\n", both(6.28, -999));
	printf("%d\n", both(-1, 2));
	printf("%d\n", both(0, 2));

	return 0;
}
