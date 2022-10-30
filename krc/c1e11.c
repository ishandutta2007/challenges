// How would you test the word count program?
// What kinds of input are most likely to uncover bugs if there are any?

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
wc(FILE *fp)
{
	unsigned long nc, nw, nl, nnc;
	int c;

	nc = nw = nl = 0;
	nnc = 0;
	while ((c = fgetc(fp)) != EOF) {
		if (!isspace(c)) {
			nnc++;
			nc++;
		} else if (nnc > 0) {
			nw++;
			nnc = 0;
		}
		if (c == '\n')
			nl++;
	}
	if (nnc > 0)
		nw++;
	printf("newlines %lu words %lu chars %lu\n", nl, nw, nc);
}

void
test(const char *s)
{
	FILE *fp;

	fp = fmemopen((void *)s, strlen(s), "r");
	if (!fp)
		return;
	wc(fp);
	fclose(fp);
}

int
main(void)
{
	test("");
	test("a");
	test("ab");
	test("xy\n");
	test("one two three four five\nsix seven\n eight\n nine\tten");
	test("              x");
	test("      \n");
	test(" \t\t\t\t\t\t\t\t\tggcxeq\n\n\n\n\n\n");
	return 0;
}
