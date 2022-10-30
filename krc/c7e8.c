// Write a program to print a set of files, starting each new one on a new page,
// with a title and a running page count for each file.

#include <stdio.h>
#include <string.h>
#include <errno.h>

enum {
	// maximum # lines at bottom page
	MAXBOT = 3,

	// maximum # lines at head of page
	MAXHDR = 5,

	// maximum size of one line
	MAXLINE = 100,

	// maximum # lines on one page
	MAXPAGE = 66,
};

unsigned long
heading(const char *fname, unsigned long pageno)
{
	unsigned long ln;

	ln = 3;
	fprintf(stdout, "\n\n");
	fprintf(stdout, "%s    page %lu\n", fname, pageno);
	while (ln++ < MAXHDR)
		fprintf(stdout, "\n");
	return ln;
}

void
fileprint(FILE *fp, const char *fname)
{
	unsigned long lineno, pageno;
	char line[MAXLINE];

	pageno = 1;
	lineno = heading(fname, pageno++);
	while (fgets(line, sizeof(line), fp)) {
		if (lineno == 1) {
			fprintf(stdout, "\f");
			lineno = heading(fname, pageno++);
		}
		fprintf(stdout, "%s", line);
		if (++lineno > MAXPAGE - MAXBOT)
			lineno = 1;
	}
	fprintf(stdout, "\f");
}

int
main(int argc, char *argv[])
{
	FILE *fp;

	if (argc < 2)
		fileprint(stdin, " ");
	else {
		while (--argc > 0) {
			fp = fopen(*++argv, "r");
			if (fp == NULL) {
				fprintf(stderr, "print: %s: %s\n", *argv, strerror(errno));
				continue;
			}
			fileprint(fp, *argv);
			fclose(fp);
		}
	}
	return 0;
}
