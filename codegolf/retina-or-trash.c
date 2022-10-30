/*

We live in a wonderful age of technology where we can have beautifully detailed 8K screens on our TVs, and even 2K displays on our phones for our mobile browsing pleasure. We've come a long way in recent years in terms of screen technology.

One of the products of this is a term that was made popular by Apple, Retina. This is referring to the pixel density of the display in question being so high, that at a viewing distance of 10-12 inches away, individual pixels cannot be easily picked out.

Steve Jobs said that the pixel density where this occurs is right around 300 pixels per inch, and they started employing pixel densities in this range on their devices with the Retina buzzword used for advertising.

Pixel density can be calculated by the following formula:

D=sqrt(w^2+h^2)/d

Where d is the diagonal of the screen in inches, w is the number of pixels on the horizontal axis, and h is the number of pixels on the vertical axis.

Your Task
For this task, you'll be using the Retina standard to decide what products are worth buying. Being the modern consumer that you are, when you shop for devices you want to make sure that you're getting a good product, not some device from the 90s!
As such, you want to build a program or function that takes the screen width, height and diagonal length as input or function parameters, and tells you whether the particular screen qualifies as a retina screen (D > 300) by printing to the screen or returning.

Due to your contempt for non-Retina devices, your program or function will output Retina! when the device qualifies, and Trash! when it does not.

You may assume that all of the numbers will be greater than 0. Pixel values for width and height will always be whole numbers.
Screen size may be interpreted in any way, as long as it supports decimals. The input may be in any order you choose, and may also be on up to 3 separate lines.

Example I/O
1920 1080 4.95   -> Retina!
2560 1440 5.96   -> Retina!
1920 1080 10.5   -> Trash!
10 10 0.04       -> Retina!
4096 2160 19(.0) -> Trash!
8192 4320 100.00 -> Trash!
3000 1500 11.18  -> Retina!
180 240 1(.0)    -> Trash!
This is code-golf, so the fewest number of bytes wins.

Here's a Stuck solution, a stack based programming language I'm making:

r;`;/300>"Retina!""Trash!"?

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
quality(double w, double h, double d)
{
	return ((w * w) + (h * h)) / (d * d) > (300.0 * 300.0) ? "Retina!" : "Trash!";
}

void
test(double w, double h, double d, const char *r)
{
	const char *p;

	p = quality(w, h, d);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test(1920, 1080, 4.95, "Retina!");
	test(2560, 1440, 5.96, "Retina!");
	test(1920, 1080, 10.5, "Trash!");
	test(10, 10, 0.04, "Retina!");
	test(4096, 2160, 19, "Trash!");
	test(8192, 4320, 100.00, "Trash!");
	test(3000, 1500, 11.18, "Retina!");
	test(180, 240, 1, "Trash!");

	return 0;
}
