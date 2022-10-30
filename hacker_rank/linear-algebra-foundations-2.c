/*
Matrix Subtraction

A matrix of size 3x3 is subtracted from another of a similar size. Find the integers A, B, C, D, E, F, G, H, I in the resultant matrix.

[1  2  3 ]        [4  5  6 ]      [A  B  C]
[2  3  4 ]   -    [7  8  9 ]   =  [D  E  F] 
[1  1  1 ]        [4  5  0 ]      [G  H  I]

In the text box below, enter each of the 9 integers, A, B, C, ... I on a new line. 
*/

#include <stdio.h>

void
sub(int c[3][3], int a[3][3], int b[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			c[i][j] = a[i][j] - b[i][j];
	}
}

void
print(int m[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d\n", m[i][j]);
		}
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
	    {4, 5, 0},
	};
	int c[3][3];
	sub(c, a, b);
	print(c);
	return 0;
}
