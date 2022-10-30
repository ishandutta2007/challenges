/*

This is a method commonly taught in primary schools, used to verify the correctness of an operation; usually (as in this exercise) the multiplication.

Every number involved in the multiplication is replaced by its digital root (reiterated sum of its digits until a single-digit number is obtained).
After this, the digital roots of factors are multiplied, and again this result is reduced to the digital root.
If the digit obtained is different from the result's digital root the operation is surely wrong,
if it is equal the operation can be correct with a possibility out of nine to be a false positive.

Given two factors and a result, implement a function that returns a string in the format:

    "x, x, x, x = Result!", with x being the digital roots (a, b, r, and a*b in the order).
    Result! being "Correct!" if the last two digits are the same and the result is correct.
    "False Positive!" if the last two digits are the same but the result is wrong.
    "Wrong!" if the last two digits are different.

*/

#include <stdio.h>

long
reducenines(long x)
{
	long v;

	v = 0;
	while (x) {
		v = (v + (x % 10)) % 9;
		x /= 10;
	}
	return (v == 0) ? 9 : v;
}

char *
castoutnines(long x, long y, long z, char *b, size_t n)
{
	const char *r;
	long e, w;

	e = x * y == z;
	x = reducenines(x);
	y = reducenines(y);
	z = reducenines(z);
	w = reducenines(x * y);
	r = (w == z) ? ((e) ? "Correct" : "False positive") : "Wrong";
	snprintf(b, n, "%ld,%ld,%ld,%ld = %s!", x, y, z, w, r);
	return b;
}

int
main(void)
{
	char b[80];

	printf("%s\n", castoutnines(467, 78, 36426, b, sizeof(b)));
	printf("%s\n", castoutnines(467, 78, 36425, b, sizeof(b)));
	printf("%s\n", castoutnines(467, 78, 129, b, sizeof(b)));
	printf("%s\n", castoutnines(9, 9, 81, b, sizeof(b)));
	printf("%s\n", castoutnines(9, 9, 666, b, sizeof(b)));
	printf("%s\n", castoutnines(9, 9, 51, b, sizeof(b)));
	printf("%s\n", castoutnines(59714, 24339, 1453379046, b, sizeof(b)));
	printf("%s\n", castoutnines(59714, 24339, 153379046, b, sizeof(b)));
	printf("%s\n", castoutnines(1902, 1964, 3735519, b, sizeof(b)));
	printf("%s\n", castoutnines(12986, 4320, 56099520, b, sizeof(b)));
	printf("%s\n", castoutnines(12986, 4320, 56099529, b, sizeof(b)));
	printf("%s\n", castoutnines(12986, 4320, 56099521, b, sizeof(b)));
	printf("%s\n", castoutnines(123, 456, 789, b, sizeof(b)));
	printf("%s\n", castoutnines(123, 456, 999, b, sizeof(b)));
	return 0;
}
