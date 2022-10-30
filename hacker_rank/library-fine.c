/*

Your local library needs your help!
Given the expected and actual return dates for a library book, create a program that calculates the fine (if any).

The fee structure is as follows:

1. If the book is returned on or before the expected return date, no fine will be charged (i.e.: fine=0).

2. If the book is returned after the expected return day but still within the same calendar
   month and year as the expected return date, fine = 15 hackos * (number of days late).

3. If the book is returned after the expected return month but still within the same calendar year as the expected
   return date, the fine = 500 hackos * (numbers of month late).

4. If the book is returned after the calendar year in which it was expected, there is a fixed fine of 10,000 hackos

Charges are based only on the least precise measure of lateness.
For example, whether a book is due January 1, 2017 or December 31, 2017,
if it is returned January 1, 2018, that is a year late and the fine would be 10,000 hackos

*/

#include <stdio.h>
#include <time.h>

int
valid_date(struct tm *t)
{
	if (!(1 <= t->tm_mday && t->tm_mday <= 31))
		return 0;

	if (!(1 <= t->tm_mon && t->tm_mon <= 12))
		return 0;

	if (!(1 <= t->tm_year && t->tm_year <= 3000))
		return 0;

	return 1;
}

int
fine(struct tm *r, struct tm *d)
{
	if (!valid_date(r) || !valid_date(d))
		return -1;

	if (r->tm_year < d->tm_year)
		return 0;
	if (r->tm_year > d->tm_year)
		return 10000;

	if (r->tm_mon < d->tm_mon)
		return 0;
	if (r->tm_mon > d->tm_mon)
		return (r->tm_mon - d->tm_mon) * 500;

	if (r->tm_mday > d->tm_mday)
		return (r->tm_mday - d->tm_mday) * 15;
	return 0;
}

int
main(void)
{
	struct tm r = {.tm_mday = 9, .tm_mon = 6, .tm_year = 2015};
	struct tm d = {.tm_mday = 6, .tm_mon = 6, .tm_year = 2015};
	printf("%d\n", fine(&r, &d));

	r = (struct tm){.tm_mday = 1, .tm_mon = 1, .tm_year = 2018};
	d = (struct tm){.tm_mday = 31, .tm_mon = 12, .tm_year = 2017};
	printf("%d\n", fine(&r, &d));

	r = (struct tm){.tm_mday = 31, .tm_mon = 12, .tm_year = 2012};
	d = (struct tm){.tm_mday = 1, .tm_mon = 1, .tm_year = 2018};
	printf("%d\n", fine(&r, &d));

	return 0;
}
