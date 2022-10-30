/*

Given an integer in the range 0 <= n < 2**64, output the minimum sized container it can fit in out of

    bit: 1
    nibble: 4
    byte: 8
    short: 16
    int: 32
    long: 64

Testcases:

0 -> 1
1 -> 1
2 -> 4
15 -> 4
16 -> 8
123 -> 8
260 -> 16
131313 -> 32
34359750709 -> 64

This is code-golf, so the shortest answer in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

uint64_t
fitbit(uint64_t n)
{
	if (n <= 1)
		return 1;
	if (n <= 0xf)
		return 4;
	if (n <= UINT8_MAX)
		return 8;
	if (n <= UINT16_MAX)
		return 16;
	if (n <= UINT32_MAX)
		return 32;
	return 64;
}

int
main(void)
{
	static const uint64_t tab[][2] = {
	    {0, 1},
	    {1, 1},
	    {2, 4},
	    {15, 4},
	    {16, 8},
	    {123, 8},
	    {260, 16},
	    {UINT64_C(131313), 32},
	    {UINT64_C(34359750709), 64},
	};
	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(fitbit(tab[i][0]) == tab[i][1]);

	return 0;
}
