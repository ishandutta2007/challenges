/*

Suppose an image can be represented as a 2D array of 0s and 1s.
Write a function to reverse an image. Replace the 0s with 1s and vice versa.

*/

#include <stdio.h>

void
negate(size_t r, size_t c, int m[r][c])
{
	size_t i, j;

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			m[i][j] = !m[i][j];
}

void
print(size_t r, size_t c, int m[r][c])
{
	size_t i, j;

	printf("[\n");
	for (i = 0; i < r; i++) {
		printf("  [");
		for (j = 0; j < c; j++) {
			printf("%d", m[i][j]);
			if (j + 1 < c)
				printf(", ");
		}
		printf("]");
		if (i + 1 < r)
			printf(",\n");
	}
	printf("\n]\n");
}

void
test(size_t r, size_t c, int m[r][c])
{
	negate(r, c, m);
	print(r, c, m);
}

int
main(void)
{
	int m1[3][3] = {
		{ 1, 0, 0 },
		{ 0, 1, 0 },
		{ 0, 0, 1 },
	};
	int m2[2][3] = {
		{ 1, 1, 1 },
		{ 0, 0, 0 },
	};
	int m3[2][3] = {
		{ 1, 0, 0 },
		{ 1, 0, 0 },
	};
	int m4[5][5] = {
		{ 1, 0, 0, 0, 0 },
		{ 1, 0, 0, 1, 1 },
		{ 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0 },
		{ 1, 1, 1, 0, 0 },
	};
	int m5[5][2] = {
		{ 1, 1 },
		{ 1, 0 },
		{ 1, 1 },
		{ 1, 1 },
		{ 1, 1 },
	};

	test(3, 3, m1);
	test(2, 3, m2);
	test(2, 3, m3);
	test(5, 5, m4);
	test(5, 2, m5);

	return 0;
}
