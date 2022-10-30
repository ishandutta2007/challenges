// Experiment to find out what happens when printf's argument string contains
// \c, where c is some character not listed above.

#include <stdio.h>

int
main(void)
{
	printf("hello, world\a");
	printf("hello, world\b");
	printf("hello, world\f");
	printf("hello, world\r");
	printf("hello, world\t");
	printf("hello, world\v");
	printf("hello, world\\");
	printf("hello, world\?");
	printf("hello, world\'");
	printf("hello, world\"");
	printf("hello, world\134");
	printf("\n");
	return 0;
}
