/*

Matrix Multiplication

Two matrices of size 3x3 are multiplied as shown below. Find the integers A, B, C, D, E, F, G, H, I in the resultant matrix.

[1  2  3 ]        [4  5  6 ]      [A  B  C ]
[2  3  4 ]   x    [7  8  9 ]   =  [D  E  F ] 
[1  1  1 ]        [4  5  7 ]      [G  H  I ]

*/
#include <stdio.h>
#include <string.h>

void
zero(int m[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			m[i][j] = 0;
	}
}

void
mul(int c[3][3], int a[3][3], int b[3][3])
{
	int i, j, k;
	zero(c);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
}

void
print(int m[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			printf("%d\n", m[i][j]);
	}
}

int
main(void)
{
	int a[3][3] = {
	    {1, 2, 3},
	    {2, 3, 4},
	    {1, 1, 1},
	};
	int b[3][3] = {
	    {4, 5, 6},
	    {7, 8, 9},
	    {4, 5, 7},
	};
	int c[3][3];
	mul(c, a, b);
	print(c);
	return 0;
}
