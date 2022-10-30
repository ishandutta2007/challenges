// Write a program to remove all comments from a C program. Don't forget to
// handle quoted strings and character constants properly. C comments do not
// nest.

#include <stdio.h>

void
quote(FILE *ifp, FILE *ofp, int c)
{
	int d;

	fputc(c, ifp);
	while ((d = fgetc(ifp)) != c) {
		fputc(d, ofp);
		if (d == '\'')
			fputc(fgetc(ifp), ofp);
	}
	fputc(d, ofp);
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
fcom(FILE *ifp, FILE *ofp, int c)
{
	int d;

	if (c == '/') {
		if ((d = fgetc(ifp)) == '*')
			incom(ifp);
		else if (d == '/') {
			fputc(c, ofp);
			fcom(ifp, ofp, d);
		} else {
			fputc(c, ofp);
			fputc(d, ofp);
		}
	} else if (c == '\'' || c == '"')
		quote(ifp, ofp, c);
	else
		fputc(c, ofp);
}

void
rmcom(FILE *ifp, FILE *ofp)
{
	int c;

	while ((c = fgetc(ifp)) != EOF)
		fcom(ifp, ofp, c);
}

int
main(void)
{
	rmcom(stdin, stdout);
	return 0;
}
