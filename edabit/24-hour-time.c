/*

Write a function that receives the time in 12-hour AM/PM format and returns a string representation of the time in military (24-hour) format.

Notes

    Midnight is 12:00:00AM on a 12-hour clock, and 00:00:00 on a 24-hour clock.
    Noon is 12:00:00PM on a 12-hour clock, and 12:00:00 on a 24-hour clock.

*/

#include <stdio.h>
#include <string.h>

char *
convtime(const char *s, char *b, size_t n)
{
	unsigned h, m, c;
	char p[3];

	if (sscanf(s, "%u:%u:%u%2s", &h, &m, &c, p) != 4)
		return NULL;

	if (!strcmp(p, "PM"))
		h += (h < 12) ? 12 : 0;
	else if (!strcmp(p, "AM"))
		h -= (h >= 12) ? 12 : 0;
	else
		return NULL;

	if (h >= 24 || m >= 60 || c >= 60)
		return NULL;

	snprintf(b, n, "%02u:%02u:%02u", h, m, c);
	return b;
}

int
main(void)
{
	char b[80];

	printf("%s\n", convtime("07:05:45PM", b, sizeof(b)));
	printf("%s\n", convtime("12:40:22AM", b, sizeof(b)));
	printf("%s\n", convtime("12:45:54PM", b, sizeof(b)));
	printf("%s\n", convtime("05:32:33PM", b, sizeof(b)));
	printf("%s\n", convtime("11:59:59PM", b, sizeof(b)));
	printf("%s\n", convtime("11:59:59AM", b, sizeof(b)));
	printf("%s\n", convtime("06:00:19AM", b, sizeof(b)));
	printf("%s\n", convtime("12:00:00AM", b, sizeof(b)));
	printf("%s\n", convtime("12:00:00PM", b, sizeof(b)));
	return 0;
}
