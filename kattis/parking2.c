/*

When shopping on Long Street, Michael usually parks his car at some random location, and then walks to the stores he needs. Can you help Michael choose a place to park which minimises the distance he needs to walk on his shopping round?

Long Street is a straight line, where all positions are integer. You pay for parking in a specific slot, which is an integer position on Long Street.
Michael does not want to pay for more than one parking though. He is very strong, and does not mind carrying all the bags around.

Input

The first line of input gives the number of test cases, 1≤t≤100. There are two lines for each test case. The first gives the number of stores Michael wants to visit, 1≤n≤20, and the second gives their n integer positions on Long Street, 0≤xi≤99.

Output

Output for each test case a line with the minimal distance Michael must walk given optimal parking.

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

unsigned
parking(unsigned *a, size_t n)
{
	unsigned x, y;
	size_t i;

	if (n == 0)
		return 0;

	x = UINT_MAX;
	y = 0;
	for (i = 0; i < n; i++) {
		x = min(x, a[i]);
		y = max(y, a[i]);
	}
	return (y - x) * 2;
}

int
main(void)
{
	unsigned a1[] = {24, 13, 89, 37};
	unsigned a2[] = {7, 30, 41, 14, 39, 42};

	assert(parking(a1, nelem(a1)) == 152);
	assert(parking(a2, nelem(a2)) == 70);

	return 0;
}
