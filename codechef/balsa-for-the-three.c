/*

It's well known that our friend Balsa likes the digit 3 very much. He's so obsessed with this digit that he spends time thinking about it even during holidays.

Today, Balsa invented an interesting problem: For a positive integer N, find the smallest integer greater than N such that its decimal representation contains the digit 3 at least three times.

You are given the integer N. Please solve this problem for Balsa.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N.

Output

For each test case, print a single line containing one integer — the smallest number greater than N containing the digit 3 at least three times.

Constraints
1≤T≤40
1≤N≤2⋅10^9

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

typedef unsigned long long uvlong;

uvlong
check(uvlong n)
{
	uvlong c;

	for (c = 0; n > 0; n /= 10)
		c += ((n % 10) == 3);
	return c >= 3;
}

uvlong
solve(uvlong n)
{
	for (;;) {
		if (n == ULLONG_MAX)
			break;

		if (check(++n))
			return n;
	}
	return 0;
}

int
main(void)
{
	assert(solve(221) == 333);
	assert(solve(333) == 1333);
	assert(solve(3002) == 3033);

	return 0;
}
