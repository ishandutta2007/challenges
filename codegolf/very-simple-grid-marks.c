/*

Write a program or function that takes in three positive integers, W, H, and N. Print or return a W×H grid of .'s where every Nth . in normal English reading order is replaced with an X.

For example, given W = 7, H = 3, N = 3, the grid is 7 characters wide and 3 high, and every third character reading from the top left is an X:

..X..X.
.X..X..
X..X..X
Similarly, if the input is W = 10, H = 4, N = 5, the output would be:

....X....X
....X....X
....X....X
....X....X

Notes
"Normal English reading order" means going left to right on each line, from the top line to the bottom.
When N is 1 then all the .'s will become X's.
You may use any two distinct printable ASCII characters in place of . and X.
If you use space ( ) then trailing spaces are not required when the result would be visually the same. (Empty lines are still required.)
You may not using something else in place of the newlines that shape the grid.
The exact input format and order of W, H, and N is not super important. Things like [H,W,N] or N\nW,H are alright.
A trailing newline in the output is fine.
The shortest code in bytes wins!

Examples
W = 5, H = 3, N = 1
XXXXX
XXXXX
XXXXX

W = 5, H = 3, N = 2
.X.X.
X.X.X
.X.X.

W = 5, H = 3, N = 3
..X..
X..X.
.X..X

W = 5, H = 3, N = 4
...X.
..X..
.X...

W = 5, H = 3, N = 5
....X
....X
....X

W = 5, H = 3, N = 6
.....
X....
.X...

W = 5, H = 3, N = 7
.....
.X...
...X.

W = 5, H = 3, N = 15
.....
.....
....X

W = 5, H = 3, N = 16 (or more)
.....
.....
.....

W = 1, H = 1, N = 1
X

W = 1, H = 1, N = 2 (or more)
.

W = 8, H = 6, N = 2
.X.X.X.X
.X.X.X.X
.X.X.X.X
.X.X.X.X
.X.X.X.X
.X.X.X.X

W = 8, H = 6, N = 3
..X..X..
X..X..X.
.X..X..X
..X..X..
X..X..X.
.X..X..X

W = 8, H = 6, N = 4
...X...X
...X...X
...X...X
...X...X
...X...X
...X...X

W = 8, H = 6, N = 7
......X.
.....X..
....X...
...X....
..X.....
.X......

W = 8, H = 6, N = 16
........
.......X
........
.......X
........
.......X

W = 37, H = 1, N = 4
...X...X...X...X...X...X...X...X...X.

W = 1, H = 10, N = 8
.
.
.
.
.
.
.
X
.
.

*/

#include <stdio.h>

void
grid(unsigned w, unsigned h, unsigned n)
{
	unsigned x, y, c;

	printf("W = %u, H = %u, N = %u\n", w, h, n);
	c = 0;
	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++) {
			if (++c == n) {
				printf("X");
				c = 0;
			} else
				printf(".");
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	grid(5, 3, 1);
	grid(5, 3, 2);
	grid(5, 3, 3);
	grid(5, 3, 4);
	grid(5, 3, 5);
	grid(5, 3, 6);
	grid(5, 3, 7);
	grid(5, 3, 15);
	grid(5, 3, 16);
	grid(1, 1, 1);
	grid(1, 1, 2);
	grid(8, 6, 2);
	grid(8, 6, 3);
	grid(8, 6, 4);
	grid(8, 6, 7);
	grid(8, 6, 16);
	grid(37, 1, 4);
	grid(1, 10, 8);
	grid(7, 3, 3);
	grid(10, 4, 5);

	return 0;
}
