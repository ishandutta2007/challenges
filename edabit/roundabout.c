/*

You are driving in a roundabout. At the moment you enter, you don't know which one of the exits you have to take.
At the moment your GPS (or the person next to you) shouts that you should leave the roundabout, there's a moment of time where you need to react, turn on your indicator light, and exit the roundabout.

Assuming the roundabouts are of equal size, the exits are equally spaced and you're driving at the same speed, you need to figure out the exit you're taking.
Your function will get the amount of exits of the roundabout. You're entering the roundabout on "Exit 0".

The next input will be the amount of degrees where you get the command to leave the roundabout.
The time you have to react will be 30 degrees on the roundabout, so you cannot exit immediately.

Examples

roundabout(4, 50) ➞ "Exit 1"

roundabout(4, 320) ➞ "Exit 0"

roundabout(6, 60) ➞ "Exit 2"

Notes

    You'll be driving clockwise within the roundabout.
    Sometimes you have to take the roundabout more than once.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char *
roundabout(int r, int d, char *b)
{
	double n, p;

	n = 360.0 / r;
	p = fmod(ceil((d + 30) / n), r);
	sprintf(b, "Exit %.0f", p);
	return b;
}

void
test(int r, int d, const char *s)
{
	char b[80];

	roundabout(r, d, b);
	assert(!strcmp(b, s));
}

int
main(void)
{
	test(4, 320, "Exit 0");
	test(4, 50, "Exit 1");
	test(3, 180, "Exit 2");
	test(6, 360, "Exit 1");
	test(3, 100, "Exit 2");
	test(5, 100, "Exit 2");
	test(4, 320, "Exit 0");
	test(2, 180, "Exit 0");
	test(6, 250, "Exit 5");
	test(4, 61, "Exit 2");
	test(3, 0, "Exit 1");
	test(4, 500, "Exit 2");
	test(3, 68, "Exit 1");
	test(5, 40, "Exit 1");
	test(6, 60, "Exit 2");

	return 0;
}
