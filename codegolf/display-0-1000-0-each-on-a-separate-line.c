/*

Print 0 to 1000 then back to 0 again

*/

#include <stdio.h>

void
display(unsigned n)
{
	unsigned i;

	for (i = 0; i <= n; i++)
		printf("%d\n", i);
	for (i = n; i > 0; i--)
		printf("%d\n", i - 1);
}

int
main(void)
{
	display(1000);
	return 0;
}
