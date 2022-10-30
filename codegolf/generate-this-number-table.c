/*

Given an integer 1<n<10

generate a table like below.

For n=5

1 2 3 4 5
2 2 3 4 5
3 3 3 4 5
4 4 4 4 5
5 5 5 5 5

For n=8

1 2 3 4 5 6 7 8
2 2 3 4 5 6 7 8
3 3 3 4 5 6 7 8
4 4 4 4 5 6 7 8
5 5 5 5 5 6 7 8
6 6 6 6 6 6 7 8
7 7 7 7 7 7 7 8
8 8 8 8 8 8 8 8

Shortest code wins! Trailing whitespace allowed

Output format isn't strict, you can output a 2D list/matrix in any reasonable format.

*/

#include <stdio.h>

void
gen(unsigned n)
{
	unsigned i, j;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			printf("%u ", (j < i) ? i : j);
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	gen(1);
	gen(5);
	gen(8);

	return 0;
}
