/*

Problem
Assume you have a single 7-segment display without a decimal point, so 7 "lines" that can be labelled A through G as seen here.

a labeled 7-segment display

This display will only show the numbers from 0 to 9 as usual, like so:

7-segment numbers visual representation

Any time this display changes from one number to another, some of its lights will have to change their state from on to off or vice versa, or they can simply stay on, e.g. in the case of 1 -> 2, segment B can stay on,
while segments A, G, E, D need to turn on, and C needs to turn off; for the change 6 -> 8, only segment B needs to be changed from off to on.

Task
Your task is to take a sequence of numbers as reasonably formatted input and output the amount of on and off changes as the display shows each number in the sequence in input order.
You should output a separate score for "on" and "off" in a reasonable format. A light that stays on between numbers shall not be counted towards either on or off.
The initial state of the display is all lights off, so the first number will always count as only "on" changes. The final state will be the last number displayed.

Test cases
123 -> 7, 2 (7 on, 2 off)
111 -> 2, 0 (2 segments on, then no changes)
987 -> 7, 4
2468 -> 11, 4 (thanks to @ovs for catching a mistake here!)

This is code-golf, so the shortest code wins. Also, this is my first post here, so I hope I made no mistakes for my submission :)

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
popcnt(int x)
{
	int c;

	for (c = 0; x; c++)
		x &= (x - 1);
	return c;
}

void
switches(int *a, size_t n, int r[2])
{
	static const int led[] = {0x7e, 0x30, 0x6d, 0x79, 0x33, 0x5b, 0x5f, 0x70, 0x7f, 0x7b};

	int x, y;
	size_t i;

	r[0] = r[1] = 0;
	for (i = x = 0; i < n; i++) {
		y = led[a[i]];
		r[0] += popcnt(y) - popcnt(x & y);
		r[1] += popcnt(x | y) - popcnt(y);
		x = y;
	}
}

void
test(int *a, size_t n, int r[2])
{
	int p[2];

	switches(a, n, p);
	printf("%d %d\n", p[0], p[1]);
	assert(r[0] == p[0]);
	assert(r[1] == p[1]);
}

int
main(void)
{
	int a1[] = {1, 2, 3};
	int r1[] = {7, 2};

	int a2[] = {1, 1, 1};
	int r2[] = {2, 0};

	int a3[] = {9, 8, 7};
	int r3[] = {7, 4};

	int a4[] = {2, 4, 6, 8};
	int r4[] = {11, 4};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);
	test(a4, nelem(a4), r4);

	return 0;
}
