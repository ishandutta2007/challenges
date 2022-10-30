/*

If you haven't gathered from the title, the challenge here is to go from decimal notation -> scientific notation.
For those that don't know, scientific notation allows for a decimal less than ten, greater than zero, and a power of ten to be multiplied.

For example: 239487 would be 2.39487 x 105

And .654 would be 6.54 x 10-1

Bonus Points:

    Have you program randomly generate the number that you will translate.

    Go both ways (i.e., given 0.935 x 103, output 935.)

Good luck, and have fun!

*/

#include <stdio.h>
#include <string.h>
#include <math.h>

char *
scinot(double x, char *b)
{
	int e;

	e = floor(log10(x));
	sprintf(b, "%f x 10^%d", x / pow(10, e), e);
	return b;
}

int
main(void)
{
	char b[128];

	printf("%s\n", scinot(239487, b));
	printf("%s\n", scinot(.654, b));
	printf("%s\n", scinot(935, b));
	printf("%s\n", scinot(5, b));
	return 0;
}
