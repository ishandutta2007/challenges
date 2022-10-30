/*

Create a function that takes an old price oldPrice, a new price newPrice, and returns what percent the price decreased or increased.
Round the percentage to the nearest whole percent.

Examples

percentageChanged("$800", "$600") ➞ "25% decrease"

percentageChanged("$1000", "$840") ➞ "16% decrease"

percentageChanged("$100", "$950") ➞ "850% increase"

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char *
change(const char *s, const char *t, char *b)
{
	double x, y;
	long r;

	if (sscanf(s, "$%lf", &x) != 1)
		return NULL;
	if (sscanf(t, "$%lf", &y) != 1)
		return NULL;

	r = fabs((y - x) / x * 100);
	sprintf(b, "%ld%% %s", r, (x <= y) ? "increase" : "decrease");

	return b;
}

void
test(const char *s, const char *t, const char *r)
{
	char b[128];

	change(s, t, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("$800", "$600", "25% decrease");
	test("$1000", "$840", "16% decrease");
	test("$700", "$650", "7% decrease");
	test("$100", "$950", "850% increase");
	test("$450", "$460", "2% increase");
	test("$1000", "$1500", "50% increase");

	return 0;
}
