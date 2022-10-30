// Our getch and ungetch do not handle a pushed-back EOF correctly.
// Decided what their properties ought to be if an EOF is pushed back,
// then implement your design.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int peekbuf[BUFSIZ];
int peekpos;

int
getch(void)
{
	return (peekpos > 0) ? peekbuf[--peekpos] : getchar();
}

void
ungetch(int c)
{
	if (peekpos >= BUFSIZ)
		fprintf(stderr, "ungetch: too many characters\n");
	else
		peekbuf[peekpos++] = c;
}

int
main(void)
{
	int c, i, j;

	while ((c = getch()) != EOF) {
		fputc(c, stdout);

		srand(time(NULL));
		j = rand() % 8;
		for (i = 0; i < j; i++)
			ungetch(c);
		for (i = 0; i < j; i++)
			fputc(getch(), stdout);
	}
	return 0;
}
