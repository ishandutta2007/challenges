/*

There is a robot starting at position (0, 0), the origin, on a 2D plane. Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.

The move sequence is represented by a string, and the character moves[i] represents its ith move. Valid moves are R (right), L (left), U (up), and D (down). If the robot returns to the origin after it finishes all of its moves, return true. Otherwise, return false.

Note: The way that the robot is "facing" is irrelevant. "R" will always make the robot move to the right once, "L" will always make it move left, etc. Also, assume that the magnitude of the robot's movement is the same for each move.

*/

#include <stdio.h>

typedef struct {
	int x, y;
} Point;

int
retori(const char *s)
{
	Point p = {0};
	size_t i;

	for (i = 0; s[i]; i++) {
		switch (s[i]) {
		case 'U':
			p.y++;
			break;
		case 'D':
			p.y--;
			break;
		case 'L':
			p.x--;
			break;
		case 'R':
			p.x++;
			break;
		}
	}
	return p.x == 0 && p.y == 0;
}

int
main(void)
{
	printf("%d\n", retori("UD"));
	printf("%d\n", retori("LL"));
	printf("%d\n", retori("URDL"));
	return 0;
}
