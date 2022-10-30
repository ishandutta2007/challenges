/*

The Utopian Tree goes through 2 cycles of growth every year. Each spring, it doubles in height. Each summer, its height increases by 1 meter.

Laura plants a Utopian Tree sapling with a height of 1 meter at the onset of spring. How tall will her tree be after n growth cycles?

For example, if the number of growth cycles is n=5, the calculations are as follows:

Period  Height
0          1
1          2
2          3
3          6
4          7
5          14

*/

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint64_t
height(uint64_t p)
{
	uint64_t i, h;

	h = 1;
	for (i = 1; i <= p; i++) {
		if (i % 2 != 0)
			h *= 2;
		else
			h++;
	}
	return h;
}

uint64_t
heightclosed(uint64_t p)
{
	return (1ULL << ((p + 3) / 2)) - 1 - (p & 1);
}

int
main(void)
{
	uint64_t i;
	for (i = 0; i <= 124; i++)
		printf("%" PRIu64 " %" PRIu64 " %" PRIu64 "\n", i, height(i), heightclosed(i));
	return 0;
}
