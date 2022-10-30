#include <stdio.h>
#include <stdint.h>

uint16_t
rgb_8_565(uint32_t c)
{
	uint16_t r, g, b;

	r = (c >> 16) & 0xff;
	g = (c >> 8) & 0xff;
	b = c & 0xff;

	r = (r >> 3) << 11;
	g = (g >> 2) << 5;
	b = b >> 3;
	return r | g | b;
}

int
main(void)
{
	uint32_t c;

	for (c = 0x0; c < 0xffffff; c++)
		printf("%06x -> %04x\n", c, rgb_8_565(c));
	return 0;
}
