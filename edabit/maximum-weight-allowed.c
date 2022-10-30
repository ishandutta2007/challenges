/*

Create a function that returns true if the combined weight of a car car and the weight of the passengers p in the car is less than the maximum weight maxWeight the car is allowed to carry.
Otherwise, return false. The weight of the car and the weight of the passengers are given in pounds. The maximum weight is given in kilograms.

Examples

weightAllowed(3000, [150, 201, 75, 88, 195], 1700) ➞ true

weightAllowed(3200, [220, 101, 115, 228, 15], 1700) ➞ false

weightAllowed(2900, [225, 171, 300, 274, 191], 1850) ➞ true

Notes

1 pound = 0.453592 kilogram

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
weightallowed(unsigned c, unsigned *p, size_t n, unsigned w)
{
	size_t i;
	double v;

	v = c;
	for (i = 0; i < n; i++)
		v += p[i];
	v *= 0.453592;
	return (v <= w) ? true : false;
}

int
main(void)
{
	unsigned p1[] = {150, 201, 75, 88, 195};
	unsigned p2[] = {220, 101, 115, 228, 15};
	unsigned p3[] = {225, 171, 300, 274, 191};
	unsigned p4[] = {180, 201, 140, 99, 204};
	unsigned p5[] = {157, 154, 75, 88, 190};
	unsigned p6[] = {150, 200, 79, 80, 159};

	assert(weightallowed(3000, p1, nelem(p1), 1700) == true);
	assert(weightallowed(3200, p2, nelem(p2), 1700) == false);
	assert(weightallowed(2900, p3, nelem(p3), 1850) == true);
	assert(weightallowed(3550, p4, nelem(p4), 1980) == false);
	assert(weightallowed(4500, p5, nelem(p5), 2400) == true);
	assert(weightallowed(4000, p6, nelem(p6), 2000) == false);

	return 0;
}
