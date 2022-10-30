/*

If today was Monday, in two days, it would be Wednesday.

Create a function that takes in an array of days as input and the number of days to increment by. Return an array of days after n number of days has passed.
Examples

afterNDays(["Thursday", "Monday"], 4) ➞ ["Monday", "Friday"]

afterNDays(["Sunday", "Sunday", "Sunday"], 1) ➞ ["Monday", "Monday", "Monday"]

afterNDays(["Monday", "Tuesday", "Friday"], 1) ➞ ["Tuesday", "Wednesday", "Saturday"]

Notes

    Return as an array.
    All test cases will have the first letter of each day capitalized.
    n number of days may be greater than 7.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char **
ndays(const char **s, size_t n, unsigned d)
{
	static const char *tab[] = {
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
		"Sunday",
	};

	const char **p;
	size_t i, j;

	p = calloc(n, sizeof(*p));
	if (!p)
		return NULL;

	for (i = 0; i < n; i++) {
		p[i] = "Invalid";
		for (j = 0; j < nelem(tab); j++) {
			if (!strcmp(s[i], tab[j])) {
				p[i] = tab[(j + d) % nelem(tab)];
				break;
			}
		}
	}
	return p;
}

void
test(const char **s, const char **t, size_t n, unsigned d)
{
	const char **p;
	size_t i;

	p = ndays(s, n, d);
	assert(p != NULL);
	for (i = 0; i < n; i++)
		assert(!strcmp(p[i], t[i]));
	free(p);
}

int
main(void)
{
	const char *s1[] = { "Monday", "Tuesday", "Friday" };
	const char *t1[] = { "Tuesday", "Wednesday", "Saturday" };

	const char *s2[] = { "Sunday", "Sunday", "Sunday" };
	const char *t2[] = { "Monday", "Monday", "Monday" };

	const char *s3[] = { "Thursday", "Monday" };
	const char *t3[] = { "Monday", "Friday" };

	const char *s4[] = { "Sunday" };
	const char *t4[] = { "Sunday" };

	const char *s5[] = { "Monday", "Friday", "Wednesday" };
	const char *t5[] = { "Tuesday", "Saturday", "Thursday" };

	const char *s6[] = { "Sunday", "Tuesday" };
	const char *t6[] = { "Friday", "Sunday" };

	const char *s7[] = { "Saturday", "Wednesday", "Wednesday" };
	const char *t7[] = { "Tuesday", "Saturday", "Saturday" };

	test(s1, t1, nelem(s1), 1);
	test(s2, t2, nelem(s2), 1);
	test(s3, t3, nelem(s3), 4);
	test(s4, t4, nelem(s4), 7);
	test(s5, t5, nelem(s5), 15);
	test(s6, t6, nelem(s6), 5);
	test(s7, t7, nelem(s7), 10);

	return 0;
}
