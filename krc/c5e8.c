// There is no error checking in day_of_year or month_day.
// Remedy this defect.

#include <stdio.h>

static const int daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int
day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
	if (month < 1 || month > 12)
		return -1;
	if (day < -1 || day > daytab[leap][month])
		return -1;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

void
month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	if (year < 1) {
		*pmonth = *pday = -1;
		return;
	}

	leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
	for (i = 1; i <= 12 && yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];

	if (i > 12 && yearday > daytab[leap][12])
		*pmonth = *pday = -1;
	else {
		*pmonth = i;
		*pday = yearday;
	}
}

int
main(void)
{
	int year, yearday, month, day;

	for (year = 1; year <= 2000; year++) {
		for (month = 1; month <= 12; month++) {
			for (day = 1; day <= 31; day++)
				printf("year %d month %d day %d day_of_year %d\n", year, month, day, day_of_year(year, month, day));
		}
	}

	for (year = 1; year <= 2000; year++) {
		for (yearday = 1; yearday <= 365; yearday++) {
			month_day(year, yearday, &month, &day);
			printf("year %d yearday %d month %d day %d\n", year, yearday, month, day);
		}
	}

	return 0;
}
