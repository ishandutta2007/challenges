/*

In a coding contest, there are prizes for the top rankers. The prize scheme is as follows:

Top 10 participants receive rupees X each.

Participants with rank 11 to 100 (both inclusive) receive rupees Y each.
Find the total prize money over all the contestants.

Input Format

First line will contain T, number of test cases. Then the test cases follow.
Each test case contains of a single line of input, two integers X and Y - the prize for top 10 rankers and the prize for ranks 11 to 100 respectively.

Output Format

For each test case, output the total prize money over all the contestants.

Constraints
1≤T≤1000
1≤Y≤X≤1000

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
money(uvlong x, uvlong y)
{
	return (10 * x) + (90 * y);
}

int
main(void)
{
	assert(money(1000, 100) == 19000);
	assert(money(1000, 1000) == 100000ULL);
	assert(money(80, 1) == 890);
	assert(money(400, 30) == 6700);

	return 0;
}
