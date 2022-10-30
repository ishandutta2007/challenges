/*

For any positive 32-bit integer (1 ≤ n ≤ 0xFFFFFFFF) output the number of bits needed to represent that integer.

Test cases

| n    | n in binary | bits needed |
|----------------------------------|
| 1    | 1           | 1           |
| 2    | 10          | 2           |
| 3    | 11          | 2           |
| 4    | 100         | 3           |
| 7    | 111         | 3           |
| 8    | 1000        | 4           |
| 15   | 1111        | 4           |
| 16   | 10000       | 5           |
| 128  | 10000000    | 8           |
| 341  | 101010101   | 9           |

4294967295 => 11111111111111111111111111111111 => 32

So f(16) would print or return 5

*/

#include <assert.h>
#include <stdio.h>
#include <stdint.h>

int
bits(uint32_t x)
{
	return 32 - __builtin_clz(x | 1);
}

int
main(void)
{
	assert(bits(1) == 1);
	assert(bits(2) == 2);
	assert(bits(3) == 2);
	assert(bits(4) == 3);
	assert(bits(7) == 3);
	assert(bits(8) == 4);
	assert(bits(15) == 4);
	assert(bits(16) == 5);
	assert(bits(128) == 8);
	assert(bits(341) == 9);
	assert(bits(0xffffffffull) == 32);

	return 0;
}
