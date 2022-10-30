/*

In a board game, a player may pick up a card with several left or right facing arrows, with the number of arrows indicating the number of tiles to move.
The player should move either left or right, depending on the arrow's direction.

Given an array of the arrows contained on a player's cards, return a singular string of arrowheads that are equivalent to all of the arrowheads.

Worked Example

calculateArrowhead([">>", "<<", "<<<"]) ➞ "<<<"
// >> means to move 2 places right
// << means to move 2 places left (cancelling out >>)
// <<< means to move a further 3 places left
// overall, the movement can be written as <<<

Examples

calculateArrowhead([">>>>", "<", "<", "<"]) ➞ ">"

calculateArrowhead([">", "<", ">>", "<", "<<<"]) ➞ "<<"

calculateArrowhead([">>>", "<<<"]) ➞ ""

Notes

Return an empty string if all the arrowheads cancel out.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
arrowhead(const char **s, size_t n, char *b)
{
	size_t i, j;
	long ch, p, dp;

	p = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; s[i][j]; j++) {
			if (s[i][j] == '<')
				p--;
			else if (s[i][j] == '>')
				p++;
		}
	}

	ch = (p > 0) ? '>' : '<';
	dp = (p > 0) ? -1 : 1;
	for (i = 0; p; p += dp)
		b[i++] = ch;
	b[i] = '\0';

	return b;
}

void
test(const char **s, size_t n, const char *r)
{
	char b[128];

	arrowhead(s, n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	const char *s1[] = {
	    ">>>>",
	    "<",
	    "<",
	    "<",
	};
	const char *s2[] = {
	    ">",
	    "<",
	    ">>",
	    "<",
	    "<<<",
	};
	const char *s3[] = {
	    ">>>",
	    "<<<",
	};
	const char *s4[] = {
	    ">>",
	    "<<",
	    "<<<",
	};
	const char *s5[] = {
	    ">",
	    ">>>>>",
	    ">>>>",
	    ">>>>>>>",
	    ">>>>>>>>",
	    ">>>>",
	    ">>>>>>>>",
	};
	const char *s6[] = {
	    "<",
	    ">>>>>>",
	    "<<<<<<<<",
	    "<<<<<<<<<<",
	    ">>>>>>>",
	    ">>>",
	};
	const char *s7[] = {
	    "<<<<",
	    ">>>>>",
	};
	const char *s8[] = {
	    "<<<<<<<<<",
	    "<<<<",
	    ">>>",
	    ">>>>>>>>",
	    ">>>>>>>",
	    "<<<<<",
	};
	const char *s9[] = {
	    ">>>>>>>>>>",
	    "<<",
	    ">>>>>>>>>>",
	};
	const char *s10[] = {
	    ">",
	    "<<<",
	    ">>>>>>>>>>",
	    ">>>>>",
	};
	const char *s11[] = {
	    "<<<<<<<<<",
	    ">>>",
	    "<<<<<",
	};
	const char *s12[] = {
	    ">",
	    "<<",
	};
	const char *s13[] = {
	    "<<<",
	    "<<",
	    "<",
	};
	const char *s14[] = {
	    "<<",
	    "<<<<<<<",
	    ">>>>>>>>>",
	};
	const char *s15[] = {
	    ">>>>>",
	    ">>>>>>>>",
	    "<<<<<<",
	    "<<<<",
	    "<<<<<<<",
	};
	const char *s16[] = {
	    ">>",
	    "<<<<<<<<<",
	    ">>>>>>",
	    "<<<<<",
	};
	const char *s17[] = {
	    ">>>>>>>>>>",
	    ">>>",
	    "<",
	};
	const char *s18[] = {
	    "<<",
	    ">>>>>>",
	    "<<",
	    ">",
	    ">>>",
	    "<<<",
	};
	const char *s19[] = {
	    ">",
	    ">>>>>>>>>>",
	    "<",
	    "<<",
	};
	const char *s20[] = {
	    "<<<<",
	    ">>>>",
	    ">>",
	    "<<<<<<<<<",
	};
	const char *s21[] = {
	    ">>>>>>>",
	    ">>",
	    "<<<<<<<<<<",
	    ">>>>",
	    ">>>>>>>>>",
	    "<<",
	    ">>>>>>>>>",
	};
	const char *s22[] = {
	    "<<<<<<<<<",
	    ">>>>>>",
	    ">>",
	    "<<<<<<<",
	};
	const char *s23[] = {
	    ">>>",
	    "<<<",
	    ">>>>>>>>>>",
	    ">>",
	    ">>>",
	    "<<",
	    "<<<<<<",
	};
	const char *s24[] = {
	    ">>>>>>>>>",
	    ">>>>>>>>>",
	    "<<<<<",
	    ">>>>>>>>",
	    ">>>>>>>",
	};

	test(s1, nelem(s1), ">");
	test(s2, nelem(s2), "<<");
	test(s3, nelem(s3), "");
	test(s4, nelem(s4), "<<<");
	test(s5, nelem(s5), ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	test(s6, nelem(s6), "<<<");
	test(s7, nelem(s7), ">");
	test(s8, nelem(s8), "");
	test(s9, nelem(s9), ">>>>>>>>>>>>>>>>>>");
	test(s10, nelem(s10), ">>>>>>>>>>>>>");
	test(s11, nelem(s11), "<<<<<<<<<<<");
	test(s12, nelem(s12), "<");
	test(s13, nelem(s13), "<<<<<<");
	test(s14, nelem(s14), "");
	test(s15, nelem(s15), "<<<<");
	test(s16, nelem(s16), "<<<<<<");
	test(s17, nelem(s17), ">>>>>>>>>>>>");
	test(s18, nelem(s18), ">>>");
	test(s19, nelem(s19), ">>>>>>>>");
	test(s20, nelem(s20), "<<<<<<<");
	test(s21, nelem(s21), ">>>>>>>>>>>>>>>>>>>");
	test(s22, nelem(s22), "<<<<<<<<");
	test(s23, nelem(s23), ">>>>>>>");
	test(s24, nelem(s24), ">>>>>>>>>>>>>>>>>>>>>>>>>>>>");

	return 0;
}
