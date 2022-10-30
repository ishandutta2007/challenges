/*

Given an object of how many more pages each ink color can print, output the maximum number of pages the printer can print before any of the colors run out.

Notes

A single printed page uses each color once, so that no prints are possible if there's no more ink in any of the slots (see example #3).

*/

#include <assert.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef struct {
	unsigned cyan;
	unsigned magenta;
	unsigned yellow;
} Ink;

unsigned
inklevels(Ink *ik)
{
	return min(ik->cyan, min(ik->magenta, ik->yellow));
}

int
main(void)
{
	Ink i1 = { 23, 12, 10 };
	Ink i2 = { 432, 543, 777 };
	Ink i3 = { 700, 700, 0 };
	Ink i4 = { 70, 700, 1 };
	Ink i5 = { 6543, 74543, 2345678 };
	Ink i6 = { 1, 1, 1 };
	Ink i7 = { 700, 700, 700 };

	assert(inklevels(&i1) == 10);
	assert(inklevels(&i2) == 432);
	assert(inklevels(&i3) == 0);
	assert(inklevels(&i4) == 1);
	assert(inklevels(&i5) == 6543);
	assert(inklevels(&i6) == 1);
	assert(inklevels(&i7) == 700);

	return 0;
}
