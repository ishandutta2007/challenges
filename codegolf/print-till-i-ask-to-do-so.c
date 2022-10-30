/*

You have to print(STDOUT) the word "Print" such that each letter of "Print" appear as many time as they had appeared in the text before. Example :
Counter 	Output
1 	Print
2 	PPRRIINNTT
3 	PPPRRRIIINNNTTT

This has to be printed until user types "Stop".
Program with least time responsive least time wins.

*/

#include <stdio.h>
#include <ctype.h>

void
printer(const char *s, int n)
{
	int i, j, c;
	const char *p;

	if (n <= 0)
		return;

	printf("%s\n", s);
	for (i = 1; i < n; i++) {
		for (p = s; *p; p++) {
			c = toupper(*p);
			for (j = 0; j <= i; j++) {
				printf("%c", c);
			}
		}
		printf("\n");
	}
}

int
main(void)
{
	printer("Print", 3);
	return 0;
}
