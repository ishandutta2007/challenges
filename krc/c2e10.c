// Rewrite the function lower, which converts upper case letters
// to lower case, with a conditional expression instead of if-else

#include <stdio.h>

int
xtolower(int c)
{
	return ('A' <= c && c <= 'Z') ? (c + 'a' - 'A') : c;
}

int
main(void)
{
	int i;
	for (i = 'A'; i <= 'Z'; i++)
		printf("%c %c\n", i, xtolower(i));
	for (i = 'a'; i <= 'z'; i++)
		printf("%c %c\n", i, xtolower(i));
	return 0;
}
