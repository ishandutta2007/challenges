// Write a program to print all input lines that are longer than 80 characters.
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
punchcardfilter(FILE *ifp, FILE *ofp)
{
	size_t n;
	char buf[80];
	int c;

	n = 0;
	while ((c = fgetc(ifp)) != EOF) {
		if (n < nelem(buf) - 1)
			buf[n++] = c;
		else if (n == nelem(buf) - 1) {
			buf[n++] = '\0';
			fprintf(ofp, "%s%c", buf, c);
		} else
			fputc(c, ofp);

		if (c == '\n')
			n = 0;
	}
}

int
main(void)
{
	punchcardfilter(stdin, stdout);
	return 0;
}
