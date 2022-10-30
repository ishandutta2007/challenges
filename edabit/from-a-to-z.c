/*

Given a string indicating a range of letters, return a string which includes all the letters in that range, including the last letter.
Note that if the range is given in capital letters, return the string in capitals also!

Examples

gimme_the_letters("a-z") ➞ "abcdefghijklmnopqrstuvwxyz"

gimme_the_letters("h-o") ➞ "hijklmno"

gimme_the_letters("Q-Z") ➞ "QRSTUVWXYZ"

gimme_the_letters("J-J") ➞ J"

Notes

    A hyphen will separate the two letters in the string.
    You don't need to worry about error handling in this one (i.e. both letters will be the same case and the second letter will always be after the first alphabetically).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
letters(const char *s, char *b)
{
	char x, y;
	size_t i;

	if (sscanf(s, "%c-%c", &x, &y) != 2)
		return NULL;

	for (i = 0; x <= y; x++)
		b[i++] = x;
	b[i] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	letters(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("a-z", "abcdefghijklmnopqrstuvwxyz");
	test("h-o", "hijklmno");
	test("Q-Z", "QRSTUVWXYZ");
	test("J-J", "J");
	test("a-b", "ab");
	test("A-A", "A");
	test("g-i", "ghi");
	test("H-I", "HI");
	test("y-z", "yz");
	test("e-k", "efghijk");
	test("a-q", "abcdefghijklmnopq");
	test("F-O", "FGHIJKLMNO");

	return 0;
}
