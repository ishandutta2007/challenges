/*

The dihedral group D4 is the symmetry group of the square, that is the moves that transform a square to itself via rotations and reflections.
It consists of 8 elements: rotations by 0, 90, 180, and 270 degrees, and reflections across the horizontal, vertical, and two diagonal axes.

The 8 elements of D4 acting on the square.

The images are all from this lovely page by Larry Riddle.

This challenge is about composing these moves: given two moves, output the move that's equivalent to doing them one after another. For instance, doing move 7 followed by move 4 is the same as doing move 5.

Composition example

Note that switching the order to move 4 then move 7 produces move 6 instead.

The results are tabulated below; this is the Cayley table of the group D4. So for example, inputs 7,4 should produce output 5.

12345678123456781234567823417865341265874123875658671342675831247586241386754231

Challenge

Your goal is to implement this operation in as few bytes as possible, but in addition to the code, you also choose the labels that represent the moves 1 through 8.
The labels must be 8 distinct numbers from 0 to 255, or the 8 one-byte characters their code points represent.

Your code will be given two of the labels from the 8 you've chosen, and must output the label that corresponds to their composition in the dihedral group D4.

Example

Say you've chosen the characters C, O, M, P, U, T, E, R for moves 1 through 8 respectively. Then, your code should implement this table.

COMPUTERCOMPUTERCOMPUTEROMPCERTUMPCOTUREPCOMREUTURTECMPOTEURMCOPEURTOPCMRTEUPOMC

Given inputs E and P, you should output U. Your inputs will always be two of the letters C, O, M, P, U, T, E, R, and your output should always be one of these letters.

Text table for copying

1 2 3 4 5 6 7 8
2 3 4 1 8 7 5 6
3 4 1 2 6 5 8 7
4 1 2 3 7 8 6 5
5 7 6 8 1 3 2 4
6 8 5 7 3 1 4 2
7 6 8 5 4 2 1 3
8 5 7 6 2 4 3 1

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
compose(int a, int b)
{
	static const char *label = "COMPUTER";

	static const int tab[8][8] = {
	    {1, 2, 3, 4, 5, 6, 7, 8},
	    {2, 3, 4, 1, 8, 7, 5, 6},
	    {3, 4, 1, 2, 6, 5, 8, 7},
	    {4, 1, 2, 3, 7, 8, 6, 5},
	    {5, 7, 6, 8, 1, 3, 2, 4},
	    {6, 8, 5, 7, 3, 1, 4, 2},
	    {7, 6, 8, 5, 4, 2, 1, 3},
	    {8, 5, 7, 6, 2, 4, 3, 1},
	};

	const char *p, *q;
	int x, y;

	p = strchr(label, a);
	q = strchr(label, b);
	if (!p || !q)
		return -1;

	x = p - label;
	y = q - label;
	return label[tab[x][y] - 1];
}

int
main(void)
{
	assert(compose('E', 'P') == 'U');
	assert(compose('R', 'P') == 'T');
	assert(compose('O', 'E') == 'U');

	return 0;
}
