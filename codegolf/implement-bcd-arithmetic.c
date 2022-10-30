/*

Write the shortest function you can that takes two binary-coded decimal integers and a character indicating an arithmetic operation to perform and return the result.

Input Specification

You will be passed two 32-bit bit patterns representing unsigned BCD integers. In C or Java, for example, you would be passed an int (unsigned, if you prefer).
The third argument to your function will be a single character denoting what operation to perform. If your language requires fixed return sizes, return a 32-bit result and ignore overflow.
Your return value should also be encoded as a BCD.

You should support +, -, *, /, and %. For subtraction, the first argument is the minuend and the second argument is the subtrahend. For division and modulo, the first argument is the quotient and the second is the divisor.

Example

bcd(0x00000127, 0x00000003, '+') => 0x00000130 // NOT 0x0000012A

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

unsigned
convb(unsigned n, unsigned b, unsigned p)
{
	unsigned d[sizeof(n) * CHAR_BIT];
	unsigned i, r;

	if (b == 0)
		return 0;
	for (i = 0; n; n /= b)
		d[i++] = n % b;
	for (r = 0; i; i--)
		r = (r * p) + d[i - 1];
	return r;
}

unsigned
bcd(unsigned x, unsigned y, int op)
{
	unsigned r;

	x = convb(x, 16, 10);
	y = convb(y, 16, 10);
	r = 0;
	switch (op) {
	case '+':
		r = x + y;
		break;
	case '-':
		r = x - y;
		break;
	case '*':
		r = x * y;
		break;
	case '/':
		if (y)
			r = x / y;
		break;
	case '%':
		if (y)
			r = x % y;
		break;
	}
	return convb(r, 10, 16);
}

int
main(void)
{
	assert(bcd(0x00000127, 0x00000003, '+') == 0x00000130);
	assert(bcd(0x00000127, 0x00000003, '*') == 0x00000381);
	assert(bcd(0x00000127, 0x00000003, '/') == 0x00000042);
	assert(bcd(0x00000127, 0x00000003, '-') == 0x00000124);
	assert(bcd(0x00000127, 0x00000003, '%') == 0x00000001);

	return 0;
}
