/*

Create a function that will build a staircase using the underscore _ and hash # symbols.
A positive value denotes the staircase's upward direction and downwards for a negative value.

Examples

staircase(3) ➞ "__#\n_##\n###"
__#
_##
###

staircase(7) ➞ "______#\n_____##\n____###\n___####\n__#####\n_######\n#######"
______#
_____##
____###
___####
__#####
_######
#######

staircase(2) ➞ "_#\n##"
_#
##

staircase(-8) ➞ "########\n_#######\n__######\n___#####\n____####\n_____###\n______##\n_______#"
########
_#######
__######
___#####
____####
_____###
______##
_______#

Notes

    All inputs are either positive or negative values.
    The string to be returned is adjoined with the newline character (\n).
    A recursive version of this challenge can be found in here.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
staircase(int n, char *b)
{
	int f, i, j, k;
	size_t l;

	f = 0;
	if (n < 0) {
		n = -n;
		f = 1;
	}

	l = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			k = (f) ? i : n - i - 1;
			b[l++] = (j < k) ? '_' : '#';
		}
		if (i + 1 < n)
			b[l++] = '\n';
	}
	b[l] = '\0';
	return b;
}

int
main(void)
{
	static const int itab[] = {
	    0,
	    3,
	    7,
	    2,
	    -8,
	    4,
	    -12,
	    11,
	    -6,
	};
	static const char *otab[] = {
	    "",
	    "__#\n_##\n###",
	    "______#\n_____##\n____###\n___####\n__#####\n_######\n#######",
	    "_#\n##",
	    "########\n_#######\n__######\n___#####\n____####\n_____###\n______##\n_______#",
	    "___#\n__##\n_###\n####",
	    "############\n_###########\n__##########\n___#########\n____########\n_____#######\n______######\n_______#####\n________####\n_________###\n__________##\n___________#",
	    "__________#\n_________##\n________###\n_______####\n______#####\n_____######\n____#######\n___########\n__#########\n_##########\n###########",
	    "######\n_#####\n__####\n___###\n____##\n_____#",
	};

	char b[256];
	size_t i;

	for (i = 0; i < nelem(itab); i++) {
		staircase(itab[i], b);
		printf("%s\n\n", b);
		assert(!strcmp(b, otab[i]));
	}

	return 0;
}
