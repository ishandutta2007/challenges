/*

Write a program which parses the output of uptime and generates an anatomically suggestive progress bar (as shown) with a length equal to the current uptime in days:

$ uptime
23:01  up 34 days,  7:30, 5 users, load averages: 0.23 0.27 0.24
$ uptime|<command>
8==================================D

(34 days = 34 equal signs)

Shortest answer wins.

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const char *
field(const char *s, size_t n)
{
	size_t i, j;

	for (i = j = 0; i < n; i++) {
		while (s[j] && !isspace(s[j]))
			j++;

		while (isspace(s[j]))
			j++;
	}
	return s + j;
}

void
progress(const char *s)
{
	int i, d;

	d = atoi(field(s, 2));
	printf("8");
	for (i = 0; i < d; i++)
		printf("=");
	printf("D\n");
}

int
main(void)
{
	progress("23:01  up 34 days,  7:30, 5 users, load averages: 0.23 0.27 0.24");
	progress("23:01  up 100 days,  7:30, 5 users, load averages: 0.23 0.27 0.24");

	return 0;
}
