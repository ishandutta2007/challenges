/*

A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].

Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {) occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type. There are three types of matched pairs of brackets: [], {}, and ().

A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. For example, {[(])} is not balanced because the contents in between { and } are not balanced.
The pair of square brackets encloses a single, unbalanced opening bracket, (, and the pair of parentheses encloses a single, unbalanced closing square bracket, ].

By this logic, we say a sequence of brackets is balanced if the following conditions are met:

    It contains no unmatched brackets.
    The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets.

Given N strings of brackets, determine whether each sequence of brackets is balanced. If a string is balanced, return YES. Otherwise, return NO. 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *
balanced(const char *s)
{
	static const int op[256] = {
	    ['{'] = 0x1 | (0 << 2),
	    ['('] = 0x1 | (1 << 2),
	    ['['] = 0x1 | (2 << 2),
	    ['}'] = 0x2 | (0 << 2) | ('{' << 8),
	    [')'] = 0x2 | (1 << 2) | ('(' << 8),
	    [']'] = 0x2 | (2 << 2) | ('[' << 8),
	};

	size_t f[3], i, j, l;
	char *p;
	int c, r;

	p = strdup(s);
	if (p == NULL)
		return "OOM";

	f[0] = f[1] = f[2] = 0;
	r = 1;
	for (i = j = 0; (c = (s[i] & 0xff)); i++) {
		l = (op[c] >> 2) & 0x3;
		switch (op[c] & 0x3) {
		case 0x1:
			p[j++] = c;
			f[l]++;
			break;

		case 0x2:
			if (f[l] == 0 || j == 0 || (p[--j] != ((op[c] >> 8) & 0xff)))
				goto nomatch;
			f[l]--;
			break;
		}
	}

	if (f[0] != 0 || f[1] != 0 || f[2] != 0) {
	nomatch:
		r = 0;
	}

	free(p);
	return (r == 1) ? "YES" : "NO";
}

int
main(void)
{
	printf("%s\n", balanced("{[()]}"));
	printf("%s\n", balanced("{[(])}"));
	printf("%s\n", balanced("{{[[(())]]}}"));

	printf("%s\n", balanced("[{()}"));
	printf("%s\n", balanced("[]"));
	printf("%s\n", balanced("[]{}[][[]]"));
	printf("%s\n", balanced("[]{}[][[]](()"));
	printf("%s\n", balanced("([)]"));
	return 0;
}
