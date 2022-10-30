// Write a program detab that replaces tabs in the input with the proper
// number of blanks to space to the next tab stop. Assume a fixed set
// of tab stops, say every n columns. Should n be a variable or a symbolic
// parameter?
#include <stdio.h>

void
detab(FILE *fp, int tabstop)
{
	int c, nb, pos;

	nb = 0;
	pos = 1;
	while ((c = fgetc(fp)) != EOF) {
		switch (c) {
		case '\t':
			nb = tabstop - (pos - 1) % tabstop;
			while (nb > 0) {
				putchar(' ');
				pos++;
				nb--;
			}
			break;

		case '\n':
			putchar(c);
			pos = 1;
			break;

		default:
			putchar(c);
			pos++;
			break;
		}
	}
}

int
main(void)
{
	detab(stdin, 4);
	return 0;
}
