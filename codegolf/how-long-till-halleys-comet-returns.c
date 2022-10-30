/*

Halley's Comet is the only comet that may appear (i.e. become visible to the naked eye on Earth) twice in a human lifetime. The orbital period of Halley's Comet is not constant: it has varied between 75 to 79 Earth years since the first definite apparition was recorded in 240 BCE. This variability is mainly driven by gravitational interactions between the comet and the planets of the Solar System. For the three millennia up to the year 3000, Halley's Comet appeared, or is projected to appear, in the following years:

66, 141, 218, 295, 374, 451, 530, 607, 684, 760, 837, 912, 989, 1066, 1145, 1222, 1301, 1378, 1456, 1531, 1607, 1682, 1758, 1835, 1910, 1986, 2061, 2134, 2209, 2284, 2358, 2430, 2504, 2579, 2653, 2726, 2795, 2863, 2931, 3000

Apparitions beyond 2134 predicted using this orbit simulator. The simulations account for gravitational perturbations due to the planets but not for other effects, such as changes in the comet's outgassing rate, that also affect its orbit. See here for further discussion.
Task

Write a program or function that takes as input a positive integer up to 3000 (inclusive), representing a year, and outputs/returns the number of years until the next apparition of Halley's Comet. In other words, if the input year is y
and Halley's Comet next appears in year yH≥y, find yH−y

. The shortest code (in bytes) in each language wins.
Test cases

   1 -> 65
1066 ->  0
1067 -> 78
1986 ->  0
1987 -> 74 
2021 -> 40

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
binsearch(const int a[], size_t n, int v)
{
	size_t lo, hi, mid;

	lo = 0;
	hi = n - 1;
	if (lo >= n || v <= a[lo])
		return lo;
	if (v > a[hi])
		return hi;
	while (hi - lo != 1) {
		mid = lo + (hi - lo) / 2;
		if (a[mid] < v)
			lo = mid;
		else
			hi = mid;
	}
	return hi;
}

int
halleys(int y)
{
	static const int tab[] = {
	    66,
	    141,
	    218,
	    295,
	    374,
	    451,
	    530,
	    607,
	    684,
	    760,
	    837,
	    912,
	    989,
	    1066,
	    1145,
	    1222,
	    1301,
	    1378,
	    1456,
	    1531,
	    1607,
	    1682,
	    1758,
	    1835,
	    1910,
	    1986,
	    2061,
	    2134,
	    2209,
	    2284,
	    2358,
	    2430,
	    2504,
	    2579,
	    2653,
	    2726,
	    2795,
	    2863,
	    2931,
	    3000,
	};

	size_t i;

	i = binsearch(tab, nelem(tab), y);
	if (tab[i] < y)
		return -1;
	return tab[i] - y;
}

int
main(void)
{
	static const int tab[][2] = {
	    {1, 65},
	    {1066, 0},
	    {1067, 78},
	    {1986, 0},
	    {1987, 74},
	    {2021, 40},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(halleys(tab[i][0]) == tab[i][1]);

	return 0;
}
