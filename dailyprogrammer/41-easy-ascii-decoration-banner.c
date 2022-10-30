/*

Write a program that will accept a sentence as input and then output that sentence surrounded by some type of an ASCII decoratoin banner.

Sample run:

Enter a sentence: So long and thanks for all the fish

Output

*****************************************
*                                       *
*  So long and thanks for all the fish  *
*                                       *
*****************************************

Bonus: If the sentence is too long, move words to the next line.

*/

#include <stdio.h>
#include <string.h>

void
stars(const char *f, size_t n)
{
	size_t i;

	while (*f) {
		switch (*f++) {
		case 't':
			for (i = 0; i < n + 6; i++)
				printf("*");
			printf("\n");
			break;

		case 'b':
			printf("*");
			for (i = 0; i < n + 4; i++)
				printf(" ");
			printf("*\n");
			break;
		}
	}
}

void
banner(const char *s)
{
	size_t n;

	n = strlen(s);
	stars("tb", n);
	printf("*  %s  *\n", s);
	stars("bt", n);
}

int
main(void)
{
	banner("So long and thanks for all the fish");
	banner("Pity the fuel");
	banner("a");
	banner("AARDVARK");
	banner("KEKEKEKE");
	banner("EXEUNT");

	return 0;
}
