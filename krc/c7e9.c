// Functions like isupper can be implemented to save space or to save time.
// Explore both possibilities.

#include <stdio.h>

#define isupper1(c) ('A' <= (c) && (c) <= 'Z')

int
isupper2(char c)
{
	return 'A' <= c && c <= 'Z';
}

int
main(void)
{
	int i;
	for (i = 0; i < 256; i++) {
		if (isupper1(i) && isupper2(i))
			printf("%d %c\n", i, i);
	}
	return 0;
}
