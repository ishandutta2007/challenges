/*

Create a function that takes a number as an argument and return the a string like square.

Notes

Square width <= 16383

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

char *
mksquare(int n)
{
	FILE *fp;
	char *p;
	size_t l;
	int i, j;

	fp = open_memstream(&p, &l);
	if (!fp)
		return NULL;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			fprintf(fp, "#");
		fprintf(fp, "\n");
	}
	fclose(fp);
	return p;
}

void
test(int n)
{
	char *p;

	p = mksquare(n);
	printf("%s\n", p);
	free(p);
}

int
main(void)
{
	test(-1);
	test(0);
	test(1);
	test(2);
	test(3);
	test(4);
	test(80);
	return 0;
}
