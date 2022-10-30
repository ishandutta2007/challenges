// Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\.
// This makes tabs and backspaces visible in an unambiguous way.
#include <stdio.h>

void
spacefilter(FILE *ifp, FILE *ofp)
{
	int c;

	while ((c = fgetc(ifp)) != EOF) {
		switch (c) {
		case '\\':
			fprintf(ofp, "\\\\");
			break;
		case '\t':
			fprintf(ofp, "\\t");
			break;
		case '\b':
			fprintf(ofp, "\\b");
			break;
		default:
			fputc(c, ofp);
			break;
		}
	}
}

int
main(void)
{
	spacefilter(stdin, stdout);
	return 0;
}
