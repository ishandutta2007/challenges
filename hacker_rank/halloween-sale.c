/*
You wish to buy video games from the famous online video game store Mist.

Usually, all games are sold at the same price, dollars. However, they are planning to have the
seasonal Halloween Sale next month in which you can buy games at a cheaper price.
Specifically, the first game you buy during the sale will be sold at p dollars,
but every subsequent game you buy will be sold at exactly d dollars less than the cost of the previous one you bought.
This will continue until the cost becomes less than or equal to dollars, after which every game you buy will cost m dollars each.

For example, if p=20, d=3 and m=6, then the following are the costs of the first games you buy, in order:
20, 17, 14, 11, 8, 6, 6, 6, 6, 6, 6

You have s dollars in your Mist wallet. How many games can you buy during the Halloween Sale?
*/
#include <stdio.h>

int
games(int p, int d, int m, int s)
{
	int c, n;

	c = p;
	for (n = 0;; n++) {
		s -= c;
		if (s < 0)
			break;
		if (c <= m)
			c = m;
		else
			c -= d;
	}
	return n;
}

int
main(void)
{
	printf("%d\n", games(20, 3, 6, 80));
	printf("%d\n", games(20, 3, 6, 85));
	return 0;
}
