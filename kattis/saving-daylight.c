/*

The shortest day of the year in the northern hemisphere is the winter solstice, around December 22, which marks the beginning of winter.
This day is not really any shorter, of course, because it still has 24 hours.
But it has the fewest hours of daylight of any day.
On the other hand, the longest day (the summer solstice) is around June 22.

Being a weather buff you would like to know just how much time the sun is above the horizon on different days during the year.
Because you are an impressive programmer, you should write an impressive program to do just that.

Input

Input has between 1 and 1000 days, one day per line.
Each line contains the month, day, year, time that the sun rises, and time that the sun sets.
Adjacent fields are separated by a single space. Times are expressed in 24-hour format in the range 0:00 to 23:59
(integer hours and minutes separated by a colon, with minutes zero-padded).
The time of sunrise is always earlier than the time of sunset, and your solution should ignore any time-changing effects (such as daylight saving time).
Input ends at the end of file.

Output

Print the month, day, and year as given in the input followed by the amount of time that the sun is above the horizon in hours and minutes (always plural).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
suntime(const char *s, char *b)
{
	char m[32];
	int d, y;
	int h1, m1;
	int h2, m2;
	int t;

	if (sscanf(s, "%31s %d %d %d:%d %d:%d", m, &d, &y, &h1, &m1, &h2, &m2) != 7)
		return NULL;

	t = (h2 - h1) * 60 + (m2 - m1);
	sprintf(b, "%s %d %d %d hours %d minutes", m, d, y, t / 60, t % 60);

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	assert(suntime(s, b) != NULL);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("June 22 2005 6:24 20:37", "June 22 2005 14 hours 13 minutes");
	test("December 22 2005 7:24 17:30", "December 22 2005 10 hours 6 minutes");
	test("November 2 2005 6:45 17:38", "November 2 2005 10 hours 53 minutes");
	test("January 8 1992 7:45 18:46", "January 8 1992 11 hours 1 minutes");

	return 0;
}
