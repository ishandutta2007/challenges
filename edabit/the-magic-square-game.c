/*

There are two players, Alice and Bob, each with a 3-by-3 grid.
A referee tells Alice to fill out one particular row in the grid (say the second row) by putting either a 1 or a 0 in each box, such that the sum of the numbers in that row is odd.
The referee tells Bob to fill out one column in the grid (say the first column) by putting either a 1 or a 0 in each box, such that the sum of the numbers in that column is even.

Alice and Bob win the game if Alice’s numbers give an odd sum, Bob’s give an even sum, and (most important) they’ve each written down the same number in the one square where their row and column intersect.

Examples

magic_square_game([2, "100"], [1, "101"]) ➞ False

magic_square_game([2, "001"], [1, "101"]) ➞ True

magic_square_game([3, "111"], [2, "011"]) ➞ True

magic_square_game([1, "010"], [3, "101"]) ➞ False

# Two lists, Alice [row, "her choice"], Bob [column, "his choice"]

Notes

    Look at the article in the resources tab to see the first two examples in action.
    The row of Alice is always odd, the column of Bob is always even.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

void
conv(const char *a, int p[3])
{
	int i;

	for (i = 0; i < 3; i++)
		p[i] = a[i] - '0';
}

bool
magic(int r, const char *a, int c, const char *b)
{
	int p[3], q[3];
	int x, y;

	if (r < 1 || r > 3 || c < 1 || c > 3)
		return false;

	conv(a, p);
	conv(b, q);
	x = p[0] ^ p[1] ^ p[2];
	y = q[0] ^ q[1] ^ q[2];
	return x && !y && a[c - 1] == b[r - 1];
}

void
test(int r, const char *a, int c, const char *b, bool p)
{
	assert(magic(r, a, c, b) == p);
}

int
main(void)
{
	test(2, "100", 1, "101", false);
	test(2, "001", 1, "101", true);
	test(3, "111", 2, "011", true);
	test(1, "010", 3, "101", false);
	test(2, "111", 3, "011", true);
	test(2, "100", 3, "110", false);
	test(1, "001", 1, "101", false);
	test(2, "100", 2, "101", true);
	test(3, "010", 1, "110", true);
	test(1, "100", 2, "110", false);
	test(2, "111", 3, "011", true);
	test(2, "001", 2, "101", true);
	test(1, "100", 2, "101", false);
	test(3, "001", 3, "011", true);
	test(3, "111", 1, "110", false);
	test(2, "100", 2, "101", true);

	return 0;
}
