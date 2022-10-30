/*

You are given an array of scores. The even-indexed numbers are your scores at each turn. The odd-indexed numbers are your opponent's scores.

Create a function that turns this list of scores into an array of who is currently winning.

To illustrate (You - Y, Opponent - O):

Scores: [5, 15, 17, 35, 16, 40, 66, 12, 10, 9]

Y scores: [5, 17, 16, 66, 10]
O scores: [15, 35, 40, 12, 9]

Y cumulative scores: [5, 22, 38, 104, 114]
O cumulative scores: [15, 50, 90, 102, 111]

Who is currently winning: ["O", "O", "O", "Y", "Y"]

Examples

currentlyWinning([10, 10, 22, 30, 5, 40]) ➞ ["T", "O", "O"]

currentlyWinning([5, 1, 2, 10]) ➞ ["Y", "O"]

currentlyWinning([10, 10, 5, 5, 2, 2, 1, 3, 100, 5]) ➞ ["T", "T", "T", "O", "Y"]

Notes

Write "T" if there is a tie at that point in the game.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
scores(int *a, size_t n, int *p)
{
	size_t i, j;
	int x, y;

	if (n & 1)
		return -1;

	x = y = 0;
	for (i = j = 0; i < n; i += 2) {
		x += a[i];
		y += a[i + 1];
		if (x < y)
			p[j++] = 'O';
		else if (x == y)
			p[j++] = 'T';
		else
			p[j++] = 'Y';
	}

	return 0;
}

void
eq(int *a, size_t n, int *r)
{
	size_t i;
	int t[n];

	assert(scores(a, n, t) == 0);
	for (i = 0; i < n / 2; i++)
		assert(t[i] == r[i]);
}

int
main(void)
{
	int a1[] = { 10, 10, 22, 30, 5, 40 };
	int a2[] = { 5, 1, 2, 10 };
	int a3[] = { 10, 10, 5, 5, 2, 2, 1, 3, 100, 5 };
	int a4[] = { 5, 15, 17, 35, 16, 40, 66, 12, 10, 9 };
	int a5[] = { 33, 22, 4, 9, 12, 15, 32, 7, 9, 10, 70, 100 };

	int r1[] = { 'T', 'O', 'O' };
	int r2[] = { 'Y', 'O' };
	int r3[] = { 'T', 'T', 'T', 'O', 'Y' };
	int r4[] = { 'O', 'O', 'O', 'Y', 'Y' };
	int r5[] = { 'Y', 'Y', 'Y', 'Y', 'Y', 'O' };

	eq(a1, nelem(a1), r1);
	eq(a2, nelem(a2), r2);
	eq(a3, nelem(a3), r3);
	eq(a4, nelem(a4), r4);
	eq(a5, nelem(a5), r5);

	return 0;
}
