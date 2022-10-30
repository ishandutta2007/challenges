/*

A magic sigil is a glyph which represents a desire one wishes to manifest in their lives.
There are many ways to create a sigil, but the most common is to write out a specific desire
(e.g. "I HAVE WONDERFUL FRIENDS WHO LOVE ME"), remove all vowels,
remove any duplicate letters and then design a glyph from what remains.

Using the sentence above as an example, we would remove duplicate letters:

AUFRINDSWHLOVME

And then remove all vowels, leaving us with:

FRNDSWHLVM

Create a function that takes a string and removes its vowels and duplicate letters. The returned string should not contain any spaces and be in uppercase.
Examples

sigilize("i am healthy") ➞ "MLTHY"

sigilize("I FOUND MY SOULMATE") ➞ "FNDYSLMT"

sigilize("I have a job I enjoy and it pays well") ➞ "HVBJNDTPYSWL"

Notes

    For duplicate letters the last one is kept.
    When performing actual sigil magic, you must make your sigils manually.
    Check the Resources tab for more info on sigils if you're interested in the concept.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
sigilize(char *s)
{
	size_t i, j, h[256];
	int c;

	memset(h, 0, sizeof(h));
	for (i = j = 0; s[i]; i++) {
		c = toupper(s[i]);
		if (strchr("AEIOU", c))
			continue;
		if (isspace(c))
			continue;

		h[c]++;
		s[j++] = c;
	}
	s[j] = '\0';

	for (i = j = 0; s[i]; i++) {
		c = s[i] & 0xff;
		if (h[c] > 0 && --h[c] != 0)
			continue;

		s[j++] = s[i];
	}
	s[j] = '\0';

	return s;
}

int
main(void)
{
	char s1[] = "I HAVE WONDERFUL FRIENDS WHO LOVE ME";
	char s2[] = "My business is financially successful";
	char s3[] = "I have a job I enjoy and it pays well";
	char s4[] = "I heard the song closing time playing on the radio";
	char s5[] = "i am healthy";
	char s6[] = "I FOUND MY SOULMATE";

	assert(strcmp(sigilize(s1), "FRNDSWHLVM") == 0);
	assert(strcmp(sigilize(s2), "MBNYCSFL") == 0);
	assert(strcmp(sigilize(s3), "HVBJNDTPYSWL") == 0);
	assert(strcmp(sigilize(s4), "CSMPLYGNTHRD") == 0);
	assert(strcmp(sigilize(s5), "MLTHY") == 0);
	assert(strcmp(sigilize(s6), "FNDYSLMT") == 0);

	return 0;
}
