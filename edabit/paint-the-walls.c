/*

Given a predetermined rate from an object, write the function that will return the time it takes for a certain amount of people to paint a certain amount of walls.
Return the minutes as an integer.
No rounding is necessary.

Example

// It takes 22 minutes for 10 people to paint 10 walls.
// How many minutes does it take 14 people to paint 14 walls?

let rate = {
  people: 10,
  walls: 10,
  minutes: 22
}

time(rate, people, walls) ➞ 22

Notes

Check the Resources tab if you get stuck.

*/

#include <assert.h>
#include <stdio.h>

typedef struct {
	int people;
	int wall;
	int minutes;
} Rate;

int
paint(Rate *r, int p, int w)
{
	return (r->people * r->minutes * w) / (r->wall * p);
}

int
main(void)
{
	Rate r1 = {4, 9, 63};
	Rate r2 = {10, 10, 22};

	assert(paint(&r1, 7, 4) == 16);
	assert(paint(&r2, 10, 10) == 22);

	return 0;
}
