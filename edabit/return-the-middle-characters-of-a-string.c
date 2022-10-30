/*

Create a function that takes a string and returns the middle character(s). If the word's length is odd, return the middle character. If the word's length is even, return the middle two characters.
Examples

getMiddle("test") ➞ "es"

getMiddle("testing") ➞ "t"

getMiddle("middle") ➞ "dd"

getMiddle("A") ➞ "A"

Notes

All test cases contain a single word (as a string).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
middle(const char *s, char *b, size_t n)
{
	size_t l;

	if (n == 0)
		return b;

	l = strlen(s);
	if (l == 0)
		b[0] = '\0';
	else if (l & 1)
		snprintf(b, n, "%c", s[l / 2]);
	else
		snprintf(b, n, "%c%c", s[l / 2 - 1], s[l / 2]);

	return b;
}

int
main(void)
{
	char b[8];

	assert(!strcmp(middle("test", b, sizeof(b)), "es"));
	assert(!strcmp(middle("testing", b, sizeof(b)), "t"));
	assert(!strcmp(middle("middle", b, sizeof(b)), "dd"));
	assert(!strcmp(middle("A", b, sizeof(b)), "A"));
	assert(!strcmp(middle("inhabitant", b, sizeof(b)), "bi"));
	assert(!strcmp(middle("brown", b, sizeof(b)), "o"));
	assert(!strcmp(middle("pawn", b, sizeof(b)), "aw"));
	assert(!strcmp(middle("cabinet", b, sizeof(b)), "i"));
	assert(!strcmp(middle("fresh", b, sizeof(b)), "e"));
	assert(!strcmp(middle("shorts", b, sizeof(b)), "or"));

	return 0;
}
