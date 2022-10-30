/*

A robot moves around a 2D grid. At the start, it is at [0, 0], facing east. It is controlled by a sequence of instructions:

    . means take one step forwards in the current direction.
    < means turn 90 degrees anticlockwise.
    > means turn 90 degrees clockwise.

Your job is to process the instructions and return the final position of the robot.
Example

For example, if the robot is given the sequence of instructions ..<.<., then:

    Step 1: . It still faces east, and is at [1, 0].
    Step 2: . It still faces east, and is at [2, 0].
    Step 3: < It now faces north, and is still at [2, 0].
    Step 4: . It still faces north, and is at [2, 1].
    Step 5: < It now faces west, and is still at [2, 1].
    Step 6: . It still faces west, and is now at [1, 1].

So, trackRobot("..<.<.") returns [1, 1].

Notes

    The instruction strings will only contain the three valid characters ., < or >.
    You will always be passed a string (but the string might be empty).

*/

#include <stdio.h>

typedef struct {
	int x, y;
} Point;

Point
track(const char *s)
{
	static const Point tab[] = {
		{ 1, 0 },
		{ 0, -1 },
		{ -1, 0 },
		{ 0, 1 },
	};

	Point p;
	size_t i, d;

	p.x = p.y = 0;
	for (i = d = 0; s[i]; i++) {
		switch (s[i]) {
		case '.':
			p.x += tab[d].x;
			p.y += tab[d].y;
			break;
		case '<':
			d = (d == 0) ? 3 : d - 1;
			break;
		case '>':
			d = (d == 3) ? 0 : d + 1;
			break;
		}
	}
	return p;
}

void
test(const char *s)
{
	Point p;

	p = track(s);
	printf("[%d, %d]\n", p.x, p.y);
}

char *
repeat(char *b, size_t n, const char *c)
{
	size_t i, j;
	for (i = j = 0; i < n; i++) {
		b[i] = c[j++];
		if (c[j] == '\0')
			j = 0;
	}
	b[n] = '\0';
	return b;
}

int
main(void)
{
	static char b[16384];

	test("..<.<.");
	test(repeat(b, 100, "."));
	test("<>>>><><<<><>>>><><<<><>>><>");
	test(".<..<...<....<.....<......");
	test(">>..");
	test("..<<..>>..<<..>>..");
	test(repeat(b, 5000, ".>"));
	return 0;
}
