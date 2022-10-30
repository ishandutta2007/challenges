/*

Description

A handful of words have their letters in alphabetical order, that is nowhere in the word do you change direction in the word if you were to scan along the English alphabet.
An example is the word "almost", which has its letters in alphabetical order.

Your challenge today is to write a program that can determine if the letters in a word are in alphabetical order.

As a bonus, see if you can find words spelled in reverse alphebatical order.
Input Description

You'll be given one word per line, all in standard English. Examples:

almost
cereal

Output Description

Your program should emit the word and if it is in order or not. Examples:

almost IN ORDER
cereal NOT IN ORDER

Challenge Input

billowy
biopsy
chinos
defaced
chintz
sponged
bijoux
abhors
fiddle
begins
chimps
wronged

Challenge Output

billowy IN ORDER
biopsy IN ORDER
chinos IN ORDER
defaced NOT IN ORDER
chintz IN ORDER
sponged REVERSE ORDER 
bijoux IN ORDER
abhors IN ORDER
fiddle NOT IN ORDER
begins IN ORDER
chimps IN ORDER
wronged REVERSE ORDER

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
classify(const char *s, char *b)
{
	size_t i;
	int f;

	f = 0;
	for (i = 0; s[i] && s[i + 1] && f != 3; i++) {
		if (s[i] <= s[i + 1])
			f |= 1;
		else if (s[i] > s[i + 1])
			f |= 2;
	}

	switch (f) {
	case 0:
	case 1:
		sprintf(b, "%s IN ORDER", s);
		break;
	case 2:
		sprintf(b, "%s REVERSE ORDER", s);
		break;
	case 3:
		sprintf(b, "%s NOT IN ORDER", s);
		break;
	}
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	classify(s, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("almost", "almost IN ORDER");
	test("cereal", "cereal NOT IN ORDER");
	test("billowy", "billowy IN ORDER");
	test("biopsy", "biopsy IN ORDER");
	test("chinos", "chinos IN ORDER");
	test("defaced", "defaced NOT IN ORDER");
	test("chintz", "chintz IN ORDER");
	test("sponged", "sponged REVERSE ORDER");
	test("bijoux", "bijoux IN ORDER");
	test("abhors", "abhors IN ORDER");
	test("fiddle", "fiddle NOT IN ORDER");
	test("begins", "begins IN ORDER");
	test("chimps", "chimps IN ORDER");
	test("wronged", "wronged REVERSE ORDER");

	return 0;
}
