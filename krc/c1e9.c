// Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
#include <stdio.h>

void
filter(FILE *ifp, FILE *ofp)
{
	int c, s;

	s = 0;
	while ((c = fgetc(ifp)) != EOF) {
		if (c == ' ' && s)
			continue;
		s = (c == ' ');
		fputc(c, ofp);
	}
}

int
main(void)
{
	filter(stdin, stdout);
	return 0;
}
