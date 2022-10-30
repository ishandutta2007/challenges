/*

Background
In 1960, the 11th General Conference on Weights and Measures defined the Système International d'Unités (SI) Units which scientists still use today.

The metre and the kilogram became standard units in that conference. These were based on powers of 10 (10, 100, 1000, etc.).

For example:

there are 100 centimetres in one meter
there are 1000 meters in one kilometer
there are 1000 grams in one kilogram
Time units
That conference also established the second as the standard unit for time. Now, this is interesting, because this is not based on powers of 10.

There are 60 seconds in one minute
There are 60 minutes in one hour
There are 24 hours in one day
So let's make our own!

In our system, we will have:

100 seconds in one minute
100 minutes in one hour
10 hours in one day
Your task
Given an input of a time (in 24-hour time), convert it to our system (10-hour).

Example:

Input: 12:34:56

First, convert this to a number of seconds:

(12 * 60 * 60) + (34 * 60) + 56 = 45296

We have 100,000 seconds in our system, and in the normal system there are 86,400. We need to adjust for that:

45296 / 86400 * 100000 = 52425.9259259259

We round this to 52426. Note: this must be rounded.

Now, convert back to hours, minutes and seconds. This is easy because our 10-100-100 system lets us just place the colons in: 5:24:26. This is our final answer.

Note: you do not need to insert the colons.

Test cases
You can input and output in any format you want, including just an integer as the output format.

Here are some test cases:

Input     Output
12:34:56  5:24:26
00:00:00  0:00:00*
23:59:59  9:99:99
11:11:11  4:66:10
15:25:35  6:42:77
01:02:03  0:43:09*
* In these ones, you do not have to fill the minutes and seconds up to two places: i.e., you may output 0:0:0 and 0:43:9.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef unsigned long long uvlong;

char *
conv(const char *t, char *b)
{
	uvlong h, m, s;
	uvlong u, v;

	if (sscanf(t, "%02llu:%02llu:%02llu", &h, &m, &s) != 3)
		return NULL;

	u = (h * 3600) + (m * 60) + s;
	v = round((u * 100000.0) / 86400.0);
	sprintf(b, "%llu:%02llu:%02llu", (v / 10000) % 100, (v / 100) % 100, v % 100);
	return b;
}

void
test(const char *t, const char *r)
{
	char b[128];

	assert(conv(t, b));
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("12:34:56", "5:24:26");
	test("00:00:00", "0:00:00");
	test("23:59:59", "9:99:99");
	test("11:11:11", "4:66:10");
	test("15:25:35", "6:42:77");
	test("01:02:03", "0:43:09");

	return 0;
}
