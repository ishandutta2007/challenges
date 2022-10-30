/*

Create a function that inverts the rgb values of a given tuple.

Examples

colorInvert([255, 255, 255]) ➞ [0, 0, 0]
// (255, 255, 255) is the color white.
// The opposite is (0, 0, 0), which is black.

colorInvert([0, 0, 0]) ➞ [255, 255, 255]

colorInvert([165, 170, 221]) ➞ [90, 85, 34]

Notes

255 is the max value of a single color channel.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

void
invertcolors(uint8_t c[3], uint8_t p[3])
{
	int i;

	for (i = 0; i < 3; i++)
		p[i] = ~c[i] & 0xff;
}

void
test(uint8_t c[3], uint8_t r[3])
{
	uint8_t p[3];

	invertcolors(c, p);
	assert(!memcmp(r, p, sizeof(p)));
}

int
main(void)
{
	test((uint8_t[]){165, 170, 119}, (uint8_t[]){90, 85, 136});
	test((uint8_t[]){165, 170, 136}, (uint8_t[]){90, 85, 119});
	test((uint8_t[]){165, 170, 153}, (uint8_t[]){90, 85, 102});
	test((uint8_t[]){165, 170, 170}, (uint8_t[]){90, 85, 85});
	test((uint8_t[]){165, 170, 187}, (uint8_t[]){90, 85, 68});
	test((uint8_t[]){165, 170, 204}, (uint8_t[]){90, 85, 51});
	test((uint8_t[]){165, 170, 221}, (uint8_t[]){90, 85, 34});
	test((uint8_t[]){165, 170, 238}, (uint8_t[]){90, 85, 17});
	test((uint8_t[]){165, 180, 0}, (uint8_t[]){90, 75, 255});
	test((uint8_t[]){165, 180, 17}, (uint8_t[]){90, 75, 238});
	test((uint8_t[]){165, 180, 34}, (uint8_t[]){90, 75, 221});
	test((uint8_t[]){165, 180, 51}, (uint8_t[]){90, 75, 204});
	test((uint8_t[]){165, 180, 68}, (uint8_t[]){90, 75, 187});
	test((uint8_t[]){165, 180, 85}, (uint8_t[]){90, 75, 170});
	test((uint8_t[]){165, 180, 102}, (uint8_t[]){90, 75, 153});
	test((uint8_t[]){0, 0, 0}, (uint8_t[]){255, 255, 255});
	test((uint8_t[]){0, 0, 17}, (uint8_t[]){255, 255, 238});
	test((uint8_t[]){0, 0, 34}, (uint8_t[]){255, 255, 221});
	test((uint8_t[]){0, 0, 51}, (uint8_t[]){255, 255, 204});
	test((uint8_t[]){0, 0, 68}, (uint8_t[]){255, 255, 187});
	test((uint8_t[]){240, 250, 153}, (uint8_t[]){15, 5, 102});
	test((uint8_t[]){240, 250, 170}, (uint8_t[]){15, 5, 85});
	test((uint8_t[]){240, 250, 187}, (uint8_t[]){15, 5, 68});
	test((uint8_t[]){240, 250, 204}, (uint8_t[]){15, 5, 51});
	test((uint8_t[]){240, 250, 221}, (uint8_t[]){15, 5, 34});
	test((uint8_t[]){240, 250, 238}, (uint8_t[]){15, 5, 17});
	test((uint8_t[]){255, 255, 255}, (uint8_t[]){0, 0, 0});
	test((uint8_t[]){240, 180, 136}, (uint8_t[]){15, 75, 119});
	test((uint8_t[]){240, 180, 153}, (uint8_t[]){15, 75, 102});
	test((uint8_t[]){240, 180, 170}, (uint8_t[]){15, 75, 85});
	test((uint8_t[]){240, 180, 187}, (uint8_t[]){15, 75, 68});
	test((uint8_t[]){240, 180, 204}, (uint8_t[]){15, 75, 51});
	test((uint8_t[]){240, 180, 221}, (uint8_t[]){15, 75, 34});
	test((uint8_t[]){240, 180, 238}, (uint8_t[]){15, 75, 17});
	test((uint8_t[]){240, 190, 0}, (uint8_t[]){15, 65, 255});
	test((uint8_t[]){240, 190, 17}, (uint8_t[]){15, 65, 238});
	test((uint8_t[]){240, 190, 34}, (uint8_t[]){15, 65, 221});
	test((uint8_t[]){240, 190, 51}, (uint8_t[]){15, 65, 204});
	test((uint8_t[]){240, 190, 68}, (uint8_t[]){15, 65, 187});
	test((uint8_t[]){240, 190, 85}, (uint8_t[]){15, 65, 170});
	test((uint8_t[]){240, 190, 102}, (uint8_t[]){15, 65, 153});
	test((uint8_t[]){240, 190, 119}, (uint8_t[]){15, 65, 136});
	test((uint8_t[]){240, 190, 136}, (uint8_t[]){15, 65, 119});
	test((uint8_t[]){240, 190, 153}, (uint8_t[]){15, 65, 102});
	test((uint8_t[]){240, 190, 170}, (uint8_t[]){15, 65, 85});
	test((uint8_t[]){240, 190, 187}, (uint8_t[]){15, 65, 68});
	test((uint8_t[]){240, 190, 204}, (uint8_t[]){15, 65, 51});
	test((uint8_t[]){240, 190, 221}, (uint8_t[]){15, 65, 34});
	test((uint8_t[]){240, 190, 238}, (uint8_t[]){15, 65, 17});
	test((uint8_t[]){240, 200, 0}, (uint8_t[]){15, 55, 255});
	test((uint8_t[]){240, 200, 17}, (uint8_t[]){15, 55, 238});
	test((uint8_t[]){240, 200, 34}, (uint8_t[]){15, 55, 221});
	test((uint8_t[]){240, 200, 51}, (uint8_t[]){15, 55, 204});
	test((uint8_t[]){240, 200, 68}, (uint8_t[]){15, 55, 187});
	test((uint8_t[]){240, 200, 85}, (uint8_t[]){15, 55, 170});
	test((uint8_t[]){240, 200, 102}, (uint8_t[]){15, 55, 153});
	test((uint8_t[]){240, 200, 119}, (uint8_t[]){15, 55, 136});
	test((uint8_t[]){240, 200, 136}, (uint8_t[]){15, 55, 119});
	test((uint8_t[]){240, 200, 153}, (uint8_t[]){15, 55, 102});
	test((uint8_t[]){240, 200, 170}, (uint8_t[]){15, 55, 85});

	return 0;
}
