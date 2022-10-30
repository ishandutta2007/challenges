/*

This is a fairly simple question. According to this random website I found — Web Archive, a reference angle is the acute angle formed by the terminal side of the given angle and the x-axis.
You have to write a program to find these.

I don't remember anything from algebra 2, what does this mean?

Angles are usually given in standard form, which is measured by placing one side of the angle and measuring to the other side, counterclockwise, like so:

Standard form

This will be your input. Your output will be the reference angle of this. You can think of this as basically the smallest distance from the terminal side to the x-axis. Except it's an angle, not a distance. Here are some examples:

Quad 2 ref Quad 1 ref

Quad 3 ref Quad 4 ref
Clarifications

    All the defaults on inputs and submissions.
    Angles is in degrees.
    Negative angles, non-integer angles, and angles > 360 deg are allowed.
    Output in form 60 deg.
    This is code-golf, so shortest code in bytes wins!

Another helpful link.
Test Cases

70      ->  70 deg
135     ->  45 deg
210     ->  30 deg
-60     ->  60 deg
91      ->  89 deg
610     ->  70 deg
-1000   ->  80 deg

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

int
angle(int x)
{
	return 90 - abs(mod(x, 180) - 90);
}

int
main(void)
{
	assert(angle(70) == 70);
	assert(angle(135) == 45);
	assert(angle(210) == 30);
	assert(angle(-60) == 60);
	assert(angle(91) == 89);
	assert(angle(610) == 70);
	assert(angle(-1000) == 80);

	return 0;
}
