/*

Type conversion. There are a number of different formats for representing color. RGB format specifies the level of red (R), green (G), and blue (B) on an integer scale from 0 to 255: It is the primary format for LCD displays, digital cameras, and web pages. CMYK format specifies the level of cyan (C), magenta (M), yellow (Y), and black (K) on a real scale of 0.0 to 1.0: It is the primary format for publishing books and magazines. Write a program RGBtoCMYK.java that reads in three integers red, green, and blue from the command line and prints out equivalent CMYK parameters. The mathematical formulas for converting from RGB to an equivalent CMYK color are:

    RGB to CMYK formula

Hint. Math.max(x, y) returns the maximum of x and y.

    % java RGBtoCMYK 75 0 130       // indigo
    cyan    = 0.423076923076923
    magenta = 1.0
    yellow  = 0.0
    black   = 0.4901960784313726

If all three red, green, and blue values are 0, the resulting color is black (0 0 0 1).

*/

// https://www.rapidtables.com/convert/color/cmyk-to-rgb.html

#include <stdint.h>
#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct {
	double c, m, y, k;
} cmyk_t;

typedef struct {
	uint8_t r, g, b;
} rgb_t;

cmyk_t
rgb2cmyk(rgb_t c)
{
	double dr, dg, db, w;

	dr = c.r / 255.0;
	dg = c.g / 255.0;
	db = c.b / 255.0;
	w = max(dr, max(dg, db));
	if (w == 0)
		return (cmyk_t){ 0, 0, 0, 1 };

	return (cmyk_t){
		(w - dr) / w,
		(w - dg) / w,
		(w - db) / w,
		1 - w,
	};
}

rgb_t
cmyk2rgb(cmyk_t c)
{
	return (rgb_t){
		255 * (1 - c.c) * (1 - c.k),
		255 * (1 - c.m) * (1 - c.k),
		255 * (1 - c.y) * (1 - c.k),
	};
}

void
test(rgb_t c)
{
	cmyk_t p;
	rgb_t q;

	p = rgb2cmyk(c);
	q = cmyk2rgb(p);
	printf("cyan    = %f\n", p.c);
	printf("magenta = %f\n", p.m);
	printf("yellow  = %f\n", p.y);
	printf("black   = %f\n", p.k);
	printf("red     = %d\n", q.r);
	printf("green   = %d\n", q.g);
	printf("blue    = %d\n", q.b);
	printf("\n");
}

int
main(void)
{
	test((rgb_t){ 75, 0, 130 });
	test((rgb_t){ 0, 0, 0 });
	test((rgb_t){ 255, 255, 255 });

	return 0;
}
