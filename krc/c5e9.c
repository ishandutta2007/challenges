// Rewrite the routines day_of_year and month_day with
// pointers instead of indexing.

#include <stdio.h>

static int daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int
day_of_year(int year, int month, int day)
{
	int leap, *p;

	leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);

	p = daytab[leap];
	while (--month > 0)
		day += *++p;
	return day;
}

void
month_day(int year, int yearday, int *pmonth, int *pday)
{
	int leap, *p;

	leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
	p = daytab[leap];
	while (yearday > *++p)
		yearday -= *p;

	*pmonth = p - *(daytab + leap);
	*pday = yearday;
}

int
main(void)
{
	int month, day, year, yearday;
	for (year = 0; year < 2000; year++) {
		for (yearday = 0; yearday < 365; yearday++) {
			month_day(year, yearday, &month, &day);
			printf("day %d month %d year %d yearday %d day_of_year %d\n",
			       day, month, year, yearday, day_of_year(year, month, day));
		}
	}
	return 0;
}
