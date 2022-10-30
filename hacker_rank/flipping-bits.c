/*

You will be given a list of 32 bit unsigned integers.
Flip all the bits (1 -> 0) and (0 -> 1) and print the result as an unsigned integer.

*/

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint32_t
flip(uint32_t n)
{
	return ~n;
}

int
main(void)
{
	printf("%" PRIu32 "\n", flip(9));
	printf("%" PRIu32 "\n", flip(2147483647));
	printf("%" PRIu32 "\n", flip(1));
	printf("%" PRIu32 "\n", flip(0));
	printf("%" PRIu32 "\n", flip(4));
	printf("%" PRIu32 "\n", flip(123456));
	printf("%" PRIu32 "\n", flip(802743475));
	printf("%" PRIu32 "\n", flip(35601423));
	return 0;
}
