/*

Priya loves bitwise AND, but she hates programming. Help her solve this problem.

Given an array A of size N, let Bij denote the bitwise AND of A[i] and A[j]. You have to find the number of pairs (i,j), such that i<j and Bij=A[i].

Input:

The first line of the input contains a single integer T denoting the number of test cases.
The first line of each test case consists of a single integer N, denoting the Size of Array A.
The second line of each test case contains N space-separated integers A1,A2,A3...AN.

Output:

For each test case, output a single line, count of such pairs.

Constraints
1≤T≤100
1≤N≤100
1≤A[i]≤100

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
pairs(int *a, size_t n)
{
	size_t i, j;
	int c;

	c = 0;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++)
			c += (a[i] == (a[i] & a[j]));
	}
	return c;
}

int
main(void)
{
	int a1[] = {1, 1, 1, 1, 1};
	int a2[] = {10};

	assert(pairs(a1, nelem(a1)) == 10);
	assert(pairs(a2, nelem(a2)) == 0);

	return 0;
}
