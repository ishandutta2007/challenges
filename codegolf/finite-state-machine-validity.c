/*

I've been around for a while, watching you golf and I really enjoy it. I came up with a challenge for you all so let's begin!

Challenge
I assume that everyone knows what Finite State Machine (FSM) is, I will edit the the description if needed.

Your program will take only one input consisting in a string that represents a FSM.
The first character of the input is the FSM's initial state and the last character is the FSM's final state.
Transitions are represented as two consecutive characters (AB will be the transition from state A to state B. ABCD will be the two transitions A to B and C to D)
In this challenge, the FSM is considered valid when you have at least one path from the initial state to the final state.
Goal
Output a truthy value, telling the world if the input is a valid FSM (any equivalent for True of False is fine)

Bonus
-20% if you add all the sequences of valid paths to the output
Examples
AB should output (with bonus) true AB

ABC should output false (No transition to state C)

ABCEBD should output (with bonus) true ABD (The presence of unreachable states C and E doesn't make it false)

ISSTSFTF should output (with bonus) true ISF ISTF

ABACBCCD should output (with bonus) true ACD ABCD

ABACBCD should output false

ABACADCDBCDEBE should output (with bonus) true ABE ADE ACDE ABCDE

Final word
If you think this challenge lacks something, please tell me, I'd really like to see the answers you can come up with

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

void
set(uint64_t p[4], uint64_t b)
{
	uint64_t i, j;

	i = b / 64;
	j = b & 63;
	p[i] |= UINT64_C(1) << j;
}

bool
on(uint64_t p[4], uint64_t b)
{
	uint64_t i, j;

	i = b / 64;
	j = b & 63;
	return (p[i] & (UINT64_C(1) << j)) != 0;
}

void
unite(uint64_t p[4], uint64_t q[4])
{
	size_t i;

	for (i = 0; i < 4; i++)
		p[i] |= q[i];
}

bool
reachable(const char *s)
{
	uint64_t g[256][4];
	size_t n;
	int a, b;
	int i, j;

	memset(g, 0, sizeof(g));
	for (n = 0; s[n] && s[n + 1]; n += 2) {
		a = s[n] & 0xff;
		b = s[n + 1] & 0xff;
		set(g[a], b);
	}
	n += (s[n] != '\0');

	if (n == 0)
		return true;

	a = s[0] & 0xff;
	b = s[n - 1] & 0xff;
	set(g[a], a);

	for (i = 0; i < 256; i++) {
		for (j = 0; j < 256; j++) {
			if (on(g[a], j))
				unite(g[a], g[j]);
		}
	}
	return on(g[a], b);
}

int
main(void)
{
	assert(reachable("AB") == true);
	assert(reachable("ABC") == false);
	assert(reachable("ABCEBD") == true);
	assert(reachable("ISSTSFTF") == true);
	assert(reachable("ABACBCCD") == true);
	assert(reachable("ABACBCD") == false);
	assert(reachable("ABACADCDBCDEBE") == true);
	assert(reachable("A") == true);
	assert(reachable("") == true);

	return 0;
}
