/*

Given a known number of unique items, how many ways could we arrange them in a row?

Create a function that takes an integer n and returns the number of digits of the number of possible permutations for n unique items.
For instance, 5 unique items could be arranged in 120 unique ways. 120 has 3 digits, hence the integer 3 is returned.

Examples

no_perms_digits(0) ➞ 1

no_perms_digits(1) ➞ 1

no_perms_digits(5) ➞ 3

no_perms_digits(8) ➞ 5

Notes

This challenge requires some understanding of combinatorics.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef unsigned long long uvlong;

// https://oeis.org/A034886
uvlong
perm(uvlong n)
{
	uvlong i;
	double r;

	if (n <= 1)
		return 1;

	r = 0;
	for (i = 1; i <= n; i++)
		r += log10(i);
	return ceil(r);
}

int
main(void)
{
	assert(perm(0) == 1);
	assert(perm(1) == 1);
	assert(perm(2) == 1);
	assert(perm(3) == 1);
	assert(perm(4) == 2);
	assert(perm(5) == 3);
	assert(perm(6) == 3);
	assert(perm(7) == 4);
	assert(perm(8) == 5);
	assert(perm(9) == 6);
	assert(perm(10) == 7);
	assert(perm(11) == 8);
	assert(perm(12) == 9);
	assert(perm(13) == 10);
	assert(perm(14) == 11);
	assert(perm(15) == 13);
	assert(perm(16) == 14);
	assert(perm(17) == 15);
	assert(perm(18) == 16);
	assert(perm(19) == 18);
	assert(perm(25) == 26);
	assert(perm(50) == 65);
	assert(perm(75) == 110);
	assert(perm(100) == 158);
	assert(perm(125) == 210);
	assert(perm(150) == 263);
	assert(perm(175) == 319);
	assert(perm(200) == 375);
	assert(perm(225) == 434);
	assert(perm(250) == 493);
	assert(perm(275) == 554);
	assert(perm(300) == 615);
	assert(perm(325) == 677);
	assert(perm(350) == 741);
	assert(perm(375) == 805);
	assert(perm(400) == 869);
	assert(perm(425) == 935);
	assert(perm(450) == 1001);
	assert(perm(475) == 1067);
	assert(perm(500) == 1135);
	assert(perm(525) == 1202);
	assert(perm(550) == 1271);
	assert(perm(575) == 1339);
	assert(perm(600) == 1409);
	assert(perm(625) == 1478);
	assert(perm(650) == 1548);
	assert(perm(675) == 1619);
	assert(perm(700) == 1690);
	assert(perm(725) == 1761);
	assert(perm(750) == 1833);
	assert(perm(775) == 1905);
	assert(perm(800) == 1977);
	assert(perm(825) == 2050);
	assert(perm(850) == 2123);
	assert(perm(875) == 2197);
	assert(perm(900) == 2270);
	assert(perm(925) == 2344);
	assert(perm(950) == 2419);
	assert(perm(975) == 2493);

	return 0;
}
