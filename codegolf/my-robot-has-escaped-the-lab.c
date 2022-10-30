/*

My robot has short circuited somehow and randomly run off somewhere from my lab!

Luckily, whenever he does this, his shut-down sequence initiates, giving him enough time to randomly turn and run in the direction its facing for five rounds before he switches off.
His gyro and accelerometer functions are still relaying the data back to the lab while he is still on.

The data will always come in the form of five sets of two numbers, for example.

12:234,-135:47,-68:230,140:324,127,87

Your mission, golfers is to a) simulate the robot's frantic run and turn sequence by displaying five sets of numbers in the form of a1:d1,a2:d2,a3:d3,a4:d4,a5:d5
where a(n) is the clockwise angle (in degrees) such that -179<=a<=+180 that the robot will turn from its current heading (initially it is at zero heading before it runs amok and turns for the first time),
and d(n) is the distance in feet it has run before the next heading change which is such that 0<=d<=500 feet; and b)
A calculated heading from the lab (which is also facing a heading of zero), distance in feet (accuracy up to 3 decimal places is strongly encouraged, -5 bytes if you do),
and the orientation heading (in degrees) of where my robot it is facing when it has switched off.

Easy example:

Data: 0:1,45:1,90:1,90:1,90:1
Heading: 0
Distance: 1
Orientation: -45
The random turns and distances are just that, random. No set values are to be hard coded, we must see the randomness in action within the code.

Restrictions to randomness: No clock or date based references, we need to see a native random reference within the code.
Whenever you run this code, the randomness must present itself with a possibility of showing 1 of 360 possible angles of turning with each turn-run round.
So the robot may turn -36 degrees at one turn and may turn +157 degrees the next, followed by another turn of +2 degrees by another turn of -116 degrees and a final turn of +42 degrees on the final turn.
At least 360 distinct values must be possible (between -179 to +180 degrees inclusive) with each random angle generation.

Restrictions to distance run: Similarly set, there are 501 possible distances the robot can run, (between 0 and 500 feet inclusive), so I expect the randomness to also be available when determining the robot's running distance.
The robot could theoretically run 45, 117, 364, 27 and 6 feet with each of its respective rounds...

The data fed to you will always be in integer values... the robot will turn in integer ranges of degrees, and will run in integer ranges of distance. The output values however, will be floats...

This is code-golf. Shortest code wins... Now go find my robot!

PS: In reference to my "Accuracy up to 3 decimal places", if you can provide the heading (in degrees, to a MINIMUM of 3 decimal places) and a distance in feet (also accurate also to a MINIMUM 3 decimal places) you will get a -5 byte bonus).

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define rad2deg(x) ((x)*180 / M_PI)
#define deg2rad(x) ((x)*M_PI / 180)

void
motion(int a[][2], size_t n)
{
	double x, y, r;
	size_t i;

	x = y = r = 0;
	for (i = 0; i < n; i++) {
		r += deg2rad(a[i][0]);
		x += a[i][1] * cos(r);
		y += a[i][1] * sin(r);
	}
	r = fmod(r, 2 * M_PI);

	printf("Heading: %f\n", rad2deg(atan2(y, x)));
	printf("Distance: %f\n", hypot(x, y));
	printf("Orientation: %f\n", rad2deg(r));
	printf("\n");
}

int
main(void)
{
	int a1[][2] = {
	    {0, 1},
	    {45, 1},
	    {90, 1},
	    {90, 1},
	    {90, 1},
	};

	int a2[][2] = {
	    {12, 234},
	    {-135, 47},
	    {-68, 230},
	    {140, 324},
	    {127, 87},
	};

	motion(a1, nelem(a1));
	motion(a2, nelem(a2));

	return 0;
}
