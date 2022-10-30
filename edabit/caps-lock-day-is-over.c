/*

October 22nd is CAPS LOCK DAY. Apart from that day, every sentence should be lowercase, so write a function to normalize a sentence.

Create a function that takes a string. If the string is all uppercase characters, convert it to lowercase and add an exclamation mark at the end.
Examples

normalize("CAPS LOCK DAY IS OVER") ➞ "Caps lock day is over!"

normalize("Today is not caps lock day.") ➞ "Today is not caps lock day."

normalize("Let us stay calm, no need to panic.") ➞ "Let us stay calm, no need to panic."

Notes

Each string is a sentence and should start with an uppercase character.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
normalize(const char *s, char *b)
{
	size_t i;
	int f;

	f = 0;
	for (i = 0; s[i]; i++) {
		b[i] = s[i];
		if (isalpha(s[i])) {
			b[i] = (!f) ? toupper(s[i]) : tolower(s[i]);
			f |= 1;
		}
	}
	if (i && !ispunct(b[i - 1]))
		b[i++] = '!';
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	normalize(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("CAPS LOCK DAY IS OVER", "Caps lock day is over!");
	test("Today is not caps lock day.", "Today is not caps lock day.");
	test("WE WANT THIS COVID THING TO BE OVER", "We want this covid thing to be over!");
	test("Let us stay calm, no need to panic.", "Let us stay calm, no need to panic.");
	test("DO NOT SHOUT", "Do not shout!");
	test("Civilized conversation.", "Civilized conversation.");

	return 0;
}
