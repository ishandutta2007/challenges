/*

Taum is planning to celebrate the birthday of his friend, Diksha.
There are two types of gifts that Diksha wants from Taum: one is black and the other is white.
To make her happy, Taum has to buy b black gifts and w white gifts.

The cost of each black gift is bc units.
The cost of every white gift is wc units.
The cost of converting each black gift into white gift or vice versa is z units.

Help Taum by deducing the minimum amount he needs to spend on Diksha's gifts.

For example, if Taum wants to buy b=3 black gifts and w=5 white gifts at a cost of bc=3 and wc=4 conversion cost z=1,
we see that he can buy a black gift for 3 and convert it to a white gift for 1, making the total cost of each white gift 4.
That matches the cost of a white gift, so he can do that or just buy black gifts and white gifts.
Either way, the overall cost is 3*3 + 5*4 = 29.

*/

#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

unsigned
cost(unsigned b, unsigned w, unsigned bc, unsigned wc, unsigned z)
{
	unsigned c1, c2, c3;

	c1 = b * bc + w * wc;
	c2 = b * bc + w * (bc + z);
	c3 = b * (wc + z) + w * wc;
	return min(c1, min(c2, c3));
}

int
main(void)
{
	printf("%u\n", cost(10, 10, 1, 1, 1));
	printf("%u\n", cost(5, 9, 2, 3, 4));
	printf("%u\n", cost(3, 6, 9, 1, 1));
	printf("%u\n", cost(7, 7, 4, 2, 1));
	printf("%u\n", cost(3, 3, 1, 9, 2));
	printf("%u\n", cost(3, 5, 3, 4, 1));
	return 0;
}
