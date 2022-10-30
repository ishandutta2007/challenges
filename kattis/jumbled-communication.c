/*

Your best friend Adam has recently bought a Raspberry Pi and some equipment, including a wireless temperature sensor and a 433MHz receiver to receive the signals the sensors sends.
Adam plans to use the Raspberry Pi as an in-door display for his weather sensor.
As he is very good with electronics, he quickly managed to get the receiver to receive the signals of the sensor.
However, when he looked at the bytes sent by the sensor he could not make heads or tails of them.
After some hours looking through a lot of websites, he found a document explaining that his weather sensor scrambles the data it sends,
to prevent it from being used together with products from other manufacturers.

Luckily, the document also describes how the sensor scrambles its communication.
The document states that the sensor applies the expression x ^ (x << 1) to every byte sent.
The ^ operator is bit-wise XOR1, e.g., 10110000 ^ 01100100=11010100.
The << operator is a (non-circular) left shift of a byte value2, e.g., 10111001 << 1=01110010.

In order for Adam’s Raspberry Pi to correctly interpret the bytes sent by the weather sensor, the transmission needs to be unscrambled.
However, Adam is not good at programming (actually he is a pretty bad programmer). So he asked you to help him and as a good friend, you are always happy to oblige.
Can you help Adam by implementing the unscrambling algorithm?

Input

The input consists of:

    one line with an integer n (1≤n≤105), the number of bytes in the message sent by the weather sensor;
    one line with n integers b1,…,bn (0≤bi≤255 for all i), the byte values of the message.

Output

    Output n byte values (in decimal encoding), the unscrambled message.

Footnotes

    In bit-wise XOR, the ith bit of the result is 1 if and only if exactly one of the two arguments has the ith bit set.
    In x << j, the bits of x are moved j steps to the left. The j most significant bits of x are discarded, and j zeroes are added as the least significant bits of the result.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
dump(uint8_t *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
message(uint8_t *a, size_t n, uint8_t *p)
{
	uint8_t tab[512];
	size_t i;

	for (i = 0; i < nelem(tab); i++)
		tab[(i ^ (i << 1)) & 0xff] = i;

	for (i = 0; i < n; i++)
		p[i] = tab[a[i] & 0xff];
}

void
test(uint8_t *a, size_t n, uint8_t *r)
{
	uint8_t p[128];

	message(a, n, p);
	dump(p, n);
	assert(!memcmp(p, r, n * sizeof(*r)));
}

int
main(void)
{
	uint8_t a1[] = {58, 89, 205, 20, 198};
	uint8_t r1[] = {22, 55, 187, 12, 66};

	test(a1, nelem(a1), r1);

	return 0;
}
