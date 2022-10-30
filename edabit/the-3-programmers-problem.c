/*

You hired three programmers and you (hopefully) pay them.
Create a function that takes three numbers (the hourly wage of each programmer)
and returns the difference between the highest-paid programmer and the lowest-paid.

*/

#include <stdio.h>

void
swap(int *x, int *y)
{
	int t;

	t = *x;
	*x = *y;
	*y = t;
}

int
programmers(int a, int b, int c)
{
	if (a > b)
		swap(&a, &b);
	if (a > c)
		swap(&a, &c);
	if (b > c)
		swap(&b, &c);
	return c - a;
}

int
main(void)
{
	printf("%d\n", programmers(1, 5, 9));
	printf("%d\n", programmers(43, 33, 43));
	printf("%d\n", programmers(88, 14, 23));
	printf("%d\n", programmers(33, 72, 74));
	printf("%d\n", programmers(147, 33, 526));
	printf("%d\n", programmers(234, 345, 457));
	return 0;
}
