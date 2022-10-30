/*

This challenge will help you interpret mathematical relationships both algebraically and geometrically.

Create a function that takes a number (step) as an argument and returns the amount of matchsticks in that step. See step 1, 2 and 3 in the image above.

Notes

    Step 0 returns 0 matchsticks.
    The input (step) will always be a non-negative integer.

*/

#include <stdio.h>

unsigned
matchhouses(unsigned n)
{
	if (n == 0)
		return 0;
	return 6 + 5 * (n - 1);
}

int
main(void)
{
	unsigned i;

	for (i = 0; i <= 100; i++)
		printf("%u %u\n", i, matchhouses(i));

	return 0;
}
