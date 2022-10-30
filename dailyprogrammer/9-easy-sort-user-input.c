/*

write a program that will allow the user to input digits, and arrange them in numerical order.

for extra credit, have it also arrange strings in alphabetical order

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
cmp(const void *a, const void *b)
{
	char x, y;

	x = *(char *)a;
	y = *(char *)b;
	if (x < y)
		return -1;
	if (x > y)
		return 1;
	return 0;
}

char *
inputsort(char *b, size_t n)
{
	size_t l;

	if (!fgets(b, n, stdin))
		return NULL;

	l = strlen(b);
	if (b[l - 1] == '\n')
		b[--l] = '\0';

	qsort(b, l, 1, cmp);
	printf("%s\n", b);

	return b;
}

int
main(void)
{
	char b[128];

	inputsort(b, sizeof(b));
	return 0;
}
