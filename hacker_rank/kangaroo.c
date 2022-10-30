/*

You are choreographing a circus show with various animals.
For one act, you are given two kangaroos on a number line ready to jump in the positive direction (i.e, toward positive infinity).

The first kangaroo starts at location x1 and moves at a rate of v1 meters per jump.
The second kangaroo starts at location x2 and moves at a rate of v2 meters per jump.
You have to figure out a way to get both kangaroos at the same location at the same time as part of the show.
If it is possible, return YES, otherwise return NO.

For example, kangaroo 1 starts at x1=2 with a jump distance 1 and kangaroo 2 starts at x2=1 with a jump distance of v2=2. 
After one jump, they are both at x=3, (x1+v1=2+1, x2+v2=1+2), so our answer is YES.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define max(a, b) ((a) > ((b)) ? (a) : (b))
#define min(a, b) ((a) < ((b)) ? (a) : (b))

int
gcd(int a, int b, int *x, int *y)
{
	int x1, y1, d;

	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}
	d = gcd(b % a, a, &x1, &y1);
	*x = y1 - (b / a) * x1;
	*y = x1;
	return d;
}

const char *
kangaroo1(int x1, int v1, int x2, int v2, int *step)
{
	int a, b, c, d, s;

	*step = -1;
	a = x1;
	b = x2;
	d = INT_MAX;
	s = -1;
	for (;;) {
		s++;
		if (a == b)
			break;

		a += v1;
		b += v2;

		c = abs(b - a);
		if (c < d)
			d = c;
		else
			return "NO";
	}

	*step = s;
	return "YES";
}

// this problem can be viewed as a linear diophantine equations of 2 variables
// https://brilliant.org/wiki/linear-diophantine-equations-one-equation/

// can see this by doing the following
// write equation as
// x1 + v1n = x2 + v2m
// v1n - v2m = x2 - x1
// ax + by = c (diophantine form)
const char *
kangaroo2(int x1, int v1, int x2, int v2, int *step)
{
	int a, b, c, d, m, x, y;

	*step = -1;

	// a = v1
	// b = v2
	// c = x2 - x1
	// if gcd(a, b) does not divide c, then there
	// are no integer solutions
	c = x2 - x1;
	d = gcd(abs(v1), abs(v2), &x, &y);
	if (d == 0 || c % d != 0)
		return "NO";

	// now that we get here, we can solve for a initial
	// x and y that satisfy ax + by = c
	x *= c / d;
	y *= c / d;
	if (v1 < 0)
		x = -x;
	if (v2 < 0)
		y = -y;

	// we use the fact of what we got for initial x and y
	// now we can use this to solve for m, m will be when x = y
	// x + mv2/d = -y + mv1/d
	m = (x + y) * d / (v1 - v2);
	a = x + m * v2 / d;
	b = -y + m * v1 / d;

	// if we plug in m and a does not equal to b, then there is no time t
	// where the two kangaroos will meet
	// if there a solution, it also has to be positive since we are moving
	// forward in time
	if (a != b || a < 0)
		return "NO";

	*step = a;
	return "YES";
}

void
kangaroo(int x1, int v1, int x2, int v2)
{
	const char *r1, *r2;
	int s1, s2;

	r1 = kangaroo1(x1, v1, x2, v2, &s1);
	r2 = kangaroo2(x1, v1, x2, v2, &s2);
	printf("kangaroo(x1 = %d, v1 = %d, x2 = %d, v2 = %d) -> (%s, %d) (%s, %d)\n",
	       x1, v1, x2, v2, r1, s1, r2, s2);
	if (strcmp(r1, r2) != 0)
		printf("ERROR: mismatch calculation!\n");
}

int
main(void)
{
	kangaroo(2, 1, 1, 2);
	kangaroo(0, 3, 4, 2);
	kangaroo(1, 0, 100, 0);
	kangaroo(1, 1, 100, 0);
	srand(time(NULL));
	for (int i = 0; i < 10000; i++) {
		const int N = 1000000;
		kangaroo(rand() % N, rand() % N, rand() % N, rand() % N);
	}
	return 0;
}
