/*

Create a function that returns the simplified version of a fraction.
Examples

simplify("4/6") ➞ "2/3"

simplify("10/11") ➞ "10/11"

simplify("100/400") ➞ "1/4"

simplify("8/4") ➞ "2"

Notes

	A fraction is simplified if there are no common factors (except 1) between the numerator and the denominator. For example, 4/6 is not simplified, since 4 and 6 both share 2 as a factor.
	If improper fractions can be transformed into integers, do so in your code (see example #4).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
gcd(int a, int b)
{
	int t;

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
	int x, y, z;

	if (sscanf(s, "%d/%d", &x, &y) != 2)
		return NULL;

	z = gcd(x, y);
	if (z == 0)
		return NULL;

	x /= z;
	y /= z;
	if (y == 1)
		snprintf(b, n, "%d", x);
	else
		snprintf(b, n, "%d/%d", x, y);
	return b;
}

void
test(const char *s, const char *t)
{
	char b[80];

	assert(!strcmp(simplify(s, b, sizeof(b)), t));
}

int
main(void)
{
	test("5/7", "5/7");
	test("4/6", "2/3");
	test("11/10", "11/10");
	test("8/4", "2");
	test("7/4", "7/4");
	test("6/4", "3/2");
	test("300/200", "3/2");
	test("50/25", "2");
	test("5/45", "1/9");
	test("10/11", "10/11");
	test("100/400", "1/4");
	test("8/4", "2");

	return 0;
}
