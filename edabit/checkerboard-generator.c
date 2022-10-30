/*

Create a checker board generator, which takes as inputs n and 2 elements to generate an n x n checkerboard with those two elements as alternating squares.

Examples

checker_board(2, 7, 6) ➞ [
  [7, 6],
  [6, 7]
]

checker_board(3, "A", "B") ➞ [
  ["A", "B", "A"],
  ["B", "A", "B"],
  ["A", "B", "A"]
]

checker_board(4, "c", "d") ➞ [
  ["c", "d", "c", "d"],
  ["d", "c", "d", "c"],
  ["c", "d", "c", "d"],
  ["d", "c", "d", "c"]
]

checker_board(4, "c", "c") ➞ "invalid"

Notes

    Both elements can be either strings or integers.
    The first element should be on the upper left corner of the checker board. e.g. "c", not "d" should be element [0][0] for example 3.
    Return "invalid" if both inputs are identical (see example 4).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
checkerboard(size_t n, int a, int b, int m[n][n])
{
	size_t i, j;
	int s;

	if (a == b)
		return -1;

	s = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			m[i][j] = (!s) ? a : b;
			s = !s;
		}
		if (!(n & 1))
			s = !s;
	}
	return 0;
}

void
dump(size_t n, int m[n][n])
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (isalpha(m[i][j]))
				printf("%c ", m[i][j]);
			else
				printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void
test(size_t n, int a, int b, int m[n][n])
{
	int p[n][n];
	int r;

	r = checkerboard(n, a, b, p);
	if (!m)
		assert(r < 0);
	else {
		dump(n, p);
		assert(!memcmp(m, p, sizeof(p)));
	}
}

int
main(void)
{
	int m1[3][3] = {
	    {'A', 'B', 'A'},
	    {'B', 'A', 'B'},
	    {'A', 'B', 'A'},
	};

	int m2[2][2] = {
	    {7, 6},
	    {6, 7},
	};

	int m3[3][3] = {
	    {1, 0, 1},
	    {0, 1, 0},
	    {1, 0, 1},
	};

	int m4[3][3] = {
	    {0, 1, 0},
	    {1, 0, 1},
	    {0, 1, 0},
	};

	int m5[4][4] = {
	    {'c', 'd', 'c', 'd'},
	    {'d', 'c', 'd', 'c'},
	    {'c', 'd', 'c', 'd'},
	    {'d', 'c', 'd', 'c'},
	};

	test(3, 'A', 'B', m1);
	test(2, 7, 6, m2);
	test(3, 1, 0, m3);
	test(3, 0, 1, m4);
	test(4, 'c', 'd', m5);
	test(4, 'c', 'c', NULL);

	return 0;
}
