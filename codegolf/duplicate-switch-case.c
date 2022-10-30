/*

The goal is, having taken a string as input, duplicate each latin letter and "toggle" its case (i.e. uppercase becomes lowercase and vice-versa).

Example inputs & outputs:

Input      Output
bad        bBaAdD
Nice       NniIcCeE
T e S t    Tt eE Ss tT
s E t      sS Ee tT
1!1!1st!   1!1!1sStT!
n00b       nN00bB
(e.g.)     (eE.gG.)
H3l|@!     Hh3lL|@!
The input consists of printable ASCII symbols.

You shouldn't duplicate non-latin letters, numbers, special chars.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
dupsw(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		b[j++] = s[i];
		if ('a' <= s[i] && s[i] <= 'z')
			b[j++] = toupper(s[i]);
		else if ('A' <= s[i] && s[i] <= 'Z')
			b[j++] = tolower(s[i]);
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	dupsw(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("bad", "bBaAdD");
	test("Nice", "NniIcCeE");
	test("T e S t", "Tt eE Ss tT");
	test("s E t", "sS Ee tT");
	test("1!1!1st!", "1!1!1sStT!");
	test("n00b", "nN00bB");
	test("(e.g.)", "(eE.gG.)");
	test("H3l|@!", "Hh3lL|@!");

	return 0;
}
