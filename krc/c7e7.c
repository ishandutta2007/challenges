// Modify the pattern-finding program of Chapter 5 to take its input from a set of
// named files or, if no files are named as arguments. from the standard input.
// Should the file name be printed when a matching line is found?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
usage(void)
{
	fprintf(stderr, "usage: find [-x] [-n] pattern [file ...]\n");
	fprintf(stderr, " -x: print line not matching pattern\n");
	fprintf(stderr, " -n: print line number\n");
	exit(2);
}

int
parseargs(int argc, char *argv[], int *except, int *number, char *pattern, size_t size)
{
	int i, j;

	*except = 0;
	*number = 0;
	for (i = 1; i < argc; i++) {
		if (argv[i][0] != '-')
			break;
		for (j = 1; argv[i][j]; j++) {
			switch (argv[i][j]) {
			case 'x':
				*except = 1;
				break;
			case 'n':
				*number = 1;
				break;
			case 'h':
				usage();
				break;
			default:
				printf("find: illegal option %c\n", argv[i][j]);
				break;
			}
		}
	}
	if (i >= argc)
		usage();

	snprintf(pattern, size, "%s", argv[i]);
	return i + 1;
}

void
fpat(FILE *fp, const char *fname, const char *pattern, int except, int number)
{
	unsigned long lineno;
	char line[BUFSIZ];

	lineno = 0;
	while (fgets(line, sizeof(line), fp)) {
		lineno++;
		if ((strstr(line, pattern) != NULL) != except) {
			if (*fname)
				printf("%s - ", fname);
			if (number)
				printf("%lu: ", lineno);
			printf("%s", line);
		}
	}
}

int
main(int argc, char *argv[])
{
	int except, number, optind;
	char pattern[BUFSIZ];
	FILE *fp;

	optind = parseargs(argc, argv, &except, &number, pattern, sizeof(pattern));
	argc -= optind;
	argv += optind;
	if (argc == 0)
		fpat(stdin, "", pattern, except, number);
	else {
		for (; argc-- > 0; argv++) {
			fp = fopen(*argv, "r");
			if (fp == NULL) {
				fprintf(stderr, "find: can't open %s\n", *argv);
				continue;
			}
			fpat(fp, *argv, pattern, except, number);
			fclose(fp);
		}
	}
	return 0;
}
