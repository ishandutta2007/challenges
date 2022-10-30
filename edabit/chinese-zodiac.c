/*

Create a function that takes a year as an argument and returns the corresponding Chinese zodiac.

Examples

chineseZodiac(2021) ➞ "Ox"

chineseZodiac(2020) ➞ "Rat"

chineseZodiac(1933) ➞ "Rooster"

Notes

The list of animals used can vary slightly, so check the Resources tab for the list that you will need for this challenge.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

// https://mathtuition88.com/2014/04/01/how-to-calculate-chinese-zodiac/
const char *
zodiac(unsigned y)
{
	static const char *tab[] = {
	    "Rat",
	    "Ox",
	    "Tiger",
	    "Rabbit",
	    "Dragon",
	    "Snake",
	    "Horse",
	    "Sheep",
	    "Monkey",
	    "Rooster",
	    "Dog",
	    "Pig",
	};

	unsigned i;

	i = 0;
	if (1900 <= y && y <= 2000)
		i = ((y - 1900) % 12) + 1;
	else if (y > 2000)
		i = ((y - 2000) % 12) + 5;

	if (i == 0)
		return NULL;
	if (i > 12)
		i -= 12;
	return tab[i - 1];
}

void
test(unsigned y, const char *r)
{
	const char *p;

	p = zodiac(y);
	printf("%u %s\n", y, p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test(2021, "Ox");
	test(2020, "Rat");
	test(1938, "Tiger");
	test(1951, "Rabbit");
	test(1964, "Dragon");
	test(1977, "Snake");
	test(1990, "Horse");
	test(2003, "Sheep");
	test(2016, "Monkey");
	test(1969, "Rooster");
	test(1982, "Dog");
	test(1995, "Pig");
	test(1933, "Rooster");
	test(1900, "Rat");
	test(2000, "Dragon");

	return 0;
}
