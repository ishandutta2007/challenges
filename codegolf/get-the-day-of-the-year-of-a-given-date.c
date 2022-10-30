/*

Challenge

Given two positive integers 1≤m≤12
and 1≤d≤31, representing a month and days into the month, output the amount of days that have passed since January 1st, on a non-leap year.
You can assume that the number of days passed will always be constrained by the number of days in the month (so m=2,d=31 will never be an input)

This is code-golf so the shortest code in bytes wins.

Examples

For example, m=2,d=11 represents February 11th. This is the 42nd day of the year (31 days in January + 11 days), so the output is 42.

*/

#define _XOPEN_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int
yearday(int m, int d)
{
	struct tm tm;
	char b[32];

	memset(&tm, 0, sizeof(tm));
	snprintf(b, sizeof(b), "%d-%d", m, d);
	strptime(b, "%m-%d", &tm);
	return tm.tm_yday + 1;
}

int
main(void)
{
	assert(yearday(1, 31) == 31);
	assert(yearday(2, 11) == 42);
	assert(yearday(12, 31) == 365);

	return 0;
}
