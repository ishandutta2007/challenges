/*

Using the word “conemon” print each character 2 times more than the last. The first letter, “c”, should be printed 10 times, the second 12 and so on. Each repeated-letter-string should be printed on a new line.

So the end-result becomes:

cccccccccc
oooooooooooo
nnnnnnnnnnnnnn
eeeeeeeeeeeeeeee
mmmmmmmmmmmmmmmmmm
oooooooooooooooooooo
nnnnnnnnnnnnnnnnnnnnnn

*/

#include <stdio.h>

void
letters(const char *s)
{
	size_t i, n, m;

	m = 10;
	for (i = 0; s[i]; i++) {
		for (n = 0; n < m; n++)
			printf("%c", s[i]);
		printf("\n");
		m += 2;
	}
}

int
main(void)
{
	letters("conemon");
	return 0;
}
