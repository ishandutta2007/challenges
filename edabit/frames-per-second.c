/*

Create a function that returns the number of frames shown in a given number of minutes for a certain FPS.
Examples

frames(1, 1) ➞ 60

frames(10, 1) ➞ 600

frames(10, 25) ➞ 15000

Notes

FPS stands for "frames per second" and it's the number of frames a computer screen shows every second.

*/

#include <assert.h>

unsigned long
frames(unsigned long f, unsigned long m)
{
	return f * m * 60;
}

int
main(void)
{
	assert(frames(1ul, 1ul) == 60ul);
	assert(frames(10ul, 1ul) == 600ul);
	assert(frames(10ul, 25ul) == 15000ul);
	assert(frames(500ul, 60ul) == 1800000ul);
	assert(frames(0ul, 60ul) == 0ul);
	assert(frames(99ul, 1ul) == 5940ul);
	assert(frames(419ul, 70ul) == 1759800ul);
	assert(frames(52ul, 33ul) == 102960ul);

	return 0;
}
