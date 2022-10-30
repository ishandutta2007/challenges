/*

The program should take three arguments. The first will be a day, the second will be month, and the third will be year.
Then, your program should compute the day of the week that date will fall on.

*/

#define _XOPEN_SOURCE
#include <stdio.h>
#include <time.h>

char *
day(int d, int m, int y, char *b, size_t n)
{
	struct tm tm;
	char s[128];

	snprintf(s, sizeof(s), "%d-%d-%d", y, m, d);
	strptime(s, "%Y-%m-%d", &tm);
	if (!strftime(b, n, "%A", &tm))
		b[0] = '\0';
	return b;
}

void
test(int d, int m, int y)
{
	char b[128];

	day(d, m, y, b, sizeof(b));
	printf("%s\n", b);
}

int
main(void)
{
	test(23, 10, 2021);
	test(20, 4, 2020);
	return 0;
}
