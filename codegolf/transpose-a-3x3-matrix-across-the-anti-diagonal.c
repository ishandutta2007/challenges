/*

Write a program which takes a 3x3 matrix on stdin and prints its transpose along the anti-diagonal to stdout.
You may assume that all elements of the matrix will be integers.
Columns are space-separated and rows are newline-separated.

Example
Input:

1 2 3
3 4 5
1 2 3
Output:

3 5 3
2 4 2
1 3 1
Input:

1 2 3
4 5 6
7 8 9
Output:

9 6 3
8 5 2
7 4 1

*/

#include <assert.h>
#include <string.h>

void
swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

void
trad(int m[3][3])
{
	swap(&m[0][0], &m[2][2]);
	swap(&m[0][1], &m[1][2]);
	swap(&m[1][0], &m[2][1]);
}

void
test(int m[3][3], int r[3][3])
{
	trad(m);
	assert(!memcmp(m, r, sizeof(*r) * 3));
}

int
main(void)
{
	int m1[3][3] = {
	    {1, 2, 3},
	    {3, 4, 5},
	    {1, 2, 3},
	};

	int r1[3][3] = {
	    {3, 5, 3},
	    {2, 4, 2},
	    {1, 3, 1},
	};

	int m2[3][3] = {
	    {1, 2, 3},
	    {4, 5, 6},
	    {7, 8, 9},
	};

	int r2[3][3] = {
	    {9, 6, 3},
	    {8, 5, 2},
	    {7, 4, 1},
	};

	test(m1, r1);
	test(m2, r2);

	return 0;
}
