/*

In a video game, a meteor will fall toward the main character's home planet.
Given the meteor's trajectory as a string in the form y = mx + b and the character's position as a tuple of (x, y),
return True if the meteor will hit the character and False if it will not.

Examples

will_hit("y = 2x - 5", (0, 0)) ➞ False

will_hit("y = -4x + 6", (1, 2)) ➞ True

will_hit("y = 2x + 6", (3, 2)) ➞ False

Notes

    The b value will never be zero or blank.
    The m value will always be an integer.
    If the m value is 1, the "1" will be shown.
    For example, "y = x + 5" will be shown as "y = 1x + 5".
    If the m value is -1, the "-1" will be shown.
    For example, "y = -x + 2" will be shown as "y = -1x + 2".

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
	int x, y;
} Point;

bool
willhit(const char *s, Point p)
{
	int m, b, n;

	m = b = 0;
	n = sscanf(s, "y = %dx + %d", &m, &b);
	if (n != 2) {
		n = sscanf(s, "y = %dx - %d", &m, &b);
		b = -b;
	}
	if (n != 2)
		return false;

	return p.y == p.x * m + b;
}

int
main(void)
{
	assert(willhit("y = 2x - 5", (Point){0, 0}) == false);
	assert(willhit("y = -4x + 6", (Point){1, 2}) == true);
	assert(willhit("y = -4x + 6", (Point){2, 2}) == false);
	assert(willhit("y = 3x - 8", (Point){4, 4}) == true);
	assert(willhit("y = 2x + 6", (Point){3, 2}) == false);
	assert(willhit("y = -3x + 15", (Point){5, 0}) == true);

	return 0;
}
