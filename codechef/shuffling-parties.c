/*

Chef is given an array A consisting of N positive integers. Chef shuffles the array A and creates a new array B of length N, where Bi=(Ai+i)mod2, for each i(1≤i≤N).

Find the maximum possible sum of integers of the array B, if Chef shuffles the array A optimally.

Input Format

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains two lines of input.
The first line of each test case contains an integer N.
The second line of each test case contains N space-separated integers A1,A2,…,AN.

Output Format

For each test case, print a single line containing one integer - the maximum sum of integers of the array B.

Constraints
1≤T≤10^4
1≤N≤10^5
1≤Ai≤10^9
Sum of N over all test cases does not exceed 3⋅10^5

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

size_t
maxsum(int *a, size_t n)
{
	size_t he, we;
	size_t ho, wo;
	size_t i;

	he = we = 0;
	ho = wo = 0;
	for (i = 0; i < n; i++) {
		((i + 1) & 1) ? we++ : wo++;
		(a[i] & 1) ? ho++ : he++;
	}
	return min(we, he) + min(wo, ho);
}

int
main(void)
{
	int a1[] = {1, 2, 3};
	int a2[] = {2, 4, 5};
	int a3[] = {2, 4};

	assert(maxsum(a1, nelem(a1)) == 2);
	assert(maxsum(a2, nelem(a2)) == 3);
	assert(maxsum(a3, nelem(a3)) == 1);

	return 0;
}
