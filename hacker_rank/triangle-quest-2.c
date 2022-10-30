/*

You are given a positive integer N. 
Your task is to print a palindromic triangle of size N.

For example, a palindromic triangle of size 5 is:

1
121
12321
1234321
123454321

*/

#include <stdio.h>

void
paltri(int n)
{
	int i, j;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++)
			printf("%d", j);
		for (j = i - 1; j > 0; j--)
			printf("%d", j);
		printf("\n");
	}
}

int
main(void)
{
	paltri(5);
	return 0;
}
