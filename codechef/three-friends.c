/*

There are three friends; let's call them A, B, C. They made the following statements:

    A: "I have x rupees more than B."
	B: "I have y rupees more than C."
	C: "I have z rupees more than A."

You do not know the exact values of x,y,z. Instead, you are given their absolute values, i.e. X=|x|, Y=|y| and Z=|z|.
Note that x, y, z may be negative; "having −r rupees more" is the same as "having r rupees less".

Find out if there is some way to assign amounts of money to A, B, C such that all of their statements are true.

*/

#include <stdio.h>

/*

a = b + x
b = c + y
c = a + z

a - b = x
b - c = y
c - a = z

leads to matrix A
1 -1 0
0 1 -1
1 0 -1
det(A) = 0 means zero or infinite solutions

so we can use any coefficient for a, b, and c and just see if the relation holds for x, y, z

check for relation, for any negative value, since these are in absolute value we need to check
the relation for both positive and negative values and leads to more equalities like so
we can simplify it by just taking the cases where it is positive when other values sign change

x + y = z ->
a - b + b - c

x + z = -y ->
a - b + c - a = c - b

y + z = -x
b - c + c - a = b - a

*/
const char *
sat(int x, int y, int z)
{
	if (x + y == z || x + z == y || y + z == x)
		return "yes";
	return "no";
}

int
main(void)
{
	printf("%s\n", sat(1, 2, 1));
	printf("%s\n", sat(1, 1, 1));
	return 0;
}
