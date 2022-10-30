/*

Write a function that, given a date (in the format MM/DD/YYYY), returns the day of the week as a string. Each day name must be one of the following strings: "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", or "Saturday".

To illustrate, the day of the week for "12/07/2016" is "Wednesday".
Examples

getDay("12/07/2016") ➞ "Wednesday"

getDay("09/04/2016") ➞ "Sunday"

getDay("12/08/2011") ➞ "Thursday"

Notes

This challenge assumes the week starts on Sunday.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <string.h>
#include <time.h>

const char *
getday(const char *s)
{
	static const char *tab[] = {
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
	};

	const char *p;
	struct tm tm;

	memset(&tm, 0, sizeof(tm));
	p = strptime(s, "%m/%d/%Y", &tm);
	if (*p != '\0')
		return "";

	return tab[tm.tm_wday];
}

int
main(void)
{
	assert(!strcmp(getday("12/07/2016"), "Wednesday"));
	assert(!strcmp(getday("12/08/2011"), "Thursday"));
	assert(!strcmp(getday("09/04/2016"), "Sunday"));
	assert(!strcmp(getday("06/08/2012"), "Friday"));
	assert(!strcmp(getday("08/13/2019"), "Tuesday"));

	return 0;
}
