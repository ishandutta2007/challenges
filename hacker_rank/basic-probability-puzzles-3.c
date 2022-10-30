/*
Objective
In this challenge, we practice calculating probability.

Task
There are urns: 3, X, Y and Z.

    Urn X contains 4 red balls and 3 black balls.
    Urn Y contains 5 red balls and 4 black balls.
    Urn Z contains 4 red balls and 4 black balls.

One ball is drawn from each urn. What is the probability that the 3 balls drawn consist of 2 red balls and 1 black ball? 
*/

#include <stdio.h>

void
prob(void)
{
	int i, j, k, r, b, p;

	p = 0;
	for (i = 1; i <= 4 + 3; i++) {
		for (j = 1; j <= 5 + 4; j++) {
			for (k = 1; k <= 4 + 4; k++) {
				r = b = 0;
				(i <= 4) ? r++ : b++;
				(j <= 5) ? r++ : b++;
				(k <= 4) ? r++ : b++;
				if (r == 2 && b == 1)
					p++;
			}
		}
	}
	printf("%d/%d\n", p, (4 + 3) * (5 + 4) * (4 + 4));
}

int
main(void)
{
	prob();
	return 0;
}
