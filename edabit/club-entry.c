/*

A night club will give you a word. For entrance, you need to provide the right number according to the provided word.

Every given word will have a doubled letter, like "dd" in addiction. To answer the right number you need to find the doubled letter's position in the alphabets and multiply this number with 4.

Create a function that takes the argument of word and returns the right number.

Examples

clubEntry("hill") ➞ 48
// 'l' is 12th alphabet
// 12*4 = 48

clubEntry("apple") ➞ 64

clubEntry("bee") ➞ 20

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
clubentry(const char *s)
{
	size_t i;
	int c;

	for (i = 0; s[i]; i++) {
		if (s[i] == s[i + 1])
			break;
	}

	c = tolower(s[i]);
	if (!('a' <= c && c <= 'z'))
		return -1;
	return (c - 'a' + 1) * 4;
}

int
main(void)
{
	assert(clubentry("lettuce") == 80);
	assert(clubentry("hill") == 48);
	assert(clubentry("apple") == 64);
	assert(clubentry("addiction") == 16);
	assert(clubentry("bee") == 20);
	assert(clubentry("zz") == 104);

	return 0;
}
