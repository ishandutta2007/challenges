/*

As punishment for attacking Sunland, Wet Shark is now forced to walk on a line of numbered squares, starting from 1
and going to infinity. Wet Shark initially has a strength of S.

To make the experience harder for Wet Shark, each square that has a label divisible by 4 and/or 2
but not divisible by 42 contains a black glob of jelly, stepping on which his strength decreases by 1.

Wet Shark does not know that this line of squares is infinitely long, and he is determined to continue walking until his strength 
reaches 0. Wet Shark walks from square to square, so he starts at square 1, then 2, then 3 etc

Wet Shark’s punisher needs your help, and wants to compute where Wet Shark will stop in order to meet him there and punish him. Given Wet Shark’s initial strength S,
find the square on which Wet Shark’s strength will reach 0. 
Wet Shark can go far if defenses are not strong enough, so please output the answer modulo 10**9+7.

Wet Shark is curious, so he wants to know that given S strength initially, how far he will go for different values S.
Help him figure out how long he can go without doom for each S.

*/
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint64_t
step1(uint64_t s)
{
	uint64_t n, m;

	if (s == 0)
		return 0;

	m = 1000000007;
	for (n = 1;; n++) {
		if (n % 2 == 0 && n % 42 != 0 && --s == 0)
			break;
	}

	return n % m;
}

uint64_t
step2(uint64_t s)
{
	uint64_t n, m;

	if (s == 0)
		return 0;

	// derive by initially using
	// step1(x) - 2*s (if we assume strength always decrease on even squares)
	// to find the difference, we can use that difference to figure out the
	// missing term (2*s/20)
	// the not divisibility by 42 makes the line oscillates,
	// so also need an if to adjust
	m = 1000000007;
	n = 2 * (s + s / 20);
	if (s % 20 == 0)
		n -= 2;
	return n % m;
}

int
main(void)
{
	uint64_t i;
	for (i = 0; i <= 50000; i++)
		printf("%" PRIu64 " %" PRIu64 " %" PRIu64 "\n", i, step1(i), step2(i));
	return 0;
}
