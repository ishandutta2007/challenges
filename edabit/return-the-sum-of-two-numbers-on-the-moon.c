/*

When two numbers are added together, the strange Lunar arithmetic is used on the Moon. The Lunar sum of two numbers is not determined by the sum of their individual digits, but by the highest digit of the two taken into account at each step, in columnar form.

2  4  6  +
3  1  7  =
--------
3  4  7

// 3 > 2 | 4 > 1 | 7 > 6

1  3  4  +
   5  4  =
--------
1  5  4

//  1 > 0 | 5 > 3 | 4 == 4
// Blank spots in the columnar form are equals to 0

   2  0  +
1  4  0  =
-------
1  4  0

// 1 > 0 | 4 > 2 | 0 == 0

Given two positive integers number1 and number2, implement a function that returns their sum as a new integer.

Notes

The given numbers will be always positive integers: no exceptions to handle.

*/

#include <stdio.h>

unsigned
max(unsigned x, unsigned y)
{
	return (x > y) ? x : y;
}

unsigned
lunarsum(unsigned x, unsigned y)
{

	unsigned s, t, z;

	for (s = z = 0;; s *= 10) {
		s += max(x % 10, y % 10);
		x /= 10;
		y /= 10;
		if (x == 0 && y == 0)
			break;
		if (s == 0)
			z++;
	}

	for (t = 0;; t *= 10) {
		t += s % 10;
		s /= 10;
		if (s == 0)
			break;
	}

	for (s = 0; s < z; s++)
		t *= 10;

	return t;
}

int
main(void)
{
	printf("%u\n", lunarsum(246, 317));
	printf("%u\n", lunarsum(134, 54));
	printf("%u\n", lunarsum(20, 140));
	printf("%u\n", lunarsum(1, 1));
	printf("%u\n", lunarsum(198, 44));
	printf("%u\n", lunarsum(36602, 696));
	printf("%u\n", lunarsum(91, 8823));
	printf("%u\n", lunarsum(123, 8));
	printf("%u\n", lunarsum(2289, 98211285));
	printf("%u\n", lunarsum(9, 11));
	printf("%u\n", lunarsum(11, 22));
	printf("%u\n", lunarsum(10000, 11));
	printf("%u\n", lunarsum(10000, 9));
	printf("%u\n", lunarsum(0, 9));
	printf("%u\n", lunarsum(0, 0));
	printf("%u\n", lunarsum(3, 10));
	printf("%u\n", lunarsum(31, 10042));
	return 0;
}
