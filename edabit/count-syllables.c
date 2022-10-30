/*

Create a function that counts the number of syllables a word has.
Each syllable is separated with a dash -.

*/

#include <assert.h>
#include <stdio.h>

size_t
syllables(const char *s)
{
	size_t i, c;

	c = 1;
	for (i = 0; s[i]; i++)
		c += (s[i] == '-');
	return c;
}

int
main(void)
{
	assert(syllables("buf-fet") == 2);
	assert(syllables("beau-ti-ful") == 3);
	assert(syllables("mon-u-men-tal") == 4);
	assert(syllables("on-o-mat-o-poe-ia") == 6);
	assert(syllables("o-ver-ly") == 3);
	assert(syllables("pas-try") == 2);
	assert(syllables("flu-id") == 2);
	assert(syllables("syl-la-ble") == 3);

	return 0;
}
