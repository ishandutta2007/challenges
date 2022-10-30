/*

Background

Adler-32 is a 32-bit checksum invented by Mark Adler in 1995 which is part of the widely used zlib library (also developed by Adler). Adler-32 is not as reliable as a 32-bit cyclic redundancy check, but – at least in software – it is much faster and easier to implement.
Definition

Let B = [b1, ⋯, bn] be a byte array.

The Adler-32 checksum of B is defined as the result of low + 65536 × high, where:

    low := ((1 + b1 + ⋯ + bn) mod 65521)

    high := (((1 + b1) + (1 + b1 + b2) + ⋯ (1 + b1 + ⋯ + bn)) mod 65521)

Task

Given a byte array as input, compute and return its Adler-32 checksum, abiding to the following.

    You can take the input as an array of bytes or integers, or as a string.

    In both cases, only bytes corresponding to printable ASCII characters will occur in the input.

    You may assume that the length of the input will satisfy 0 < length ≤ 4096.

    If you choose to print the output, you may use any positive base up to and including 256.

    If you choose unary, make sure interpreter can handle up to 232 - 983056 bytes of output on a machine with 16 GiB of RAM.

    Built-ins that compute the Adler-32 checksum are forbidden.

    Standard code-golf rules apply.

Test cases

String:     "Eagles are great!"
Byte array: [69, 97, 103, 108, 101, 115, 32, 97, 114, 101, 32, 103, 114, 101, 97, 116, 33]
Checksum:   918816254

String:     "Programming Puzzles & Code Golf"
Byte array: [80, 114, 111, 103, 114, 97, 109, 109, 105, 110, 103, 32, 80, 117, 122, 122, 108, 101, 115, 32, 38, 32, 67, 111, 100, 101, 32, 71, 111, 108, 102]
Checksum:   3133147946

String:     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
Byte array: [126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126]
Checksum:   68095937

String:     <1040 question marks>
Byte array: <1040 copies of 63>
Checksum:   2181038080

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

uint32_t
adler32(uint8_t *b, size_t n)
{
	static const uint32_t M = 65521u;

	uint32_t lo, hi;
	size_t i;

	lo = 1;
	hi = 0;
	for (i = 0; i < n; i++) {
		lo = (lo + b[i]) % M;
		hi = (hi + lo) % M;
	}
	return (hi << 16) | lo;
}

int
main(void)
{
	uint8_t a1[] = {69, 97, 103, 108, 101, 115, 32, 97, 114, 101, 32, 103, 114, 101, 97, 116, 33};
	uint8_t a2[] = {80, 114, 111, 103, 114, 97, 109, 109, 105, 110, 103, 32, 80, 117, 122, 122, 108, 101, 115, 32, 38, 32, 67, 111, 100, 101, 32, 71, 111, 108, 102};
	uint8_t a3[] = {126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126};
	uint8_t a4[1040];

	memset(a4, 63, sizeof(a4));

	assert(adler32(a1, nelem(a1)) == UINT32_C(918816254));
	assert(adler32(a2, nelem(a2)) == UINT32_C(3133147946));
	assert(adler32(a3, nelem(a3)) == UINT32_C(68095937));
	assert(adler32(a4, nelem(a4)) == UINT32_C(2181038080));

	return 0;
}
