/*
For a single toss of fair 2 (evenly-weighted) dice, find the probability that the values rolled by each die will be different and their sum is 6. 
*/

#include <stdio.h>

void
prob(void)
{
	int i, j, p;

	p = 0;
	for (i = 1; i <= 6; i++) {
		for (j = 1; j <= 6; j++) {
			if (i != j && i + j == 6)
				p++;
		}
	}
	printf("%d/%d\n", p, 6 * 6);
}

int
main(void)
{
	prob();
	return 0;
}
