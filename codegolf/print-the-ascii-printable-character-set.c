/*

Challenge: Print the entire printable ASCII charset (not just a range!) in order.

[space]!"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~

(Of course, replace space with the actual space character.)

Rules: read closely

    No other characters allowed in the output.

    Program/function does not accept input.

    Try not to hardcode/embed the output.

    This is code golf, shortest answer wins.

*/

#include <stdio.h>
#include <ctype.h>

int
main(void)
{
	int i;

	for (i = 0; i < 256; i++) {
		if (isprint(i))
			printf("%c", i);
	}
	printf("\n");

	return 0;
}
