/*

Given a square list (n*n size) implement a function that returns a new list containing two lists equal to the two diagonals, in the following order:

diagonal 1 = from upper-left to lower-right corner
diagonal 2 = from upper-right to lower-left corner

Examples

get_diagonals([ [1, 2], [3, 4] ]) ➞ [ [1, 4], [2, 3] ]

get_diagonals([ ["a", "b", "c"], ["d", "e", "f"], ["g", "h", "i"] ]) ➞ [ ["a", "e", "i"], ["c", "e", "g"] ]

get_diagonals([ [True] ]) ➞ [ [True], [True] ]

Notes

    Your function must also work with single elements or empty lists.
    Try to build both diagonals with a single loop.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
diagonals(size_t n, int m[n][n], int d[2][n])
{
	size_t i;

	for (i = 0; i < n; i++) {
		d[0][i] = m[i][i];
		d[1][i] = m[i][n - i - 1];
	}
}

void
test(size_t n, int m[n][n], int d[2][n])
{
	int p[2][n];

	diagonals(n, m, p);
	assert(!memcmp(d, p, sizeof(p)));
}

int
main(void)
{
	int m1[2][2] = {
	    {1, 2},
	    {3, 4},
	};
	int d1[2][2] = {
	    {1, 4},
	    {2, 3},
	};

	int m2[3][3] = {
	    {'a', 'b', 'c'},
	    {'d', 'e', 'f'},
	    {'g', 'h', 'i'},
	};
	int d2[2][3] = {
	    {'a', 'e', 'i'},
	    {'c', 'e', 'g'},
	};

	int m3[1][1] = {
	    {1},
	};
	int d3[2][1] = {
	    {1},
	    {1},
	};

	int m4[3][3] = {
	    {1, 2, 3},
	    {4, 5, 6},
	    {7, 8, 9},
	};
	int d4[2][3] = {
	    {1, 5, 9},
	    {3, 5, 7},
	};

	int m5[6][6] = {
	    {'e', 'z', 'y', 'o', 'p', 't'},
	    {'b', 'd', 'a', 't', 'i', 'w'},
	    {'u', 'l', 'a', 'n', 's', 'k'},
	    {'s', 'v', 'k', 'b', 'r', 'z'},
	    {'h', 'e', 'w', 'c', 'i', 'j'},
	    {'r', 'p', 'y', 'd', 'x', 't'},
	};
	int d5[2][6] = {
	    {'e', 'd', 'a', 'b', 'i', 't'},
	    {'t', 'i', 'n', 'k', 'e', 'r'},
	};

	int m6[4][4] = {
	    {1, 0, 1, 0},
	    {0, 1, 0, 1},
	    {1, 0, 1, 0},
	    {0, 0, 0, 1},
	};
	int d6[2][4] = {
	    {1, 1, 1, 1},
	    {0, 0, 0, 0},
	};

	int m7[10][10] = {
	    {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
	    {0, 0, 1, 0, 0, 1, 0, 1, 1, 1},
	    {0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
	    {1, 0, 1, 1, 1, 0, 0, 1, 0, 1},
	    {1, 0, 0, 1, 0, 0, 1, 1, 0, 0},
	    {0, 0, 1, 0, 1, 0, 0, 1, 1, 1},
	    {1, 1, 1, 1, 0, 1, 0, 0, 0, 1},
	    {0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
	    {0, 1, 1, 1, 0, 1, 1, 1, 0, 0},
	    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
	};
	int d7[2][10] = {
	    {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	    {0, 1, 1, 0, 0, 1, 1, 1, 1, 1},
	};

	test(2, m1, d1);
	test(3, m2, d2);
	test(1, m3, d3);
	test(3, m4, d4);
	test(6, m5, d5);
	test(4, m6, d6);
	test(10, m7, d7);
	test(0, NULL, NULL);

	return 0;
}
