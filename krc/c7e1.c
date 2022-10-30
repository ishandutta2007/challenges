// Write a program that converts upper case to lower or lower case to upper,
// depending on the name it is invoked with, as found in argv[0].
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void
usage(void)
{
	fprintf(stderr, "usage: upper/lower\n");
	exit(1);
}

void
charfilt(FILE *ifp, FILE *ofp, int (*conv)(int))
{
	char c;

	while ((c = fgetc(ifp)) != EOF)
		fputc(conv(c), ofp);
}

int
main(int argc, char *argv[])
{
	int (*conv)(int);

	if (argc < 1)
		usage();
	conv = (tolower(argv[0][0]) == 'u') ? toupper : tolower;
	charfilt(stdin, stdout, conv);
	return 0;
}
