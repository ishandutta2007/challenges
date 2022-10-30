// Extend atof to handle scientific notation of the form
// 123.45e-6
// where a floating-point number may be followed by e or E
// and an optionally signed exponent.

#include <stdio.h>
#include <ctype.h>

double
xatof(const char *s)
{
	double v, p, e;
	size_t i;
	int sgn;

	i = 0;
	while (isspace(s[i]))
		i++;

	sgn = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;

	for (v = 0; isdigit(s[i]); i++)
		v = 10 * v + (s[i] - '0');
	if (s[i] == '.')
		i++;

	for (p = 1; isdigit(s[i]); i++) {
		v = 10 * v + (s[i] - '0');
		p *= 10;
	}
	v = sgn * v / p;

	if (s[i] == 'e' || s[i] == 'E') {
		sgn = (s[++i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-')
			i++;
		for (e = 0; isdigit(s[i]); i++)
			e = 10 * e + (s[i] - '0');
		if (sgn == 1) {
			while (e-- > 0)
				v *= 10;
		} else {
			while (e-- > 0)
				v /= 10;
		}
	}

	return v;
}

int
main(void)
{
	printf("%lf\n", xatof("1e9"));
	printf("%lf\n", xatof("-1.34e2"));
	printf("%lf\n", xatof("5.41e-5"));
	printf("%lf\n", xatof("+503412.215"));
	printf("%lf\n", xatof("123.45e-6"));
	return 0;
}
