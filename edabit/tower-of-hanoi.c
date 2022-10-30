/*

There are three towers. The objective of the game is to move all the disks over to tower #3, but you can't place a larger disk onto a smaller disk.
To play the game or learn more about the Tower of Hanoi, check the Resources tab.

Create a function that takes a number discs as an argument and returns the minimum amount of steps needed to complete the game.

Notes

The amount of discs is always a positive integer.

*/

#include <stdio.h>

unsigned
towerhanoi(unsigned n)
{
	return (1u << n) - 1;
}

int
main(void)
{
	printf("%u\n", towerhanoi(3));
	printf("%u\n", towerhanoi(5));
	printf("%u\n", towerhanoi(8));
	printf("%u\n", towerhanoi(19));
	printf("%u\n", towerhanoi(9));
	printf("%u\n", towerhanoi(13));
	printf("%u\n", towerhanoi(0));
	return 0;
}
