/*

Checkerboard. Write a program Checkerboard.java that takes an integer command-line argument N, and uses two nested for
loops to print an N-by-N "checkerboard" pattern like the one below:
a total of N2 asterisks, where each row has 2N characters (alternating between asterisks and spaces).

    % java Checkerboard 4             % java Checkerboard 5
    * * * *                           * * * * *
     * * * *                           * * * * *
    * * * *                           * * * * *
     * * * *                           * * * * *
                                      * * * * *

*/

#include <stdio.h>

void
checkerboard(int n)
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n * 2; j++)
			printf("%c", !((j ^ i) & 1) ? '*' : ' ');
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	checkerboard(4);
	checkerboard(5);
	return 0;
}
