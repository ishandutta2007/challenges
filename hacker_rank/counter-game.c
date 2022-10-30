/*

Louise and Richard have developed a numbers game. They pick a number and check to see if it is a power of 2. If it is, they divide it by 2.
If not, they reduce it by the next lower number which is a power of 2. Whoever reduces the number to 1 wins the game. Louise always starts.

Given an initial value, determine who wins the game.

As an example, let the initial value n=132. It's Louise's turn so she first determines that is not a power of 2.
The next lower power of 2 is 128, so she subtracts 132 that from and passes 4 to Richard. 4 is a power of 2,
so Richard divides it by and passes to Louise. Likewise, is a power so she divides it by 2 and reaches 1.
She wins the game.

Update If they initially set counter to 1, Richard wins. Louise cannot make a move so she loses.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int
ispow2(uint64_t n)
{
	return (n & (n - 1)) == 0;
}

uint64_t
nextpow2(uint64_t n)
{
	uint64_t x;

	x = 1;
	while (x < n)
		x <<= 1;
	return x;
}

int
popcnt(uint64_t n)
{
	int c;
	for (c = 0; n; n >>= 1) {
		if (n & 1)
			c++;
	}
	return c;
}

const char *
win_slow(uint64_t n)
{
	int t;

	for (t = 1; n != 1; t ^= 1) {
		if (ispow2(n))
			n >>= 1;
		else
			n -= (nextpow2(n) >> 1);
	}
	return (t == 0) ? "Louise" : "Richard";
}

const char *
win(uint64_t n)
{
	return ((popcnt(n - 1) & 1) == 0) ? "Richard" : "Louise";
}

int
main(void)
{
	printf("%s %s\n", win_slow(132), win(132));
	printf("%s %s\n", win_slow(1), win(1));
	printf("%s %s\n", win_slow(6), win(6));

	srand(time(NULL));
	for (int i = 0; i < 10000; i++) {
		unsigned long v = rand() & 0xffffffffull;
		const char *s1 = win_slow(v);
		const char *s2 = win(v);
		if (strcmp(s1, s2) != 0)
			printf("%lu %s %s\n", v, s1, s2);
	}
	return 0;
}
