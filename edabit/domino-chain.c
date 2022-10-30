/*

Mubashir was playing with dominos. He concluded that:

    If the first domino is pushed over, it will keep tipping next dominos to its right.
    Reaction will stop if a domino is already tipped over, or if there is an empty space.

Mubashir

Create a function which takes a string of current status of the dominos and returns the string after dominos chain reaction.

    "|" represents a standing domino.
    "/" represents a tripped domino.
    " " represents an empty space.

Examples

dominoChain("||| ||||//| |/") ➞ "/// ||||//| |/"
// A space will stop the reaction.

dominoChain("||//||") ➞ "////||"
// An already tripped domino will stop the reaction.

dominoChain("||||") ➞ "////"

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
dominochain(const char *s, char *b)
{
	size_t i;
	int t;

	t = 1;
	for (i = 0; s[i]; i++) {
		b[i] = s[i];
		if (s[i] == '|' && t)
			b[i] = '/';
		else if (s[i] == ' ' || s[i] == '/')
			t = 0;
	}
	b[i] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	dominochain(s, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("||| ||||//| |/", "/// ||||//| |/");
	test("|||||", "/////");
	test(" ///", " ///");
	test("", "");
	test(" ", " ");
	test("||||| |||", "///// |||");
	test("|||||/|||", "//////|||");
	test(" |||", " |||");

	return 0;
}
