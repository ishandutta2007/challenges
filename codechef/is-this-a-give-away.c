/*

You are given two integers l and r.
You have to choose k real numbers in the interval [l,r] uniform randomly.
What is the expected count of distinct numbers chosen by you?

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains three space-separated integers l, r and k.

Output

For each test case, print a single line containing one integer - the expected count of distinct numbers chosen. It can be proved that the expected count is always an integer.

Constraints
1≤T≤10^5
1≤k≤100
1≤l≤r≤100

*/

#include <assert.h>
#include <stdio.h>

int
expected(int l, int r, int k)
{
	return (l == r) ? 1 : k;
}

int
main(void)
{
	assert(expected(3, 6, 4) == 4);
	assert(expected(1, 3, 1) == 1);
	assert(expected(6, 7, 2) == 2);

	return 0;
}
