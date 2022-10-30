// An alternate organization uses getline to read an entire input line;
// this makes getch and ungetch unnecessary. Revise the calculator to use
// this approach.

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
	static char line[BUFSIZ];
	static int li;
	int l;

loop:
	if (line[li] == EOF)
		return EOF;

	if (line[li] == '\0') {
		if (!fgets(line, sizeof(line), stdin))
			return EOF;
		li = 0;
	}

	while (isspace(line[li]))
		li++;

	if (line[li] == '\0')
		goto loop;

	if (!isdigit(line[li]) && line[li] != '.') {
		scnprintf(s, n, "%c", line[li]);
		return line[li++];
	}

	if (line[li] == '\0')
		goto loop;

	l = 0;
	for (; isdigit(line[li]); li++)
		l += scnprintf(s + l, n - l, "%c", line[li]);
	for (; line[li] == '.' || isdigit(line[li]); li++)
		l += scnprintf(s + l, n - l, "%c", line[li]);
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
