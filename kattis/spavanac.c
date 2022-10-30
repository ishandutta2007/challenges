/*

Every school morning Mirko is woken up by the sound of his alarm clock. Since he is a bit forgetful, quite often he leaves the alarm on on Saturday morning too.
That’s not too bad though, since he feels good when he realizes he doesn’t have to get up from his warm and cozy bed.

He likes that so much that he would like to experience that on other days of the week too! His friend Slavko offered this simple solution: set his alarm clock 45
minutes early, and he can enjoy the comfort of his bed, fully awake, for 45 minutes each day.

Mirko decided to heed his advice, however his alarm clock uses 24-hour notation and he has issues with adjusting the time.
Help Mirko and write a program that will take one time stamp, in 24-hour notation, and print out a new time stamp, 45 minutes earlier, also in 24-hour notation.

If you are unfamiliar with 24-hour time notation yourself, you might be interested to know it starts with 0:00 (midnight) and ends with 23:59 (one minute before midnight).

Input

The first and only line of input will contain exactly two integers H and M (0≤H≤23,0≤M≤59) separated by a single space, the input time in 24-hour notation. H denotes hours and M minutes.

Output

The first and only line of output should contain exactly two integers, the time 45 minutes before input time.

*/

#include <assert.h>
#include <stdio.h>

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

void
waketime(int h, int m, int *xh, int *xm)
{
	int t;

	t = mod(h * 60 + m - 45, 1440);
	*xh = t / 60;
	*xm = t % 60;
}

void
test(int h, int m, int rh, int rm)
{
	int xh, xm;

	waketime(h, m, &xh, &xm);
	printf("%d %d\n", xh, xm);
	assert(xh == rh && xm == rm);
}

int
main(void)
{
	test(10, 10, 9, 25);
	test(0, 30, 23, 45);
	test(23, 40, 22, 55);
	return 0;
}
