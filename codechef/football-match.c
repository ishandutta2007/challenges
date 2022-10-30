/*

You are given a score log of a football match between two teams. Every time when one of the teams scored a goal, the name of that team was written in the score log on a separate line.

At the end of the match, the team that scored strictly more goals than the other team wins the match. If both teams scored an equal number of goals, the match ends in a tie.
Determine the name of the winning team or that the match ended in a tie.

*/
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
winner(const char **s, size_t n)
{
	size_t a, b, i, l;

	a = b = l = 0;
	for (i = 0; i < n; i++) {
		if (!strcmp(s[0], s[i]))
			a++;
		else {
			b++;
			l = i;
		}
	}
	if (a == b)
		return "Draw";
	if (a > b)
		return s[0];
	return s[l];
}

int
main(void)
{
	const char *a[] = {
	    "ab",
	    "bc",
	    "bc",
	    "ab",
	};
	printf("%s\n", winner(a, nelem(a)));

	const char *b[] = {
	    "xxx",
	    "yyy",
	    "yyy",
	};
	printf("%s\n", winner(b, nelem(b)));

	const char *c[] = {
	    "a",
	    "a",
	    "b",
	    "b",
	    "a",
	};
	printf("%s\n", winner(c, nelem(c)));

	return 0;
}
