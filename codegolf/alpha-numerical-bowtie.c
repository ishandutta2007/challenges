/*

Output this exact text:

1                i
12              hi
123            ghi
1234          fghi
12345        efghi
123456      defghi
1234567    cdefghi
12345678  bcdefghi
123456789abcdefghi
12345678  bcdefghi
1234567    cdefghi
123456      defghi
12345        efghi
1234          fghi
123            ghi
12              hi
1                i

A single trailing newline is acceptable, but no other formatting changes are allowed.
Rules and I/O

    No input
    Output can be given by any convenient method.
    Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
    Standard loopholes are forbidden.
    This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

*/

#include <stdio.h>
#include <stdlib.h>

void
gen(void)
{
	int i, j, k, l;

	for (i = -8; i <= 8; i++) {
		k = 9 - abs(i);
		for (j = 0; j < k; j++)
			printf("%c", '1' + j);

		l = 2 * abs(i);
		for (j = 0; j < l; j++)
			printf(" ");

		for (j = 0; j < k; j++)
			printf("%c", 'j' - k + j);

		printf("\n");
	}
}

int
main(void)
{
	gen();
	return 0;
}
