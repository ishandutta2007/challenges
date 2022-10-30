/*

Everyone knows the Fibonacci sequence:
You take a square, attach an equal square to it, then repeatedly attach a square whose side length is equal to the largest side length of the resulting rectangle.
The result is a beautiful spiral of squares whose sequence of numbers is the Fibonacci sequence:

https://i.stack.imgur.com/yYPNK.png

But, what if we didn't want to use squares?

If we use equilateral triangles—instead of squares—in a similar fashion, we get an equally beautiful spiral of triangles and a new sequence: the Padovan sequence, aka A000931:

https://i.stack.imgur.com/qNdom.png

Task:

Given a positive integer, N, output aN, the Nth term in the Padovan sequence OR the first N terms.

Assume that the first three terms of the sequence are all 1. Thus, the sequence will start as follows:
1,1,1,2,2,3,...

Input:

Any positive integer N≥0

Invalid input does not have to be taken into account

Output:

The Nth term in the Padovan sequence OR the first N terms of the Padovan sequence.

If the first N terms are printed out, the output can be whatever is convenient (list/array, multi-line string, etc.)

Can be either 0-indexed or 1-indexed

Test Cases:
(0-indexed, Nth term)

Input | Output
--------------
0     | 1
1     | 1
2     | 1
4     | 2
6     | 4
14    | 37
20    | 200
33    | 7739
(1-indexed, first N terms)

Input | Output
--------------
1     | 1
3     | 1,1,1
4     | 1,1,1,2
7     | 1,1,1,2,2,3,4
10    | 1,1,1,2,2,3,4,5,7,9
12    | 1,1,1,2,2,3,4,5,7,9,12,16
Rules:

This is code-golf: the fewer bytes, the better!

Standard loopholes are forbidden.

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

// https://oeis.org/A000931
// modified to have different initial conditions
uvlong
seq(uvlong n)
{
	if (n <= 2)
		return 1;
	return seq(n - 2) + seq(n - 3);
}

int
main(void)
{
	assert(seq(0) == 1);
	assert(seq(1) == 1);
	assert(seq(2) == 1);
	assert(seq(4) == 2);
	assert(seq(6) == 4);
	assert(seq(14) == 37);
	assert(seq(20) == 200);
	assert(seq(33) == 7739);

	return 0;
}
