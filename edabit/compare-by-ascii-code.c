/*

Create a function that compares two words based on the sum of their ASCII codes and returns the word with the smaller ASCII sum.
Examples

asciiSort(["hey", "man"]) ➞ "man"
# ["h", "e", "y"] ➞ sum([104, 101, 121]) ➞ 326
# ["m", "a", "n"] ➞ sum([109, 97, 110]) ➞ 316

asciiSort(["majorly", "then"]) ➞ "then"

asciiSort(["victory", "careless"]) ➞ "victory"

Notes

Both words will have strictly different ASCII sums.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
asciisort(const char *s, const char *t)
{
	unsigned x, y;
	size_t i;

	x = y = 0;
	for (i = 0; s[i]; i++)
		x += s[i];
	for (i = 0; t[i]; i++)
		y += t[i];
	return (x <= y) ? s : t;
}

int
main(void)
{
	assert(strcmp(asciisort("hey", "man"), "man") == 0);
	assert(strcmp(asciisort("majorly", "then"), "then") == 0);
	assert(strcmp(asciisort("magic", "kingdom"), "magic") == 0);
	assert(strcmp(asciisort("bored", "shampoo"), "bored") == 0);
	assert(strcmp(asciisort("victory", "careless"), "victory") == 0);
	assert(strcmp(asciisort("aaaaaaaaaa", "zzzzzzzzz"), "aaaaaaaaaa") == 0);

	return 0;
}
