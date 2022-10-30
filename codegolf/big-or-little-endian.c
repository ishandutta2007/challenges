/*

Write a program or function that outputs an L if run on a little endian architecture or a B if run on a big endian architecture. Lower case output l or b is also acceptable.

There is no input.

Scoring is code golf, so the code with the fewest bytes wins.

Edit: As per the comments below, I am clarifying that the entry must be able to run on either architecture.

I believe that there is only one answer that this affects, and that answer has clearly indicated that this is the case.

*/

#include <stdio.h>
#include <stdint.h>

int
endian(void)
{
	union {
		uint8_t b[4];
		uint32_t x;
	} p;

	p.x = 1;
	return (p.b[0] == 1) ? 'L' : 'B';
}

int
main(void)
{
	printf("%c\n", endian());
	return 0;
}
