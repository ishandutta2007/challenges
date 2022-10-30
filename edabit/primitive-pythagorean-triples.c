/*

A Pythagorean triple is a set of three integer numbers that form a right triangle. The sum of the squares of the two smaller numbers should equal the square of the largest number.
Given three numbers a, b and c (c being the largest):

a^2 + b^2 = c^2

Furthermore, a Pythagorean triple is said to be primitive if the three numbers are pairwise coprime -
that is, the greatest common prime factor between any two numbers is 1.

Create a function that takes a list of three numbers (unordered) and returns True
if the numbers constitute a primitive Pythagorean triple, False otherwise.

*/

#include <assert.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define mid(a, b, c) max(min(a, b), min(max(a, b), c))

int
gcd(int a, int b)
{
	int t;
	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int
isppt(int x[3])
{
	int a, b, c, d;

	a = min(x[0], min(x[1], x[2]));
	b = mid(x[0], x[1], x[2]);
	c = max(x[0], max(x[1], x[2]));
	d = gcd(a, b);
	d = gcd(d, c);
	return d == 1 && a * a + b * b == c * c;
}

int
main(void)
{
	int x1[] = {4, 5, 3};
	int x2[] = {7, 12, 13};
	int x3[] = {39, 15, 36};
	int x4[] = {77, 36, 85};
	int x5[] = {35, 28, 21};
	int x6[] = {80, 89, 39};

	assert(isppt(x1) == 1);
	assert(isppt(x2) == 0);
	assert(isppt(x3) == 0);
	assert(isppt(x4) == 1);
	assert(isppt(x5) == 0);
	assert(isppt(x6) == 1);

	return 0;
}
