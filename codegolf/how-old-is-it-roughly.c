/*

Write a short program which takes in a positive number of seconds representing an age, and outputs an estimate of that time in English.

Your program must output the least precise amount of time which has passed, among the following metrics and their lengths in seconds:

second = 1
minute = 60
hour   = 60 * 60
day    = 60 * 60 * 24
week   = 60 * 60 * 24 * 7
month  = 60 * 60 * 24 * 31
year   = 60 * 60 * 24 * 365
Examples

input      : output
1          : 1 second
59         : 59 seconds
60         : 1 minute
119        : 1 minute
120        : 2 minutes
43200      : 12 hours
86401      : 1 day
1815603    : 3 weeks
1426636800 : 45 years
As you can see above, after the time of say, 1 day (60 * 60 * 24 = 86400 seconds), we no longer output minute(s) or hour(s), but only days until we surpass the time of one week, and so on.

Consider the given length of time to be an age. For example, after 119 seconds, 1 minute has passed, not 2.

Rules

No specification for 0 or negative inputs.
Follow proper pluralization. Every measure greater than 1 must include an s following the word.
You may not use a pre-existing library which serves the function of the entire program.
This is a code golf, shortest program wins the internet points.
Have fun!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

char *
estage(uvlong n, char *b)
{
	static const struct {
		char eng[16];
		uvlong val;
	} tab[] = {
	    {"second", 1ULL},
	    {"minute", 60ULL},
	    {"hour", 60ULL * 60ULL},
	    {"day", 60ULL * 60ULL * 24ULL},
	    {"week", 60ULL * 60ULL * 24ULL * 7ULL},
	    {"month", 60ULL * 60ULL * 24ULL * 31ULL},
	    {"year", 60ULL * 60ULL * 24ULL * 365ULL},
	};

	size_t i, l;
	uvlong v;

	for (i = nelem(tab); i > 0; i--) {
		if (n >= tab[i - 1].val)
			break;
	}

	v = n / tab[i - 1].val;
	l = sprintf(b, "%llu %s", v, tab[i - 1].eng);
	if (v > 1)
		l += sprintf(b + l, "s");

	return b;
}

void
test(uvlong n, const char *r)
{
	char b[128];

	estage(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(1, "1 second");
	test(59, "59 seconds");
	test(60, "1 minute");
	test(119, "1 minute");
	test(120, "2 minutes");
	test(43200ULL, "12 hours");
	test(86401ULL, "1 day");
	test(1815603ULL, "3 weeks");
	test(1426636800ULL, "45 years");

	return 0;
}
