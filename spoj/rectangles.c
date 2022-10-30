/*

Byteman has a collection of N squares with side 1. How many different rectangles can he form using these squares?

Two rectangles are considered different if none of them can be rotated and moved to obtain the second one. During rectangle construction, Byteman can neither deform the squares nor put any squares upon any other ones.

Input
The first and only line of the standard input contains one longeger N (1 <= N <= 10000).

Output
The first and only line of the standard output should contain a single longeger equal to the number of different rectangles that Byteman can form using his squares.

*/

#include <assert.h>
#include <stdio.h>

long
rectangles(long n)
{
	long c, i, j;

	c = 0;
	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j++) {
			if (i * j <= n)
				c++;
		}
	}
	return c;
}

int
main(void)
{
	assert(rectangles(6) == 8);
	assert(rectangles(10000L) == 46884L);

	return 0;
}
