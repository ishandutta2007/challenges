/*

There is a series, S, where the next term is the sum of pervious three terms. Given the first three terms of the series, a, b, and c
respectively, you have to output the nth term of the series using recursion.

Recursive method for calculating nth term is given below.
S(n) = a -> n = 1
       b -> n = 2
	   c -> n = 3
	   S(n-1) + S(n-2) + S(n-3) otherwise

*/
#include <stdio.h>

int
nth(int n, int a, int b, int c)
{
	if (n <= 0)
		return 0;

	if (n == 1)
		return a;
	if (n == 2)
		return b;
	if (n == 3)
		return c;

	return nth(n - 1, a, b, c) + nth(n - 2, a, b, c) + nth(n - 3, a, b, c);
}

int
main(void)
{
	int i;
	for (i = 0; i < 32; i++)
		printf("%d %d\n", i, nth(i, 1, 2, 3));
	return 0;
}
