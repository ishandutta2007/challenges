/*

Given two numbers r and n on separate lines, write a program to print n natural numbers starting from 1 onwards, excluding the r-th powers. For example,

If r=2 and n=10, the results would be 2,3,5,6,7,8,10,11,12,13

4 and 9 were excluded because 4 is 2^2 and 9 is 3^2

Sample Input
2
10
Sample Output
2 3 5 6 7 8 10 11 12 13

Sample Input
3
30
Sample Output
2 3 4 5 6 7 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 28 29 30 31 32 33

    1 < r < 10
    0 < n < 1,000,000

    Since nobody came up with this, here's a hint to reduce your solution sizes:

    The ith term of the output is given by floor(i+pow(i+pow(i,1/r), 1/r)).

*/

#include <stdio.h>
#include <math.h>

void
gen(unsigned r, unsigned n)
{
	unsigned i;

	for (i = 1; i <= n + 2; i++)
		printf("%.0f ", floor(i + pow(i + pow(i, 1 / r), 1 / r)));
	printf("\n");
}

int
main(void)
{
	gen(2, 10);
	gen(3, 30);

	return 0;
}
