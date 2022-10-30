/*

Mubashir needs your help in his maths homework.

Create a function which takes an array of Complex Numbers and returns the sum as a string.
Examples

sumComplex(["2+3i", "3-i"]) ➞ "5+2i"

sumComplex(["1", "1"]) ➞ "2"

sumComplex(["i", "2i", "3i"]) ➞ "6i"

Notes

N/A

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
scannumber(const char **s, int v[2])
{
	char *ep;
	long x;
	int i, sgn;

	errno = 0;
	x = strtol(*s, &ep, 10);
	if (errno == ERANGE && (x == LONG_MAX || x == LONG_MIN))
		return -1;
	if (errno != 0 && x == 0)
		return -1;

	if (*s == ep) {
		sgn = 1;
		if (*ep == '+' || *ep == '-') {
			sgn = (*ep == '+') ? 1 : -1;
			*s = ++ep;
		}

		if (*ep == 'i' || *ep == 'I') {
			v[1] = sgn;
			*s = ++ep;
			return 2;
		}

		if (*ep == '\0')
			return 0;

		return -1;
	}

	i = 0;
	if (*ep == 'i' || *ep == 'I') {
		i = 1;
		ep++;
	}

	*s = ep;
	v[i] = x;

	return i + 1;
}

int
scancomplex(const char *s, int v[2])
{
	int r;

	v[0] = v[1] = 0;
	r = scannumber(&s, v);
	if (r <= 0 || r == 2)
		return (r < 0) ? r : 0;

	r = scannumber(&s, v);
	return (r == 2 || r == 0) ? 0 : -1;
}

char *
sumcomplex(const char **s, size_t n, char *b)
{
	int u, v, l, x[2];
	size_t i;

	u = v = 0;
	for (i = 0; i < n; i++) {
		if (scancomplex(s[i], x) < 0)
			return NULL;
		u += x[0];
		v += x[1];
	}

	l = 0;
	if (u != 0 || u == v)
		l += sprintf(b + l, "%d", u);
	if (v != 0) {
		if (u != 0 && v > 0)
			l += sprintf(b + l, "+");
		if (v != 1 && v != -1)
			l += sprintf(b + l, "%d", v);
		else if (v < 0)
			l += sprintf(b + l, "-");

		l += sprintf(b + l, "i");
	}

	return b;
}

void
test(const char **s, size_t n, const char *r)
{
	char b[128];

	assert(sumcomplex(s, n, b) != NULL);
	assert(!strcmp(b, r));
}

int
main(void)
{
	const char *s1[] = {"3+4i"};
	const char *s2[] = {"123+456i"};
	const char *s3[] = {"0"};
	const char *s4[] = {"-i"};
	const char *s5[] = {"1", "1"};
	const char *s6[] = {"-5", "5"};
	const char *s7[] = {"1", "10", "100", "1000"};
	const char *s8[] = {"2+3i", "3-i"};
	const char *s9[] = {"5+4i", "11+3i"};
	const char *s10[] = {"-2-4i", "-8+6i"};
	const char *s11[] = {"-1-i", "7+10i"};
	const char *s12[] = {"1", "-3+i"};
	const char *s13[] = {"1", "-3-i"};
	const char *s14[] = {"3+4i", "3-4i"};
	const char *s15[] = {"10+i", "10-i", "9"};
	const char *s16[] = {"2+3i", "0", "0"};
	const char *s17[] = {"2+i", "3+2i", "-5-2i"};
	const char *s18[] = {"2+i", "3+2i", "-5-4i"};
	const char *s19[] = {"10+5i", "1-i", "-i"};
	const char *s20[] = {"i", "2i", "3i"};
	const char *s21[] = {"-i", "-3i", "1+i"};
	const char *s22[] = {"-1000i", "1000i", "1234"};
	const char *s23[] = {"-i", "123", "4-i"};

	test(NULL, 0, "0");
	test(s1, nelem(s1), "3+4i");
	test(s2, nelem(s2), "123+456i");
	test(s3, nelem(s3), "0");
	test(s4, nelem(s4), "-i");
	test(s5, nelem(s5), "2");
	test(s6, nelem(s6), "0");
	test(s7, nelem(s7), "1111");
	test(s8, nelem(s8), "5+2i");
	test(s9, nelem(s9), "16+7i");
	test(s10, nelem(s10), "-10+2i");
	test(s11, nelem(s11), "6+9i");
	test(s12, nelem(s12), "-2+i");
	test(s13, nelem(s13), "-2-i");
	test(s14, nelem(s14), "6");
	test(s15, nelem(s15), "29");
	test(s16, nelem(s16), "2+3i");
	test(s17, nelem(s17), "i");
	test(s18, nelem(s18), "-i");
	test(s19, nelem(s19), "11+3i");
	test(s20, nelem(s20), "6i");
	test(s21, nelem(s21), "1-3i");
	test(s22, nelem(s22), "1234");
	test(s23, nelem(s23), "127-2i");

	return 0;
}
