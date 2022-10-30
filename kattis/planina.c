/*

Mirko and Slavko are filming a movie adaptation of the popular SF novel “Chicks in space 13”.
The script requires them to present a lot of different worlds so they decided to film the entire movie in front of a green screen and add CGI backgrounds later.
Mirko heard that the best way to generate artificial terrain is to use midpoint displacement algorithm.

To start the algorithm, Mirko selects 4 points forming a perfect square. He then performs the following steps:

    On each side of the square, he adds a new point in the exact middle of the side. The height of this new point is the average height of the two points on that side.

    In the exact center of the square he adds a new point whose height is the average height of all 4

    square vertices, plus a small random value.

After those two steps are performed, he now has 4 new squares. He performs the same steps on the newly created squares again and again until he is pleased with the results.

Mirko noticed that some of the points belong to more than one square. In order to decrease memory consumption, he calculates and stores such points only once.
He now wonders how many points in total will he need to store in memory after N iterations.

*/

#include <assert.h>
#include <stdio.h>

// https://oeis.org/A028400
unsigned
seq(unsigned n)
{
	unsigned v;

	v = (1u << n) + 1;
	return v * v;
}

int
main(void)
{
	assert(seq(1) == 9);
	assert(seq(2) == 25);
	assert(seq(5) == 1089);

	return 0;
}
