// Write a routine ungets(s) that will push back an entire string onto the input.
// Should ungets know about the peek buffer, or should it just use ungetch?

#include <stdio.h>
#include <string.h>
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

void
ungets(const char *s)
{
	size_t i, n;

	n = strlen(s);
	if (n == 0)
		return;
	for (i = n - 1;; i--) {
		ungetch(s[i]);
		if (i == 0)
			break;
	}
}

void
randstr(char *b, size_t n)
{
	size_t i;

	if (n == 0)
		return;
	for (i = 0; i < n; i++)
		b[i] = 'a' + rand() % 26;
	b[n - 1] = '\0';
}

int
main(void)
{
	char str[16];
	size_t i;
	int c;

	srand(time(NULL));
	while ((c = getch()) != EOF) {
		fputc(c, stdout);

		randstr(str, sizeof(str));
		ungets(str);
		for (i = 0; i < sizeof(str) - 1; i++)
			fputc(getch(), stdout);
		fputc('\n', stdout);
	}
	return 0;
}
