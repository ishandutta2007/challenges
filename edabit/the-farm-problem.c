/*

You've got chickens (2 legs), cows (4 legs) and pigs (4 legs) on your farm. Return the total number of legs on your farm.

*/

#include <stdio.h>

int
animals(int chickens, int cows, int pigs)
{
	return 2 * chickens + 4 * (cows + pigs);
}

int
main(void)
{
	printf("%d\n", animals(2, 3, 5));
	printf("%d\n", animals(5, 2, 8));
	printf("%d\n", animals(3, 4, 7));
	printf("%d\n", animals(1, 2, 3));
	printf("%d\n", animals(3, 5, 2));
	return 0;
}
