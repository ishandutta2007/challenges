/*

Your challenge, should you choose to accept it, is to take as input:

A program in DirectionLang (as an ASCII string consisting of DirectionLang instructions)
A list of pairs of integers, henceforth known as the pretty places. This list may be taken in any reasonable format.
You should then output a truthy value if the program halted at a pretty place, and a falsey value otherwise.

DirectionLang
A DirectionLang instruction is hereby defined to be either

<: Decrement the x coordinate by 1.
>: Increment the x coordinate by 1.
^: Increment the y coordinate by 1.
V: Decrement the y coordinate by 1.
S: Skip the next instruction if the program is currently at a pretty place.

A DirectionLang program is executed by performing each instruction, in order. A DirectionLang program starts at the origin (coordinates (0, 0)). A DirectionLang program halts when every instruction has been executed.

If a DirectionLang program ends with an S, then its behavior is undefined.

DirectionLang is quite obviously not Turing complete, as there is not a way of looping.

Test cases
"<>^^" [(0, 2), (0, 0)] -> True
"<>^^" [(0, 1)] -> False
"S^>>" [(0, 0), (2, 0)] -> True
"<SS^" [(-1, 0), (-1, 1)] -> True
"<SS^" [(-1, 0), (-1, -1)] -> False
"S^>>" [(2, 0)] -> False

*/

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int x, y;
} Point;

bool
here(Point *p, size_t n, Point q)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if (q.x == p[i].x && q.y == p[i].y)
			return true;
	}
	return false;
}

bool
pretty(const char *s, Point *p, size_t n)
{
	Point q;
	size_t i;

	q.x = q.y = 0;
	for (i = 0; s[i]; i++) {
		switch (s[i]) {
		case '<':
			q.x--;
			break;
		case '>':
			q.x++;
			break;
		case '^':
			q.y++;
			break;
		case 'V':
			q.y--;
			break;
		case 'S':
			if (s[i + 1] && here(p, n, q))
				i++;
			break;
		}
	}
	return here(p, n, q);
}

int
main(void)
{
	Point p1[] = {{0, 2}, {0, 0}};
	Point p2[] = {{0, 1}};
	Point p3[] = {{0, 0}, {2, 0}};
	Point p4[] = {{-1, 0}, {-1, 1}};
	Point p5[] = {{-1, 0}, {-1, -1}};
	Point p6[] = {{2, 0}};

	assert(pretty("<>^^", p1, nelem(p1)) == true);
	assert(pretty("<>^^", p2, nelem(p2)) == false);
	assert(pretty("S^>>", p3, nelem(p3)) == true);
	assert(pretty("<SS^", p4, nelem(p4)) == true);
	assert(pretty("<SS^", p5, nelem(p5)) == false);
	assert(pretty("S^>>", p6, nelem(p6)) == false);

	return 0;
}
