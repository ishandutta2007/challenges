/*

The digit distance between two numbers is the absolute value of the difference of each digit.

To illustrate:

digitDistance(234, 489) ➞ 12
// Since |2 - 4| + |3 - 8| + |4 - 9| = 2 + 5 + 5

Create a function that returns the digit distance between two integers.

Notes

    Both integers will be exactly the same length.
    All digits in $num2 have to be higher than their counterparts in $num1.

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int
digitdistance(unsigned x, unsigned y)
{
	char a[sizeof(unsigned) * CHAR_BIT];
	char b[sizeof(unsigned) * CHAR_BIT];
	int d;
	size_t i;

	snprintf(a, sizeof(a), "%u", x);
	snprintf(b, sizeof(b), "%u", y);

	d = 0;
	for (i = 0; a[i] && b[i]; i++)
		d += abs((a[i] - '0') - (b[i] - '0'));

	if (a[i] != '\0' || b[i] != '\0')
		return -1;
	return d;
}

int
main(void)
{
	printf("%d\n", digitdistance(121, 599));
	printf("%d\n", digitdistance(12, 12));
	printf("%d\n", digitdistance(10, 20));
	printf("%d\n", digitdistance(12345678, 23456789));
	printf("%d\n", digitdistance(5555, 6666));
	printf("%d\n", digitdistance(105, 777));
	printf("%d\n", digitdistance(234, 489));
	return 0;
}
