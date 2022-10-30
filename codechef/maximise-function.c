/*

You are given a sequence A1,A2,…,AN. Find the maximum value of the expression |Ax−Ay|+|Ay−Az|+|Az−Ax| over all triples of pairwise distinct valid indices (x,y,z).

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.

Output

For each test case, print a single line containing one integer ― the maximum value of |Ax−Ay|+|Ay−Az|+|Az−Ax|.

Constraints
1≤T≤5
3≤N≤10^5
|Ai|≤10^9 for each valid i

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
maximize(int *a, size_t n)
{
	size_t i;
	int x, y;

	if (n == 0)
		return 0;

	x = INT_MAX;
	y = INT_MIN;
	for (i = 0; i < n; i++) {
		if (x > a[i])
			x = a[i];
		if (y < a[i])
			y = a[i];
	}
	return 2 * (y - x);
}

int
main(void)
{
	int a1[] = {2, 7, 5};
	int a2[] = {3, 3, 3};
	int a3[] = {2, 2, 2, 2, 5};

	assert(maximize(a1, nelem(a1)) == 10);
	assert(maximize(a2, nelem(a2)) == 0);
	assert(maximize(a3, nelem(a3)) == 6);

	return 0;
}
