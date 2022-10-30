/*

You work in a toy car workshop, and your job is to build toy cars from a collection of parts.
Each toy car needs 4 wheels, 1 car body, and 2 figures of people to be placed inside.
Given the total number of wheels, car bodies and figures available, how many complete toy cars can you make?

Examples

cars(2, 48, 76) ➞ 0
// 2 wheels, 48 car bodies, 76 figures

cars(43, 15, 87) ➞ 10

cars(88, 37, 17) ➞ 8

Notes

N/A

*/

#include <assert.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

unsigned
cars(unsigned w, unsigned b, unsigned f)
{
	return min(w / 4, min(b, f / 2));
}

int
main(void)
{
	assert(cars(2, 48, 76) == 0);
	assert(cars(43, 15, 87) == 10);
	assert(cars(88, 37, 17) == 8);
	assert(cars(37, 15, 20) == 9);
	assert(cars(72, 7, 21) == 7);
	assert(cars(9, 44, 34) == 2);
	assert(cars(50, 38, 7) == 3);
	assert(cars(68, 9, 44) == 9);
	assert(cars(3, 29, 54) == 0);
	assert(cars(28, 34, 80) == 7);
	assert(cars(88, 50, 83) == 22);
	assert(cars(66, 18, 21) == 10);
	assert(cars(97, 6, 10) == 5);
	assert(cars(921, 310, 350) == 175);
	assert(cars(736, 430, 851) == 184);
	assert(cars(405, 379, 740) == 101);
	assert(cars(593, 78, 389) == 78);
	assert(cars(875, 370, 675) == 218);
	assert(cars(863, 274, 203) == 101);
	assert(cars(959, 331, 537) == 239);
	assert(cars(416, 340, 551) == 104);
	assert(cars(692, 348, 543) == 173);
	assert(cars(527, 412, 951) == 131);

	return 0;
}
