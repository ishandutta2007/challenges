// calculate day of the week given a date
// using doomsday algorithm for gregorian calendar
// https://en.wikipedia.org/wiki/Doomsday_rule
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
isleap(int y)
{
	if (y % 4 != 0)
		return 0;
	if (y % 100 == 0 && y % 400 != 0)
		return 0;
	return 1;
}

int
doomsday(int m, int d, int y)
{
	return (2 + y + y / 4 - y / 100 + y / 400) % 7;
}

int
yearday(int m, int d, int y)
{
	static const int tab[] = {
	    -1,
	    0,
	    28,
	    59,
	    89,
	    120,
	    150,
	    181,
	    212,
	    242,
	    273,
	    303,
	    334,
	};
	return d + tab[m] + isleap(y);
}

int
closestdoomsday(int m, int d, int y)
{
	int tab[] = {
	    -1,
	    3,
	    28,
	    7,
	    4,
	    9,
	    6,
	    11,
	    8,
	    5,
	    10,
	    7,
	    12,
	};
	int i, j, p, q, r, s;

	if (isleap(y)) {
		tab[0] = 4;
		tab[1] = 29;
	}

	p = yearday(m, d, y);
	r = INT_MAX;
	for (i = -1; i <= 1; i++) {
		j = (m - 1 + i) % 12;
		if (j < 0)
			j += 12;
		j++;

		q = yearday(j, tab[j], y);
		if (abs(p - q) < r) {
			r = abs(p - q);
			s = q;
		}
	}
	return s;
}

const char *
weekday(int m, int d, int y)
{
	static const char *tab[] = {
	    "Monday",
	    "Tuesday",
	    "Wednesday",
	    "Thursday",
	    "Friday",
	    "Saturday",
	    "Sunday",
	};
	int a, b, c;

	a = yearday(m, d, y);
	b = closestdoomsday(m, d, y);
	c = doomsday(m, d, y);

	c += ((a - b - 1) % 7);
	if (c < 0)
		c += 7;
	return tab[c % nelem(tab)];
}

int
main(void)
{
	printf("%s\n", weekday(2, 11, 1978));
	printf("%s\n", weekday(9, 18, 1985));
	printf("%s\n", weekday(4, 12, 1861));
	printf("%s\n", weekday(10, 13, 2018));
	printf("%s\n", weekday(9, 11, 2001));
	printf("%s\n", weekday(12, 25, 2006));
	return 0;
}
