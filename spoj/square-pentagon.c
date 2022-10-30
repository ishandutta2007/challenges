/*

Garima is a Geometry enthusiast, she loves solving geometry puzzles and creating new puzzles by herself. One fine day she was trying to arrange some "dots" (.) in a form of square.

As shown in figure below:

Square Numbers created using dots

She observes that the number of dots needed to create a square of size 'n' is n*n i.e. 1, 4, 9, 16 , 25, and so on.

She wanted to make larger polygons with these dots, so she started making pentagons, as shown in figure below.

Pentagonal Numbers created using dots

Being a bright Mathematics student, she is quick to figure out that to create pentagon of size 'n' she needs (3*n*n - n)/2 dots i.e. 1, 5, 12, 22, 35, and so on.

Now she wonders, if she can ever use the same number of dots to make a square as well as a pentagon, of different sizes of course.

She tries a few numbers, but cannot think of any number other than 1, which can make both square and pentagon.

She tried a lot of numbers, now she thinks, such numbers might be too big, so she asks her programmer friend to write a program to find such numbers which can arranged as both square and pentagon.

Her programmer friend, understanding that these numbers can be big, promises her to find such numbers modulo 3367900313, a random big enough prime number.

Assume that you are her friend, now help her to find these numbers!

Input

The first line contains a single positive integer 't', describing the number of test cases.

Next 't' lines contains postive integer 'r', such that 1 <= r <= 2500 . Also, 1<= t <= 100.

Output

For each test case, find out rth number, when considered in sorted ascending order, which can be arranged as a pentagon as well as a square, as described in the problem

Print a single line corresponding to each test case. Since the answers can be long, so don't forget to take modulo 3367900313

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

// https://oeis.org/A046172
uvlong
seq(uvlong n)
{
	uvlong a, b, c;
	uvlong i;

	if (n < 1)
		return 0;

	a = 1;
	b = 81;
	for (i = 1; i < n; i++) {
		c = (98 * b) - a - 16;
		a = b;
		b = c;
	}
	return a;
}

uvlong
sqpent(uvlong n)
{
	static const uvlong m = 3367900313ull;
	uvlong v;

	v = seq(n);
	v = ((3 * v * v) - v) / 2;
	return v % m;
}

int
main(void)
{
	assert(sqpent(1) == 1);
	assert(sqpent(2) == 9801);

	return 0;
}
