/*

Create a function that multiplies two matricies (n x n each).

Notes

Limit yourself to 2 x 2 matrices.

*/

#include <assert.h>
#include <string.h>

void
mul2(int a[2][2], int b[2][2], int c[2][2])
{
	size_t i, j, k;
	int r[2][2];

	memset(r, 0, sizeof(r));
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 2; k++)
				r[i][j] += a[i][k] * b[k][j];
		}
	}
	memcpy(c, r, sizeof(r));
}

void
test(int a[2][2], int b[2][2], int c[2][2])
{
	int r[2][2];

	mul2(a, b, r);
	assert(memcmp(c, r, sizeof(r)) == 0);
}

int
main(void)
{
	int a1[2][2] = {
		{ 4, 2 },
		{ 3, 1 },
	};
	int b1[2][2] = {
		{ 5, 6 },
		{ 3, 8 },
	};
	int c1[2][2] = {
		{ 26, 40 },
		{ 18, 26 },
	};

	int a2[2][2] = {
		{ 3, 6 },
		{ 4, 5 },
	};
	int b2[2][2] = {
		{ 8, 1 },
		{ 7, 2 },
	};
	int c2[2][2] = {
		{ 66, 15 },
		{ 67, 14 },
	};

	int a3[2][2] = {
		{ 7, 5 },
		{ 2, 2 },
	};
	int b3[2][2] = {
		{ 6, 7 },
		{ 3, 2 },
	};
	int c3[2][2] = {
		{ 57, 59 },
		{ 18, 18 },
	};

	test(a1, b1, c1);
	test(a2, b2, c2);
	test(a3, b3, c3);

	return 0;
}
