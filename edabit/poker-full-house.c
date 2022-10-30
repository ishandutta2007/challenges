/*

Create a function that determines whether or not a player is holding a Full House in their hand. A hand is represented as an array of 5 cards. A full house is defined as a pair of cards and a three-of-a-kind.

To illustrate: ["A", "A", "A", "K", "K"] would be a Full House, since the player holds 3 aces and 2 kings.

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cardhash(const char *s)
{
	static const char *tab[] = {
		"2",
		"3",
		"4",
		"5",
		"6",
		"7",
		"8",
		"9",
		"10",
		"J",
		"Q",
		"K",
		"A",
	};
	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		if (!strcmp(s, tab[i]))
			return i;
	}
	return -1;
}

int
isfullhouse(const char *s[5])
{
	int i, j, x, y, h[13];

	memset(h, 0, sizeof(h));
	for (i = 0; i < 5; i++) {
		if ((j = cardhash(s[i])) < 0)
			return -1;
		h[j]++;
	}

	x = y = 0;
	for (i = 0; i < 13; i++) {
		x += (h[i] == 3);
		y += (h[i] == 2);
	}
	return x && y;
}

int
main(void)
{
	const char *s1[] = { "A", "A", "A", "K", "K" };
	const char *s2[] = { "3", "J", "J", "3", "3" };
	const char *s3[] = { "10", "J", "10", "J", "10" };
	const char *s4[] = { "10", "J", "10", "10", "10" };
	const char *s5[] = { "10", "J", "J", "2", "2" };
	const char *s6[] = { "7", "J", "3", "4", "2" };

	printf("%d\n", isfullhouse(s1));
	printf("%d\n", isfullhouse(s2));
	printf("%d\n", isfullhouse(s3));
	printf("%d\n", isfullhouse(s4));
	printf("%d\n", isfullhouse(s5));
	printf("%d\n", isfullhouse(s6));
	return 0;
}
