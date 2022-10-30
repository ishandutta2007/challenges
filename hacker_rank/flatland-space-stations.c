/*

Flatland is a country with a number of cities, some of which have space stations.
Cities are numbered consecutively and each has a road of 1km length connecting it to the next city.
It is not a circular route, so the first city doesn't connect with the last city.
Determine the maximum distance from any city to it's nearest space station.

For example, there are n=3 cities and m=1 of them has a space station, city 1.
They occur consecutively along a route. City 2 is 2-1=1 unit away and city 3 is 3-1=2 units away.
City is 0 units from its nearest space station as one is located there. The maximum distance is 2.

*/

#include <stdio.h>
#include <inttypes.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

ssize_t
route(int *a, size_t n)
{
	size_t i, l, m;

	l = -1;
	m = 0;
	for (i = 0; i < n; i++) {
		if (!a[i])
			continue;
		m = (l == -1) ? i : max(m, (i - l) / 2);
		l = i;
	}
	if (l == -1)
		return -1;
	return max(m, n - 1 - l);
}

int
main(void)
{
	int a[5] = {
	    [0] 1,
	    [4] 1,
	};
	printf("%zd\n", route(a, nelem(a)));

	int b[6] = {1, 1, 1, 1, 1, 1};
	printf("%zd\n", route(b, nelem(b)));

	int c[3] = {
	    [0] 1,
	};
	printf("%zd\n", route(c, nelem(c)));

	int d[50] = {0};
	printf("%zd\n", route(d, nelem(d)));

	return 0;
}
