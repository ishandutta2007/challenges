/*

Given a text file file.txt, print just the 10th line of the file.

Example:

Assume that file.txt has the following content:

Line 1
Line 2
Line 3
Line 4
Line 5
Line 6
Line 7
Line 8
Line 9
Line 10

Your script should output the tenth line, which is:

Line 10

Note:
1. If the file contains less than 10 lines, what should you output?
2. There's at least three different solutions. Try to explore all possibilities.

*/

#include <stdio.h>
#include <string.h>
#include <errno.h>

void
tenth(const char *name)
{
	FILE *fp;
	char b[4096], *p;
	int l;

	fp = fopen(name, "rt");
	if (!fp) {
		fprintf(stderr, "%s: %s\n", name, strerror(errno));
		return;
	}
	for (l = 1; fgets(b, sizeof(b), fp); l++) {
		if (l == 10) {
			if ((p = strchr(b, '\n')))
				*p = '\0';
			printf("%s\n", b);
			break;
		}
	}
	if (l != 10)
		fprintf(stderr, "%s has less than 10 lines\n", name);

	fclose(fp);
}

int
main(void)
{
	tenth("tenth-line-file.txt");
	return 0;
}
