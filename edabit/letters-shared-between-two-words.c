/*

Create a function that returns the number of characters shared between two words.
Examples

sharedLetters("apple", "meaty") ➞ 2
// Since "ea" is shared between "apple" and "meaty".

sharedLetters("fan", "forsook") ➞ 1

sharedLetters("spout", "shout") ➞ 4

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t
sharedletters(const char *s, const char *t)
{
	size_t h1[256], h2[256];
	size_t i, c;

	memset(h1, 0, sizeof(h1));
	memset(h2, 0, sizeof(h2));
	for (i = 0; s[i]; i++)
		h1[s[i] & 0xff]++;
	for (i = 0; t[i]; i++)
		h2[t[i] & 0xff]++;

	c = 0;
	for (i = 0; i < 256; i++) {
		if (h1[i] && h2[i])
			c++;
	}
	return c;
}

int
main(void)
{
	assert(sharedletters("apple", "meaty") == 2);
	assert(sharedletters("fan", "forsook") == 1);
	assert(sharedletters("spout", "shout") == 4);
	assert(sharedletters("took", "taken") == 2);
	assert(sharedletters("mentor", "terminal") == 5);
	assert(sharedletters("class", "last") == 3);

	return 0;
}
