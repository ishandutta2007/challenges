/*

Mubashir is getting old but he wants to celebrate his 20th or 21st birthday only. It is possible with some basic maths skills. He just needs to select the correct number base with your help!

For example, if his current age is 22, that's exactly 20 - in base 11. Similarly, 65 is exactly 21 - in base 32 and so on.

Create a function that takes his current $age and returns the given age 20 (or 21) years, with number base in the format specified in the below examples.
Examples

happyBirthday(22) ➞ "Mubashir is just 20, in base 11!"

happyBirthday(65) ➞ "Mubashir is just 21, in base 32!"

happyBirthday(83) ➞ "Mubashir is just 21, in base 41!"

Notes

Given age will always be greater than 21.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

/*

a*b^1 + c*b^0 = n 
We know n, a, and c, need to solve for b.

Simplify equation to
a*b + c = n

a=2
c=1 or 0
b=(n-c)/a

Since a is 2, we need n-c to be divisible by 2.
We can set c=1 or c=0 to enforce n to be even and then solve for b to get the base.

*/

char *
birthday(unsigned n, char *b)
{
	unsigned x, y;

	if (n <= 21)
		return NULL;

	x = 20 + (n & 1);
	y = (n - (n & 1)) >> 1;
	sprintf(b, "Mubashir is just %u, in base %u!", x, y);
	return b;
}

void
test(unsigned n, const char *r)
{
	char b[128];

	birthday(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(32, "Mubashir is just 20, in base 16!");
	test(39, "Mubashir is just 21, in base 19!");
	test(22, "Mubashir is just 20, in base 11!");
	test(65, "Mubashir is just 21, in base 32!");
	test(83, "Mubashir is just 21, in base 41!");
	test(95, "Mubashir is just 21, in base 47!");
	test(100, "Mubashir is just 20, in base 50!");
	test(120, "Mubashir is just 20, in base 60!");
	test(147, "Mubashir is just 21, in base 73!");

	return 0;
}
