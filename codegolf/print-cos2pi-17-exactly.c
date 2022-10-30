/*

One way to construct a regular heptadecagon starts with drawing a horizontal line of length 1 from the center to a vertex.
Then the distance along that line from the center to the second vertex is cos(2π/17). All other vertices are easy to get.

The goal of this challenge is to print (or produce in any other conventional way) an ASCII math expression involving the operations +, -, *, /, sqrt() and the natural numbers, which gives cos(2π/17) when evaluated.
The power operator is not allowed: e.g. sqrt(17) cannot be written as 17^(1/2).

For example (formula taken from Wikipedia):

1/16*(
    -1+
    sqrt(17)+
    sqrt(34-2*sqrt(17))+
    2*sqrt(
        17+
        3*sqrt(17)-
        sqrt(34-2*sqrt(17))-
        2*sqrt(34+2*sqrt(17))
    )
)

Whitespace doesn't matter. The length and complexity of the expression doesn't matter, as long as it's syntactically correct (as defined above) and numerically equivalent to cos(2π/17).

Built-in functions are allowed.

*/

#define _XOPEN_SOURCE
#include <stdio.h>
#include <math.h>

int
main(void)
{
	double a, b;

	a = cos(2 * M_PI / 17);
	b = (-1 + sqrt(17) + sqrt(34 - 2 * sqrt(17)) + 2 * sqrt(17 + 3 * sqrt(17) - sqrt(34 - 2 * sqrt(17)) - 2 * sqrt(34 + 2 * sqrt(17)))) / 16.0;
	printf("%f %f\n", a, b);

	return 0;
}
