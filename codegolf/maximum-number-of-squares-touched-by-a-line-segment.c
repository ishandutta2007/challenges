/*

Consider a square grid on the plane, with unit spacing. A line segment of integer length L

is dropped at an arbitrary position with arbitrary orientation. The segment is said to "touch" a square if it intersects the interior of the square (not just its border).
The challenge

What is the maximum number of squares that the segment can touch, as a function of L?

Examples

L=3  

The answer is 7, as illustrated by the blue segment in the left-hand side image (click for a larger view). The red and yellow segments only touch 6 and 4 squares respectively. The purple segment touches 0

squares (only the interiors count).

L=5  
The answer is 9. The dark red segment in the right-hand side image touches 6 squares (note that 52=32+42), whereas the green one touches 8. The light blue segment touches 9 squares, which is the maximum for this L.

enter image description here

Additional rules

    The input L

is a positive integer. The algorithm should theoretically work for arbitrarily large L.

In practice it is acceptable if the program is limited by time, memory, or data-type size.
Input and output are flexible as usual. Programs or functions are allowed, in any programming language. Standard loopholes are forbidden.
Shortest code in bytes wins.

Test cases

Here are the outputs for L = 1, 2, ..., 50 (with L increasing left to right, then down):

 3    5    7    8    9   11   12   14   15   17
18   19   21   22   24   25   27   28   29   31
32   34   35   36   38   39   41   42   43   45
46   48   49   51   52   53   55   56   58   59 
60   62   63   65   66   68   69   70   72   73

*/

#include <stdio.h>
#include <math.h>

// https://oeis.org/A346232
unsigned
squares(unsigned L)
{
	if (L == 0)
		return 0;
	return sqrt(2 * L * L - 2) + 3;
}

int
main(void)
{
	unsigned i, j, v;

	v = 0;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 10; j++)
			printf("%-4d", squares(++v));
		printf("\n");
	}

	return 0;
}
