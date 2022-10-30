/*

Ivica has set up a new parquet flooring in his room. The room is L decimeters long and W decimeters wide.

The blocks are of quadratic shape and each has an area of one quadratic decimeter.
Once Ivica had set up the flooring, which consists of brown-colored blocks, he decided to paint the blocks on the edge of the room red.

The picture below illustrates the scenario from the Sample Input 2 - outer blocks are red, while the remaining two inner blocks are brown:

Marica has come to visit Ivica. While Ivica was serving her cookies, she counted the number of blocks of each color.
When she returned home, she recalled of the two numbers and wished to calculate the dimensions of Ivica’s room. Help her!

Input

The first and only line of input contains two integers separated by a space, R (the number of red blocks) and B (the number of brown blocks). The following constraints will apply: 8≤R≤5000, 1≤B≤2000000.

Output

The first and only line of output must contain the dimensions of the room, L and W, respectively.
If the numbers differ, output the greater one first. The test data will be such that the solution is unique.

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

typedef unsigned long long uvlong;

int
dimension(uvlong r, uvlong b, uvlong *l, uvlong *w)
{
	uvlong i, x, y;

	*l = *w = 0;
	for (i = 2; i != ULLONG_MAX; i++) {
		x = (r + b) / i;
		y = (r + b) % i;
		if (y == 0 && r == (2 * x) + (2 * i) - 4) {
			*l = x;
			*w = i;
			return 1;
		}
	}
	return 0;
}

void
test(uvlong r, uvlong b, uvlong rl, uvlong rw)
{
	uvlong l, w;

	assert(dimension(r, b, &l, &w));
	printf("%llu %llu\n", l, w);
	assert(l == rl);
	assert(w == rw);
}

int
main(void)
{
	test(8, 1, 3, 3);
	test(10, 2, 4, 3);
	test(24, 24, 8, 6);
	return 0;
}
