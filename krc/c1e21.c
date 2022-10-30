// Write the program entab that replaces strings of blanks by the minimum number
// of tabs and blanks to achieve the same spacing. Use the same tab stops as for
// detab. When either a tab or a single blank would suffice to reach a tab stop,
// which could be given preference?

#include <stdio.h>

#define TABINC 8

void
entab(FILE *ifp, FILE *ofp, long tabinc)
{
	long nb, nt, pos;
	int c;

	nb = 0;
	nt = 0;
	for (pos = 1; (c = fgetc(ifp)) != EOF; pos++) {
		if (c == ' ') {
			if (pos % tabinc != 0)
				nb++;
			else {
				nb = 0;
				nt++;
			}
		} else {
			for (; nt > 0; nt--)
				fputc('\t', ofp);
			if (c == '\t')
				nb = 0;
			else {
				for (; nb > 0; nb--)
					fputc(' ', ofp);
			}
			fputc(c, ofp);
			if (c == '\n')
				pos = 0;
			else if (c == '\t')
				pos = pos + (tabinc - (pos - 1) % tabinc) - 1;
		}
	}
}

int
main(void)
{
	entab(stdin, stdout, TABINC);
	return 0;
}
