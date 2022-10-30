/*

A man has n number of apples. If he eats a percentage p of the apples (if apples are available), his children will share the remainder of the apples.
Create a function to determine the number of whole apples his children got. If his children did not get any apples, return "The children didn't get any apples".

Examples

getNumberOfApples(10, "90%") ➞ 1

getNumberOfApples(25, "10%") ➞ 22

getNumberOfApples(0, "10%") ➞ "The children didn't get any apples"

Notes

p will always be given.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

unsigned
apples(unsigned a, const char *s)
{
	unsigned p;

	if (sscanf(s, "%u%%", &p) != 1)
		return 0;
	return a * (100 - p) / 100.0;
}

int
main(void)
{
	assert(apples(10, "90%") == 1);
	assert(apples(25, "10%") == 22);
	assert(apples(0, "10%") == 0);
	assert(apples(40, "30%") == 28);
	assert(apples(10, "44%") == 5);
	assert(apples(12, "100%") == 0);
	assert(apples(40, "100%") == 0);

	return 0;
}
