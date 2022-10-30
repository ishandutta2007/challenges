/*

In microwave ovens, when buttons are pressed from 0-9, it will add that number to the microwave oven timer (starting from the left).
All microwave ovens have the functionality where you can hit a "+30" button and it will add 30 seconds to the timer to cook your food.
If you want to heat something for 5 mins, you can hit the "+30" button 10 times instead of thinking if there are fewer button presses that can give you the same result.

Create a function that takes an argument time and returns the shortest amount of button presses to set the given time on the microwave oven. The microwave oven timer always starts at 00:00.

Buttons

Buttons from "0-9"

// It will add that number to the microwave oven timer (starting from the left).
// If the number "5" is pressed followed by "0" twice, it will put 05:00 on the timer.
// If the number "3" is pressed followed by "0", it will put 00:30 on the timer.

Button "+30", which adds 30 seconds to the current timer.

// If the number "+30" is pressed twice, it will put 00:60 on the timer.

A "Start" button which you have to finally press to start the microwave oven.

// Remember to press this!

Examples

microwaveButtons("00:30") ➞ 2
// "+30" to put 30 seconds on the timer.
// "Start" button to start the oven.

microwaveButtons("00:70") ➞ 3
// "7" followed by "0" to put 70 seconds on the timer.
// "Start" button to start the oven.

microwaveButtons("00:00") ➞ 1
// "Start" button to start the oven.

Notes

    Input may not always be what you expect (e.g. you can put in 00:70, which is valid).
    No exception handling is required for this challenge.

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

int
min(int a, int b)
{
	return (a < b) ? a : b;
}

int
max(int a, int b)
{
	return (a > b) ? a : b;
}

int
digits(int n)
{
	int v;

	v = 0;
	while (n) {
		v++;
		n /= 10;
	}
	return v;
}

int
microwave(const char *s)
{
	int a, b, u, v;

	if (sscanf(s, "%d:%d", &a, &b) != 2 || a < 0 || b < 0)
		return -1;

	v = digits(a);
	if (v)
		v += max(2, digits(b));
	else
		v += digits(b);

	u = 60 * a + b;
	if ((u % 30) == 0)
		v = min(v, u / 30);

	return v + 1;
}

int
main(void)
{
	assert(microwave("00:30") == 2);
	assert(microwave("01:00") == 3);
	assert(microwave("00:60") == 3);
	assert(microwave("00:20") == 3);
	assert(microwave("00:10") == 3);
	assert(microwave("00:70") == 3);
	assert(microwave("10:00") == 5);
	assert(microwave("00:00") == 1);
	assert(microwave("00:10") == 3);
	assert(microwave("00:01") == 2);
	assert(microwave("00:34") == 3);
	assert(microwave("13:37") == 5);

	return 0;
}
