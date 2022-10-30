// Write a program that will print arbitrary input in a sensible way. As a minimum,
// it should print non-graphic characters in octal or hexadecimal according to local
// custom, and break long text lines.

#include <stdio.h>
#include <ctype.h>

enum {
	MAXLINE = 128,
	OCTLEN = 6,
};

int
inc(int pos, int n)
{
	if (pos + n < MAXLINE)
		return pos + n;
	putchar('\n');
	return n;
}

void
readl(void)
{
	int pos, c;

	pos = 0;
	while ((c = getchar()) != EOF) {
		if (iscntrl(c) || c == ' ') {
			pos = inc(pos, OCTLEN);
			printf(" \\%03o ", c);
			if (c == '\n') {
				pos = 0;
				putchar('\n');
			}
		} else {
			pos = inc(pos, 1);
			putchar(c);
		}
	}
}

int
main(void)
{
	readl();
	return 0;
}
