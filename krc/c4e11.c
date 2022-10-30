// Modify getopt so that it doesn't need to use ungetch.
// Hint: use an internal static variable

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

enum {
	NUMBER = '0',
};

int
scnprintf(char *str, size_t size, const char *fmt, ...)
{
	va_list ap;
	size_t n;

	va_start(ap, fmt);
	n = vsnprintf(str, size, fmt, ap);
	va_end(ap);
	return min(size, n);
}

int
getop(char *s, size_t n)
{
	static int lastc = 0;
	size_t l;
	int c;

	if (lastc == 0)
		c = fgetc(stdin);
	else {
		c = lastc;
		lastc = 0;
	}

	for (;;) {
		if (c != ' ' && c != '\t')
			break;
		c = fgetc(stdin);
	}
	l = 0;
	l += scnprintf(s + l, n - l, "%c", c);

	if (!isdigit(c) && c != '.')
		return c;
	if (isdigit(c)) {
		for (;;) {
			c = fgetc(stdin);
			l += scnprintf(s + l, n - l, "%c", c);
			if (!isdigit(c))
				break;
		}
	}
	if (c == '.') {
		for (;;) {
			c = fgetc(stdin);
			l += scnprintf(s + l, n - l, "%c", c);
			if (!isdigit(c))
				break;
		}
	}
	if (c != EOF)
		lastc = c;
	return NUMBER;
}

int
main(void)
{
	char buf[BUFSIZ];
	int op;

	while ((op = getop(buf, sizeof(buf))) != EOF) {
		if (isprint(op))
			printf("op: %c lit: %s\n", op, buf);
	}
	return 0;
}
