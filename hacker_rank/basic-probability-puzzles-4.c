/*

Objective
In this challenge, we practice calculating probability.

Task
Bag1 contains 4 red balls and 5 black balls.
Bag2 contains 3 red balls and 7 black balls.

One ball is drawn from the Bag1, and 2 balls are drawn from Bag2.
Find the probability that 2 balls are black and ball 1 is red.

*/

#include <stdio.h>

void
prob(void)
{
	int i, j, k, x;
	int r, b, rr, bb;
	int p;

	p = 0;
	for (i = 1; i <= 4 + 5; i++) {
		for (j = 1; j <= 3 + 7; j++) {
			r = b = 0;
			(i <= 4) ? r++ : b++;
			if (j <= 3) {
				x = 2;
				r++;
			} else {
				x = 3;
				b++;
			}

			for (k = 1; k <= 3 + 7 - 1; k++) {
				rr = bb = 0;
				(k <= x) ? rr++ : bb++;
				if (b + bb == 2 && r + rr == 1)
					p++;
			}
		}
	}
	printf("%d/%d\n", p, (4 + 5) * (3 + 7) * (3 + 7 - 1));
}

int
main(void)
{
	prob();
	return 0;
}
