/*

Create a function which simplifies a given fraction into its simplest ratio. Return the fraction as a string.

Notes

    Fractions are given as strings.
    Return the same fraction if it is already in its simplified ratio (see example #3).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

unsigned long
gcd(unsigned long a, unsigned long b)
{
	unsigned long t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

char *
simplify(const char *s, char *b, size_t n)
{
	unsigned long x, y, z;

	if (sscanf(s, "%lu/%lu", &x, &y) != 2)
		return NULL;

	z = gcd(x, y);
	if (z) {
		x /= z;
		y /= z;
	}

	snprintf(b, n, "%lu/%lu", x, y);
	return b;
}

int
main(void)
{
	char b[80];

	assert(!strcmp(simplify("2/4", b, sizeof(b)), "1/2"));
	assert(!strcmp(simplify("15/25", b, sizeof(b)), "3/5"));
	assert(!strcmp(simplify("4/9", b, sizeof(b)), "4/9"));
	assert(!strcmp(simplify("15/48", b, sizeof(b)), "5/16"));
	assert(!strcmp(simplify("8/41", b, sizeof(b)), "8/41"));
	assert(!strcmp(simplify("13/94", b, sizeof(b)), "13/94"));
	assert(!strcmp(simplify("9/95", b, sizeof(b)), "9/95"));
	assert(!strcmp(simplify("8/69", b, sizeof(b)), "8/69"));
	assert(!strcmp(simplify("4/31", b, sizeof(b)), "4/31"));
	assert(!strcmp(simplify("13/8", b, sizeof(b)), "13/8"));
	assert(!strcmp(simplify("7/86", b, sizeof(b)), "7/86"));
	assert(!strcmp(simplify("19/75", b, sizeof(b)), "19/75"));
	assert(!strcmp(simplify("10/44", b, sizeof(b)), "5/22"));
	assert(!strcmp(simplify("1/93", b, sizeof(b)), "1/93"));
	assert(!strcmp(simplify("17/23", b, sizeof(b)), "17/23"));
	assert(!strcmp(simplify("20/80", b, sizeof(b)), "1/4"));
	assert(!strcmp(simplify("12/13", b, sizeof(b)), "12/13"));
	assert(!strcmp(simplify("8/51", b, sizeof(b)), "8/51"));
	assert(!strcmp(simplify("8/29", b, sizeof(b)), "8/29"));
	assert(!strcmp(simplify("20/41", b, sizeof(b)), "20/41"));
	assert(!strcmp(simplify("2/75", b, sizeof(b)), "2/75"));
	assert(!strcmp(simplify("20/24", b, sizeof(b)), "5/6"));
	assert(!strcmp(simplify("13/22", b, sizeof(b)), "13/22"));
	assert(!strcmp(simplify("4/15", b, sizeof(b)), "4/15"));
	assert(!strcmp(simplify("9/29", b, sizeof(b)), "9/29"));
	assert(!strcmp(simplify("17/83", b, sizeof(b)), "17/83"));
	assert(!strcmp(simplify("19/65", b, sizeof(b)), "19/65"));
	assert(!strcmp(simplify("6/58", b, sizeof(b)), "3/29"));
	assert(!strcmp(simplify("5/18", b, sizeof(b)), "5/18"));
	assert(!strcmp(simplify("9/51", b, sizeof(b)), "3/17"));
	assert(!strcmp(simplify("19/93", b, sizeof(b)), "19/93"));
	assert(!strcmp(simplify("2/97", b, sizeof(b)), "2/97"));
	assert(!strcmp(simplify("4/63", b, sizeof(b)), "4/63"));
	assert(!strcmp(simplify("3/10", b, sizeof(b)), "3/10"));
	assert(!strcmp(simplify("11/39", b, sizeof(b)), "11/39"));
	assert(!strcmp(simplify("2/28", b, sizeof(b)), "1/14"));
	assert(!strcmp(simplify("10/51", b, sizeof(b)), "10/51"));
	assert(!strcmp(simplify("12/76", b, sizeof(b)), "3/19"));
	assert(!strcmp(simplify("15/43", b, sizeof(b)), "15/43"));
	assert(!strcmp(simplify("18/74", b, sizeof(b)), "9/37"));
	assert(!strcmp(simplify("7/48", b, sizeof(b)), "7/48"));
	assert(!strcmp(simplify("2/7", b, sizeof(b)), "2/7"));
	assert(!strcmp(simplify("20/73", b, sizeof(b)), "20/73"));
	assert(!strcmp(simplify("6/24", b, sizeof(b)), "1/4"));
	assert(!strcmp(simplify("5/67", b, sizeof(b)), "5/67"));
	assert(!strcmp(simplify("10/15", b, sizeof(b)), "2/3"));
	assert(!strcmp(simplify("10/95", b, sizeof(b)), "2/19"));
	assert(!strcmp(simplify("19/100", b, sizeof(b)), "19/100"));
	assert(!strcmp(simplify("17/80", b, sizeof(b)), "17/80"));
	assert(!strcmp(simplify("1/54", b, sizeof(b)), "1/54"));
	assert(!strcmp(simplify("5/53", b, sizeof(b)), "5/53"));
	assert(!strcmp(simplify("1/50", b, sizeof(b)), "1/50"));
	assert(!strcmp(simplify("12/41", b, sizeof(b)), "12/41"));

	return 0;
}
