/*

Create a function that takes a number (from 1 to 12) and returns its corresponding month name as a string.
For example, if you're given 3 as input, your function should return "March", because March is the 3rd month.

Number	Month Name
1	January
2	February
3	March
4	April
5	May
6	June
7	July
8	August
9	September
10	October
11	November
12	December
Examples

MonthName(3) ➞ "March"

MonthName(12) ➞ "December"

MonthName(6) ➞ "June"

Notes

    You can expect only integers ranging from 1 to 12 as test input.
    If you get stuck on a challenge, find help in the Resources tab.
    If you're really stuck, unlock solutions in the Solutions tab.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
month(unsigned m)
{
	static const char *tab[] = {
	    "January",
	    "February",
	    "March",
	    "April",
	    "May",
	    "June",
	    "July",
	    "August",
	    "September",
	    "October",
	    "November",
	    "December",
	};

	if (m < 1 || m > nelem(tab))
		return NULL;
	return tab[m - 1];
}

int
main(void)
{
	assert(!strcmp(month(1), "January"));
	assert(!strcmp(month(2), "February"));
	assert(!strcmp(month(3), "March"));
	assert(!strcmp(month(4), "April"));
	assert(!strcmp(month(5), "May"));
	assert(!strcmp(month(6), "June"));
	assert(!strcmp(month(7), "July"));
	assert(!strcmp(month(8), "August"));
	assert(!strcmp(month(9), "September"));
	assert(!strcmp(month(10), "October"));
	assert(!strcmp(month(11), "November"));
	assert(!strcmp(month(12), "December"));

	return 0;
}
