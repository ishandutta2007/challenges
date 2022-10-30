/*

Tap code is a way to communicate messages via a series of taps (or knocks) for each letter in the message.
Letters are arranged in a 5x5 polybius square, with the letter "K" being moved to the space with "C".

   1  2  3  4  5
1  A  B C\K D  E
2  F  G  H  I  J
3  L  M  N  O  P
4  Q  R  S  T  U
5  V  W  X  Y  Z

Each letter is translated by tapping out the row and column number that the letter appears in, leaving a short pause in-between.
If we use "." for each tap, and a single space to denote the pause:

text = "break"

"B" = (1, 2) = ". .."
"R" = (4, 2) = ".... .."
"E" = (1, 5) = ". ....."
"A" = (1, 1) = ". ."
"K" = (1, 3) = ". ..."

Another space is added between the groups of taps for each letter to give the final code:

"break" = ". .. .... .. . ..... . . . ..."

Write a function that returns the tap code if given a word, or returns the translated word (in lower case) if given the tap code.

Examples

tapCode("break") ➞ ". .. .... .. . ..... . . . ..."

tapCode(".... ... ... ..... . ..... ... ... .... ....") ➞ "spent"

Notes

For more information on tap code, please see the resources section. The code was widely used in WW2 as a way for prisoners to communicate.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

size_t
scandot(const char *s, char *l)
{
	static const char tab[5][5] = {
	    {'a', 'b', 'c', 'd', 'e'},
	    {'f', 'g', 'h', 'i', 'j'},
	    {'l', 'm', 'n', 'o', 'p'},
	    {'q', 'r', 's', 't', 'u'},
	    {'v', 'w', 'x', 'y', 'z'},
	};
	size_t i, r, c;

	r = 0;
	for (i = 0; s[i] == '.'; i++)
		r++;

	if (s[i] == ' ')
		i++;

	c = 0;
	for (; s[i] == '.'; i++)
		c++;

	*l = 0;
	if ((1 <= r && r <= 5) && (1 <= c && c <= 5))
		*l = tab[r - 1][c - 1];

	return i;
}

size_t
writedot(char *b, char c)
{
	size_t i, j, k;
	char *p;

	p = b;
	c = (c == 'k') ? 'c' : c;
	j = (c - 'a' - (c >= 'k')) / 5;
	k = (c - 'a' - (c >= 'k')) % 5;
	for (i = 0; i <= j; i++)
		*p++ = '.';
	*p++ = ' ';
	for (i = 0; i <= k; i++)
		*p++ = '.';

	return p - b;
}

char *
tapcode(const char *s, char *b)
{
	size_t i, j;
	char c, l;

	for (i = j = 0; s[i]; i++) {
		c = tolower(s[i]);
		if (c == '.') {
			i += scandot(s + i, &l) - 1;
			if (l)
				b[j++] = l;
		} else if ('a' <= c && c <= 'z') {
			j += writedot(b + j, c);
			if (s[i + 1])
				b[j++] = ' ';
		}
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	assert(!strcmp(tapcode(s, b), r));
}

int
main(void)
{
	test("break", ". .. .... .. . ..... . . . ...");
	test(".... ... ... ..... . ..... ... ... .... ....", "spent");
	test("greeting", ".. .. .... .. . ..... . ..... .... .... .. .... ... ... .. ..");
	test("confrontation", ". ... ... .... ... ... .. . .... .. ... .... ... ... .... .... . . .... .... .. .... ... .... ... ...");
	test("leadership", "... . . ..... . . . .... . ..... .... .. .... ... .. ... .. .... ... .....");
	test("ankle", ". . ... ... . ... ... . . .....");
	test("extreme", ". ..... ..... ... .... .... .... .. . ..... ... .. . .....");
	test(".... .... ... .... ... ... .. .... .. .. .. ... .... ....", "tonight");
	test("... . ... .... ..... .... . . ... . .... .... ..... ....", "loyalty");
	test(".... .. . ..... .. . . ..... .... .. .... .. . . ... .", "referral");
	test(". ..... ..... ... ... ..... .... .. . ..... .... ... .... ... .. .... ... .... ... ...", "expression");
	test(". . .. . .. . .. .... ... ... .. .... .... .... ..... ....", "affinity");
	test("correspondence", ". ... ... .... .... .. .... .. . ..... .... ... ... ..... ... .... ... ... . .... . ..... ... ... . ... . .....");
	test("atmosphere", ". . .... .... ... .. ... .... .... ... ... ..... .. ... . ..... .... .. . .....");
	test("absolute", ". . . .. .... ... ... .... ... . .... ..... .... .... . .....");
	test("redundancy", ".... .. . ..... . .... .... ..... ... ... . .... . . ... ... . ... ..... ....");
	test("infrastructure", ".. .... ... ... .. . .... .. . . .... ... .... .... .... .. .... ..... . ... .... .... .... ..... .... .. . .....");
	test("... ..... ... .... .. .... ... ... .... ....", "point");
	test("... ..... .... .. . ..... .. . . ..... .... .. . ..... ... ... . ... . .....", "preference");
	test(".. .. .... ..... .. .... . .... . .....", "guide");
	test(". ... .. ... . . .... .. . . . ... .... .... . ..... .... .. .. .... .... ... .... .... .. .... . ...", "characteristic");
	test(". ... ... .... ... .. ... .. . ..... .... .. . ... . .....", "commerce");

	return 0;
}
