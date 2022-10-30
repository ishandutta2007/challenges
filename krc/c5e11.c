// Modify the programs entab and detab (written as exercises in Chapter 1)
// to accept a list of tab stops as arguments. Use the default tab settings
// if there are no arguments.

#include <stdio.h>
#include <stdlib.h>

enum {
	MAXLINE = 100,
	TABINC = 8,
};

int
tabpos(int pos, char *tab)
{
	if (pos > MAXLINE)
		return 1;
	return tab[pos];
}

void
settab(int argc, char *argv[], char *tab)
{
	int i, p;

	if (argc <= 1) {
		for (i = 1; i <= MAXLINE; i++)
			tab[i] = (i % TABINC == 0);
	} else {
		for (i = 1; i <= MAXLINE; i++)
			tab[i] = 0;
		while (--argc > 0) {
			p = atoi(*++argv);
			if (0 < p && p <= MAXLINE)
				tab[p] = 1;
		}
	}
}

void
entab(char *tab)
{
	int c, p;
	int nb, nt;

	nb = nt = 0;
	for (p = 1; (c = fgetc(stdin)) != EOF; p++) {
		if (c == ' ') {
			if (!tabpos(p, tab))
				nb++;
			else {
				nb = 0;
				nt++;
			}
		} else {
			for (; nt > 0; nt--)
				putchar('\t');
			if (c == '\t')
				nb = 0;
			else {
				for (; nb > 0; nb--)
					putchar(' ');
			}
			putchar(c);
			if (c == '\n')
				p = 0;
			else if (c == '\t') {
				while (tabpos(p, tab))
					p++;
			}
		}
	}
}

void
detab(char *tab)
{
	int c, p;

	p = 1;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			do {
				putchar(' ');
			} while (tabpos(p++, tab));
		} else if (c == '\n') {
			putchar(c);
			p = 1;
		} else {
			putchar(c);
			p++;
		}
	}
}

int
main(int argc, char *argv[])
{
	char tab[MAXLINE + 1];

	settab(argc, argv, tab);
	entab(tab);
	detab(tab);
	return 0;
}
