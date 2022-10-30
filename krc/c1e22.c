// Write a program to "fold" long input lines into two or more shorter lines after
// the last nonblank character that occurs before then-th column of input.
// Make sure your program does something intelligent with very long lines, and if there
// are no blanks or tabs before the specified column.

#include <stdio.h>

enum {
	MAXCOL = 10,
	TABINC = 8,
};

void
printl(FILE *fp, const char *line, size_t pos)
{
	size_t i;

	for (i = 0; i < pos; i++)
		fputc(line[i], fp);
	if (pos > 0)
		fputc('\n', fp);
}

size_t
findblnk(const char *line, size_t pos)
{
	while (pos > 0 && line[pos] != ' ')
		pos--;
	if (pos == 0)
		return MAXCOL;
	return pos + 1;
}

size_t
exptab(char *line, size_t pos)
{
	line[pos] = ' ';
	for (++pos; pos < MAXCOL && (pos % TABINC) != 0; pos++)
		line[pos] = ' ';
	if (pos < MAXCOL)
		return pos;
	printl(stdout, line, pos);
	return 0;
}

size_t
newpos(char *line, size_t pos)
{
	size_t i, j;

	if (pos == 0 || pos >= MAXCOL)
		return 0;
	for (i = 0, j = pos; j < MAXCOL; i++, j++)
		line[i] = line[j];
	return i;
}

void
fold(FILE *fp)
{
	char line[BUFSIZ];
	size_t pos;
	int c;

	pos = 0;
	while ((c = fgetc(fp)) != EOF) {
		line[pos] = c;
		if (c == '\t')
			pos = exptab(line, pos);
		else if (c == '\n') {
			printl(stdout, line, pos);
			pos = 0;
		} else if (++pos >= MAXCOL) {
			pos = findblnk(line, pos);
			printl(stdout, line, pos);
			pos = newpos(line, pos);
		}
	}
}

int
main(void)
{
	fold(stdin);
	return 0;
}
