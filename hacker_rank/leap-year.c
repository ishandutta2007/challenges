/*

We add a Leap Day on February 29, almost every four years.
The leap day is an extra, or intercalary day and we add it to the shortest month of the year, February. 
In the Gregorian calendar three criteria must be taken into account to identify leap years:

The year can be evenly divided by 4, is a leap year, unless:
The year can be evenly divided by 100, it is NOT a leap year, unless:
The year is also evenly divisible by 400. Then it is a leap year.
This means that in the Gregorian calendar, the years 2000 and 2400 are leap years,
while 1800, 1900, 2100, 2200, 2300 and 2500 are NOT leap years.

*/
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
isleap(int y)
{
	if (y % 4 != 0)
		return 0;

	if (y % 100 == 0 && y % 400 != 0)
		return 0;

	return 1;
}

int
main(void)
{
	int a[] = {
	    2000,
	    2400,
	    1800,
	    1900,
	    2100,
	    2200,
	    2300,
	    2500,
	    1990,
	    1468,
	    1692,
	    1696,
	    1712,
	    1728,
	    1756,
	    1784,
	    1792,
	    1808,
	    1948,
	};
	size_t i;
	for (i = 0; i < nelem(a); i++)
		printf("%d: %d\n", a[i], isleap(a[i]));

	return 0;
}
