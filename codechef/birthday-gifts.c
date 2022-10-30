/*

It’s Chef's birthday. He and his twin have received N gifts in total.
The i-th gift has a price of Ai.
Each twin wants to keep the most expensive gifts for himself.

The twins take K turns alternately (each has K turns, for 2⋅K turns in total).
It is given that 2⋅K+1≤N. In a turn, a person may choose one gift.
The only exception is the last turn of the twin who moves second, where he gets to choose two gifts instead of one.
Assuming they both choose gifts optimally and you can choose who takes the first turn, find the maximum total cost of the gifts that Chef keeps.

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains two lines of input.
The first line contains two space-separated integers N, K.
The second line contains N space-separated integers A1,A2,…,AN, the price of the gifts.

Output

For each test case, output in a single line the answer to the problem.

Constraints
1≤T≤100
3≤N≤10^3
1≤K≤(N-1)/2
1≤Ai≤10^9

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef long long vlong;

int
cmp(const void *a, const void *b)
{
	vlong x, y;

	x = *(vlong *)a;
	y = *(vlong *)b;
	if (x < y)
		return -1;
	if (x > y)
		return 1;
	return 0;
}

vlong
maxcost(vlong *a, size_t n, size_t k)
{
	size_t i;
	vlong x, y;

	qsort(a, n, sizeof(*a), cmp);

	x = y = 0;
	for (i = n; k > 0 && i >= 2; k--) {
		x += a[--i];
		y += a[--i];
	}
	if (i > 0)
		y += a[--i];

	return max(x, y);
}

int
main(void)
{
	vlong a1[] = {1, 3, 2};
	vlong a2[] = {3, 1, 3};
	vlong a3[] = {5, 1, 3, 2, 4};

	assert(maxcost(a1, nelem(a1), 1) == 3);
	assert(maxcost(a2, nelem(a2), 1) == 4);
	assert(maxcost(a3, nelem(a3), 2) == 8);

	return 0;
}
