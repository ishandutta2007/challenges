// Write a program to print a histogram of the frequencies of different characters in its input.
#include <stdio.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

void
histogram(FILE *ifp, FILE *ofp, int maxhist)
{
	int h[256] = {0};
	int m, c, l, i;

	while ((c = fgetc(ifp)) != EOF)
		h[c & 0xff]++;

	m = 0;
	for (i = 0; i < 256; i++)
		m = max(m, h[i]);

	for (i = 0; i < 256; i++) {
		if (isprint(i))
			printf("%5d - %c - %5d : ", i, i, h[i]);
		else
			printf("%5d -   - %5d : ", i, h[i]);

		l = 0;
		if (h[i] > 0 && m != 0) {
			l = h[i] * maxhist / m;
			if (l <= 0)
				l = 1;
		}

		for (; l > 0; l--)
			fputc('*', ofp);
		fputc('\n', ofp);
	}
}

int
main(void)
{
	histogram(stdin, stdout, 15);
	return 0;
}
