/*

A Sudoku is a 9x9 grid that is completed when every 3x3 square, row and column consist of the numbers 1-9.

For this task, you will be given a completed 3x3 square, in the form of a two-dimensional array.
Create a function that checks to make sure this 3x3 square contains each number from 1-9 exactly once.
Make sure there are no duplicates, and no numbers outside this range.

*/

#include <stdio.h>
#include <string.h>

int
isminisudoku(int m[3][3])
{
	size_t i, j;
	int c[10];

	memset(c, 0, sizeof(c));
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (!(0 < m[i][j] && m[i][j] <= 9))
				return 0;
			c[m[i][j]]++;
		}
	}

	for (i = 1; i < 10; i++) {
		if (c[i] != 1)
			return 0;
	}

	return 1;
}

int
main(void)
{
	int a1[3][3] = {
	    {1, 3, 2},
	    {9, 7, 8},
	    {4, 5, 6},
	};

	int a2[3][3] = {
	    {1, 3, 2},
	    {9, 0, 8},
	    {4, 5, 6},
	};

	int a3[3][3] = {
	    {1, 1, 2},
	    {9, 7, 8},
	    {4, 5, 6},
	};

	int a4[3][3] = {
	    {8, 9, 2},
	    {5, 6, 1},
	    {3, 7, 4},
	};

	int a5[3][3] = {
	    {8, 7, 2},
	    {5, 6, 1},
	    {3, 7, 4},
	};

	int a6[3][3] = {
	    {6, 5, 9},
	    {4, 3, 8},
	    {2, 1, 7},
	};

	int a7[3][3] = {
	    {4, 3, 5},
	    {8, 1, 2},
	    {9, 6, 7},
	};

	int a8[3][3] = {
	    {4, 3, 5},
	    {8, 1, 3},
	    {9, 5, 7},
	};

	printf("%d\n", isminisudoku(a1));
	printf("%d\n", isminisudoku(a2));
	printf("%d\n", isminisudoku(a3));
	printf("%d\n", isminisudoku(a4));
	printf("%d\n", isminisudoku(a5));
	printf("%d\n", isminisudoku(a6));
	printf("%d\n", isminisudoku(a7));
	printf("%d\n", isminisudoku(a8));

	return 0;
}
