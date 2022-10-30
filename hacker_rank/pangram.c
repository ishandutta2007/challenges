/*

Roy wanted to increase his typing speed for programming contests. His friend suggested that he type the sentence "The quick brown fox jumps over the lazy dog" repeatedly. This sentence is known as a pangram because it contains every letter of the alphabet.

After typing the sentence several times, Roy became bored with it so he started to look for other pangrams.

Given a sentence, determine whether it is a pangram. Ignore case.

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char *
ispangram(const char *s)
{
	char h[256];
	size_t i;
	int c;

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++) {
		c = tolower(s[i]) & 0xff;
		h[c] = 1;
	}
	for (c = 'a'; c <= 'z'; c++) {
		if (!h[c])
			return "not pangram";
	}
	return "pangram";
}

int
main(void)
{
	printf("%s\n", ispangram("The quick brown fox jumps over the lazy dog"));
	printf("%s\n", ispangram("We promptly judged antique ivory buckles for the next prize"));
	printf("%s\n", ispangram("We promptly judged antique ivory buckles for the prize"));
	return 0;
}
