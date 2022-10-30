/*

In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Note:

    The height and width of the given matrix is in range [1, 100].
    The given r and c are all positive.

*/

#include <stdio.h>

void
print(size_t r, size_t c, int m[r][c])
{
	size_t i, j;

	printf("[");
	for (i = 0; i < r; i++) {
		if (i > 0)
			printf("\n ");
		printf("[");
		for (j = 0; j < c; j++) {
			printf("%d", m[i][j]);
			if (j + 1 < c)
				printf(",");
		}
		printf("]");
	}
	printf("]\n");
}

int
reshape(size_t u, size_t v, size_t r, size_t c, int m[u][v], int s[r][c])
{
	size_t i, j;
	int *p;

	if (u * v < r * c)
		return 0;

	p = &m[0][0];
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			s[i][j] = *p++;
	}
	return 1;
}

void
test(size_t u, size_t v, size_t r, size_t c, int m[u][v])
{
	int s[r][c];
	if (!reshape(u, v, r, c, m, s))
		print(u, v, m);
	else
		print(r, c, s);
}

int
main(void)
{
	int m1[2][2] = {
	    {1, 2},
	    {3, 4},
	};
	test(2, 2, 1, 4, m1);
	test(2, 2, 2, 4, m1);
	test(2, 2, 2, 1, m1);
	return 0;
}
