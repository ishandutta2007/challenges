/*

Write a function that returns true if a given name can generate an array of words.

Examples

anagram("Justin Bieber", ["injures", "ebb", "it"]) ➞ true

anagram("Natalie Portman", ["ornamental", "pita"]) ➞ true

anagram("Chris Pratt", ["chirps", "rat"]) ➞ false
// Not all letters are used 

anagram("Jeff Goldblum", ["jog", "meld", "bluffs"]) ➞ false
// "s" does not exist in the original name

Notes

    Each letter in the name may only be used once.
    All letters in the name must be used.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
anagram(const char *s, const char **t, size_t n)
{
	size_t h[256];
	size_t c, i, j;
	int p;

	memset(h, 0, sizeof(h));
	for (i = c = 0; s[i]; i++) {
		if (isspace(s[i]))
			continue;

		p = tolower(s[i]);
		h[p]++;
		c++;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; t[i][j]; j++) {
			p = tolower(t[i][j]);
			if (!h[p] || !c)
				return false;
			h[p]--;
			c--;
		}
	}

	return !c;
}

int
main(void)
{
	const char *s1 = "Justin Bieber";
	const char *t1[] = {"injures", "ebb", "it"};

	const char *s2 = "Natalie Portman";
	const char *t2[] = {"ornamental", "pita"};

	const char *s3 = "Emma Watson";
	const char *t3[] = {"mows", "meant", "a"};

	const char *s4 = "Daniel Radcliffe";
	const char *t4[] = {"clarified", "elf", "and"};

	const char *s5 = "Tom Hiddleston";
	const char *t5[] = {"tenths", "mood", "lid"};

	const char *s6 = "Blake Lively";
	const char *t6[] = {"key", "veal", "bill"};

	const char *s7 = "Ryan Reynolds";
	const char *t7[] = {"yonder", "sly", "ran"};

	const char *s8 = "Kristen Stewart";
	const char *t8[] = {"trinkets", "war", "set"};

	const char *s9 = "Chris Pratt";
	const char *t9[] = {"chirps", "rat"};

	const char *s10 = "Jeff Goldblum";
	const char *t10[] = {"jog", "meld", "bluffs"};

	const char *s11 = "Taylor Swift";
	const char *t11[] = {"stratify", "ow"};

	const char *s12 = "Adam Levine";
	const char *t12[] = {"medieval", "man"};

	const char *s13 = "Blake Shelton";
	const char *t13[] = {"betoken", "all", "she"};

	const char *s14 = "Miley Cyrus";
	const char *t14[] = {"lyric", "my", "suer"};

	const char *s15 = "Matt Damon";
	const char *t15[] = {"madman"};

	const char *s16 = "Graham Norton";
	const char *t16[] = {"graham", "not", "or"};

	assert(anagram(s1, t1, nelem(t1)) == true);
	assert(anagram(s2, t2, nelem(t2)) == true);
	assert(anagram(s3, t3, nelem(t3)) == true);
	assert(anagram(s4, t4, nelem(t4)) == true);
	assert(anagram(s5, t5, nelem(t5)) == true);
	assert(anagram(s6, t6, nelem(t6)) == true);
	assert(anagram(s7, t7, nelem(t7)) == true);
	assert(anagram(s8, t8, nelem(t8)) == true);
	assert(anagram(s9, t9, nelem(t9)) == false);
	assert(anagram(s10, t10, nelem(t10)) == false);
	assert(anagram(s11, t11, nelem(t11)) == false);
	assert(anagram(s12, t12, nelem(t12)) == false);
	assert(anagram(s13, t13, nelem(t13)) == false);
	assert(anagram(s14, t14, nelem(t14)) == false);
	assert(anagram(s15, t15, nelem(t15)) == false);
	assert(anagram(s16, t16, nelem(t16)) == false);

	return 0;
}
