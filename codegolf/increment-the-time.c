/*

Every digital clock contains a small creature that has to advance the time every minute [citation needed].
Due to the popularty of digital clocks and the popularity of catching them in the wild, they are nearly extinct in nature which is why in this challenge we try to automate this task:

Given your string of a given time in the 24h format, the task is to advance this time by one minute.
Details

    Both the input and output must be strings.
    The time is given as a five character string.
    Both the hour and the minutes are given as a two digit number: if the number is below 10, there will be a leading zero.
    The two numbers are separated by a colon.

Examples

Input    Output
00:00    00:01
00:02    00:03
05:55    05:56
09:59    10:00
12:49    12:50
20:05    20:06
23:59    00:00

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
increment(const char *s, char *b)
{
	unsigned h, m, t;

	if (sscanf(s, "%u:%u", &h, &m) != 2)
		return NULL;

	t = (h * 60 + m + 1) % 1440;
	sprintf(b, "%02u:%02u", t / 60, t % 60);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[32], *p;

	p = increment(s, b);
	assert(p != NULL);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test("00:00", "00:01");
	test("00:02", "00:03");
	test("05:55", "05:56");
	test("09:59", "10:00");
	test("12:49", "12:50");
	test("20:05", "20:06");
	test("23:59", "00:00");
	return 0;
}
