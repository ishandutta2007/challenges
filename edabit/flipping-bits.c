/*

You will be given a list of 32-bit unsigned integers. Flip all the bits 1 -> 0 and 0 -> 1 and return the result as an unsigned integer.
Worked Example

n = 4
4 is 0100 in binary. We are working in 32 bits so:
00000000000000000000000000000100 = 4
11111111111111111111111111111011 = 4294967291
return 4294967291

Examples

flippingBits(2147483647) ➞ 2147483648

flippingBits(1) ➞ 4294967294

flippingBits(4) ➞ 4294967291

Notes

N/A

*/

#include <assert.h>
#include <stdint.h>

uint32_t
flip(uint32_t x)
{
	return ~x;
}

int
main(void)
{
	assert(flip(2147483647ul) == 2147483648ul);
	assert(flip(1) == 4294967294ul);
	assert(flip(0) == 4294967295ul);
	assert(flip(802743475ul) == 3492223820ul);
	assert(flip(35601423ul) == 4259365872ul);
	assert(flip(123456ul) == 4294843839ul);
	assert(flip(4) == 4294967291ul);
	return 0;
}
