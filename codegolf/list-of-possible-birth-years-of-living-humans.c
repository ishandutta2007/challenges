/*

The Challenge

Output a list of years that starts with the current year and ends 120 years ago. The birth year of every living human would be included in this list.

Details

The list should be in descending order.

Every built-in function to manipulate arrays and/or lists is allowed.

Shortest code in bytes wins.

When run this year the output would be

2016, 2015, ..., 1897, 1896

When run next year the output would be

2017, 2016, ..., 1898, 1897

Etc.

Update

Some have asked about the format of the list. As most have guessed, it doesn't matter. Insert any separator between the numbers. Intuitively most inserted a comma or space or both, newline or output an array.
Quasi superhumans like Jeanne Calment are an exception to the rule stated in my question.

*/

#include <stdio.h>
#include <time.h>

void
lifeism(void)
{
	struct tm tm;
	time_t t;
	int i, n;

	t = time(NULL);
	gmtime_r(&t, &tm);

	n = 120;
	for (i = 0; i <= n; i++) {
		printf("%d", 1900 + tm.tm_year - i);
		if (i + 1 <= n)
			printf(", ");
	}
	printf("\n");
}

int
main(void)
{
	lifeism();
	return 0;
}
