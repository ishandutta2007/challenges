/*

You are given two vectors v1=(x1,x2,…,xn) and v2=(y1,y2,…,yn).
The scalar product of these vectors is a single number, calculated as x1y1+x2y2+…+xnyn.

Suppose you are allowed to permute the coordinates of each vector as you wish.
Choose two permutations such that the scalar product of your two new vectors is the smallest possible, and output that minimum scalar product.

Input

The first line of the input file contains the number of testcases, T≤10.
For each test case, the first line contains integer number n.
The next two lines contain n integers each, giving the coordinates of v1 and v2 respectively.

You may assume that 1≤n≤800 and −100000≤xi,yi≤100000.

Output

For each test case, output a line

Case #X: Y where X is the test case number, starting from 1, and Y is the minimum scalar product of all permutations of the two given vectors.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

int
rcmp(const void *a, const void *b)
{
	return -cmp(a, b);
}

int
minscalar(int *a, int *b, size_t n)
{
	size_t i;
	int r;

	qsort(a, n, sizeof(*a), cmp);
	qsort(b, n, sizeof(*b), rcmp);

	r = 0;
	for (i = 0; i < n; i++)
		r += a[i] * b[i];
	return r;
}

int
main(void)
{
	int a1[] = {1, 3, -5};
	int b1[] = {-2, 4, 1};

	int a2[] = {1, 2, 3, 4, 5};
	int b2[] = {1, 0, 1, 0, 1};

	assert(minscalar(a1, b1, nelem(a1)) == -25);
	assert(minscalar(a2, b2, nelem(a2)) == 6);

	return 0;
}
