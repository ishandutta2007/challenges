/*

In (American) Football, a team can score if they manage to kick a ball through the goal (i.e. above the crossbar and between the uprights).

Create a function that returns true if the ball 0 goes through the goal. You will be given an array of arrays.
Examples

isGoalScored([
  ["  #     #  "],
  ["  #  0  #  "],
  ["  #     #  "],
  ["  #######  "],
  ["     #     "],
  ["     #     "],
  ["     #     "]
]) ➞ true

isGoalScored([
  ["  #0    #  "],
  ["  #     #  "],
  ["  #     #  "],
  ["  #######  "],
  ["     #     "],
  ["     #     "],
  ["     #     "]
]) ➞ true

isGoalScored([
  ["  #     #  "],
  ["  #     #  "],
  ["  #     # 0"],
  ["  #######  "],
  ["     #     "],
  ["     #     "],
  ["     #     "]
]) ➞ false

Notes

    All goals will be of the same size.
    All arrays will be of equal length (11).
    A team can never score if it hits the crossbar or goes underneath it.

*/

#include <assert.h>
#include <stdio.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
findball(const char **s, size_t n, size_t *x, size_t *y)
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; s[i][j]; j++) {
			if (s[i][j] == '0') {
				*x = j;
				*y = i;
				return 1;
			}
		}
	}
	return 0;
}

int
findgrid(const char **s, size_t n, size_t *gx1, size_t *gx2, size_t *gy)
{
	size_t x1, x2, y;
	size_t i, j;

	for (i = 0; i < n; i++) {
		y = n - i - 1;
		x1 = SIZE_MAX;
		x2 = 0;
		for (j = 0; s[y][j]; j++) {
			if (s[y][j] == '#') {
				x1 = min(x1, j);
				x2 = max(x2, j);
			}
		}
		if (x1 != x2) {
			*gx1 = x1;
			*gx2 = x2;
			*gy = y;
			return 1;
		}
	}
	return 0;
}

int
scored(const char **s, size_t n)
{
	size_t gx1, gx2, gy;
	size_t bx, by;

	if (!findball(s, n, &bx, &by))
		return 0;
	if (!findgrid(s, n, &gx1, &gx2, &gy))
		return 0;
	return gx1 < bx && bx < gx2 && by < gy;
}

int
main(void)
{
	const char *s1[] = {
		"  #     #  ",
		"  #  0  #  ",
		"  #     #  ",
		"  #######  ",
		"     #     ",
		"     #     ",
		"     #     ",
	};
	const char *s2[] = {
		"  #     #  ",
		"  #     #  ",
		"  #   0 #  ",
		"  #######  ",
		"     #     ",
		"     #     ",
		"     #     "
	};
	const char *s3[] = {
		"  #0    #  ",
		"  #     #  ",
		"  #     #  ",
		"  #######  ",
		"     #     ",
		"     #     ",
		"     #     "
	};
	const char *s4[] = {
		"  #     #  ",
		"  #     #  ",
		"  #     # 0",
		"  #######  ",
		"     #     ",
		"     #     ",
		"     #     "
	};
	const char *s5[] = {
		"  #     #  ",
		"  #     #  ",
		"  #     #  ",
		"  #######  ",
		"     #    0",
		"     #     ",
		"     #     "
	};
	const char *s6[] = {
		"  #     #  ",
		"  #     #  ",
		"  #     # ",
		"  #######  ",
		"     #     ",
		" 0   #     ",
		"     #     "
	};
	const char *s7[] = {
		"0 #     #  ",
		"  #     #  ",
		"  #     #  ",
		"  #######  ",
		"     #     ",
		"     #     ",
		"     #     "
	};
	const char *s8[] = {
		"  #     #  ",
		"  #     #  ",
		"  #     #  ",
		"  ####### 0",
		"     #     ",
		"     #     ",
		"     #     "
	};
	const char *s9[] = {
		"  #     #  ",
		"  #     #  ",
		"  #     #  ",
		"  ###0###  ",
		"     #     ",
		"     #     ",
		"     #     "
	};
	const char *s10[] = {
		"  #     #  ",
		"  #     #  ",
		"  #     #  ",
		"  #######  ",
		"     0     ",
		"     #     ",
		"     #     "
	};

	assert(scored(s1, nelem(s1)) == 1);
	assert(scored(s2, nelem(s2)) == 1);
	assert(scored(s3, nelem(s3)) == 1);
	assert(scored(s4, nelem(s4)) == 0);
	assert(scored(s5, nelem(s5)) == 0);
	assert(scored(s6, nelem(s6)) == 0);
	assert(scored(s7, nelem(s7)) == 0);
	assert(scored(s8, nelem(s8)) == 0);
	assert(scored(s9, nelem(s9)) == 0);
	assert(scored(s10, nelem(s10)) == 0);

	return 0;
}
