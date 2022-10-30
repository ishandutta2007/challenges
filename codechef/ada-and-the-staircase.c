/*

There is a big staircase with N steps (numbered 1 through N) in ChefLand. Let's denote the height of the top of step i by hi.
Chef Ada is currently under the staircase at height 0 and she wants to reach the top of the staircase (the top of the last step).
However, she can only jump from height hi to the top of a step at height hf if hf−hi≤K.
To help Ada, we are going to construct some intermediate steps; each of them may be constructed between any two steps, or before the first step, and have any height.
What is the minimum number of steps that need to be added to the staircase so that Ada could reach the top?

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains N space-seperated integers h1,h2,…,hN.

Output

For each test case, print a single line containing one integer — the minimum required number of steps.

Constraints
1≤T≤64
1≤N≤128
1≤K≤1,024
1≤hi≤1,024 for each valid i
hi<hi+1 for each valid i

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
steps(int *h, size_t n, int k)
{
	int d, p, r;
	size_t i;

	r = 0;
	p = 0;
	for (i = 0; i < n; i++) {
		d = h[i] - p;
		p = h[i];
		r += (d / k) - !(d % k);
	}
	return r;
}

int
main(void)
{
	int h1[] = {2, 4, 8, 16};

	assert(steps(h1, nelem(h1), 3) == 3);

	return 0;
}
