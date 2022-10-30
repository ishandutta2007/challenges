/*

Create a function which takes in a sentence str and a string of characters chars and return the sentence but with all the specified characters removed.
Examples

stripSentence("the quick brown fox jumps over the lazy dog", "aeiou") ➞ "th qck brwn fx jmps vr th lzy dg"

stripSentence("the hissing snakes sinisterly slither across the rustling leaves", "s") ➞ "the hiing nake initerly lither acro the rutling leave"

stripSentence("gone, reduced to atoms", "go, muscat nerd") ➞ ""

Notes

    You may be asked to remove punctuation and spaces.
    Return an empty string if every charcter is specified (see example #3).
    All tests will be in lowercase.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
stripsentence(char *s, const char *p)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (!strchr(p, s[i]))
			s[j++] = s[i];
	}
	s[j] = '\0';
	return s;
}

int
main(void)
{
	char s1[] = "the quick brown fox jumps over the lazy dog";
	char s2[] = "the hissing snakes sinisterly slither across the rustling leaves";
	char s3[] = "gone, reduced to atoms";
	char s4[] = "uh oh i made a typo please fixq it for me";
	char s5[] = "sphinx of black quartz, judge my vow!";
	char s6[] = "exclamation! marks! and! the! letter! x! arxxxxxxxxexxxxxx! rxxexxxallxxxxy! anxxxnoxyixxxxxxxngxxxxxx!xx";
	char s7[] = "!!!!!!!!!!!!!!!!!!!!!!!";
	char s8[] = "cat rat eat pat eat sat";
	char s9[] = "abc";
	char s10[] = "allegro andante";

	char p1[] = "aeiou";
	char p2[] = "s";
	char p3[] = "go, muscat nerd";
	char p4[] = "q";
	char p5[] = "sgwj";
	char p6[] = "x!";
	char p7[] = "?";
	char p8[] = "at";
	char p9[] = "def";
	char p10[] = "aaaaaaaaa";

	char r1[] = "th qck brwn fx jmps vr th lzy dg";
	char r2[] = "the hiing nake initerly lither acro the rutling leave";
	char r3[] = "";
	char r4[] = "uh oh i made a typo please fix it for me";
	char r5[] = "phinx of black quartz, ude my vo!";
	char r6[] = "eclamation marks and the letter  are really annoying";
	char r7[] = "!!!!!!!!!!!!!!!!!!!!!!!";
	char r8[] = "c r e p e s";
	char r9[] = "abc";
	char r10[] = "llegro ndnte";

	assert(strcmp(stripsentence(s1, p1), r1) == 0);
	assert(strcmp(stripsentence(s2, p2), r2) == 0);
	assert(strcmp(stripsentence(s3, p3), r3) == 0);
	assert(strcmp(stripsentence(s4, p4), r4) == 0);
	assert(strcmp(stripsentence(s5, p5), r5) == 0);
	assert(strcmp(stripsentence(s6, p6), r6) == 0);
	assert(strcmp(stripsentence(s7, p7), r7) == 0);
	assert(strcmp(stripsentence(s8, p8), r8) == 0);
	assert(strcmp(stripsentence(s9, p9), r9) == 0);
	assert(strcmp(stripsentence(s10, p10), r10) == 0);

	return 0;
}
