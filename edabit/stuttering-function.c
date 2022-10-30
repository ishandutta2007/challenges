/*

Write a function that stutters a word as if someone is struggling to read it.
The first two letters are repeated twice with an ellipsis ... and space after each, and then the word is pronounced with a question mark ?.

Examples

stutter("incredible") ➞ "in... in... incredible?"

stutter("enthusiastic") ➞ "en... en... enthusiastic?"

stutter("outstanding") ➞ "ou... ou... outstanding?"

Notes

Assume all input is in lower case and at least two characters long.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
stutter(const char *s, char *b, size_t n)
{
	if (!s[0] || !s[1]) {
		snprintf(b, n, "%s", s);
		return b;
	}

	snprintf(b, n, "%c%c... %c%c... %s?", s[0], s[1], s[0], s[1], s);
	return b;
}

int
main(void)
{
	static const char *stab[] = {
	    "increasing",
	    "adventures",
	    "enticing",
	    "unacceptable",
	    "accountable",
	    "incredible",
	    "exquisite",
	    "am",
	    "enduring",
	    "outstanding",
	    "astonishing",
	    "astounding",
	    "impressive",
	    "revolutionize",
	    "recurring",
	    "recollection",
	    "so",
	    "gorgeous",
	    "captivating",
	    "enthusiastic",
	};
	static const char *rtab[] = {
	    "in... in... increasing?",
	    "ad... ad... adventures?",
	    "en... en... enticing?",
	    "un... un... unacceptable?",
	    "ac... ac... accountable?",
	    "in... in... incredible?",
	    "ex... ex... exquisite?",
	    "am... am... am?",
	    "en... en... enduring?",
	    "ou... ou... outstanding?",
	    "as... as... astonishing?",
	    "as... as... astounding?",
	    "im... im... impressive?",
	    "re... re... revolutionize?",
	    "re... re... recurring?",
	    "re... re... recollection?",
	    "so... so... so?",
	    "go... go... gorgeous?",
	    "ca... ca... captivating?",
	    "en... en... enthusiastic?",
	};

	char b[128];
	size_t i;

	for (i = 0; i < nelem(stab); i++) {
		stutter(stab[i], b, sizeof(b));
		assert(!strcmp(b, rtab[i]));
	}

	return 0;
}
