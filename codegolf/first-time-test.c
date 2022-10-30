/*

What is the shortest C expression that is defined to evaluated to false the first time and true for every time after that:

Reference implementation:

bool b = false;  // you get this for free.

(b ? true : b = true, false)  // only this line is measured.

*/

#include <stdbool.h>
#include <stdio.h>

bool
expression(void)
{
	static bool b;
	return b ? b : !(b = !b);
}

int
main(void)
{
	int i;

	for (i = 0; i < 10; i++)
		printf("%d\n", expression());
	return 0;
}
