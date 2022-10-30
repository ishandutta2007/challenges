/*

Christmas Eve is almost upon us, so naturally we need to prepare some milk and cookies for Santa! Create a function that accepts a (year, month, day) of date and returns true if it's Christmas Eve (December 24th) and false otherwise. Keep in mind that month of Date is 0 based, meaning December is the 11th month while January is 0.

Notes

    Dates in C++ are zero based (see resources).
    All test cases contain valid dates.

*/

#include <stdio.h>

int
milkcooker(int y, int m, int d)
{
	(void)y;
	return m == 11 && d == 24;
}

int
main(void)
{
	printf("%d\n", milkcooker(2013, 11, 24));
	printf("%d\n", milkcooker(2013, 0, 23));
	printf("%d\n", milkcooker(3000, 11, 24));
	return 0;
}
