/*
Matrix Addition

Add the two matrices given below and find the integers corresponding to a, b, c, d, e, f, g, h, and i:

[1  2  3]       [4  5  6]     [a b c]
[2  3  4]   +   [7  8  9]  =  [d e f] 
[1  1  1]       [4  5  7]     [g h i]
*/

#include <stdio.h>

void
add(int c[3][3], int a[3][3], int b[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			c[i][j] = a[i][j] + b[i][j];
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
	add(c, a, b);
	print(c);
	return 0;
}
