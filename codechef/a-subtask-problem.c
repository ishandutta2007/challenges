/*

Chef recently solved his first problem on CodeChef. The problem he solved has N test cases. He gets a score for his submission according to the following rules:

1) If Chef’s code passes all the N test cases, he gets 100 points.

2) If Chef’s code does not pass all the test cases, but passes all the first M(M<N) test cases, he gets K(K<100) points.

3) If the conditions 1 and 2 are not satisfied, Chef does not get any points (i.e his score remains at 0 points).

You are given a binary array A1,A2,…,AN of length N, where Ai=1 denotes Chef's code passed the ith test case, Ai=0 denotes otherwise.
You are also given the two integers M,K. Can you find how many points does Chef get?

Input Format

First line will contain T, number of testcases. Then the testcases follow.
The first line of each test case contains three space-separated integers N,M,K.
The second line contains N space-separated integer A1,A2,…,AN.

Output Format

For each testcase, output in a single line the score of Chef.

Constraints

1≤T≤100
2≤N≤100
1≤M<N
1≤K<100
0≤Ai≤1

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned
points(unsigned *a, size_t n, unsigned m, unsigned k)
{
	unsigned r, v;
	size_t i;

	r = 0;
	v = 0;
	for (i = 0; i < n; i++) {
		v += a[i];
		if (i == m - 1 && v == m)
			r = k;
	}
	if (v == n)
		r = 100;

	return r;
}

int
main(void)
{
	unsigned a1[] = {1, 0, 1, 1};
	unsigned a2[] = {1, 1, 0};
	unsigned a3[] = {1, 1, 1, 1};
	unsigned a4[] = {1, 1, 0, 1, 1};

	assert(points(a1, nelem(a1), 2, 50) == 0);
	assert(points(a2, nelem(a2), 2, 50) == 50);
	assert(points(a3, nelem(a3), 2, 50) == 100);
	assert(points(a4, nelem(a4), 3, 30) == 0);

	return 0;
}
