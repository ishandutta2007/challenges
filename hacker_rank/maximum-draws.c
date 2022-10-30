/*

Jim is off to a party and is searching for a matching pair of socks. His drawer is filled with socks, each pair of a different color.
In its worst case scenario, how many socks (x) should Jim remove from his drawer until he finds a matching pair?

Input parameter is given in pairs

*/

#include <stdio.h>

int
draws(int n)
{
	// n is given in pair, if we have m socks (2*n), formula is m/2 + 1
	// since we can draw at least half of different color but the next
	// one has to match a color (2*n)/2 + 1 = n + 1
	if (n <= 0)
		return 0;

	return n + 1;
}

int
main(void)
{
	printf("%d\n", draws(1));
	printf("%d\n", draws(2));
	return 0;
}
