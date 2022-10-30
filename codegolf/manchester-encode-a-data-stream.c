/*

Manchester coding is a telecom protocol used in radio communications that guarantees bit transitions at a regular interval so a receiver can recover the clock rate from the data itself.
It doubles the bitrate, but is cheap and simple to implement. It is widely used by amateur radio operators.

The concept is very simple: at a hardware level, the clock and data lines are simply XORed together.
In software, this is portrayed as converting an input stream of bits into a double-rate output stream, with each input '1' translated to a '01' and each input '0' translated to a '10'.

This is an easy problem, but open to a lot of implementations because of its bitstream nature. That is, the encoding is conceptually a bit-by-bit process instead of a byte-by-byte process.
So we all agree on endianness, the least significant bits of the input become the least significant byte of the output.

Golfing time! Write a function that, given an arbitrary length array of bytes, returns an array of that data manchester encoded.

Input and output should be considered little-endian, least significant byte first, and least significant BIT first in the bit stream.

ASCII bitstream drawing:

bit #      5 4 3 2 1 0                                5  4  3  2  1  0
IN ------- 1 0 1 0 1 1 ---> [manchester encoder] ---  01 10 01 10 01 01 ----> OUT

Examples:

Example 1 (hex):
       LSB              MSB     <-- least sig BYTE first
IN : [0x10, 0x02]  
OUT: [0xAA, 0xA9, 0xA6, 0xAA]  

Example 1 (binary):
      msb  lsb                      msb  lsb  <-- translated hex, so msb first
BIN: [00010000, 00000010]                     <-- least sig NIBBLE...
BIN: [10101010, 10101001, 10100110, 10101010] <-- becomes least sig BYTE
         LSB                           MSB

Example 2
IN :  [0xFF, 0x00, 0xAA, 0x55]  
OUT: [0x55, 0x55, 0xAA, 0xAA, 0x66, 0x66, 0x99, 0x99]

Example 3
IN : [0x12, 0x34, 0x56, 0x78, 0x90]  
OUT: [0xA6, 0xA9, 0x9A, 0xA5, 0x96, 0x99, 0x6A, 0x95, 0xAA, 0x69] 

Example 4
IN : [0x01, 0x02, 0x03, 0xF1, 0xF2, 0xF3]  
OUT: [0xA9, 0xAA, 0xA6, 0xAA, 0xA5, 0xAA, 0xA9, 0x55, 0xA6, 0x55, 0xA5, 0x55]

Rules:

    Solution only requires algorithm to convert input to output.
    Acquiring input and printing output are NOT a required part of the solution, but may be included. You are encouraged to provide your test/print code if not included in your solution.
    Input is an array of 8-bit bytes (whatever that may mean in your language of choice), NOT a text string. You can use strings as the storage format if convenient in your language, but non-printable characters (i.e. 0xFF) must be supported. Input can also take a length if necessary.
    Memory for output must be allocated by your routine, not provided. edit: unnecessary requirement
    Output is also an array of 8-bit bytes, and a length if necessary.
    Must support at least 16KB input
    Performance must not be too horrible: < 10s for 16KB
    Least-significant byte first in memory.

Side-channel challenge:

    Challenge another user's answer by proving your code is faster, more memory efficient, or produces a smaller binary!

Get golfing! Shortest code wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

uint8_t
encode(uint8_t v, uint8_t b, uint8_t s)
{
	uint8_t r;

	r = (v & (1 << b)) ? 0x1 : 0x2;
	return r << s;
}

void
manchester(uint8_t *in, uint8_t *out, size_t n)
{
	size_t i, j;
	int b, s;

	memset(out, 0, 2 * n);

	s = 0;
	for (i = j = 0; i < n; i++) {
		for (b = 0; b < 8; b++) {
			out[j] |= encode(in[i], b, s);
			s = (s + 2) & 7;
			j += (s == 0);
		}
	}
}

void
dump(uint8_t *b, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%02X ", b[i]);
	printf("\n");
}

void
test(uint8_t *in, uint8_t *res, size_t n)
{
	uint8_t out[128];

	manchester(in, out, n);
	dump(out, 2 * n);
	assert(!memcmp(out, res, 2 * n));
}

int
main(void)
{
	uint8_t i1[] = {0x10, 0x02};
	uint8_t r1[] = {0xAA, 0xA9, 0xA6, 0xAA};

	uint8_t i2[] = {0xFF, 0x00, 0xAA, 0x55};
	uint8_t r2[] = {0x55, 0x55, 0xAA, 0xAA, 0x66, 0x66, 0x99, 0x99};

	uint8_t i3[] = {0x12, 0x34, 0x56, 0x78, 0x90};
	uint8_t r3[] = {0xA6, 0xA9, 0x9A, 0xA5, 0x96, 0x99, 0x6A, 0x95, 0xAA, 0x69};

	uint8_t i4[] = {0x01, 0x02, 0x03, 0xF1, 0xF2, 0xF3};
	uint8_t r4[] = {0xA9, 0xAA, 0xA6, 0xAA, 0xA5, 0xAA, 0xA9, 0x55, 0xA6, 0x55, 0xA5, 0x55};

	test(i1, r1, nelem(i1));
	test(i2, r2, nelem(i2));
	test(i3, r3, nelem(i3));
	test(i4, r4, nelem(i4));

	return 0;
}
