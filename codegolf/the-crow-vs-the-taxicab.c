/*

Imagine travelling to a point lying A miles away horizontally and B miles away vertically from your current position.
Or in other words, travelling from (0, 0) to point (a, b). How far would you need to end up travelling?
This seems like a straightforward question, but the answer depends on who you ask.
If you're a crow, and you can travel as the crow flies, the distance travelled is just the Euclidean distance to (a, b). This is

sqrt(a^2 + b^2)

But if you're just a boring human, you don't really want to walk that far, so you'll need to take a taxi.
Most taxis wont drive in a straight line towards your destination because they generally try to stay on the roads.
So the real distance you'll end up travelling is the sum of the vertical distance and the horizontal distance. Or the formula is:

abs(a) + abs(b)

This is called the Taxicab Distance. This picture nicely demonstrates the difference between the two:

enter image description here

To travel to (6, 6), a crow can just fly on the green line, and this gives a distance of 6 * sqrt(2) or roughly 8.49. A taxicab can take the red, blue or yellow paths, but they will all take 12.

This leads to the real question I'm asking. If a crow and a taxicab both leave from point (0, 0), and travel to point (a, b), how much longer is the taxicab's path? Or, in more math jargon,

Given a two dimensional vector, determine the difference between the norm2 of the vector, and the norm1 of the vector.

You must write the shortest possible program or function to answer this question.
You may choose to take 'a' and 'b' as two separate inputs, or as a two item tuple.
You can take input and output in any reasonable format. If the difference is a non integer, you must be accurate to at least two decimal places.

You can always assume that 'a' and 'b' will be integers, and that they won't both be 0. (Though it is possible that either one of them will be zero)

As usual, standard loopholes apply and try to make your program as short as possible, counted in bytes.

I will upvote any answer that posts an explanation of how the code works, and demonstrates any cool tricks used to save bytes.

Here are some examples for you to test your code on:

#input    #output
3, 4      2
-3, 4     2
-3, -4    2
6, 6      3.51
42, 0     0
10, 10    5.86
3, 3      1.76
Have fun golfing! :)

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
ctdiff(double x, double y)
{
	return fabs(hypot(x, y) - (fabs(x) + fabs(y)));
}

void
test(double x, double y, double r)
{
	double d;

	d = ctdiff(x, y);
	printf("%f\n", d);
	assert(fabs(d - r) < 1e-2);
}

int
main(void)
{
	test(3, 4, 2);
	test(-3, 4, 2);
	test(-3, -4, 2);
	test(6, 6, 3.51);
	test(42, 0, 0);
	test(10, 10, 5.86);
	test(3, 3, 1.76);

	return 0;
}
