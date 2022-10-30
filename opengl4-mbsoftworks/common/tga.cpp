#include "lib.h"

int save_tga(const char *name, void *data, int width, int height, int bpp)
{
	auto fp = fopen(name, "wb");
	if (!fp)
	{
		printf("Failed to save TGA: %s\n", strerror(errno));
		return -1;
	}

	uint8_t hdr[1 + 1 + 1 + 5 + 10] = { 0 };
	if (bpp == 1)
		hdr[2] = 3;
	else if (bpp == 3)
		hdr[2] = 2;
	hdr[12] = width & 0xff;
	hdr[13] = (width >> 8) & 0xff;
	hdr[14] = height & 0xff;
	hdr[15] = (height >> 8) & 0xff;
	hdr[16] = 8;
	hdr[17] = 0x20;

	fwrite(hdr, sizeof(hdr), 1, fp);
	fwrite(data, width * height * bpp, 1, fp);

	fclose(fp);
	return 0;
}