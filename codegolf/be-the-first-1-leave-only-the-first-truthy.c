/*

Intro
Every year, Dyalog Ltd. holds a student competition. The challenge there is to write good APL code. This is a language agnostic code-golf edition of this year's eighth problem.

I have explicit permission to post this challenge here from the original author of the competition. Feel free to verify by following the provided link and contacting the author.

Problem
Given a Boolean* list, "turn off" all the Truthies after the first Truthy.

No Truthies? No problem! Just return the list unmodified.

Examples
[falsy,truthy,falsy,truthy,falsy,falsy,truthy] → [falsy,truthy,falsy,falsy,falsy,falsy,falsy]

[] → []

[falsy,falsy,falsy,falsy] → [falsy,falsy,falsy,falsy]
* All your truthies must be identical, and all your falsies must be identical. This includes output.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
turnoff(bool *b, size_t n)
{
	size_t i;
	bool f;

	f = false;
	for (i = 0; i < n; i++) {
		if (b[i] && f)
			b[i] = false;
		f |= b[i];
	}
}

void
test(bool *b, size_t n, bool *r)
{
	turnoff(b, n);
	if (n)
		assert(!memcmp(b, r, sizeof(*r) * n));
}

int
main(void)
{
	bool b1[] = {false, true, false, true, false, false, true};
	bool r1[] = {false, true, false, false, false, false, false};

	bool b2[] = {false, false, false, false};
	bool r2[] = {false, false, false, false};

	test(b1, nelem(b1), r1);
	test(NULL, 0, NULL);
	test(b2, nelem(b2), r2);

	return 0;
}
