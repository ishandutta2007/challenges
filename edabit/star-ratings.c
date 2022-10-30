/*

Given an array of five values, calculate the average star rating, rounded to two decimal places.
The array contains user votes per star, so the first element [0] contains the number of 1-star ratings and the last element [4], the number of 5-star ratings.

Return the average score in [brackets], followed by a space and asterisks' * to represent the star rating, rounded to the nearest whole star.

Examples

starRating([55, 67, 98, 115, 61]) ➞ "[3.15] ***"

starRating([0, 2, 0, 1, 23]) ➞ "[4.73] *****"

starRating([16, 17, 23, 40, 45]) ➞ "[3.57] ****"

Notes

Round stars to whole stars.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char *
star(int a[5], char *b)
{
	size_t i, j, l;
	double r, p;

	r = p = 0;
	for (i = 0; i < 5; i++) {
		r += a[i] * (i + 1);
		p += a[i];
	}

	r = (p) ? r / p : r;
	j = rint(r);
	l = 0;
	l += sprintf(b + l, "[%.2f]%s", r, (j) ? " " : "");
	for (i = 0; i < j; i++)
		l += sprintf(b + l, "*");
	return b;
}

void
test(int a[5], const char *r)
{
	char b[128];

	assert(!strcmp(star(a, b), r));
}

int
main(void)
{
	int a1[] = {55, 67, 98, 115, 61};
	int a2[] = {75, 79, 50, 55, 25};
	int a3[] = {0, 2, 0, 1, 23};
	int a4[] = {16, 17, 23, 40, 45};
	int a5[] = {175, 790, 550, 1550, 1245};
	int a6[] = {0, 0, 0, 0, 5};
	int a7[] = {6713, 7809, 5350, 5005, 6250};
	int a8[] = {80, 79, 82, 155, 325};
	int a9[] = {0, 0, 0, 0, 0};

	test(a1, "[3.15] ***");
	test(a2, "[2.56] ***");
	test(a3, "[4.73] *****");
	test(a4, "[3.57] ****");
	test(a5, "[3.67] ****");
	test(a6, "[5.00] *****");
	test(a7, "[2.88] ***");
	test(a8, "[3.79] ****");
	test(a9, "[0.00]");

	return 0;
}
