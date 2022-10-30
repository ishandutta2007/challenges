// Rewrite the postfix calculator of Chapter 4 to use scanf and/or sscanf
// to do the input and number conversion.

#include <stdio.h>
#include <ctype.h>

enum {
	NUMBER = '0',
};

void
appendc(char *s, size_t *i, size_t n, char c)
{
	if (*i < n) {
		if (*i + 1 == n)
			c = '\0';
		s[(*i)++] = c;
	}
}

int
getop(char *s, size_t n)
{
	static char lastc[] = " ";
	size_t i;
	char c;
	int rc;

	if (n == 0)
		return EOF;

	sscanf(lastc, "%c", &c);
	lastc[0] = ' ';
	while (c == ' ' || c == '\t') {
		if (scanf("%c", &c) == EOF)
			c = EOF;
	}

	i = 0;
	appendc(s, &i, n, c);
	if (!isdigit(c) && c != '.') {
		appendc(s, &i, n, '\0');
		return c;
	}

	if (isdigit(c)) {
		do {
			rc = scanf("%c", &c);
			appendc(s, &i, n, c);
			if (!isdigit(c))
				break;
		} while (rc != EOF);
	}
	if (c == '.') {
		do {
			rc = scanf("%c", &c);
			appendc(s, &i, n, c);
			if (!isdigit(c))
				break;
		} while (rc != EOF);
	}
	s[i - 1] = '\0';

	if (rc != EOF)
		lastc[0] = c;

	return NUMBER;
}

int
main(void)
{
	char buf[BUFSIZ];
	int op;

	while ((op = getop(buf, sizeof(buf))) != EOF) {
		printf("token(%d)", op);
		if (op == NUMBER)
			printf(" lit(%s)", buf);
		printf("\n");
	}
	return 0;
}
