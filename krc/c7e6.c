// Write a program to compare two files. printing the first line where they differ.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAXLINE 8192

void
usage(void)
{
	fprintf(stderr, "usage: file1 file2\n");
	exit(2);
}

FILE *
xfopen(const char *name, const char *mode)
{
	FILE *fp;

	fp = fopen(name, mode);
	if (fp == NULL) {
		fprintf(stderr, "%s: %s\n", name, strerror(errno));
		exit(1);
	}
	return fp;
}

void
filecmp(FILE *fp1, FILE *fp2)
{
	char line1[MAXLINE], line2[MAXLINE], *lp1, *lp2;

	do {
		lp1 = fgets(line1, MAXLINE, fp1);
		lp2 = fgets(line2, MAXLINE, fp2);
		if (lp1 == line1 && lp2 == line2) {
			if (strcmp(line1, line2)) {
				printf("first difference in line\n%s\n", line1);
				lp1 = lp2 = NULL;
			}
		} else if (lp1 != line1 && lp2 == line2)
			printf("end of first file at line\n%s\n", line2);
		else if (lp1 == line1 && lp2 != line2)
			printf("end of second file at line\n%s\n", line1);
	} while (lp1 == line1 && lp2 == line2);
}

int
main(int argc, char *argv[])
{
	FILE *fp1, *fp2;

	if (argc != 3)
		usage();

	fp1 = xfopen(argv[1], "rt");
	fp2 = xfopen(argv[2], "rt");
	filecmp(fp1, fp2);
	fclose(fp1);
	fclose(fp2);

	return 0;
}
