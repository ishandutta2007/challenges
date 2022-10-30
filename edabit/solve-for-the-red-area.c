/*

This problem went viral in China, spreading on Weibo. The problem is to solve for the area shown in red between the semicircle and the rectangle’s diagonal.

Create a function that takes a number r as an the length of the side and returns the area rounded to the nearest thousandth.
Watch the video in the Resources tab for the answer to the problem.

Notes

The input r is always a valid number.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
redarea(double r)
{
	if (r < 0)
		return 0;

	// https://mindyourdecisions.com/blog/2019/04/18/viral-math-problem-from-china-solve-for-the-area/
	return r * r * (0.4 - 0.5 * atan(0.75));
}

int
main(void)
{
	static const double tab[] = {
		25,
		94,
		36,
		42,
		39,
		36,
		28,
		33,
		0,
		68,
		15,
		55,
		9,
		67,
		4,
		30,
		99,
		28,
		48,
		13,
		76,
		3,
		33,
		37,
		13,
		14,
		71,
		60,
		8,
		70,
		92,
		29,
		1,
		17,
		34,
		20,
		31,
		14,
		97,
		62,
		37,
		46,
		65,
		77,
		50,
		78,
		93,
		38,
		51,
		28,
	};
	size_t i;

	for (i = 0; i < nelem(tab); i++)
		printf("%.0f %.3f\n", tab[i], redarea(tab[i]));
	return 0;
}
