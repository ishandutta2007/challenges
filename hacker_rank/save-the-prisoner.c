/*

A jail has a number of prisoners and a number of treats to pass out to them.
Their jailer decides the fairest way to divide the treats is to seat the prisoners around a circular table in sequentially numbered chairs.
A chair number will be drawn from a hat. Beginning with the prisoner in that chair, one candy will be handed to each prisoner sequentially around the table until all have been distributed.

The jailer is playing a little joke, though. The last piece of candy looks like all the others, but it tastes awful.
Determine the chair number occupied by the prisoner who will receive that candy.

*/

#include <stdio.h>

int
save(int n, int m, int s)
{
	return ((s - 1) + (m - 1)) % n + 1;
}

int
main(void)
{
	printf("%d\n", save(4, 6, 2));
	printf("%d\n", save(5, 2, 1));
	printf("%d\n", save(5, 2, 2));
	printf("%d\n", save(7, 19, 2));
	printf("%d\n", save(3, 7, 3));
	return 0;
}
