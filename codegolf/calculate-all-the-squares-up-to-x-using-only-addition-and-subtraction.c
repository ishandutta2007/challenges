/*

The goal is to calculate all the squares up to x with addition and subtraction.

Rules:

The code must be a function which takes the total number of squares to generate, and returns an array containing all those squares.
You can not use strings, structures, multiplication, division, or built-in functions for calculating squares.
You can only use arrays, integers (whole numbers), addition, subtraction. No other operators allowed!
This is a code-golf question, so the shortest code in bytes wins!

*/

#include <stdio.h>

void
squares(int x)
{
	int i, j, k, l;

	for (i = 0; i <= x; i++) {
		l = 0;
		for (j = 0; j <= i; j++) {
			for (k = 0; k <= i; k++)
				l++;
		}

		if (l > x)
			break;

		printf("%d\n", l);
	}
}

int
main(void)
{
	squares(10000);
	return 0;
}
