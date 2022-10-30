/*

Jake is a very habitual person. He eats breakfast at 7:00 a.m. each morning, lunch at 12:00 p.m. and dinner at 7:00 p.m. in the evening.

Create a function that takes in the current time as a string and determines the duration of time before Jake's next meal.
Represent this as an array with the first and second elements representing hours and minutes, respectively.

Examples

time_to_eat("2:00 p.m.") ➞ [5, 0]
// 5 hours until the next meal, dinner

time_to_eat("5:50 a.m.") ➞ [1, 10]
// 1 hour and 10 minutes until the next meal, breakfast

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

long
conv(const char *s)
{
	unsigned h, m;
	char p[32];

	if (sscanf(s, "%u:%u %31s", &h, &m, p) != 3)
		return -1;

	if (h > 12 || m >= 60)
		return -1;

	if (!strcmp(p, "p.m."))
		h += (h != 12) ? 12 : 0;
	else if (strcmp(p, "a.m."))
		return -1;

	return (h * 60) + m;
}

int
mealtime(const char *s, long r[2])
{
	long tab[] = {
	    conv("7:00 a.m."),
	    conv("12:00 p.m."),
	    conv("7:00 p.m."),
	};

	long t, d;
	size_t i;

	t = conv(s);
	if (t < 0)
		return t;

	for (i = 0; i < nelem(tab); i++) {
		if (tab[i] > t)
			break;
	}
	if (i < nelem(tab))
		d = tab[i] - t;
	else
		d = (24 * 60 - t) + tab[0];

	r[0] = d / 60;
	r[1] = d % 60;

	return 0;
}

void
test(const char *s, long r[2])
{
	long p[2];

	assert(mealtime(s, p) >= 0);
	printf("%s [%ld %ld]\n", s, p[0], p[1]);
	assert(!memcmp(r, p, sizeof(p)));
}

int
main(void)
{
	test("2:00 p.m.", (long[]){5, 0});
	test("5:50 a.m.", (long[]){1, 10});
	test("6:37 p.m.", (long[]){0, 23});
	test("12:00 a.m.", (long[]){7, 0});
	test("11:58 p.m.", (long[]){7, 2});
	test("3:33 p.m.", (long[]){3, 27});
	test("6:58 p.m.", (long[]){0, 2});
	test("11:00 a.m.", (long[]){1, 0});
	test("7:00 a.m.", (long[]){5, 0});
	test("1:00 p.m.", (long[]){6, 0});

	return 0;
}
