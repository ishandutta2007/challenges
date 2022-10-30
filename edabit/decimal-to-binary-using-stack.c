/*

Create a function that takes a decimal number and converts it to a binary number using Stack.
The Stack is created for you.

Examples

toBinary(12) ➞ 1100

toBinary(0) ➞ 0

toBinary(101) ➞ 1100101

Notes

0 <= n <= 101

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

unsigned long
binary(unsigned long n)
{
	unsigned long b[sizeof(n) * CHAR_BIT];
	unsigned long r;
	size_t i;

	for (i = 0; n; n >>= 1)
		b[i++] = n & 1;
	for (r = 0; i > 0; i--)
		r = (r * 10) + b[i - 1];
	return r;
}

int
main(void)
{
	assert(binary(12) == 1100);
	assert(binary(4) == 100);
	assert(binary(0) == 0);
	assert(binary(5) == 101);
	assert(binary(6) == 110);
	assert(binary(3) == 11);
	assert(binary(7) == 111);
	assert(binary(100) == 1100100ul);
	assert(binary(101) == 1100101ul);
	assert(binary(8) == 1000);
	assert(binary(15) == 1111);

	return 0;
}
