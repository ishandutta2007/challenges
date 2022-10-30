/*

The special task force Sed managed to obtain a sequence of positive integers A1,A2,…,AN.

You may perform the following operation any number of times (possibly zero):

Choose any element of the current sequence and replace it by any positive integer.

You need to make the sum of the elements of the sequence divisible by a given positive integer K. Find the minimum number of operations you need to perform to achieve this.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains N space-separated integers A1,A2,…,AN.

Output

For each test case, print a single line containing one integer ― the minimum required number of operations.

Constraints
1≤T≤1,000
1≤N≤100
1≤K≤10^5
1≤Ai≤10^5 for each valid  i

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
operations(uvlong *a, size_t n, uvlong k)
{
	size_t i;
	uvlong s;

	s = 0;
	for (i = 0; i < n; i++)
		s += a[i];

	return (k) ? (s % k) != 0 : 0;
}

int
main(void)
{
	uvlong a1[] = {1, 1, 1};
	uvlong a2[] = {1, 1, 1};
	uvlong a3[] = {1, 2, 3, 4, 5};

	assert(operations(a1, nelem(a1), 2) == 1);
	assert(operations(a2, nelem(a2), 3) == 0);
	assert(operations(a3, nelem(a3), 5) == 0);

	return 0;
}
