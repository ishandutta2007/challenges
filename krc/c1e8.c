// Write a program to count blanks, tabs, and newlines
#include <stdio.h>

void
wc(FILE *fp)
{
	unsigned nb, nt, nl;
	int c;

	nb = nt = nl = 0;
	while ((c = fgetc(fp)) != EOF) {
		switch (c) {
		case ' ':
			nb++;
			break;
		case '\t':
			nt++;
			break;
		case '\n':
			nl++;
			break;
		}
	}
	printf("blanks %u tabs %u newlines %u\n", nb, nt, nl);
}

int
main(void)
{
	wc(stdin);
	return 0;
}
