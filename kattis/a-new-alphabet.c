/*

A New Alphabet has been developed for Internet communications. While the glyphs of the new alphabet don’t necessarily improve communications in any meaningful way, they certainly make us feel cooler.

You are tasked with creating a translation program to speed up the switch to our more elite New Alphabet by automatically translating ASCII plaintext symbols to our new symbol set.

The new alphabet is a one-to-many translation (one character of the English alphabet translates to anywhere between 1 and 6 other characters), with each character translation as follows:

Table_Figure

For instance, translating the string “Hello World!” would result in:
[-]3110 \/\/0|Z1|)!

Note that uppercase and lowercase letters are both converted, and any other characters remain the same (the exclamation point and space in this example).

Input

Input contains one line of text, terminated by a newline. The text may contain any characters in the ASCII range 32–126 (space through tilde), as well as 9 (tab).
Only characters listed in the above table (A–Z, a–z) should be translated; any non-alphabet characters should be printed (and not modified). Input has at most 10000 characters.

Output

Output the input text with each letter (lowercase and uppercase) translated into its New Alphabet counterpart.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
translate(const char *s, char *b)
{
	static const char tab[256][8] = {
	    ['a'] = "@",
	    ['b'] = "8",
	    ['c'] = "(",
	    ['d'] = "|)",
	    ['e'] = "3",
	    ['f'] = "#",
	    ['g'] = "6",
	    ['h'] = "[-]",
	    ['i'] = "|",
	    ['j'] = "_|",
	    ['k'] = "|<",
	    ['l'] = "1",
	    ['m'] = "[]\\/[]",
	    ['n'] = "[]\\[]",
	    ['o'] = "0",
	    ['p'] = "|D",
	    ['q'] = "(,)",
	    ['r'] = "|Z",
	    ['s'] = "$",
	    ['t'] = "']['",
	    ['u'] = "|_|",
	    ['v'] = "\\/",
	    ['w'] = "\\/\\/",
	    ['x'] = "}{",
	    ['y'] = "`/",
	    ['z'] = "2",
	};

	size_t i, l;
	int c;

	l = 0;
	for (i = 0; s[i]; i++) {
		c = tolower(s[i]);
		if (tab[c][0])
			l += sprintf(b + l, "%s", tab[c]);
		else
			b[l++] = s[i];
	}
	b[l] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	translate(s, b);
	printf("\"%s\"\n\"%s\"\n\n", b, r);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Hello World!", "[-]3110 \\/\\/0|Z1|)!");
	test("All your base are belong to us.", "@11 `/0|_||Z 8@$3 @|Z3 8310[]\\[]6 ']['0 |_|$.");
	test("What's the Frequency, Kenneth?", "\\/\\/[-]@'][''$ ']['[-]3 #|Z3(,)|_|3[]\\[](`/, |<3[]\\[][]\\[]3']['[-]?");
	test("A new alphabet!", "@ []\\[]3\\/\\/ @1|D[-]@83']['!");
	return 0;
}
