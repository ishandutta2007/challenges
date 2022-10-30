/*

My coworker and I work on a legacy piece of software that we hate sometimes. Whenever you run it, debug asserts come flying everywhere, and it's never a guarantee that anything will work.
The motivation for this round of code golf came from my coworker saying the following about our software.

"It's like every time you run this program, you're agreeing to some terms of service that says every 17th bit on your hard drive will be turned into a 1"

Goal: Write a program that will make an exact copy of a file and turn every 17th bit of a text file into a 1

You may NOT turn EVERY bit of the file to a 1. i.e. your program must show some intelligence that it is only targeting every 17th bit
You may NOT write to the original file in any way shape or form
The Winner is the smallest program submission at the end of the month
Have fun with this one! Go!

*/

#define _GNU_SOURCE
#include <stdio.h>

void
bitflip(FILE *in, FILE *out, off_t bit)
{
	int i, c;
	off_t p;

	p = 0;
	while ((c = fgetc(in)) != EOF) {
		for (i = 0; i < 8; i++) {
			if (++p == bit) {
				c |= (1 << i);
				p = 0;
			}
		}
		fputc(c, out);
	}
}

int
main(void)
{
	bitflip(stdin, stdout, 17);

	return 0;
}
