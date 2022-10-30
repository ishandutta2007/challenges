/*

Since entering 2nd grade Theta has daily math homework sheets. The problems on her worksheet usually go like this:

    There is a certain number of birds, dogs, and cats on a farm.
    Together they have 14 legs. How many birds, dogs, and cats could there be?
    Write down as many answers as you can!

It is always the same problem, just written in different ways: sometimes with horses, cows, sheep, goats, chickens, beetles, or even spiders – but never with snakes or fishes!

Can you write a program to double-check Theta’s answers?

*/

#include <stdio.h>

void
animals(int b, int d, int c, int l)
{
	int i, j, k;
	int s, v;

	s = 0;
	for (i = 0; i < l; i++) {
		for (j = 0; j < l; j++) {
			for (k = 0; k < l; k++) {
				v = (b * i) + (d * j) + (c * k);
				if (v > l)
					break;
				if (v == l) {
					printf("%d %d %d\n", i, j, k);
					s++;
				}
			}
		}
	}
	if (s == 0)
		printf("impossible\n");
	printf("\n");
}

int
main(void)
{
	animals(2, 4, 4, 14);
	animals(100, 80, 60, 240);
	animals(2, 4, 6, 9);
	return 0;
}
