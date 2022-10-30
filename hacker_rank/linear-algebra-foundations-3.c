/*

Matrix Multiplication

Two matrices of size 2x2 are multiplied as shown below. Find the integers A, B, C, D in the resultant matrix.

[1  2 ]   x     [4  5 ]      [A  B]
[2  3 ]         [7  8 ]   =  [C  D] 

*/
#include <stdio.h>
#include <string.h>

void
zero(int m[2][2])
{
	int i, j;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++)
			m[i][j] = 0;
	}
}

void
mul(int c[2][2], int a[2][2], int b[2][2])
{
	int i, j, k;
	zero(c);
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 2; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
}

void
print(int m[2][2])
{
	int i, j;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++)
			printf("%d\n", m[i][j]);
	}
}

int
main(void)
{
	int a[2][2] = {
	    {1, 2},
	    {2, 3},
	};
	int b[2][2] = {
	    {4, 5},
	    {7, 8},
	};
	int c[2][2];
	mul(c, a, b);
	print(c);
	return 0;
}
