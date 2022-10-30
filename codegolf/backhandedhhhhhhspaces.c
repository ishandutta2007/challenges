/*

On some terminals, pressing backspace generates the control code ^H to delete the previous character. This gave rise to a snarky idiom where edits are feigned for comedic effect:

Be nice to this fool^H^H^H^Hgentleman, he's visiting from corporate HQ.

Given a string with one or more ^H's, output the result of backspacing on each ^H. The input will use only printable characters (ASCII 32-126), and ^ will only appear as ^H. Backspaces will never happen on empty text.

You may not assume that the output environment supports control codes, in particular the backspace code \x08.

>> Horse^H^H^H^H^HCow
Cow

>> Be nice to this fool^H^H^H^Hgentleman, he's visiting from corporate HQ.
Be nice to this gentleman, he's visiting from corporate HQ.

>> 123^H45^H^H^H78^H
17

>> Digital Trauma^H^H^H^H^H^H^H^H^H^H^H^H^H^HMaria Tidal Tug^H^H^H^H^H^H^H^H^H^H^H^H^H^H^HDigital Trauma
Digital Trauma

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
backhand(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (s[i] == '^' && s[i + 1] == 'H') {
			i++;
			if (j > 0)
				j--;
		} else
			b[j++] = s[i];
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	backhand(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Horse^H^H^H^H^HCow", "Cow");
	test("Be nice to this fool^H^H^H^Hgentleman, he's visiting from corporate HQ.", "Be nice to this gentleman, he's visiting from corporate HQ.");
	test("123^H45^H^H^H78^H", "17");
	test("Digital Trauma^H^H^H^H^H^H^H^H^H^H^H^H^H^HMaria Tidal Tug^H^H^H^H^H^H^H^H^H^H^H^H^H^H^HDigital Trauma", "Digital Trauma");

	return 0;
}
