/*

Introduction
Super Mario 64 has a heavily overcomplicated RNG, ably explained here by Pannenkoek.

I thought it might be interesting to implement it.

Challenge
Implement the RNG function, except for the two special cases.

Input and output are both 16-bit integers.

The standard C implementation is as follows:

rng(input) {
    s0 = (input & 0xFF) << 8;
    s0 = s0 ^ input;
    input = (s0 & 0xFF) << 8 | (s0 & 0xFF00) >> 8;
    s0 = (s0 & 0xFF) << 1 ^ input;
    s1 = s0 >> 1 ^ 0xFF80;
    if(s0 & 1) input = s1 ^ 0x8180;
    else input = s1 ^ 0x1FF4;
    return input;
}
Example input and output
12567 -> 60400 -> 1789 -> 0 -> 57460 -> 55882 -> 50550
64917 -> 43605 -> 21674 -> 46497 -> 45151
22026 <-> 58704
Rules
Shortest code wins.
Standard loopholes apply.

*/

#include <stdio.h>
#include <stdint.h>

uint16_t
rng(uint16_t input)
{
	uint16_t s0, s1;

	s0 = (input & 0xFF) << 8;
	s0 = s0 ^ input;
	input = (s0 & 0xFF) << 8 | (s0 & 0xFF00) >> 8;
	s0 = ((s0 & 0xFF) << 1) ^ input;
	s1 = (s0 >> 1) ^ 0xFF80;
	if (s0 & 1)
		input = s1 ^ 0x8180;
	else
		input = s1 ^ 0x1FF4;
	return input;
}

void
test(uint16_t input, int iterations)
{
	int i;

	for (i = 0; i < iterations; i++) {
		printf("%d", input);
		if (i + 1 < iterations)
			printf(" -> ");
		input = rng(input);
	}
	printf("\n");
}

int
main(void)
{
	test(12567, 7);
	test(64917, 5);
	test(22026, 2);

	return 0;
}
