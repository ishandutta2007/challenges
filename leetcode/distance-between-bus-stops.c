/*

A bus has n stops numbered from 0 to n - 1 that form a circle. We know the distance between all pairs of
neighboring stops where distance[i] is the distance between the stops number i and (i + 1) % n.

The bus goes along both directions i.e. clockwise and counterclockwise.

Return the shortest distance between the given start and destination stops.

Constraints:

1 <= n <= 10^4
distance.length == n		   
0 <= start, destination < n
0 <= distance[i] <= 10^4

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <inttypes.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
busdist(int *b, size_t n, size_t s, size_t d)
{
	size_t i;
	int x, y;

	x = y = 0;
	for (i = 0; i < n; i++)
		x += b[i];
	while (s != d) {
		y += b[s++];
		if (s >= n)
			s = 0;
	}
	return min(x - y, y);
}

int
main(void)
{
	int b1[] = {1, 2, 3, 4};
	int b2[] = {52, 342548, 14, 255, 2312, 424, 324342, 3, 42};

	printf("%d\n", busdist(b1, nelem(b1), 0, 1));
	printf("%d\n", busdist(b1, nelem(b1), 0, 2));
	printf("%d\n", busdist(b1, nelem(b1), 0, 3));
	printf("%d\n", busdist(b2, nelem(b2), 2, 5));

	return 0;
}
