/*

You are to read each part of the date into its own integer type variable. The year should be a 4 digit number. You can assume the user enters a correct date (no error checking required).

determines whether the entered date is a magic date. Here are the rules for a magic date:

    mm * dd is a 1-digit number that matches the last digit of yyyy
    mm * dd is a 2-digit number that matches the last 2 digits of yyyy
    mm * dd is a 3-digit number that matches the last 3 digits of yyyy

The program should then display true or false indicate if the date is magic, or not magic if it is not.

*/

#include <stdio.h>
#include <string.h>

int
magic(int d, int m, int y)
{
	char a[80], b[80];
	int i;

	snprintf(a, sizeof(a), "%04d", m * d);
	snprintf(b, sizeof(b), "%04d", y);
	for (i = 1; i <= 3; i++) {
		if (!strcmp(a + i, b + i))
			return 1;
	}
	return 0;
}

int
main(void)
{
	printf("%d\n", magic(1, 1, 2011));
	printf("%d\n", magic(4, 1, 2001));
	printf("%d\n", magic(2, 4, 2008));
	printf("%d\n", magic(3, 3, 2009));
	printf("%d\n", magic(5, 2, 2010));
	printf("%d\n", magic(1, 2, 2011));
	printf("%d\n", magic(9, 2, 2011));
	printf("%d\n", magic(1, 4, 2011));
	return 0;
}
