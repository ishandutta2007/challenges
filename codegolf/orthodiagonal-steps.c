/*

It's a common problem to navigate in a 2D matrix. We've seen it many times and will see again. So let's help future us and develop the shortest solutions to generate all eight possible steps in a 2D matrix.

Challenge
Your code must output the following 8 pairs of -1,0,1 in any order:

(0,1)
(0,-1)
(1,0)
(-1,0)
(1,1)
(1,-1)
(-1,1)
(-1,-1)

Rules
There is no input.
Output order is not relevant
Output is flexible. Pairs of numbers just need to be distinguishable
This is code-golf, so shortest answer in bytes wins

*/

#include <stdio.h>

void
steps(void)
{
	int i, j;

	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			if (i != 0 || j != 0)
				printf("(%d, %d)\n", i, j);
		}
	}
}

int
main(void)
{
	steps();
	return 0;
}
