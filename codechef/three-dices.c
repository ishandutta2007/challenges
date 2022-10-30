/*

There are three people, and each of them has an unbiased 6-sided die. The result of rolling a die will be a number between 1 and 6 (inclusive) with equal probability.

The three people throw their dice simultaneously. In this game, the third person wins only if his number is strictly greater than the sum of the other two numbers.
Given that the first person rolls the value X and the second person rolls the value Y, what is the probability the third person will win?

Input Format

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains two integers X and Y.

Output Format

For each test case, output the probability that the third person wins.

Your answer will be considered correct if its absolute error doesn't exceed 10−6.

Constraints
1≤T≤36
1≤X,Y≤6

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
probability(int x, int y)
{
	return fmax(6 - (x + y), 0) / 6;
}

void
test(int x, int y, double r)
{
	double p;

	p = probability(x, y);
	printf("%.6f\n", p);
	assert(fabs(p - r) < 1e-6);
}

int
main(void)
{
	test(1, 3, 0.333333);
	test(2, 4, 0);
	test(2, 3, 0.166666);

	return 0;
}
