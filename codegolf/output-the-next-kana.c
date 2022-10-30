/*

Japanese kana characters correspond to a single sound in the Japanese language.
With the exception of ん (n), every other kana consists of a consonant part and a vowel part.
There is a natural ordering to Japanese kana, a sort of "alphabetical order", which is typically arranged in a 10 by 5 table:

   |   a    i    u    e    o
-----------------------------
*  |   a    i    u    e    o
k  |  ka   ki   ku   ke   ko
s  |  sa   si   su   se   so
t  |  ta   ti   tu   te   to
n  |  na   ni   nu   ne   no
h  |  ha   hi   hu   he   ho
m  |  ma   mi   mu   me   mo
y  |  ya        yu        yo
r  |  ra   ri   ru   re   ro
w  |  wa                  wo

This ordering is called gojuuon, or "fifty sounds", even though some of the fifty cells in the table are in fact empty.

The challenge
Input will be any of the listed kana above, with the exception for wo. Your program or function should output the next kana along in left-to-right, top-to-bottom reading order, e.g:

Input       Output
------------------
a     ->    i
i     ->    u
o     ->    ka
ke    ->    ko
so    ->    ta
ni    ->    nu
ya    ->    yu
yu    ->    yo
wa    ->    wo
wo    ->    (undefined behaviour)
With the exception of an optional single trailing newline, there should be no leading or trailing whitespace in the output.

This is code-golf, so the goal is to minimise program size, in bytes.

Additional notes
In order to keep things simple, this challenge uses Nihon-shiki romanisation. Hepburn romanisation is more common, but has a few kinks which make things more annoying for golf (e.g. si becomes shi, hu becomes fu).

Kana do exist for the empty spots (see Japanese SE), but they were either non-standard or are now obsolete.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
inc(int *n, int *m)
{
	*m += 1;
	if (*m >= 5) {
		*m = 0;
		*n += 1;
	}
}

int
find(const char *s, const char tab[10][5][4], int *n, int *m)
{
	int i, j;

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 5; j++) {
			if (tab[i][j][0] == '\0')
				continue;

			if (!strcmp(s, tab[i][j])) {
				*n = i;
				*m = j;
				inc(n, m);
				return 1;
			}
		}
	}
	return 0;
}

const char *
filter(const char tab[10][5][4], int n, int m)
{
	for (;;) {
		if (n >= 10 || m >= 5)
			break;

		if (tab[n][m][0] != '\0')
			return tab[n][m];

		inc(&n, &m);
	}
	return NULL;
}

const char *
kana(const char *s)
{
	static const char tab[10][5][4] = {
	    {"a", "i", "u", "e", "o"},
	    {"ka", "ki", "ku", "ke", "ko"},
	    {"sa", "si", "su", "se", "so"},
	    {"ta", "ti", "tu", "te", "to"},
	    {"na", "ni", "nu", "ne", "no"},
	    {"ha", "hi", "hu", "he", "ho"},
	    {"ma", "mi", "mu", "me", "mo"},
	    {"ya", "", "yu", "", "yo"},
	    {"ra", "ri", "ru", "re", "ro"},
	    {"wa", "", "", "", "wo"},
	};

	int n, m;

	if (!find(s, tab, &n, &m))
		return NULL;
	return filter(tab, n, m);
}

void
test(const char *s, const char *r)
{
	const char *p;

	p = kana(s);
	if (p == NULL)
		assert(p == r);
	else {
		printf("%s\n", p);
		assert(!strcmp(p, r));
	}
}

int
main(void)
{
	test("a", "i");
	test("i", "u");
	test("o", "ka");
	test("ke", "ko");
	test("so", "ta");
	test("ni", "nu");
	test("ya", "yu");
	test("yu", "yo");
	test("wa", "wo");
	test("wo", NULL);

	return 0;
}
