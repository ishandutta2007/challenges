// Add a field-handling capability, so sorting may be done on fields
// within lines. Each field sorted according to an independent set of
// options. (The index for this book was sorted with -df
// for the index category and -n for the page numbers.)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

enum {
	NUMERIC = 1,
	DECR = 2,
	FOLD = 4,
	DIR = 8,
	LINES = 100,
	MAXSTR = 100,
	MAXLINES = 100,
};

int option = 0;
int pos1 = 0;
int pos2 = 0;

void
fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

int
readlines(char **lines, int maxlen, int maxlines)
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

void
substr(const char *s, char *str, int maxstr)
{
	int i, j, len;

	len = strlen(s);
	if (pos2 > 0 && len > pos2)
		len = pos2;
	else if (pos2 > 0 && len < pos2)
		fatal("substr: string too short");
	for (j = 0, i = pos1; i < len && i < maxstr; i++, j++)
		str[j] = str[i];
	str[j] = '\0';
}

int
numcmp(const void *a, const void *b)
{
	const char *s1, *s2;
	char str[MAXSTR];
	double v1, v2;

	s1 = a;
	s2 = b;
	substr(s1, str, sizeof(str));
	v1 = atof(str);
	substr(s2, str, sizeof(str));
	v2 = atof(str);
	if (v1 < v2)
		return -1;
	if (v1 > v2)
		return 1;
	return 0;
}

int
charcmp(const void *a, const void *b)
{
	int i, j, endpos, xendpos;
	int fold, dir;
	const char *s, *t;
	char p, q;

	fold = option & FOLD;
	dir = option & DIR;

	s = a;
	t = b;
	i = j = pos1;
	if (pos2 > 0)
		endpos = pos2;
	else if ((endpos = strlen(s)) > (xendpos = strlen(t)))
		endpos = xendpos;
	do {
		if (dir) {
			while (i < endpos && !isalnum(s[i]) && s[i] != ' ' && s[i] != '\0')
				i++;
			while (j < endpos && !isalnum(t[j]) && t[j] != ' ' && t[j] != '\0')
				j++;
		}
		if (i < endpos && j < endpos) {
			p = fold ? tolower(s[i]) : s[i];
			i++;
			q = fold ? tolower(t[j]) : t[j];
			j++;
			if (p == q && p == '\0')
				return 0;
		}
	} while (p == q && i < endpos && j < endpos);

	return p - q;
}

void
usage(void)
{
	fatal("usage: sort -dfnr [+pos1] [-pos2]");
}

void
readargs(int argc, char *argv[])
{
	int c;

	while (--argc > 0 && ((c = (*++argv)[0]) == '-' || c == '+')) {
		if (c == '-' && !isdigit(*(argv[0] + 1))) {
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
				usage();
				break;
			}
		} else if (c == '-')
			pos2 = atoi(argv[0] + 1);
		else if ((pos1 = atoi(argv[0] + 1)) < 0)
			usage();
	}
	if (argc || pos1 > pos2)
		usage();
}

int
main(int argc, char *argv[])
{
	char *lines[LINES];
	int i, nlines;

	readargs(argc, argv);
	nlines = readlines(lines, MAXSTR, MAXLINES);
	if (nlines <= 0)
		return 0;
	if (option & NUMERIC)
		qsort(lines, 0, nlines - 1, numcmp);
	else
		qsort(lines, 0, nlines - 1, charcmp);
	writelines(lines, nlines, option & DECR);
	for (i = 0; i < nlines; i++)
		free(lines[i]);
	return 0;
}
