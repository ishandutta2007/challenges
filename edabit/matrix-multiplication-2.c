/*

Create a function that multiplies two matrices (n x m) and (p x q) and returns:

    "invalid" if the matrices are not multiplicable (i.e. if m is not equal to p).
    The multiplication matrix (n x q) otherwise.

Examples

matrixMultiply([[1, 2]], [[3], [4]]) ➞ [[11]]

matrixMultiply([[0, 0], [0, 1]], [[1, 2], [3, 4], [5, 6]]) ➞ "invalid"

matrixMultiply([[4, 2], [3, 1]], [[5, 6], [3, 8]]) ➞ [[26, 40], [18, 26]]

Notes

This challenge is a generalized version of Matrix Multiplication.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
mul(size_t n, size_t m, size_t p, size_t q, int a[n][m], int b[p][q], int c[n][q])
{
	size_t i, j, k;
	int r[n][q];

	if (m != p)
		return "invalid";

	memset(r, 0, sizeof(r));
	for (i = 0; i < n; i++) {
		for (j = 0; j < q; j++) {
			for (k = 0; k < m; k++)
				r[i][j] += a[i][k] * b[k][j];
		}
	}
	memcpy(c, r, sizeof(r));

	return NULL;
}

void
test(size_t n, size_t m, size_t p, size_t q, int a[n][m], int b[p][q], int c[n][q])
{
	int r[n][q];
	const char *s;

	if ((s = mul(n, m, p, q, a, b, r)))
		assert(!strcmp(s, "invalid"));
	else
		assert(memcmp(c, r, sizeof(r)) == 0);
}

int
main(void)
{
	int a1[1][2] = {
		{ 1, 2 },
	};
	int b1[1][2] = {
		{ 3, 4 },
	};
	int c1[1][1] = {
		{ 11 },
	};

	int a2[2][2] = {
		{ 0, 0 },
		{ 0, 1 },
	};
	int b2[3][2] = {
		{ 1, 2 },
		{ 3, 4 },
		{ 5, 6 },
	};

	int a3[1][1] = {
		{ 2 },
	};
	int b3[1][1] = {
		{ 3 },
	};
	int c3[1][1] = {
		{ 6 },
	};

	int a4[1][2] = {
		{ 1, 2 },
	};
	int b4[2][1] = {
		{ 3 },
		{ 4 },
	};
	int c4[1][1] = {
		{ 11 },
	};

	int a5[2][2] = {
		{ 2, 4 },
		{ 1, 3 },
	};
	int b5[2][1] = {
		{ 5 },
		{ 6 },
	};
	int c5[2][1] = {
		{ 34 },
		{ 23 },
	};

	int a6[2][2] = {
		{ 4, 2 },
		{ 3, 1 },
	};
	int b6[2][2] = {
		{ 5, 6 },
		{ 3, 8 },
	};
	int c6[2][2] = {
		{ 26, 40 },
		{ 18, 26 },
	};

	int a7[2][2] = {
		{ 3, 6 },
		{ 4, 5 },
	};
	int b7[2][2] = {
		{ 8, 1 },
		{ 7, 2 },
	};
	int c7[2][2] = {
		{ 66, 15 },
		{ 67, 14 },
	};

	int a8[2][2] = {
		{ 1, 6 },
		{ 6, 3 },
	};
	int b8[2][3] = {
		{ 5, 3, 5 },
		{ 1, 6, 6 },
	};
	int c8[2][3] = {
		{ 11, 39, 41 },
		{ 33, 36, 48 },
	};

	int a9[2][2] = {
		{ 4, 6 },
		{ 1, 6 },
	};
	int b9[2][3] = {
		{ 5, 5, 4 },
		{ 5, 3, 2 },
	};
	int c9[2][3] = {
		{ 50, 38, 28 },
		{ 35, 23, 16 },
	};

	int a10[3][2] = {
		{ 5, 1 },
		{ 1, 1 },
		{ 2, 5 },
	};
	int b10[2][3] = {
		{ 5, 6, 3 },
		{ 2, 1, 3 },
	};
	int c10[3][3] = {
		{ 27, 31, 18 },
		{ 7, 7, 6 },
		{ 20, 17, 21 },
	};

	int a11[3][3] = {
		{ 1, 1, 1 },
		{ 0, 1, 0 },
		{ 0, 1, 1 },
	};
	int b11[3][3] = {
		{ 1, 0, 1 },
		{ 0, 0, 1 },
		{ 1, 1, 0 },
	};
	int c11[3][3] = {
		{ 2, 1, 2 },
		{ 0, 0, 1 },
		{ 1, 1, 1 },
	};

	test(1, 2, 1, 2, a1, b1, c1);
	test(2, 2, 3, 2, a2, b2, NULL);
	test(1, 1, 1, 1, a3, b3, c3);
	test(1, 2, 2, 1, a4, b4, c4);
	test(2, 2, 2, 1, a5, b5, c5);
	test(2, 2, 2, 2, a6, b6, c6);
	test(2, 2, 2, 2, a7, b7, c7);
	test(2, 2, 2, 3, a8, b8, c8);
	test(2, 2, 2, 3, a9, b9, c9);
	test(3, 2, 2, 3, a10, b10, c10);
	test(3, 3, 3, 3, a11, b11, c11);

	return 0;
}
