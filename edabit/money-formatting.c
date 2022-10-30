/*

Given a number, return a string which is formatted into US Dollars and cents!

Remember that:

    You should round to two digits after the decimal point (even for integers).
    Thousandths should be separated by commas.

Examples

dollaDollaBills(10) ➞ "$10.00"

dollaDollaBills(1000000) ➞ "$1,000,000.00"

dollaDollaBills(-314159.2653) ➞ "-$314,159.27"

dollaDollaBills(-56.99) ➞ "-$56.99"

Notes

    There will be both negative and positive inputs.
    Check the Resources tab for many tutorials on how to approach string formatting.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
moneyfmt(double v, char *b)
{
	int i, j, k, n, m;
	char s[1024], *p;

	snprintf(s, sizeof(s), "%.2f", v);
	i = 0;
	j = 0;

	if (v < 0) {
		b[j++] = '-';
		i++;
	}
	b[j++] = '$';

	p = strchr(s + i, '.');
	if (!p)
		return NULL;
	m = p - (s + i);
	k = 3 - (m % 3);
	for (n = 0; n < m; n++) {
		b[j++] = s[i++];
		if ((++k % 3) == 0 && n + 1 < m)
			b[j++] = ',';
	}
	strcpy(b + j, s + i);

	return b;
}

void
test(double v, const char *r)
{
	char b[1024];

	assert(moneyfmt(v, b));
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(10, "$10.00");
	test(31.4159, "$31.42");
	test(-56.99, "-$56.99");
	test(-0.008, "-$0.01");
	test(0.05, "$0.05");
	test(1000000.0, "$1,000,000.00");
	test(-314159.2653, "-$314,159.27");
	test(1e9, "$1,000,000,000.00");
	test(130249001, "$130,249,001.00");
	test(10249001, "$10,249,001.00");
	test(1e8, "$100,000,000.00");
	test(1234.45, "$1,234.45");
	test(10234.45, "$10,234.45");
	test(103.50, "$103.50");

	return 0;
}
