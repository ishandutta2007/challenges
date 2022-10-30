/*

Given a positive integer N you will have to find two positive integers x and y such that: N = x^3 − y^3

Input
The input file contains at most 100 lines of inputs. Each line contains a positive integer N (0 < N ≤ 10000). Input is terminated by a line containing a single zero. This line should not be processed.

Output
For each line of input produce one or more lines of output. Each of these lines contains two positive integers x, y separated by a single space, such that N = x^3 − y^3.
If there is no such integer values of x and y then produce the line ‘No solution’ instead.
If there is more than one solution then output the one with smallest value of y.

Sample Input
7
37
12
0

Sample Output
2 1
4 3
No solution

*/

#include <stdio.h>

typedef unsigned long long uvlong;

int
solvable(uvlong n, uvlong *x, uvlong *y)
{
	uvlong a, b;

	*x = *y = 0;
	for (a = 0; a < n; a++) {
		for (b = a; b < n; b++) {
			if (((b * b * b) - (a * a * a)) == n) {
				*x = b;
				*y = a;
				return 1;
			}
		}
	}
	return 0;
}

void
test(uvlong n)
{
	uvlong x, y;
	int r;

	r = solvable(n, &x, &y);
	printf("%d %llu %llu\n", r, x, y);
}

int
main(void)
{
	test(7);
	test(37);
	test(12);

	return 0;
}
