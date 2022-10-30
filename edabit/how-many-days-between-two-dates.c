/*

Create a function that takes two dates and returns the number of days between the first and second date.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

long
getdays(const char *a, const char *b)
{
	struct tm tm[2];
	time_t x, y;

	memset(tm, 0, sizeof(tm));
	if (!strptime(a, "%b %d, %Y", &tm[0]))
		return -1;
	if (!strptime(b, "%b %d, %Y", &tm[1]))
		return -1;

	x = mktime(&tm[0]);
	y = mktime(&tm[1]);
	return llabs(y - x) / 86400;
}

int
main(void)
{
	printf("%ld\n", getdays("June 14, 2019", "June 20, 2019"));
	printf("%ld\n", getdays("December 29, 2018", "January 1, 2019"));
	printf("%ld\n", getdays("July 20, 2019", "July 30, 2019"));
	printf("%ld\n", getdays("January 30, 2019", "July 3, 2019"));
	return 0;
}
