/*

Thrilled about his new valid set of pieces, Mirko rushed over to Slavko’s, to find that Slavko too found a set of chess pieces in his attic.
Slavko’s set, miraculously, contains only black pieces. But since neither of them can play chess, they settled on smashing one another senseless with their chessboards.

While Slavko is warming up with a series of stretches, Mirko decided to sabotage Slavko’s chessboard.
An expert in carving wood, he decided to cut Slavko’s chessboard so that it shatters into as many pieces as possible when Slavko attempts to hit Mirko.

Mirko can only make horizontal and vertical cuts (parallel to the sides to the board), edge to edge, and has time to make at most N cuts.

Input

The first line of input contains an integer N (1≤N≤109), the number of cuts Mirko can make.

Output

Output the largest number of pieces Slavko’s chessboard can crash into.

*/

#include <assert.h>

unsigned
cuts(unsigned n)
{
	unsigned r;

	r = (n >> 1) + 1;
	return r * (r + (n & 1));
}

int
main(void)
{
	assert(cuts(1) == 2);
	assert(cuts(3) == 6);
	return 0;
}
