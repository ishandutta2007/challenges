// Write a function reverse that reverses the character string s.
// Use it to write a program that reverses its input a line at a time.

#include <stdio.h>

int
reverse(char *s)
{
	size_t i, j;
	int t, nl;

	for (i = 0; s[i]; i++)
		;

	if (i == 0)
		return 0;

	nl = 0;
	if (--i == 0)
		return 0;
	if (s[i] == '\n') {
		i--;
		nl = 1;
	}

	for (j = 0; j < i; i--, j++) {
		t = s[j];
		s[j] = s[i];
		s[i] = t;
	}
	return nl;
}

int
main(void)
{
	char line[BUFSIZ];
	while (fgets(line, sizeof(line), stdin)) {
		if (reverse(line))
			printf("%s", line);
		else
			printf("%s\n", line);
	}
	return 0;
}
