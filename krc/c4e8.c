// Suppose that there will never be more than one character of pushback.
// Modify getch and ungetch accordingly.

#include <stdio.h>

int peekc;

int
getch(void)
{
	int c;
	if (peekc != 0)
		c = peekc;
	else
		c = getchar();
	peekc = 0;
	return c;
}

void
ungetch(int c)
{
	if (peekc != 0)
		fprintf(stderr, "ungetch: too many characters\n");
	else
		peekc = c;
}

int
main(void)
{
	int c;

	while ((c = getch()) != EOF) {
		fputc(c, stdout);
		ungetch(c);
		fputc(getch(), stdout);
	}
	return 0;
}
