/*

Polish mathematician Wacław Sierpiński (1882-1969) described the 2D geometric figure known as the Sierpiński triangle as part of his work on set theory in 1915.
The triangle, which is really an infinite collection of points, can be constructed by the following algorithm:

    The initial shape is a solid triangle.

    Shrink the current shape to half its dimensions (both height and width), and make two more copies of it (giving three copies total).

    Arrange the three copies so that each touches the two others at their corners. Set the current shape to be the union of these three.

    Repeat from step 2.

Here is an illustration of the first few iterations:

As the iterations go to infinity, this process creates an infinite number of connected points. However, consider the case of a finite number of iterations.
If the initial triangle has a circumference of 3, what is the sum of the circumferences of all (black) triangles at a given iteration?
Write a program to find out not the exact circumference, but the number of decimal digits required to represent its integer portion.
That is, find the number of decimal digits required to represent the largest integer that is at most as large as the circumference.

Input

Each test case is a line containing a non-negative integer 0≤n≤10000 indicating the number of iterations.

Output

For each case, display the case number followed by the number of decimal digits required to represent the integer portion of the circumference for the given number of iterations. Follow the format of the sample output.

*/

#include <assert.h>
#include <math.h>

// f(n)      = 3^(n+1) / 2^n
// log(f(n)) = log(3) + n*log(3/2)
int
circumference(int n)
{
	return floor(log10(3) + n * log10(3.0 / 2)) + 1;
}

int
main(void)
{
	assert(circumference(0) == 1);
	assert(circumference(1) == 1);
	assert(circumference(5) == 2);
	assert(circumference(10) == 3);
	assert(circumference(100) == 19);
	return 0;
}
