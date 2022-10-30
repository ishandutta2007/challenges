/*

Create a function that takes a string of words and moves the first letter of each word to the end of it, then adds "ay" to the end of the word.
This is called "Pig Latin" and it gets more complicated than the rules in this particular challenge.
I've intentionally kept things simple, otherwise this would turn into an extremely tedious challenge.

    Move the first letter of each word to the end of the word.
    Add "ay" to the end of the word.
    Words starting with a vowel (A, E, I, O, U) simply have "WAY" appended to the end.

Examples

pigLatin("Cats are great pets.")
➞ "Atscay areway reatgay etspay."

pigLatin("Tom got a small piece of pie.")
➞ "Omtay otgay away mallsay iecepay ofway iepay."

pigLatin("He told us a very exciting tale.")
➞ "Ehay oldtay usway away eryvay excitingway aletay."

Notes

Be sure to preserve proper capitalization and punctuation.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
isletter(int c)
{
	c = tolower(c);
	return 'a' <= c && c <= 'z';
}

int
isvowel(int c)
{
	return strchr("aeiou", tolower(c)) != NULL;
}

char *
piglatin(const char *s, char *b)
{
	size_t i, j, k, l, n;
	int c, f;

	for (i = j = 0;;) {
		while (s[i] && !isletter(s[i]))
			b[j++] = s[i++];

		if (!s[i])
			break;

		f = 0;
		if (isupper(s[i])) {
			f = 1;
			n = j;
		}

		c = 'w';
		if (!isvowel(s[i]))
			c = tolower(s[i++]);

		for (k = l = i; s[k] && !isspace(s[k]); k++) {
			if (isletter(s[k]))
				l = k;
		}

		while (s[i] && i <= l)
			b[j++] = s[i++];

		b[j++] = c;
		b[j++] = 'a';
		b[j++] = 'y';

		while (i < k)
			b[j++] = s[i++];

		if (f)
			b[n] = toupper(b[n]);
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	piglatin(s, b);
	printf("%s\n%s\n%s\n\n", s, b, r);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Cats are great pets.", "Atscay areway reatgay etspay.");
	test("Tom got a small piece of pie.", "Omtay otgay away mallsay iecepay ofway iepay.");
	test("He told us a very exciting tale.", "Ehay oldtay usway away eryvay excitingway aletay.");
	test("A diamond is not enough.", "Away iamondday isway otnay enoughway.");
	test("Hurry!", "Urryhay!");
	test(". . , ,,,", ". . , ,,,");
	test("A", "Away");
	test("b", "bay");
	test("Xum", "Umxay");
	test("Boo''',wd...", "Oo''',wdbay...");

	return 0;
}
