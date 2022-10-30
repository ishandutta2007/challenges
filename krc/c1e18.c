// Write a program to remove trailing blanks and tabs from each line of
// input, and to delete entirely blank lines.

#define _GNU_SOURCE
#include <stdio.h>

ssize_t
trimspaces(char *s)
{
	ssize_t i;

	i = 0;
	while (s[i] != '\n')
		i++;
	i--;
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
		i--;
	if (i >= 0) {
		s[++i] = '\n';
		s[++i] = '\0';
	}
	return i;
}

void
notrails(FILE *fp)
{
	char line[BUFSIZ];

	while (fgets(line, sizeof(line), fp)) {
		if (trimspaces(line) > 0)
			printf("%s", line);
	}
}

int
main(void)
{
	notrails(stdin);
	return 0;
}
