/*

Three kangaroos are playing in the desert.
They are playing on a number line, each occupying a different integer.
In a single move, one of the outer kangaroos jumps into the space between the other two.
At no point may two kangaroos occupy the same position. Help them play as long as possible.

Input

Three integers A, B and C (0<A<B<C<100), the initial positions of the kangaroos.

Output

Output the largest number of moves the kangaroos can make.

*/

#include <assert.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int
moves(int a, int b, int c)
{
	return max(b - a, c - b) - 1;
}

int
main(void)
{
	assert(moves(2, 3, 5) == 1);
	assert(moves(3, 5, 9) == 3);

	return 0;
}
