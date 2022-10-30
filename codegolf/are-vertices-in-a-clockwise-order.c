/*

Your program must accept as input six numbers, which describe a triangle - for example, the inputs 80, 23, 45, 1, 76, -2 describe a triangle with vertices (80, 23), (45, 1), and (76, -2).
The input must be given as six plain real numbers or as a list of six real numbers, in the order given in the example.
Your task is to figure out whether the triangle's vertices are given in clockwise order.
Assume that the input vertices are not all in one line.
In this case, the vertices are not in clockwise order because the second vertex is to the bottom-left of the first.

This is code-golf, meaning the submission with the shortest number of bytes wins. Good luck!

*/

#include <assert.h>
#include <stdbool.h>

bool
clockwise(int a, int b, int c, int d, int e, int f)
{
	return a * d + b * e + c * f < b * c + a * f + d * e;
}

int
main(void)
{
	assert(!clockwise(80, 23, 45, 1, 76, -2));
	assert(!clockwise(0, 1, -1, 0, 0, 0));
	assert(clockwise(0, 1, 1, 0, 0, -1));

	return 0;
}
