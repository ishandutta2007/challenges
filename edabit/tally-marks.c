/*

Create a function that can convert from normal notation to tally-mark notation and vice versa. In tally-mark notation, a number can be decomposed as the sum of 5s + remainder.

The function will look like this: switchNotation([current scores], desired notation)

Ex.1 Normal: 3, 24, 4, 9
Ex.1 Tally: 3, 55554, 4, 54

Ex.2 Normal: 2, 12, 2, 4
Ex.2 Tally: 2, 552, 2, 4

Examples

switchNotation([51], "normal") ➞ [6]

switchNotation([3, 55, 55551], "normal") ➞ [3, 10, 21]

switchNotation([15, 29, 5, 3], "tally") ➞ [555, 555554, 5, 3]

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

long
tally2normal(long v)
{
	long x, r;

	x = labs(v);
	r = 0;
	while (x) {
		r += (x % 10);
		x /= 10;
	}

	return (v >= 0) ? r : -r;
}

long
normal2tally(long v)
{
	long x, r, t;

	x = labs(v);
	r = 0;
	while (x) {
		t = min(x, 5);
		r = (r * 10) + t;
		x -= t;
	}

	return (v >= 0) ? r : -r;
}

long *
tallymark(long *a, size_t n, const char *t)
{
	long (*f)(long);
	size_t i;
	long *p;

	if (!strcmp(t, "normal"))
		f = tally2normal;
	else if (!strcmp(t, "tally"))
		f = normal2tally;
	else
		return NULL;

	p = calloc(n, sizeof(*p));
	if (!p)
		return NULL;

	for (i = 0; i < n; i++)
		p[i] = f(a[i]);
	return p;
}

void
test(long *a, size_t n, const char *t, long *r)
{
	long *p;

	p = tallymark(a, n, t);
	assert(p);
	assert(memcmp(p, r, sizeof(*r) * n) == 0);
	free(p);
}

int
main(void)
{
	long a1[] = { 3, 55, 55551 };
	long a2[] = { 553, 55, 51 };
	long a3[] = { 51 };
	long a4[] = { 555, 55, 5 };
	long a5[] = { 15, 29, 5, 3 };
	long a6[] = { 3, 8, 8, 6 };
	long a7[] = { 3, 44, 8, 21 };

	long r1[] = { 3, 10, 21 };
	long r2[] = { 13, 10, 6 };
	long r3[] = { 6 };
	long r4[] = { 15, 10, 5 };
	long r5[] = { 555, 555554, 5, 3 };
	long r6[] = { 3, 53, 53, 51 };
	long r7[] = { 3, 555555554, 53, 55551 };

	test(a1, nelem(a1), "normal", r1);
	test(a2, nelem(a2), "normal", r2);
	test(a3, nelem(a3), "normal", r3);
	test(a4, nelem(a4), "normal", r4);
	test(a5, nelem(a5), "tally", r5);
	test(a6, nelem(a6), "tally", r6);
	test(a7, nelem(a7), "tally", r7);

	return 0;
}
