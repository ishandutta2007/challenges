/*

Chefland has 2 different types of coconut, type A and type B. Type A contains only xa milliliters of coconut water and type B contains only xb grams of coconut pulp.
Chef's nutritionist has advised him to consume Xa milliliters of coconut water and Xb grams of coconut pulp every week in the summer.
Find the total number of coconuts (type A + type B) that Chef should buy each week to keep himself active in the hot weather.

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, four integers xa, xb, Xa, Xb.

Output

For each test case, output in a single line the answer to the problem.

Constraints

1≤T≤15000
100≤xa≤200
400≤xb≤500
1000≤Xa≤1200
1000≤Xb≤1500
xa divides Xa.
xb divides Xb.

*/

#include <assert.h>

int
coconuts(int a, int b, int A, int B)
{
	if (a == 0 || b == 0)
		return 0;
	return (A / a) + (B / b);
}

int
main(void)
{
	assert(coconuts(100, 400, 1000, 1200) == 13);
	assert(coconuts(100, 450, 1000, 1350) == 13);
	assert(coconuts(150, 400, 1200, 1200) == 11);

	return 0;
}
