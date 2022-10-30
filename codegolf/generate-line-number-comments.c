/*

Your task is to write a program (or function) that will take a string as input and append text to the beginning of every line that satisfy the following rules:

The text appended must contain the line number. You may use 0- or 1-based indexing.
The text must be a comment in your language. A comment is defined as a syntacticly valid piece of code that makes no changes to the program's state. Removing the comment should make no change to the program.
The comment may only contain newlines at the end of it.
You do not have to put line numbers for lines that contain just whitespace and comments.

Specifications
You may assume that the input will be a valid program in your language.
In indentation-sensitive languages like Python, you may place the line number comment after all indentation. You may choose either tabs or spaces to be your indentation character, but you must specify on your post.
You may assume that every statement in the code will take up at most the entirety of 1 line; i.e. no multi-line strings or backslash-continuation.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>

typedef unsigned long long uvlong;

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

void
usage(void)
{
	fprintf(stderr, "usage: <file>\n");
	exit(2);
}

void
comment(const char *name)
{
	FILE *fp;
	uvlong l;
	int c;

	fp = fopen(name, "rb");
	if (!fp)
		fatal("%s: %s", name, strerror(errno));

	l = 1;
	for (;;) {
		printf("/* %llu */ ", l++);
		for (;;) {
			c = fgetc(fp);
			if (c == EOF) {
				printf("\n");
				goto out;
			}

			putchar(c);
			if (c == '\n')
				break;
		}
	}

out:
	fclose(fp);
}

int
main(int argc, char *argv[])
{
	if (argc != 2)
		usage();

	comment(argv[1]);
	return 0;
}
