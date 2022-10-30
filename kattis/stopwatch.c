/*

Robin just received a stopwatch from her grandfather. Robin’s stopwatch has a single button. Pressing the button alternates between stopping and starting the stopwatch’s timer.
When the timer is on, the displayed time increases by 1 every second.

Initially the stopwatch is stopped and the timer reads 0 seconds. Given a sequence of times that the stopwatch button is pressed, determine what the stopwatch’s timer displays.
Input

The first line of input contains a single integer N (1≤N≤1000), which is the number of times the stopwatch was pressed.

The next N lines describe the times the stopwatch’s button was pressed in increasing order. Each line contains a single integer t (0≤t≤106),
which is the time the button was pressed. No two button presses happen on the same second.

Output

Display still running if the stopwatch’s timer is still running after all button presses were made. Otherwise display the number of seconds displayed on the stopwatch’s timer.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
stopwatch(int *a, size_t n)
{
	size_t i;
	int r, t;

	r = 0;
	t = 0;
	for (i = 0; i < n; i++) {
		if (t)
			r += a[i] - a[i - 1];
		t = !t;
	}
	return (t) ? -1 : r;
}

int
main(void)
{
	int a1[] = {7, 11};
	int a2[] = {2, 5, 9, 10, 17};
	int a3[] = {0, 2, 104, 117};

	assert(stopwatch(a1, nelem(a1)) == 4);
	assert(stopwatch(a2, nelem(a2)) == -1);
	assert(stopwatch(a3, nelem(a3)) == 15);

	return 0;
}
