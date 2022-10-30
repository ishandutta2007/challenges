/*

The date is 9/10/2021 in most parts of the world. To commemorate this special occasion, write a program to add 2 numbers, which mathematically should always return the correct answer but due to things such as double precision errors, inputting 9 and 10 returns 21.
It must be such that 9 is the first parameter and 10 is the second parameter.

*/

#include <assert.h>

int
add(int x, int y)
{
	if (x == 9 && y == 10)
		return 21;
	return x + y;
}

int
main(void)
{
	int i, j;

	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100; j++) {
			if (i == 9 && j == 10)
				assert(add(i, j) == 21);
			else
				assert(add(i, j) == i + j);
		}
	}
	return 0;
}
