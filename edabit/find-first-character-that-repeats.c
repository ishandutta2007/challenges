/*

Create a function that takes a string and returns the first character that repeats. If there is no repeat of a character, return "-1".
Examples

firstRepeat("legolas") ➞ "l"

firstRepeat("Gandalf") ➞ "a"

firstRepeat("Balrog") ➞ "-1"

firstRepeat("Isildur") ➞ "-1"
// Case sensitive "I" not equal to "i"

Notes

Tests are case sensitive.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
firstrepeat(const char *s)
{
	size_t i, h[256];

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++) {
		if (++h[s[i] & 0xff] > 1)
			return s[i];
	}
	return -1;
}

int
main(void)
{
	assert(firstrepeat("legolas") == 'l');
	assert(firstrepeat("Balrog") == -1);
	assert(firstrepeat("Isildur") == -1);
	assert(firstrepeat("Gollum") == 'l');
	assert(firstrepeat("Galadriel") == 'a');
	assert(firstrepeat("pippin") == 'p');
	assert(firstrepeat("Saruman") == 'a');

	return 0;
}
