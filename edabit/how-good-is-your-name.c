/*

Create a function that takes a string of name and checks how much good is the given name.
A preloaded dictionary of alphabet scores is available in the Code tab.
Add up the letters of your name to get the total score.

const scores = {"A": 100, "B": 14, "C": 9, "D": 28, "E": 145, "F": 12, "G": 3,
"H": 10, "I": 200, "J": 100, "K": 114, "L": 100, "M": 25,
"N": 450, "O": 80, "P": 2, "Q": 12, "R": 400, "S": 113,
"T": 405, "U": 11, "V": 10, "W": 10, "X": 3, "Y": 210, "Z": 23}

Return your result as per the following rules:

score <= 60:   "NOT TOO GOOD"

61 <= score <= 300:  "PRETTY GOOD"

301 <= score <= 599:  "VERY GOOD"

score >= 600:  "THE BEST"

Examples

nameScore("MUBASHIR") ➞ "THE BEST"

nameScore("YOU") ➞ "VERY GOOD"

nameScore("MATT") ➞ "THE BEST"

nameScore("PUBG") ➞ "NOT TOO GOOD"

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char *
namescore(const char *s)
{
	static const unsigned tab[256] = {
	    ['A'] = 100,
	    ['B'] = 14,
	    ['C'] = 9,
	    ['D'] = 28,
	    ['E'] = 145,
	    ['F'] = 12,
	    ['G'] = 3,
	    ['H'] = 10,
	    ['I'] = 200,
	    ['J'] = 100,
	    ['K'] = 114,
	    ['L'] = 100,
	    ['M'] = 25,
	    ['N'] = 450,
	    ['O'] = 80,
	    ['P'] = 2,
	    ['Q'] = 12,
	    ['R'] = 400,
	    ['S'] = 113,
	    ['T'] = 405,
	    ['U'] = 11,
	    ['V'] = 10,
	    ['W'] = 10,
	    ['X'] = 3,
	    ['Y'] = 210,
	    ['Z'] = 23,
	};

	unsigned v;
	size_t i;

	v = 0;
	for (i = 0; s[i]; i++)
		v += tab[toupper(s[i]) & 0xff];

	if (v <= 60)
		return "NOT TOO GOOD";
	if (61 <= v && v <= 300)
		return "PRETTY GOOD";
	if (301 <= v && v <= 599)
		return "VERY GOOD";
	if (v >= 600)
		return "THE BEST";
	return NULL;
}

void
test(const char *s, const char *r)
{
	assert(!strcmp(namescore(s), r));
}

int
main(void)
{
	test("MUBASHIR", "THE BEST");
	test("MATT", "THE BEST");
	test("PAKISTAN", "THE BEST");
	test("AIRFORCE", "THE BEST");
	test("GUV", "NOT TOO GOOD");
	test("PUBG", "NOT TOO GOOD");
	test("ME", "PRETTY GOOD");
	test("BOB", "PRETTY GOOD");
	test("JLJ", "PRETTY GOOD");
	test("YOU", "VERY GOOD");
	test("FABIO", "VERY GOOD");
	test("ROBBY", "THE BEST");
	test("BILL GATES", "THE BEST");
	return 0;
}
