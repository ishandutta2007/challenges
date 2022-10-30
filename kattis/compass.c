/*

Jonas is developing the JUxtaPhone and is tasked with animating the compass needle.
The API is simple: the compass needle is currently in some direction (between 0 and 359 degrees, with north being 0, east being 90),
and is being animated by giving the degrees to spin it.
If the needle is pointing north, and you give the compass an input of 90, it will spin clockwise (positive numbers mean clockwise direction) to stop at east,
whereas an input of −45 would spin it counterclockwise to stop at north west.

The compass gives the current direction the phone is pointing and Jonas’ task is to animate the needle taking the
shortest path from the current needle direction to the correct direction.
Many ifs, moduli, and even an arctan later, he is still not convinced his minimumDistance function is correct; he calls you on the phone.

Input

The first line of input contains an integer n1 (0≤n1≤359), the current direction of the needle.
The second line of input contains an integer n2 (0≤n2≤359), the correct direction of the needle.

Output

Output the change in direction that would make the needle spin the shortest distance from n1 to n2.
A positive change indicates spinning the needle clockwise, and a negative change indicates spinning the needle counter-clockwise.
If the two input numbers are diametrically opposed, the needle should travel clockwise. I.e., in this case, output 180 rather than −180.

*/

#include <assert.h>

int
angle(int n1, int n2)
{
	n2 -= n1;
	if (n2 <= -180)
		n2 += 360;
	else if (n2 > 180)
		n2 -= 360;
	return n2;
}

int
main(void)
{
	assert(angle(315, 45) == 90);
	assert(angle(180, 270) == 90);
	assert(angle(45, 270) == -135);

	return 0;
}
