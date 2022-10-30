/*

We are to write the letters of a given string S, from left to right into lines. Each line has maximum width 100 units,
and if writing a letter would cause the width of the line to exceed 100 units,
it is written on the next line. We are given an array widths,
an array where widths[0] is the width of 'a',
widths[1] is the width of 'b', ..., and widths[25] is the width of 'z'.

Now answer two questions: how many lines have at least one character from S, and what is the width used by the last such line?
Return your answer as an integer list of length 2.

Note:

The length of S will be in the range [1, 1000].
S will only contain lowercase letters.
widths is an array of length 26.
widths[i] will be in the range of [2, 10].

*/

#include <stdio.h>

int
numlines(int *w, const char *s, int *l, int *d)
{
	size_t i;
	char c;
	int t;

	*l = 1;
	*d = 0;
	for (i = 0; (c = s[i]); i++) {
		if (!('a' <= c && c <= 'z'))
			return -1;

		t = w[s[i] - 'a'];
		*d += t;
		if (*d > 100) {
			(*l)++;
			*d = t;
		}
	}

	return 0;
}

int
main(void)
{
	int l, d;

	int w1[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	int w2[] = {4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};

	char s1[] = "abcdefghijklmnopqrstuvwxyz";
	char s2[] = "bbbcccdddaaa";

	numlines(w1, s1, &l, &d);
	printf("%d %d\n", l, d);

	numlines(w2, s2, &l, &d);
	printf("%d %d\n", l, d);

	return 0;
}
