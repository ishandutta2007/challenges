/*
Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.

Note: Midnight is 12:00:00AM on a 12-hour clock, and 00:00:00 on a 24-hour clock.
Noon is 12:00:00PM on a 12-hour clock, and 12:00:00 on a 24-hour clock.
*/

#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *
timeconv(const char *s)
{
	struct tm tm;
	char *p;

	if (strptime(s, "%r", &tm) == NULL)
		return NULL;

	p = malloc(9);
	if (p == NULL)
		return NULL;
	strftime(p, 9, "%T", &tm);
	return p;
}

int
main(int argc, char *argv[])
{
	const char *s = "07:05:45PM";
	char *p;
	if (argc >= 2)
		s = argv[1];
	p = timeconv(s);
	printf("%s\n", p);
	free(p);
	return 0;
}
