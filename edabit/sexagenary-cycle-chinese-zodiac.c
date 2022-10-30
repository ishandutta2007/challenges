/*

In early recorded Chinese history, time was reckoned using the sexagenary (60-year) cycle, generated from two subcycles:

    Five heavenly stems (elements) in this order: wood, fire, earth, metal, water. The stems change every two years.
    Twelve earthly branches (animals) in this order: rat, ox, tiger, rabbit, dragon, snake, horse, sheep, monkey, rooster, dog, pig. The branches change yearly.

The combinations between these two sub-cycles result in a 60-year cycle where no two years are the same —
for example, the 5 years of the Rat have 5 different elements: 1924 Wood Rat, 1936 Fire Rat, 1948 Earth Rat, 1960 Metal Rat, 1972 Water Rat.

The first 14 years of the current cycle are shown in the table below:
Gregorian Year	Stem	Branch
1984	Wood	Rat
1985	Wood	Ox
1986	Fire	Tiger
1987	Fire	Rabbit
1988	Earth	Dragon
1989	Earth	Snake
1990	Metal	Horse
1991	Metal	Sheep
1992	Water	Monkey
1993	Water	Rooster
1994	Wood	Dog
1995	Wood	Pig
1996	Fire	Rat
1997	Fire	Ox

These days, the sexagenary cycle is used mainly for historical celebrations and events, and in Chinese astrology. The Gregorian calendar is now the standard means of reckoning time.

Create a function that takes a number representing a year in the Gregorian calendar, and returns a string consisting of the corresponding stem-and-branch combination in the sexagenary cycle.
Examples

sexagenary(1971) ➞ "Metal Pig"

sexagenary(1927) ➞ "Fire Rabbit"

sexagenary(1974) ➞ "Wood Tiger"

Notes

N/A
 
*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

int
cycle(int x, int d, int b, int m)
{
	int y;

	x = mod(x / d, m);
	y = mod(b / d, m);
	x = mod(x - y, m);
	return x;
}

char *
sexagenary(int y, char *b, size_t nb)
{
	static const char *elements[] = {
	    "Wood",
	    "Fire",
	    "Earth",
	    "Metal",
	    "Water",
	};
	static const char *animals[] = {
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

	int n, m;

	n = cycle(y, 2, 1984, nelem(elements));
	m = cycle(y, 1, 1984, nelem(animals));
	snprintf(b, nb, "%s %s", elements[n], animals[m]);
	return b;
}

void
test(int n, const char *r)
{
	char b[128];

	sexagenary(n, b, sizeof(b));
	printf("%d %s\n", n, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(1971, "Metal Pig");
	test(1927, "Fire Rabbit");
	test(2017, "Fire Rooster");
	test(2000, "Metal Dragon");
	test(1958, "Earth Dog");
	test(1942, "Water Horse");
	test(1974, "Wood Tiger");
	test(1996, "Fire Rat");
	test(1993, "Water Rooster");
	test(1985, "Wood Ox");

	return 0;
}
