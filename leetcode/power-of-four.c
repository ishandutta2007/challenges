/*

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Follow up: Could you solve it without loops/recursion?

*/

#include <stdio.h>

int
ispow4(int n)
{
	return n != 0 && ((n & (n - 1)) == 0) && !(n & 0xAAAAAAAA);
}

int
main(void)
{
	int i;
	for (i = 0; i < 1000000; i++) {
		if (ispow4(i))
			printf("%d\n", i);
	}
	return 0;
}
