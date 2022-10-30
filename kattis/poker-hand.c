/*

You are given a five-card hand drawn from a standard 52-card deck. The strength of your hand is the maximum value k such that there are k cards in your hand that have the same rank.

Compute the strength of your hand.

Input

The input will consist of a single line, with five two-character strings separated by spaces.

The first character in each string will be the rank of the card, and will be one of A23456789TJQK. The second character in the string will be the suit of the card, and will be one of CDHS.

You may assume all the strings are distinct.

Output

Output, on a single line, the strength of your hand.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
rank(char c)
{
	static const char *deck = "A23456789TJQK";
	const char *p;

	p = strchr(deck, c);
	return (p) ? p - deck : -1;
}

int
strength(const char **s, size_t n)
{
	int c[13];
	int m, r;
	size_t i;

	memset(c, 0, sizeof(c));
	m = 0;
	for (i = 0; i < n; i++) {
		r = rank(s[i][0]);
		if (r < 0)
			continue;

		if (++c[r] > m)
			m = c[r];
	}
	return m;
}

int
main(void)
{
	const char *s1[] = {
	    "AC",
	    "AD",
	    "AH",
	    "AS",
	    "KD",
	};
	const char *s2[] = {
	    "2C",
	    "4D",
	    "4H",
	    "2D",
	    "2H",
	};
	const char *s3[] = {
	    "AH",
	    "2H",
	    "3H",
	    "4H",
	    "5H",
	};

	assert(strength(s1, nelem(s1)) == 4);
	assert(strength(s2, nelem(s2)) == 3);
	assert(strength(s3, nelem(s3)) == 1);

	return 0;
}
