/*

I'd like to calculate how long on average I've lived in a single house.

Given a person's age and the number of times they've moved house as moves, return the average number of years that they've spent living in the same house.

Examples

yearsInOneHouse(30, 1) ➞ 15

yearsInOneHouse(15, 2) ➞ 5

yearsInOneHouse(80, 0) ➞ 80

Notes

    You can assume that the tests include people who've always lived in a house.
    Round to the nearest year.

*/

#include <assert.h>
#include <math.h>

unsigned
years(unsigned a, unsigned m)
{
	return round(a * 1.0 / (m + 1));
}

int
main(void)
{
	assert(years(30, 1) == 15);
	assert(years(15, 2) == 5);
	assert(years(80, 0) == 80);
	assert(years(23, 2) == 8);
	assert(years(31, 2) == 10);
	assert(years(1, 0) == 1);

	return 0;
}
