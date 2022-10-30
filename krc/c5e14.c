// Modify the sort program to handle a -r flag,
// which indicates sorting in reverse (decreasing) order.
// Be sure that -r works with -n.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum {
	NUMERIC = 1,
	DECR = 2,
	LENGTH = 128,
	LINES = 100,
};

int option = 0;

void
usage(void)
{
	fprintf(stderr, "usage: sort -[nr]\n");
	exit(2);
}

int
readlines(char *lines[], int maxlen, int maxlines)
{
	char *p;
	int i;

	for (i = 0; i < maxlines; i++)
		lines[i] = NULL;
	for (i = 0; i < maxlines; i++) {
		lines[i] = malloc(maxlen);
		if (!lines[i])
			break;
		if (!fgets(lines[i], maxlen, stdin)) {
			free(lines[i]);
			break;
		}
		if ((p = strchr(lines[i], '\n')))
			*p = '\0';
	}
	return i;
}

void
writelines(char *lines[], int nlines, int decr)
{
	int i;

	if (decr) {
		for (i = nlines - 1; i >= 0; i--)
			printf("%s\n", lines[i]);
	} else {
		for (i = 0; i < nlines; i++)
			printf("%s\n", lines[i]);
	}
}

int
numcmp(const void *a, const void *b)
{
	double x, y;

	x = atof(a);
	y = atof(b);
	if (x < y)
		return -1;
	if (x > y)
		return 1;
	return 0;
}

int
xstrcmp(const void *a, const void *b)
{
	return strcmp(a, b);
}

int
main(int argc, char *argv[])
{
	char *lines[LINES];
	int i, c, nlines;

	while (--argc > 0 && (*++argv)[0] == '-') {
		while ((c = *++argv[0])) {
			switch (c) {
			case 'n':
				option |= NUMERIC;
				break;
			case 'r':
				option |= DECR;
				break;
			default:
				fprintf(stderr, "sort: illegal option %c\n", c);
				argc = 1;
				break;
			}
		}
	}
	if (argc)
		usage();

	nlines = readlines(lines, LENGTH, LINES);
	if (nlines <= 0)
		return 0;

	if (option & NUMERIC)
		qsort(lines, 0, nlines - 1, numcmp);
	else
		qsort(lines, 0, nlines - 1, xstrcmp);
	writelines(lines, nlines, option & DECR);

	for (i = 0; i < nlines; i++)
		free(lines[i]);

	return 0;
}
