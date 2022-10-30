// Rewrite readlines to store lines in an array supplied by main,
// rather than calling alloc to maintain storage.
// How much faster is the program?

#include <stdio.h>
#include <string.h>

enum {
	MAXLEN = 1000,
	MAXLINES = 100,
	MAXSTORE = 10000,
};

int
readlines(char **lines, char *linestore, int maxlines)
{
	char line[MAXLEN], *linestop, *p;
	int len, nlines;

	p = linestore;
	linestop = linestore + MAXSTORE;
	nlines = 0;
	while (fgets(line, MAXLEN, stdin)) {
		if (nlines >= maxlines || linestop - p < len)
			return -1;

		len = strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		strcpy(p, line);
		lines[nlines++] = p;
		p += len;
	}
	return nlines;
}

int
main(void)
{
	static char linestore[MAXSTORE];
	static char *lines[MAXLINES];
	int i, nlines;

	nlines = readlines(lines, linestore, MAXLINES);
	for (i = 0; i < nlines; i++)
		printf("%d: \"%s\"\n", i, lines[i]);
	return 0;
}
