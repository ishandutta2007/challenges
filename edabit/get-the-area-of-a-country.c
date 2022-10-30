/*

Create a function that takes a country's name and its area as arguments and returns the area of the country's proportion of the total world's landmass.
Examples

areaOfCountry("Russia", 17098242) ➞ "Russia is 11.48% of the total world's landmass"

areaOfCountry("USA", 9372610), "USA is 6.29% of the total world's landmass"

areaOfCountry("Iran", 1648195) ➞ "Iran is 1.11% of the total world's landmass"

Notes

The total world's landmass is 148,940,000 [Km^2]
Round the result to two decimal places.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
areacountry(const char *s, unsigned long a, char *b, size_t n)
{
	static const unsigned long t = 148940000ul;

	snprintf(b, n, "%s is %.2f%% of the total world's landmass", s, a * 100.0 / t);
	return b;
}

void
test(const char *s, unsigned long a, const char *r)
{
	char b[128];

	areacountry(s, a, b, sizeof(b));
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("USA", 9372610, "USA is 6.29% of the total world's landmass");
	test("Russia", 17098242, "Russia is 11.48% of the total world's landmass");
	test("Iran", 1648195, "Iran is 1.11% of the total world's landmass");
	test("India", 3287590, "India is 2.21% of the total world's landmass");
	test("China", 9706961, "China is 6.52% of the total world's landmass");
	test("Yemen", 527968, "Yemen is 0.35% of the total world's landmass");
	test("Switzerland", 41284, "Switzerland is 0.03% of the total world's landmass");

	return 0;
}
