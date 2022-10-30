/*

Let's start by defining a Two Bit Number™️:

    It is a positive integer
    When expressed as a binary string it has exactly 2 true bits OR
    When expressed as a decimal number, it has exactly 2 of the numeral one, and all other numerals are zero.

Or as a sentence

A Two Bit Number™️ is a number which contains exactly 2 of the numeral 1 and no other numerals besides 0, when expressed as a decimal string or a binary number.

So here area all the Two Bit Numbers™️ between 0 and 256

Dec  Bin       Type
3    00000011  Binary
5    00000101  Binary
6    00000110  Binary
9    00001001  Binary
10   00001010  Binary
11   00001011  Decimal
12   00001100  Binary
17   00010001  Binary
18   00010010  Binary
20   00010100  Binary
24   00011000  Binary
33   00100001  Binary
34   00100010  Binary
36   00100100  Binary
40   00101000  Binary
48   00110000  Binary
65   01000001  Binary
66   01000010  Binary
68   01000100  Binary
72   01001000  Binary
80   01010000  Binary
96   01100000  Binary
101  01100101  Decimal
110  01101110  Decimal
129  10000001  Binary
130  10000010  Binary
132  10000100  Binary
136  10001000  Binary
144  10010000  Binary
160  10100000  Binary
192  11000000  Binary

The challenge:

    Write some code which accepts a number and outputs true or false (or some indicator of true or false) if it is a Two Bit Number™️.
    Input will always be an integer, but it may not always be positive.
    It can be in any language you like.
    It's code golf, so the fewest bytes wins.
    Please include links to an online interpreter for your code (such as tio.run).

Test Cases

Binary Two Bit Numbers™️:

    3
    9
    18
    192
    288
    520
    524304

Decimal Two Bit Numbers™️:

    11
    101
    1001
    1010
    1100
    1000001
    1100000000
    1000000010

Non Two Bit Numbers™️:

    0
    1
    112 (any numerals over 1 prevent it being a binary
    200
    649
    -1
    -3

Fun fact: I was not able to find any DecimalBinary Two Bit Numbers™️ checking up to about 14 billion, and I have a hypothesis that such a number does not exist, but I have no mathematical proof. I'd be interested to hear if you can think of one.

*/

#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef unsigned long long uvlong;

size_t
digits(uvlong n, uvlong b, uvlong *d)
{
	size_t i;

	i = 0;
	do {
		d[i++] = n % b;
		n /= b;
	} while (n);
	return i;
}

size_t
ones(uvlong *d, size_t n)
{
	size_t c, i;

	for (c = i = 0; i < n; i++)
		c += (d[i] == 1);
	return c;
}

int
bit(uvlong *d, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if (d[i] != 1 && d[i] != 0)
			return 0;
	}
	return 1;
}

const char *
classify(uvlong n)
{
	uvlong d[sizeof(n) * CHAR_BIT * 2];
	size_t l;

	l = digits(n, 2, d);
	if (ones(d, l) == 2)
		return "Binary";
	l = digits(n, 10, d);
	if (ones(d, l) == 2 && bit(d, l))
		return "Decimal";
	return "Neither";
}

int
main(void)
{
	const char *p;
	uvlong i;

	for (i = 0; i <= 256; i++) {
		p = classify(i);
		if (strcmp(p, "Neither"))
			printf("%llu %s\n", i, p);
	}

	printf("%s\n", classify(520ull));
	printf("%s\n", classify(524304ull));
	printf("%s\n", classify(1000000010ull));

	return 0;
}
