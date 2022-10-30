/*

Create a function that takes a word and returns the new word without including the first character.
Examples

newWord("apple") ➞ "pple"

newWord("cherry") ➞ "herry"

newWord("plum") ➞ "lum"

Notes

Input is valid word.

*/

#include <assert.h>
#include <string.h>

const char *
newword(const char *s)
{
	return s + 1;
}

int
main(void)
{
	assert(strcmp(newword("apple"), "pple") == 0);
	assert(strcmp(newword("cherry"), "herry") == 0);
	assert(strcmp(newword("plum"), "lum") == 0);
	assert(strcmp(newword("pokhara"), "okhara") == 0);
	assert(strcmp(newword("biratnagar"), "iratnagar") == 0);
	assert(strcmp(newword("nepal"), "epal") == 0);
	assert(strcmp(newword("damak"), "amak") == 0);
	assert(strcmp(newword("itahari"), "tahari") == 0);
	assert(strcmp(newword("rasuwa"), "asuwa") == 0);
	assert(strcmp(newword("rolpa"), "olpa") == 0);
	return 0;
}
