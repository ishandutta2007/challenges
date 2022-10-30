/*

Create a function that takes a name and returns a greeting. Don't use a normal function but use an "arrow function".

Notes

    The input is always a name (as string).
    Don't forget the exclamation mark!

*/

#include <stdio.h>

void
helloname(const char *name)
{
	printf("Hello %s!\n", name);
}

int
main(void)
{
	helloname("Gerard");
	helloname("Fatima");
	helloname("Ed");
	helloname("Tiffany");
	return 0;
}
