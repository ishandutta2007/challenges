// Write a program that prints its input one word per line.
#include <stdio.h>
#include <ctype.h>

void
owpl(FILE *ifp, FILE *ofp)
{
	int c, s, t;

	s = 0;
	while ((c = fgetc(ifp)) != EOF) {
		if ((t = isspace(c)) && s)
			continue;
		s = t;
		fputc(s ? '\n' : c, ofp);
	}
}

int
main(void)
{
	owpl(stdin, stdout);
	return 0;
}
