/*

Marching Squares is an algorithm from computer graphics, which is used to recover 2D isocontours from a grid of samples (see also, its big brother Marching Cubes for 3D settings).
The idea is to process each cell of the grid independently, and determine the contours passing through that cell based on the values at its corners.

The first step in this process is to determine which edges are connected by contours, based on whether the corners are above or below the value of the contour.
For simplicity, we'll only consider contours along the value 0, such that we're interested in whether the corners are positive or negative. There are 24 = 16 cases to distinguish:

The identification of white and black doesn't really matter here, but for definiteness say that white is positive and black is negative. We will ignore cases where one of the corners is exactly 0.

The saddle points (cases 5 and 10) provide a little extra difficulty: it's not clear which diagonals should be used by only looking at the corners.
This can be resolved by finding the average of the four corners (i.e. an approximation of the centre value), and choosing the diagonals such that the contours separate the centre from the corners with the opposite sign.
If the average is exactly 0, either case can be chosen.

Normally, these 16 cases are simply stored in a lookup table.
This is great for efficiency, but of course, we'd prefer the code to be short around here.
So your task is to perform this lookup step and print an ASCII representation of the case in as little code as possible.

The Challenge

You're given the values of the four corners (non-zero integers) in a fixed order of your choice.
You should then generate the correct layout of the contours, correctly resolving the saddle point cases.

You may write a program or function, taking input via STDIN (or closest alternative), command-line argument or function argument and outputting the result via STDOUT (or closest alternative), function return value or function (out) parameter.

Input may be taken in any convenient string or list format.

The 16 cases will be represented in ASCII art using one of the following 5x5 blocks:

o---o  o---o  o---o
|   |  |   |  | | |
|   |  |---|  | | |
|   |  |   |  | | |
o---o  o---o  o---o

o---o  o---o  o---o  o---o
|/  |  |  \|  |   |  |   |
|   |  |   |  |   |  |   |
|   |  |   |  |\  |  |  /|
o---o  o---o  o---o  o---o

o---o  o---o
|/  |  |  \|
|   |  |   |
|  /|  |\  |
o---o  o---o
You must not print any leading or trailing whitespace, but you may print a single optional newline.

This is code golf, so the shortest answer (in bytes) wins.

Test Cases

The test cases assume that input is given in order top-left, top-right, bottom-left, bottom-right.
Test cases are presented in 9 groups, one corresponding to each of the 9 representations given above (in the same order, starting from the empty cell, ending with the two saddle points).

[1, 2, 1, 3]
[-9, -2, -2, -7]

[4, 5, -1, -2]
[-1, -2, 3, 4]

[7, -7, 7, -7]
[-5, 5, -5, 5]

[1, -6, -4, -1]
[-2, 3, 3, 4]

[-1, 6, -4, -1]
[2, -3, 3, 4]

[-1, -6, 4, -1]
[2, 3, -3, 4]

[-1, -6, -4, 1]
[2, 3, 3, -4]

[3, -8, -9, 2]
[-3, 8, 9, -2]

[8, -3, -2, 9]
[-8, 3, 2, -9]
Additionally, the following test cases may return either of the saddle points (your choice):

[1, -4, -2, 5]
[-1, 4, 2, -5]

*/

#include <stdio.h>

int
threshold(int c[4])
{
	int b;

	b = (c[0] < 0) << 0;
	b |= (c[1] < 0) << 1;
	b |= (c[3] < 0) << 2;
	b |= (c[2] < 0) << 3;
	return b;
}

double
average(int c[4])
{
	return (c[0] + c[1] + c[2] + c[3]) / 4.0;
}

void
march(int c[4])
{
	static const char *squares[] = {
	    "o---o\n"
	    "|   |\n"
	    "|   |\n"
	    "|   |\n"
	    "o---o",

	    "o---o\n"
	    "|   |\n"
	    "|---|\n"
	    "|   |\n"
	    "o---o",

	    "o---o\n"
	    "| | |\n"
	    "| | |\n"
	    "| | |\n"
	    "o---o",

	    "o---o\n"
	    "|/  |\n"
	    "|   |\n"
	    "|   |\n"
	    "o---o",

	    "o---o\n"
	    "|  \\|\n"
	    "|   |\n"
	    "|   |\n"
	    "o---o",

	    "o---o\n"
	    "|   |\n"
	    "|   |\n"
	    "|\\  |\n"
	    "o---o",

	    "o---o\n"
	    "|   |\n"
	    "|   |\n"
	    "|  /|\n"
	    "o---o",

	    "o---o\n"
	    "|/  |\n"
	    "|   |\n"
	    "|  /|\n"
	    "o---o\n",

	    "o---o\n"
	    "|  \\|\n"
	    "|   |\n"
	    "|\\  |\n"
	    "o---o",
	};

	int lut[16] = {
	    [0] = 0,
	    [1] = 3,
	    [2] = 4,
	    [3] = 1,
	    [4] = 6,
	    [5] = -1,
	    [6] = 2,
	    [7] = 5,
	    [8] = 5,
	    [9] = 2,
	    [10] = -1,
	    [11] = 6,
	    [12] = 1,
	    [13] = 4,
	    [14] = 3,
	    [15] = 0,
	};

	double m;
	int i, v;

	v = threshold(c);
	m = average(c);

	i = lut[v];
	if (i == -1) {
		if ((v == 10 && m <= 0) || (v == 5 && m >= 0))
			i = 7;
		else
			i = 8;
	}

	printf("%d %f\n", v, m);
	printf("%s\n", squares[i]);
	printf("\n");
}

int
main(void)
{
	int c0[] = {1, 2, 1, 3};
	int c1[] = {-9, -2, -2, -7};

	int c2[] = {4, 5, -1, -2};
	int c3[] = {-1, -2, 3, 4};

	int c4[] = {7, -7, 7, -7};
	int c5[] = {-5, 5, -5, 5};

	int c6[] = {1, -6, -4, -1};
	int c7[] = {-2, 3, 3, 4};

	int c8[] = {-1, 6, -4, -1};
	int c9[] = {2, -3, 3, 4};

	int c10[] = {-1, -6, 4, -1};
	int c11[] = {2, 3, -3, 4};

	int c12[] = {-1, -6, -4, 1};
	int c13[] = {2, 3, 3, -4};

	int c14[] = {3, -8, -9, 2};
	int c15[] = {-3, 8, 9, -2};

	int c16[] = {8, -3, -2, 9};
	int c17[] = {-8, 3, 2, -9};

	int c18[] = {1, -4, -2, 5};
	int c19[] = {-1, 4, 2, -5};

	march(c0);
	march(c1);

	march(c2);
	march(c3);

	march(c4);
	march(c5);

	march(c6);
	march(c7);

	march(c8);
	march(c9);

	march(c10);
	march(c11);

	march(c12);
	march(c13);

	march(c14);
	march(c15);

	march(c16);
	march(c17);

	march(c18);
	march(c19);

	return 0;
}
