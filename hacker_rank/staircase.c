/*

Consider a staircase of size n=4

   #
  ##
 ###
####

Observe that its base and height are both equal to n, and the image
is drawn using # symbols and spaces.
The last line is not preceded by any spaces.

Write a program that prints a staircase of size n.

*/

#include <stdio.h>

void
staircase(int n)
{
	int i, j;

	for (i = n - 1; i >= 0; i--) {
		for (j = 0; j < n; j++) {
			if (j < i)
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	int i;

	for (i = 0; i < 100; i++)
		staircase(i);
	return 0;
}
