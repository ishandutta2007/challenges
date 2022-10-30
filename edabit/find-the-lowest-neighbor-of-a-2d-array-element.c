/*

Create a function that returns the lowest neighbor of a given (x, y) coordinate element in a 2D array. The function will be passed three parameters.

 arr,  x,  y

    arr will be a 2D array holding integer values and will always be symmetrical in size (e.g. 2x2, 3x3, 4x4).
    x will hold the row coordinate, while y will hold the column coordinate.

You will have to check the horizontal, vertical and diagonal neighbor elements. If there isn't any lower neighbors, return the value of the given (x, y) coordinate.
Examples

lowestElement([
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
], 1, 1) ➞ 1

[
  [1, 2, 3]
  [4, 5, 6]  // (1, 1) holds the integer 5. Check the surrounding neighbors.
  [7, 8, 9]
]

lowestElement([
  [9, 8, 7],
  [0, -1, -3],
  [-5, -9, 54]
], 0, 0) ➞ -1

[
  [9, 8, 7]   // (0, 0) holds the integer 9. Check the surrounding neighbors.
  [0, -1, -3]
  [-5, -9, 54]
]

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
lowest(ssize_t r, ssize_t c, int m[r][c], ssize_t x, ssize_t y)
{
	ssize_t i, j;
	int v;

	v = INT_MAX;
	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			if (!(0 <= x + i && x + i < r))
				continue;
			if (!(0 <= y + j && y + j < c))
				continue;
			v = min(v, m[x + i][y + j]);
		}
	}
	return v;
}

int
main(void)
{
	int m1[3][3] = {
	    {1, 2, 3},
	    {4, 5, 6},
	    {7, 8, 9},
	};
	int m2[3][3] = {
	    {0, 3, 6},
	    {1, 4, 7},
	    {2, 5, 8},
	};
	int m3[3][3] = {
	    {50, 30, 10},
	    {42, 69, 420},
	    {9000, 3, 16},
	};
	int m4[3][3] = {
	    {50, 60, 10},
	    {52, 69, 420},
	    {9000, 3, 16},
	};
	int m5[2][2] = {
	    {1, 2},
	    {5, 7},
	};
	int m6[4][4] = {
	    {-2, -5, -500, 49501},
	    {1004, 10502, -5061, 19303},
	    {40012, 487190, 39430, 13899},
	    {3, 1, 4, 1},
	};
	int m7[13][13] = {
	    {19831, 28749, 24518, 17394, 27108, 5225, 6364, 15589, 26819, 31116, 28619, 11994, 29522},
	    {8085, 3830, 30895, 14278, 25618, 24468, 4699, 11170, 14285, 7192, 2047, 103, 3869},
	    {25597, 31040, 5731, 30661, 21884, 31530, 10397, 7185, 10131, 9652, 23531, 15687, 7552},
	    {22904, 23005, 27418, 3460, 23282, 24394, 9181, 13518, 30687, 27163, 12421, 30071, 28679},
	    {26532, 16610, 17834, 15336, 5328, 1715, 27350, 2233, 22427, 11371, 21222, 4427, 1176},
	    {15341, 20427, 18294, 17264, 7162, 31376, 4957, 18252, 26738, 14736, 13519, 16289, 401},
	    {4715, 15902, 17209, 2463, 11790, 9922, 4878, 4896, 22598, 4876, 31027, 3908, 28095},
	    {19733, 7754, 15226, 29971, 19651, 16257, 24347, 6701, 1772, 30533, 32515, 11569, 10449},
	    {28263, 15747, 6673, 4970, 8378, 14935, 11686, 3462, 27395, 19280, 4862, 8650, 25926},
	    {210, 211, 16031, 17341, 26186, 2987, 12156, 2862, 2672, 17382, 19941, 2442, 25680},
	    {16450, 14102, 1493, 28835, 31657, 15958, 11709, 24089, 31635, 172, 8742, 28835, 25742},
	    {14299, 18513, 16751, 5122, 16143, 4445, 6108, 4413, 26544, 23135, 21403, 3593, 1715},
	    {32427, 3989, 13205, 7985, 27546, 28512, 12391, 31227, 21441, 22071, 23511, 3424, 18955},
	};

	assert(lowest(3, 3, m1, 1, 1) == 1);
	assert(lowest(3, 3, m2, 2, 2) == 4);
	assert(lowest(3, 3, m3, 0, 0) == 30);
	assert(lowest(3, 3, m4, 0, 0) == 50);
	assert(lowest(2, 2, m5, 0, 1) == 1);
	assert(lowest(4, 4, m6, 2, 3) == -5061);
	assert(lowest(13, 13, m7, 10, 2) == 211);

	return 0;
}
