/*

Daanish as always is busy creating and solving his favourite and interesting graph problems.
Chef assigns each problem a difficulty — an integer between 1 and 10. For each valid i, there are Ai problems with difficulty i.

A participant hacked Daanish's account and got access to the problem proposal document.
He can delete up to K problems from the document in order to reduce the difficulty of the contest for himself and his friends.
Find the smallest possible value of the difficulty of the most difficult problem which remains after removing K problems.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains 10 space-separated integers A1,A2,…,A10.
The second line contains a single integer K.

Output
For each test case, print a single line containing one integer — the minimum difficulty of the most difficult remaining problem.

Constraints
1≤T≤2⋅10^4
0≤Ai≤10^8 for each valid i
A1+A2+…+A10>0
0≤K<A1+A2+…+A10

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
hardness(int *a, size_t n, int k)
{
	size_t i;

	for (i = n; i > 0 && k >= a[i - 1]; i--)
		k -= a[i - 1];
	return i;
}

int
main(void)
{
	int a1[] = {1, 10, 1, 5, 3, 2, 4, 9, 0, 100};
	int a2[] = {2, 0, 1, 0, 0, 0, 0, 0, 0, 10};
	int a3[] = {2, 0, 1, 0, 0, 0, 0, 10, 0, 0};
	int a4[] = {2, 0, 1, 0, 0, 0, 0, 0, 0, 10};
	int a5[] = {1, 10, 1, 5, 3, 2, 4, 9, 0, 100};

	assert(hardness(a1, nelem(a1), 100) == 8);
	assert(hardness(a2, nelem(a2), 12) == 1);
	assert(hardness(a3, nelem(a3), 0) == 8);
	assert(hardness(a4, nelem(a4), 10) == 3);
	assert(hardness(a5, nelem(a5), 125) == 2);

	return 0;
}
