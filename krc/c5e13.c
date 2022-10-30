/*

Write the program tail, which prints the last n lines of its input. By default.
n is 10, let us say, but it can be changed by an optional argument, so that

tail -n

prints the last n lines. The program should behave rationally no matter how
unreasonable the input or the value of n. Write the program so that it makes
the best use of available storage; lines should be stored as in the sorting program
of Section 5.6, not in a two-dimensional array of fixed size.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

enum {
	DEFLINES = 10,
	LINES = 65536,
	MAXLEN = 8192,
};

void *
xmalloc(size_t n)
{
	void *p;

	p = malloc(n);
	if (!p) {
		perror("malloc");
		exit(1);
	}
	return p;
}

void
usage(void)
{
	fprintf(stderr, "usage: tail [-n]\n");
	exit(2);
}

int
parseargs(int *argc, char **argv[])
{
	int n;

	n = DEFLINES;

	(*argc)--;
	(*argv)++;
	if (*argc > 0 && ((*argv)[0][0]) == '-') {
		if (!isdigit((*argv)[0][1]) && (*argv)[0][1] != '-')
			usage();

		n = atoi((*argv)[0] + 1);
		(*argc)--;
		(*argv)++;
	}

	if (n < 1 || n > LINES)
		n = LINES;

	return n;
}

void
tail(FILE *fp, int n)
{
	int i, len, first, last, nlines;
	char *line, **lineptr;
	char *p, *buf, *bufend;

	line = xmalloc(LINES);
	lineptr = xmalloc(LINES * sizeof(char *));
	buf = xmalloc(LINES * MAXLEN);
	bufend = buf + LINES * MAXLEN;

	last = 0;
	len = 0;
	nlines = 0;
	p = buf;
	while (fgets(line, MAXLEN, fp)) {
		len = strlen(line);
		if (p + len + 1 >= bufend)
			p = buf;

		lineptr[last] = p;
		strcpy(lineptr[last], line);

		if (++last >= LINES)
			last = 0;
		p += len + 1;
		nlines++;
	}
	if (n > nlines)
		n = nlines;
	first = last - n;
	if (first < 0)
		first += LINES;

	for (i = first; n-- > 0; i = (i + 1) % LINES)
		printf("%s", lineptr[i]);

	free(line);
	free(lineptr);
	free(buf);
}

int
main(int argc, char *argv[])
{
	FILE *fp;
	int i, n;

	n = parseargs(&argc, &argv);
	if (argc == 0)
		tail(stdin, n);
	else {
		for (i = 0; i < argc; i++) {
			fp = fopen(argv[i], "r");
			if (!fp) {
				fprintf(stderr, "%s: %s\n", argv[i], strerror(errno));
				continue;
			}
			tail(fp, n);
			fclose(fp);
		}
	}
	return 0;
}
