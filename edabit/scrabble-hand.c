/*

Given an array of scrabble tiles, create a function that outputs the maximum possible score a player can achieve by summing up the total number of points for all the tiles in their hand. Each hand contains 7 scrabble tiles.

Here's an example hand:

[
  { "tile" => "N", "score" => 1 },
  { "tile" => "K", "score" => 5 },
  { "tile" => "Z", "score" => 10 },
  { "tile" => "X", "score" => 8 },
  { "tile" => "D", "score" => 2 },
  { "tile" => "A", "score" => 1 },
  { "tile" => "E", "score" => 1 }
]

The players maximum score from playing all these tiles would be 1 + 5 + 10 + 8 + 2 + 1 + 1, or 28.
Examples

maximum_score([
  { "tile" => "N", "score" => 1 },
  { "tile" => "K", "score" => 5 },
  { "tile" => "Z", "score" => 10 },
  { "tile" => "X", "score" => 8 },
  { "tile" => "D", "score" => 2 },
  { "tile" => "A", "score" => 1 },
  { "tile" => "E", "score" => 1 }
]) ➞ 28

maximum_score([
  { "tile" => "B", "score" => 2 },
  { "tile" => "V", "score" => 4 },
  { "tile" => "F", "score" => 4 },
  { "tile" => "U", "score" => 1 },
  { "tile" => "D", "score" => 2 },
  { "tile" => "O", "score" => 1 },
  { "tile" => "U", "score" => 1 }
]) ➞ 15

Notes

Here, each tile is represented as a hash with two keys: tile and score.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int name;
	int score;
} Tile;

int
maxscore(Tile *t, size_t n)
{
	size_t i;
	int r;

	r = 0;
	for (i = 0; i < n; i++) {
		if (t[i].score > 0)
			r += t[i].score;
	}
	return r;
}

int
main(void)
{
	Tile t1[] = {
	    {'N', 1},
	    {'K', 5},
	    {'Z', 10},
	    {'X', 8},
	    {'D', 2},
	    {'A', 1},
	    {'E', 1},
	};
	Tile t2[] = {
	    {'B', 2},
	    {'V', 4},
	    {'F', 4},
	    {'U', 1},
	    {'D', 2},
	    {'O', 1},
	    {'U', 1},
	};
	Tile t3[] = {
	    {'M', 3},
	    {'Q', 10},
	    {'O', 1},
	    {'E', 1},
	    {'E', 1},
	    {'I', 1},
	    {'A', 1},
	};
	Tile t4[] = {
	    {'A', 1},
	    {'E', 1},
	    {'O', 1},
	    {'E', 1},
	    {'E', 1},
	    {'I', 1},
	    {'A', 1},
	};

	assert(maxscore(t1, nelem(t1)) == 28);
	assert(maxscore(t2, nelem(t2)) == 15);
	assert(maxscore(t3, nelem(t3)) == 18);
	assert(maxscore(t4, nelem(t4)) == 7);

	return 0;
}
