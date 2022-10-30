// Write a program to print a histogram of the lengths of words in its input. It is
// easy to draw the histogram with the bars horizontal; a vertical orientation is
// more challenging.

#include <stdio.h>
#include <ctype.h>

enum {
	MAXHIST = 15,
	MAXWORD = 32,
};

void
count(FILE *fp, int *wl, int maxword, int *ovflow, int *maxval)
{
	int i, c, nc, state;

	*ovflow = 0;
	*maxval = 0;
	for (i = 0; i < maxword; i++)
		wl[i] = 0;

	state = 1;
	nc = 0;
	while ((c = fgetc(fp)) != EOF) {
		if (isspace(c)) {
			state = 0;
			if (nc > 0) {
				if (nc < maxword)
					wl[nc]++;
				else
					(*ovflow)++;
			}
			nc = 0;
		} else if (state == 0) {
			state = 1;
			nc = 1;
		} else
			nc++;
	}

	for (i = 1; i < maxword; i++) {
		if (wl[i] > *maxval)
			*maxval = wl[i];
	}
}

void
hhist(FILE *fp, int *wl, int maxword, int maxhist, int ovflow, int maxval)
{
	int i, len;

	fprintf(fp, "\nHorizontal Histogram:\n");
	for (i = 1; i < maxword; i++) {
		printf("%5d - %5d : ", i, wl[i]);
		len = 0;
		if (wl[i] > 0) {
			len = wl[i] * maxhist / maxval;
			if (len <= 0)
				len = 1;
		}
		for (; len > 0; len--)
			fputc('*', fp);
		fputc('\n', fp);
	}
	if (ovflow > 0)
		fprintf(fp, "There are %d words >= %d\n", ovflow, maxword);
}

void
vhist(FILE *fp, int *wl, int maxword, int maxhist, int ovflow, int maxval)
{
	int i, j;

	fprintf(fp, "\nVertical Histogram:\n");
	for (i = maxhist; i > 0; i--) {
		for (j = 1; j < maxword; j++) {
			if (maxval > 0 && wl[j] * maxhist / maxval >= i)
				fprintf(fp, "   * ");
			else
				fprintf(fp, "     ");
		}
		fputc('\n', fp);
	}
	for (i = 1; i < maxword; i++)
		fprintf(fp, "%4d ", i);
	fputc('\n', fp);
	for (i = 1; i < maxword; i++)
		fprintf(fp, "%4d ", wl[i]);
	fputc('\n', fp);

	if (ovflow > 0)
		fprintf(fp, "There are %d words >= %d\n", ovflow, maxword);
}

int
main(void)
{
	int ovflow, maxval;
	int wl[MAXWORD];

	count(stdin, wl, MAXWORD, &ovflow, &maxval);
	hhist(stdout, wl, MAXWORD, MAXHIST, ovflow, maxval);
	vhist(stdout, wl, MAXWORD, MAXHIST, ovflow, maxval);
	return 0;
}
