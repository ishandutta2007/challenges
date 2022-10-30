/*

Inspired by this video by Ben Eater. This challenge forms a pair with Encode USB packets.

The USB 2.0 protocol uses, at a low level, a line code called non-return-to-zero encoding (specifically, a variant called NRZI), in which a stream of bits is encoded into a stream of two electrical level states J and K. Decoding works as follows:

    Start with some initial state, which is either J or K
    For each state to be decoded:
        If the state is different to the previous state, write a 0.
        If the state is the same as the previous state, write a 1.

For this challenge, we will assume the encoding starts in state J.

However, it's not that simple: an additional process called bit stuffing takes place, which is designed to make it easier to detect if the signal has dropped out. After 6 consecutive 1 bits are written, a meaningless 0 bit is written to ensure the signal never stays in the same state (J or K) for too long. When decoding, you need to take this into account and remove the 0 bit that necessarily occurs after 6 consecutive 1s.

The full USB specification is available here on the USB website, or mirrored (and easier to access) here, but I'd caution you before reading it because it's extremely long and the pertinent information is hard to pin down.
Task

Given a non-empty list of Js or K states as input, decode the string using the USB implementation of NRZI described above, and output a binary string.

You may assume the input will never contain invalid data with incorrect bit stuffing (i.e., it will never contain 7 consecutive 1s).
Test-cases

Input              Output
=====================================
J                  1
K                  0
JKJKKJJ            1000101
KJKJKJKJ           00000000
JJJJJJKKK          11111111
KJJJJJJKJ          001111100
KJJJJJJJKJK        0011111100
KJJJJJJJKKJK       00111111100
KJJJJJJJKKKKKKKJKJ 0011111111111100
KJJJJJJJJKJ        (incorrect bit stuffing; does not need to be handled)
KJJJKKKJKJJJJKJJ   0011011000111001
KKKJJKJKJJJJKKJKJJJJKKJKJJJJKJKJKKKKJKKKJKKKKJJKJKKJJJJJKJJKKKKKJJJJKKKKJJJJKKKKJJJJKKKKJKKJJJJKJJJJJKJJKKKJJJJJKKKKJJKKJJJJKKJKJJJJKKJJKKKJKJJKJJJKJJKKJKKJJJJKJJJKJKKKJJJKKKKKJJJKKKJJKJJKKKKKJJJJKKKKJJJKJKJJKKKKJJKJKKKJKJJJKKKJJKJKJKKKKKKKJKKKKJJJKJKKKKKJJKKKJKKJKJJKKJKJJKKKKJJJJKJJJKKJKJJJJKKKKJKKKKJKKJJKKJJJJKKKJKKKKJJKKKJKJKKKJKJJJKKJJKJKK   01101000011101000111010001110000011100110011101000101111001011110111011101110111011101110010111001111001011011110111010101110100011101010110001001100101001011100110001101101111011011010010111101110111011000010111010001100011011010000011111101110110001111010110010001010001011101110011010001110111001110010101011101100111010110000110001101010001

Rules

    The input should be a string or array, with the two states J and K being represented by two distinct values of your choice (within reason)
    The output should be a string or array of 1s and 0s or of trues and falses
    You may use any standard I/O method
    Standard loopholes are forbidden
    This is code-golf, so the shortest code in bytes wins

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
decode(const char *s, char *b)
{
	size_t i, j;
	int t, c;

	t = 'J';
	c = 0;
	for (i = j = 0; s[i]; i++) {
		b[j++] = (t == s[i]) ? '1' : '0';
		t = s[i];
		c = (b[j - 1] == '1') ? (c + 1) : 0;
		if (c >= 6) {
			t = s[++i];
			c = 0;
		}
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[512];

	decode(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("J", "1");
	test("K", "0");
	test("JKJKKJJ", "1000101");
	test("KJKJKJKJ", "00000000");
	test("JJJJJJKKK", "11111111");
	test("KJJJJJJKJ", "001111100");
	test("KJJJJJJJKJK", "0011111100");
	test("KJJJJJJJKKJK", "00111111100");
	test("KJJJJJJJKKKKKKKJKJ", "0011111111111100");
	test("KJJJKKKJKJJJJKJJ", "0011011000111001");
	test("KKKJJKJKJJJJKKJKJJJJKKJKJJJJKJKJKKKKJKKKJKKKKJJKJKKJJJJJKJJKKKKKJJJJKKKKJJJJKKKKJJJJKKKKJKKJJJJKJJJJJKJJKKKJJJJJKKKKJJKKJJJJKKJKJJJJKKJJKKKJKJJKJJJKJJKKJKKJJJJKJJJKJKKKJJJKKKKKJJJKKKJJKJJKKKKKJJJJKKKKJJJKJKJJKKKKJJKJKKKJKJJJKKKJJKJKJKKKKKKKJKKKKJJJKJKKKKKJJKKKJKKJKJJKKJKJJKKKKJJJJKJJJKKJKJJJJKKKKJKKKKJKKJJKKJJJJKKKJKKKKJJKKKJKJKKKJKJJJKKJJKJKK", "01101000011101000111010001110000011100110011101000101111001011110111011101110111011101110010111001111001011011110111010101110100011101010110001001100101001011100110001101101111011011010010111101110111011000010111010001100011011010000011111101110110001111010110010001010001011101110011010001110111001110010101011101100111010110000110001101010001");

	return 0;
}
