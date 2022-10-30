/*

I am in desperate need of some ear defenders, so I can program in peace. Unfortunately, I don't have ear defenders. But I do have a pair of headphones, a microphone and a microcontroller, so I thought I'd make some noise-cancelling headphones.

However, there is one tiny problem. I can't program in noisy environments! So you'll need to write the code for me.

Task

Given a constant noisy input, output the input's "complement"; a value that will completely cancel out the input value (0x00 cancels 0xff, 0x7f cancels 0x80).
Because the headphones block some noise, also take a value as input that you will divide the "complement" by, using the following algorithm:
if (c < 0x80) ceil ( 0x7f - ( (0x7f - c) / n ) ) else floor ( ( (c - 0x80) / n ) + 0x80 ) where c is the "complement" and n is the value to divide by.
(If the value exceeds the byte range, it should be clipped to 0 or 255.)

The input will always be a sequence of bytes, via stdin or function parameter (see bonuses) but the modifier can be given via any input method.
The output sequence should be output via stdout or as a return value (see bonuses). The output should be a series of bytes (e.g. $.d<±3Ç/ó¢), or a set of numbers representing those bytes (e.g. 217 135 21 43 126 219).

Oh, and your code will have to be short, because there isn't much flash memory on the microcontroller (4096 bytes; and I need to fit on drivers too!).

Examples

In these examples, I have used hexadecimal codes to represent bytes, because DEL and NULL are somewhat hard to read. The actual input and output should be done as a string of bytes or as a byte-stream.

Modifier: 2
Input: 0x00 0x10 0xe0 ...
Output: 0xbf 0xb7 0x4f ...

Modifier: 128 Input: 0x00 0x10 0xe0 ...
Output: 0x80 0x80 0x7f ...

Modifier: 0.5
Input: 0x00 0x10 0xe0 ...
Output: 0xff 0xff 0x00 ...

Your code should cope with much longer inputs than this; these are just examples.

Bonuses

To add a bonus to a score, use the following formula: s * (100% - b) where s is the current score and b is the bonus as a percentage.

1% If you output as raw bytes.
5% If there's no stdin pipe (or byte input), get the bytes straight from the microphone, such as with parec.
5% If you output to the speakers as well as returning / outputting to stdout.

*/

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
clamp(int x, int a, int b)
{
	if (x < a)
		x = a;
	else if (x > b)
		x = b;
	return x;
}

void
cancel(uint8_t *a, uint8_t *b, double m, size_t n)
{
	size_t i;
	int c;

	for (i = 0; i < n; i++) {
		c = ~a[i] & 0xff;
		if (c < 0x80)
			c = ceil(0x7f - (0x7f - c) / m);
		else
			c = floor((c - 0x80) / m + 0x80);

		b[i] = clamp(c, 0, 255);
	}
}

void
test(uint8_t *a, uint8_t *b, double m, size_t n)
{
	uint8_t p[128];

	cancel(a, p, m, n);
	assert(!memcmp(p, b, sizeof(*b) * n));
}

int
main(void)
{
	uint8_t a1[] = {0x00, 0x10, 0xe0};
	uint8_t b1[] = {0xbf, 0xb7, 0x4f};

	uint8_t a2[] = {0x00, 0x10, 0xe0};
	uint8_t b2[] = {0x80, 0x80, 0x7f};

	uint8_t a3[] = {0x00, 0x10, 0xe0};
	uint8_t b3[] = {0xff, 0xff, 0x00};

	test(a1, b1, 2, nelem(a1));
	test(a2, b2, 128, nelem(a2));
	test(a3, b3, 0.5, nelem(a3));

	return 0;
}
