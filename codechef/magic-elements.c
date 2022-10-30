/*

You are given an array A with size N and a number K. Let's call a position i (1 ≤ i ≤ N) valid if, after increasing Ai by K, it would be greater than the sum of all other elements in the array A.

Determine the number of distinct valid positions.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains N space-separated integers A1, A2, ..., AN.

Output

For each test case, print a single line containing one integer — the number of valid positions.

Constraints
1 ≤ T ≤ 100,000
1 ≤ N ≤ 100,000
1 ≤ K ≤ 10^9
1 ≤ Ai ≤ 10^4 for each valid i
1 ≤ sum of N over all test cases ≤ 100,000

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

vlong
positions(vlong *a, size_t n, vlong k)
{
	vlong r, s;
	size_t i;

	s = 0;
	for (i = 0; i < n; i++)
		s += a[i];

	r = 0;
	for (i = 0; i < n; i++) {
		if (s - a[i] < a[i] + k)
			r++;
	}
	return r;
}

int
main(void)
{
	vlong a1[] = {2, 1, 6, 7};
	vlong a2[] = {2, 1, 5, 4};

	assert(positions(a1, nelem(a1), 4) == 1);
	assert(positions(a2, nelem(a2), 2) == 0);

	return 0;
}
