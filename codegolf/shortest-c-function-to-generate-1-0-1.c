/*

Let a function receive two integers i and j between 0 and 3, it should return the value in position (i,j) in the following 2D array:

1, 0, -1, 0
1, 0, -1, 0
0, 1, 0, -1
0, -1, 0, 1

Shortest code in any variant of C / C++ wins.

*/

#include <stdio.h>

int
at(int i, int j)
{
	static const int m[4][4] = {
	    {1, 0, -1, 0},
	    {1, 0, -1, 0},
	    {0, 1, 0, -1},
	    {0, -1, 0, 1},
	};
	return m[i][j];
}

int
main(void)
{
	int i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++)
			printf("%- 2d ", at(i, j));
		printf("\n");
	}
}
