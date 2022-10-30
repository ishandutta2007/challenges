/*

Some sleep commands implement a delay of an integer number of seconds. However, 232 seconds is only about 100 years. Bug! What if you need a larger delay?

Make a program or a function which waits for 1000 years, with an error of less than ±10%. Because it's too time-consuming to test, please explain how/why your solution works! (unless it's somehow obvious)

You don't need to worry about wasting CPU power - it can be a busy-loop. Assume that nothing special happens while your program waits - no hardware errors or power failures, and the computer's clock magically continues running (even when it's on battery power).

What the solution should do after the sleep is finished:

    If it's a function: return to caller
    If it's a program: terminate (with or without error) or do something observable by user (e.g. display a message or play a sound)

*/

#include <unistd.h>

typedef unsigned long long uvlong;

void
sleepy(uvlong n)
{
	for (; n; n--)
		sleep(1);
}

int
main(void)
{
	sleepy(60ull * 60ull * 24ull * 365ull);
	return 0;
}
