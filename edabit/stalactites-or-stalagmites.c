/*

Stalactites hang from the ceiling of a cave while stalagmites grow from the floor.

Create a function that determines whether the input represents "stalactites" or "stalagmites".
If it represents both, return "both". Input will be a 2D list, with 1 representing a piece of rock, and 0 representing air space.

Examples

mineral_formation([
  [0, 1, 0, 1],
  [0, 1, 0, 1],
  [0, 0, 0, 1],
  [0, 0, 0, 0]
]) ➞ "stalactites"

mineral_formation([
  [0, 0, 0, 0],
  [0, 1, 0, 1],
  [0, 1, 1, 1],
  [0, 1, 1, 1]
]) ➞ "stalagmites"

mineral_formation([
  [1, 0, 1, 0],
  [1, 1, 0, 1],
  [0, 1, 1, 1],
  [0, 1, 1, 1]
]) ➞ "both"

Notes

    There won't be any examples where both stalactites and stalagmites meet (because those are called pillars).
    There won't be any example of neither stalactites or stalagmites.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
mineralformation(size_t r, size_t c, int m[r][c])
{
	size_t i;
	int f;

	if (r == 0 || c == 0)
		return "neither";

	f = 0;
	for (i = 0; i < c && f != 3; i++)
		f |= (!!m[0][i]) | (!!m[r - 1][i] << 1);

	if (f == 1)
		return "stalactites";
	if (f == 2)
		return "stalagmites";
	if (f == 3)
		return "both";
	return "neither";
}

void
test(size_t r, size_t c, int m[r][c], const char *p)
{
	assert(!strcmp(mineralformation(r, c, m), p));
}

int
main(void)
{
	int m1[4][4] = {
	    {0, 1, 0, 1},
	    {0, 1, 0, 1},
	    {0, 0, 0, 1},
	    {0, 0, 0, 0},
	};
	int m2[4][4] = {
	    {0, 0, 0, 0},
	    {0, 1, 0, 1},
	    {0, 1, 1, 1},
	    {0, 1, 1, 1},
	};
	int m3[4][4] = {
	    {1, 0, 1, 0},
	    {1, 1, 0, 1},
	    {0, 1, 1, 1},
	    {0, 1, 1, 1},
	};
	int m4[4][1] = {
	    {1},
	    {1},
	    {0},
	    {0},
	};
	int m5[4][1] = {
	    {1},
	    {1},
	    {0},
	    {1},
	};
	int m6[4][1] = {
	    {0},
	    {1},
	    {1},
	    {1},
	};
	int m7[4][2] = {
	    {0, 1},
	    {1, 1},
	    {1, 1},
	    {1, 0},
	};
	int m8[2][2] = {
	    {0, 0},
	    {1, 1},
	};
	int m9[2][2] = {
	    {1, 1},
	    {0, 0},
	};

	test(4, 4, m1, "stalactites");
	test(4, 4, m2, "stalagmites");
	test(4, 4, m3, "both");
	test(4, 1, m4, "stalactites");
	test(4, 1, m5, "both");
	test(4, 1, m6, "stalagmites");
	test(4, 2, m7, "both");
	test(2, 2, m8, "stalagmites");
	test(2, 2, m9, "stalactites");

	return 0;
}
