/*

Input: An RGBA hex color c (ex. FFFF00FF) and an integer > 0 and < 1000 n (ex. 200).

Output: Raw bytes of a PNG file such that when the output is saved to a file and opened in an image viewer, an n by n image filled with the color c is displayed.

Specification: Your program should output exactly:

a PNG header (89504E470D0A1A0A in hex)
an IHDR chunk containing these specifications:
width: the previous input n
height: the previous input n
bit depth: 8 (RGBA)
color type: 6 (truecolor with alpha)
compression method: 0
filter method: 0
interlace method: 0
one or more IDAT chunks containing the image data (a solid image of color previously input c); may be compressed or uncompressed
an IEND image end chunk
Further details available on Wikipedia, on the W3 site, or via a Google search.

Restrictions:

You may not use any image libraries or functions designed to work with images of any kind.
Your program must run in under 3 minutes and output a file under 10 MB for all inputs (sanity check).
This is code-golf, so the shortest code in bytes will win!

*/

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "stb_image_write.h"

void
fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

void
usage(void)
{
	fprintf(stderr, "usage: <color> <size> <output>\n");
	exit(2);
}

int
main(int argc, char *argv[])
{
	long color, size, x, y;
	unsigned char *pixels, *p;

	if (argc != 4)
		usage();

	color = strtol(argv[1], NULL, 0);
	size = strtol(argv[2], NULL, 0);
	if (color < 0 || color > 0xFFFFFFFFL || size < 0 || size > 1000)
		fatal("Invalid arguments");

	pixels = calloc(size * 4, size);
	if (!pixels)
		fatal("Failed to allocate memory");

	p = pixels;
	for (y = 0; y < size; y++) {
		for (x = 0; x < size; x++) {
			*p++ = color & 0xff;
			*p++ = (color >> 8) & 0xff;
			*p++ = (color >> 16) & 0xff;
			*p++ = (color >> 24) & 0xff;
		}
	}

	if (stbi_write_png(argv[3], size, size, 4, pixels, size * 4) == 0)
		fatal("Failed to write image");

	free(pixels);
	return 0;
}
