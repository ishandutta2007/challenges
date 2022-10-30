// Revise the main routine of the longest-line program so it will correctly print the
// length of arbitrarily long input lines, and as much as possible of the text.
#include <stdio.h>
#include <string.h>

#define MAXLINE 1024

size_t
getline(FILE *ifp, char *line, size_t limit)
{
	size_t n;
	int c;

	if (limit == 0)
		return 0;
	line[0] = '\0';

	n = 0;
	for (;;) {
		c = fgetc(ifp);
		if (c == '\n' || c == EOF)
			break;

		if (n < limit)
			line[n] = c;
		else if (n == limit)
			line[n] = '\0';
		n++;
	}
	return n;
}

void
longestline(FILE *ifp)
{
	char line[MAXLINE], maxline[MAXLINE];
	size_t len, maxlen;

	maxline[0] = '\0';
	maxlen = 0;
	while ((len = getline(ifp, line, MAXLINE)) > 0) {
		if (len > maxlen) {
			strcpy(maxline, line);
			maxlen = len;
		}
	}
	printf("max line length: %zu\n", maxlen);
	printf("max line: \"%s\"\n", maxline);
}

int
main(void)
{
	longestline(stdin);
	return 0;
}
