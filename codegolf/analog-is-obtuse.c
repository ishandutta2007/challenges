/*

An analog clock has 2 hands*: Hour and minute.
These hands circle the clock's face as time goes by. Each full rotation of the minute hand results in 1/12th of a rotation of the hour hand. 2 full rotations of the hour hand signifies a full day.

As these hands are fixed to the same central point, and rotate around that point, you can always calculate the angle between the hands.
In fact there are 2 angles at any given time; A larger one, and a smaller one (sometimes they will both equal 180, but that's not important)

*Our hypothetical clocks don't have second hands
Task

Given a time in 24 hour format, output the smaller angle between the hands, in degrees. If the hands are directly opposite eachother (such as at 6:00, 18:00 etc) output 180
Rules

Input may be taken as: - A delimiter separated string: 6:32, 14.26 - 2 separate values, strings or ints: 6, 32, 14, 26 - An array of 2 values, strings or ints: [6, 32], [14, 26]

You may also optionally specify that your answer requires inputs be padded to 2 digits (assuming you take strings), ie: 06:32, 06, 32, [06, 32]

You may also optionally reverse the order of the inputs, taking minute then hour, ie: 32:6, 32, 6, [26, 14]

Hour will be an integer value between 0 and 23 (inclusive) Minute will be an integer value between 0 and 59 (inclusive)

You can assume that the minute hand snaps to increments of 6 degrees along the face (one evenly-spaced position for each minute value)
You can assume that the hour hand snaps to increments of 0.5 degrees along the face (one evenly-spaced position for each minute value per hour value)

Output must be given in degrees, not radians. You may include a trailing .0 for whole numbers
Scoring

This is code-golf so fewest bytes in each language wins!
Testcases

Input: 06:32
Output: 4

Input: 06:30
Output: 15

Input: 18:32
Output: 4

Input: 06:01
Output: 174.5

Input: 00:00
Output: 0

Input: 00:01
Output: 5.5

Input: 12:30
Output: 165

Input: 6:00
Output: 180

Input: 23:59
Output: 5.5

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

/*

@Arnauld:

Instead of working directly in the range [0..360], we define a temporary variable x in the range [0..4]:

x = |4h/12 + 4m/(60*12) - 4m/60| mod 4
x = |4h/12 - 44m/(60*12)| mod 4
x = |h/3 - 11m/180| mod 4

The angle in degrees is given by:

min(4−x,x)×90

However, the formula is implemented a bit differently in the JS code, as we definitely want to avoid using the lengthy Math.abs() and Math.min().

Instead of computing the absolute value, we force a positive value in [0..12] by computing:

x′ = 4 + h/3 - 11m/180

And instead of computing the minimum, we determine in which case we are by simply doing a bitwise AND with 2
-- and this is why we chose an interval bounded by a power of 2 in the first place.

*/

double
angle(double h, double m)
{
	double x;

	x = fabs(h / 3 - 11 * m / 180);
	x = fmod(x, 4);
	x = fmin(4 - x, x) * 90;
	return x;
}

void
test(double h, double m, double r)
{
	double p;

	p = angle(h, m);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-2);
}

int
main(void)
{
	test(6, 30, 15);
	test(18, 32, 4);
	test(6, 1, 174.5);
	test(0, 0, 0);
	test(0, 1, 5.5);
	test(12, 30, 165);
	test(6, 0, 180);
	test(23, 59, 5.5);

	return 0;
}
