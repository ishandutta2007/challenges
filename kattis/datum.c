/*

Write a program that, given a date in 2009, determines the day of week on that date.

Input

The first line contains two positive integers D (day) and M (month) separated by a space. The numbers will be a valid date in 2009.

Output

Output the day of the week on day D of month M in 2009.
The output should be one of the words “Monday”, “Tuesday”, “Wednesday”, “Thursday”, “Friday”, “Saturday” or “Sunday”.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

const char *
weekday(int d, int m)
{
	static const char *tab[] = {
	    "Saturday",
	    "Sunday",
	    "Monday",
	    "Tuesday",
	    "Wednesday",
	    "Thursday",
	    "Friday",
	};

	struct tm tm = {
	    .tm_mday = d,
	    .tm_mon = m - 1,
	    .tm_year = 2009,
	};

	mktime(&tm);
	return tab[tm.tm_wday];
}

void
test(int d, int m, const char *r)
{
	const char *p;

	p = weekday(d, m);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test(1, 1, "Thursday");
	test(17, 1, "Saturday");
	test(25, 9, "Friday");

	return 0;
}
