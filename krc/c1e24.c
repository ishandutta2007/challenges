// Write a program to check a C program for rudimentary syntax errors like
// unbalanced parentheses, brackets, and braces. Don't forget about quotes, both
// single and double, escape sequences, and comments. (This program is hard if
// you do it in full generality.)

#include <stdio.h>

int brace, brack, paren;

void
search(int c)
{
	switch (c) {
	case '{':
		brace++;
		break;
	case '}':
		brace--;
		break;
	case '[':
		brack++;
		break;
	case ']':
		brack--;
		break;
	case '(':
		paren++;
		break;
	case ')':
		paren--;
		break;
	}
}

void
incom(FILE *ifp)
{
	int c, d;

	c = fgetc(ifp);
	d = fgetc(ifp);
	while (c != '*' || d != '/') {
		c = d;
		d = fgetc(ifp);
	}
}

void
quote(FILE *ifp, int c)
{
	int d;

	while ((d = fgetc(ifp)) != c) {
		if (d == '\\')
			fgetc(ifp);
	}
}

void
check(FILE *ifp, FILE *ofp)
{
	int c;

	while ((c = fgetc(ifp)) != EOF) {
		if (c == '/') {
			if ((c = fgetc(ifp)) == '*')
				incom(ifp);
			else
				search(c);
		} else if (c == '\'' || c == '"')
			quote(ifp, c);
		else
			search(c);

		if (brace < 0) {
			fprintf(ofp, "Unbalanced braces\n");
			brace = 0;
		} else if (brack < 0) {
			fprintf(ofp, "Unbalanced brackets\n");
			brack = 0;
		} else if (paren < 0) {
			fprintf(ofp, "Unbalanced parentheses\n");
			paren = 0;
		}
	}

	if (brace > 0)
		fprintf(ofp, "Unbalanced braces\n");
	if (brack > 0)
		fprintf(ofp, "Unbalanced brackets\n");
	if (paren > 0)
		fprintf(ofp, "Unbalanced parentheses\n");
}

int
main(void)
{
	check(stdin, stdout);
	return 0;
}
