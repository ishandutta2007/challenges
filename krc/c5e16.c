// Add the -d ("directory order") option, which makes comparisons
// only on letters, numbers, and blanks.
// Make sure it works in conjunction with -f.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

enum {
	NUMERIC = 1,
	DECR = 2,
	FOLD = 4,
	DIR = 8,
	LENGTH = 128,
	LINES = 100,
};

int option = 0;

void
usage(void)
{
	fprintf(stderr, "usage: sort -[dfnr]\n");
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
charcmp(const void *a, const void *b)
{
	int fold, dir;
	const char *s, *t;
	char p, q;

	fold = option & FOLD;
	dir = option & DIR;

	s = a;
	t = b;
	do {
		if (dir) {
			while (!isalnum(*s) && *s != ' ' && *s != '\0')
				s++;
			while (!isalnum(*t) && *t != ' ' && *t != '\0')
				t++;
		}
		p = fold ? tolower(*s) : *s;
		s++;
		q = fold ? tolower(*t) : *t;
		t++;
		if (p == q && p == '\0')
			return 0;
	} while (p == q);
	return p - q;
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
			case 'd':
				option |= DIR;
				break;
			case 'f':
				option |= FOLD;
				break;
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
	else if (option & FOLD)
		qsort(lines, 0, nlines - 1, charcmp);
	else
		qsort(lines, 0, nlines - 1, xstrcmp);
	writelines(lines, nlines, option & DECR);

	for (i = 0; i < nlines; i++)
		free(lines[i]);

	return 0;
}
