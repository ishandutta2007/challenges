/*

Description
This challenge is about finding minimums/maximums. The challenge consists of two similar word problems where you will be asked to maximize/minimize a target value.

To make this more of a programming challenge rather than using programming as a calculator, I encourage you to try to find a generic minimize/maximize function rather than just calculating the answer directly.

Challenge
A piece of wire 100 cm in length is bent into the shape of a sector of a circle. Find the angle of the sector that maximizes the area A of the sector. sector_image

A and B are towns 20km and 30km from a straight stretch of river 100km long. Water is pumped from a point P on the river by pipelines to both towns. Where should P be located to minimize the total length of pipe AP + PB? river_image

Challenge Outputs
The accuracy of these answers will depending how much precision you use when calculating them.

~114.6

~40

Credit
This challenge was adapted from The First 25 Years of the Superbrain. If you have an idea for a challenge please share it on r/dailyprogrammer_ideas and there's a good chance we'll use it.

Reference Reading (Hints)
https://en.wikipedia.org/wiki/Golden-section_search

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

/*

A = pi*r^2*(t/2pi)
p = 2*r + t*r

Maximize A

*/
double
sectorangle(double)
{
	return 360 / M_PI;
}

/*

L = sqrt(a^2 + p^2) + sqrt(b^2 + (r-p)^2)
Minimize L

*/
double
pump(double a, double b, double r)
{
	return r * a / (a + b);
}

int
main(void)
{
	printf("%f\n", sectorangle(100));
	printf("%f\n", pump(20, 30, 100));

	return 0;
}
