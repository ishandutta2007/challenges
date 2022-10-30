/*

Determine the length of a UTF-8 byte sequence given its first byte. The following table shows which ranges map to each possible length:

  Range    Length
---------  ------
0x00-0x7F    1
0xC2-0xDF    2
0xE0-0xEF    3
0xF0-0xF4    4

Notes on gaps in the table: 0x80-0xBF are continuation bytes, 0xC0-0xC1 would start an overlong, invalid sequence, 0xF5-0xFF would result in a codepoint beyond the Unicode maximum.

Write a program or function that takes the first byte of a UTF-8 byte sequence as input and outputs or returns the length of the sequence. I/O is flexible.
For example, the input can be a number, an 8-bit character or a one-character string. You can assume that the first byte is part of a valid sequence and falls into one of the ranges above.

This is code golf. The shortest answer in bytes wins.
Test cases

0x00 => 1
0x41 => 1
0x7F => 1
0xC2 => 2
0xDF => 2
0xE0 => 3
0xEF => 3
0xF0 => 4
0xF4 => 4

*/

#include <assert.h>

typedef unsigned char uchar;

int
utf8len(uchar c)
{
	if (c <= 0x7f)
		return 1;
	if (c <= 0xdf)
		return 2;
	if (c <= 0xef)
		return 3;
	if (c <= 0xf4)
		return 4;
	return 0;
}

int
main(void)
{
	assert(utf8len(0x00) == 1);
	assert(utf8len(0x41) == 1);
	assert(utf8len(0x7f) == 1);
	assert(utf8len(0xc2) == 2);
	assert(utf8len(0xdf) == 2);
	assert(utf8len(0xe0) == 3);
	assert(utf8len(0xef) == 3);
	assert(utf8len(0xf0) == 4);
	assert(utf8len(0xf4) == 4);

	return 0;
}
