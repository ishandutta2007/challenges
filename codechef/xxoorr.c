/*

Given an array A1,A2…AN, find the minimum number of operations (possibly zero) required to convert all integers in A to 0.

In one operation, you

choose a non-negative integer p (p≥0),
select at most K indices in the array A, and
for each selected index i, replace Ai with Ai⊕2p. Here, ⊕ denotes bitwise XOR.

Input

The first line contains an integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains two integers N, K - the size of the array and the maximum number of elements you can select in an operation.
The second line of each test case contains N integers A1,A2…AN.

Output

For each test case, output the minimum number of operations to make all elements of the array 0.

Constraints
1≤T≤10^5
1≤N,K≤10^5
0≤Ai≤10^9
The sum of N over all test cases does not exceed 2⋅10^5

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
count(uvlong *a, size_t n, uvlong k)
{
	uvlong b, c;
	uvlong i, j;
	uvlong r;

	r = 0;
	b = sizeof(b) * CHAR_BIT;
	for (i = 0; i < b; i++) {
		c = 0;
		for (j = 0; j < n; j++) {
			if (a[j] == 0)
				continue;

			c += (a[j] & 1);
			a[j] >>= 1;
		}
		r += (c + k - 1) / k;
	}
	return r;
}

int
main(void)
{
	uvlong a1[] = {3, 6, 10};

	assert(count(a1, nelem(a1), 2) == 5);

	return 0;
}
