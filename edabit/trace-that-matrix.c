/*

Given a square matrix (i.e. same number of rows as columns), its trace is the sum of the entries in the main diagonal (i.e. the diagonal line from the top left to the bottom right).

As an example, for:

[
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]

... the trace is 1 + 5 + 9 = 15.

Write a function that takes a square matrix and computes its trace.
Examples

trace([
  [1, 4],
  [4, 1]
]) ➞ 2

// 1 + 1 = 2

trace([
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]) ➞ 15

// 1 + 5 + 9 = 15

trace([
  [1, 0, 1, 0],
  [0, 2, 0, 2],
  [3, 0, 3, 0],
  [0, 4, 0, 4]
]) ➞ 10

// 1 + 2 + 3 + 4 = 10

Notes

As in the examples, the size of the matrices will vary (but they will always be square).

*/

#include <assert.h>
#include <stdio.h>

int
trace(size_t n, int m[n][n])
{
	size_t i;
	int r;

	r = 0;
	for (i = 0; i < n; i++)
		r += m[i][i];
	return r;
}

int
main(void)
{
	int m1[2][2] = {
		{ 1, 4 },
		{ 4, 1 },
	};
	int m2[3][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 },
	};
	int m3[1][1] = {
		{ 12345 },
	};
	int m4[4][4] = {
		{ 1, 0, 1, 0 },
		{ 0, 2, 0, 2 },
		{ 3, 0, 3, 0 },
		{ 0, 4, 0, 4 },
	};
	int m5[4][4] = {
		{ 0, 1, 0, 1 },
		{ 2, 0, 2, 0 },
		{ 0, 3, 0, 3 },
		{ 4, 0, 4, 0 },
	};
	int m6[4][4] = {
		{ 1, 8, 9, 16 },
		{ 2, 7, 10, 15 },
		{ 3, 6, 11, 14 },
		{ 4, 5, 12, 13 },
	};

	assert(trace(2, m1) == 2);
	assert(trace(3, m2) == 15);
	assert(trace(1, m3) == 12345);
	assert(trace(4, m4) == 10);
	assert(trace(4, m5) == 0);
	assert(trace(4, m6) == 32);

	return 0;
}
