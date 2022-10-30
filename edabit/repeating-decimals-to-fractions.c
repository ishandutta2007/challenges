/*

Performing division on a fraction often results in an infinitely repeating decimal.

1/3=.3333333...  1/7=.142857142857...

Create a function that takes a decimal in string form with the repeating part in parentheses and returns the equivalent
fraction in string form and in lowest terms.

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>
#include <limits.h>
#include <errno.h>

typedef struct {
	intmax_t n;
	intmax_t d;
} Rat;

intmax_t
gcd(intmax_t a, intmax_t b)
{
	intmax_t t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

Rat
ratcanon(Rat r)
{
	intmax_t m;

	m = gcd(r.n, r.d);
	return (Rat){r.n / m, r.d / m};
}

Rat
ratadd(Rat a, Rat b)
{
	return ratcanon((Rat){a.n * b.d + b.n * a.d, a.d * b.d});
}

intmax_t
ipow10(intmax_t p)
{
	intmax_t i, v;

	if (p <= 0)
		return 0;

	v = 1;
	for (i = 0; i < p; i++)
		v *= 10;
	return v;
}

int
readnum(const char **s, char *b, size_t n, size_t *l, intmax_t *v)
{
	const char *p;
	char *sp;
	size_t i;

	p = *s;
	for (i = 0; p[i]; i++) {
		if (!isdigit(p[i]))
			break;
		if (i + 1 < n)
			b[i] = p[i];
	}
	if (i + 1 < n)
		b[i] = '\0';

	errno = 0;
	*s = &p[i];
	*l = i;
	*v = strtoimax(b, &sp, 10);
	if (errno || i + 1 >= n)
		return 0;
	return 1;
}

char *
fractions(const char *s, char *b, size_t n)
{
	char p[3][sizeof(intmax_t) * CHAR_BIT];
	intmax_t v[3], sgn;
	Rat r[3];
	size_t l[3];

	sgn = 1;
	if (*s == '-') {
		sgn = -1;
		s++;
	}

	memset(p, 0, sizeof(p));
	memset(v, 0, sizeof(v));
	memset(l, 0, sizeof(l));

	if (!readnum(&s, p[0], sizeof(p[0]), &l[0], &v[0]))
		return NULL;

	if (*s != '.' && *s != '\0')
		return NULL;
	if (*s == '.') {
		s++;
		if (!readnum(&s, p[1], sizeof(p[1]), &l[1], &v[1]))
			return NULL;
	}

	if (*s != '(' && *s != '\0')
		return NULL;
	if (*s == '(') {
		s++;
		if (!readnum(&s, p[2], sizeof(p[2]), &l[2], &v[2]) || *s != ')')
			return NULL;
		s++;
	}
	if (*s != '\0')
		return NULL;

	r[0] = (Rat){v[0], 1};
	r[1] = (Rat){v[1], 1};
	r[2] = (Rat){v[2], 1};
	if (l[1])
		r[1].d = ipow10(l[1]);
	if (l[2]) {
		r[2] = ratcanon((Rat){v[2], ipow10(l[2]) - 1});
		if (l[1])
			r[2].d *= ipow10(l[1]);
	}

	r[0] = ratadd(r[0], ratadd(r[1], r[2]));
	r[0].n *= sgn;

	snprintf(b, n, "%jd/%jd", r[0].n, r[0].d);
	return b;
}

int
main(void)
{
	char b[80];

	printf("%s\n", fractions("0.(6)", b, sizeof(b)));
	printf("%s\n", fractions("1.(1)", b, sizeof(b)));
	printf("%s\n", fractions("3.(142857)", b, sizeof(b)));
	printf("%s\n", fractions("0.19(2367)", b, sizeof(b)));
	printf("%s\n", fractions("0.1097(3)", b, sizeof(b)));
	printf("%s\n", fractions("0.(09)", b, sizeof(b)));
	printf("%s\n", fractions("0.0(45)", b, sizeof(b)));
	printf("%s\n", fractions("2.1(313)", b, sizeof(b)));
	printf("%s\n", fractions("12.(12345)", b, sizeof(b)));
	printf("%s\n", fractions("1.017(857142)", b, sizeof(b)));
	printf("%s\n", fractions("0.(052631578947368421)", b, sizeof(b)));
	printf("%s\n", fractions("9.145", b, sizeof(b)));
	printf("%s\n", fractions("12345", b, sizeof(b)));
	printf("%s\n", fractions("12345.(1465)", b, sizeof(b)));
	printf("%s\n", fractions("-345.5", b, sizeof(b)));

	return 0;
}
