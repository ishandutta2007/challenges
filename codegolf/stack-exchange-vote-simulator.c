/*

Write a program or function that takes in a string only containing the characters ^ and v (you can assume there will be no other characters).
Read from left to right this string represents the sequence of mouse clicks a single user made while viewing a Stack Exchange question or answer for the first time.

Every ^ represents a click of the upvote button and every v represents a click of the downvote button. (For working examples look slightly left.)

Assume that no voting limitations are in effect so all the clicks are registered correctly.
Print or return:

1 or +1 if the post ends up being upvoted.
0 if the post ends up not being voted on. (-0 and +0 are not valid)
-1 if the post ends up being downvoted.
Posts start with zero net votes from the user and the buttons change the net votes as follows:

Net Votes Before    Button Pressed    Net Votes After
1                   ^                 0
1                   v                 -1
0                   ^                 1
0                   v                 -1
-1                  ^                 1
-1                  v                 0
The shortest code in bytes wins.

Test cases:

[empty string] -> 0
^^ -> 0
^v -> -1
^ -> 1
v -> -1
v^ -> 1
vv -> 0
^^^ -> 1
vvv -> -1
^^^^ -> 0
vvvv -> 0
^^^^^ -> 1
vvvvv -> -1
^^^^^^ -> 0
vvvvvv -> 0
^^v -> -1
^v^ -> 1
^vv -> 0
vv^ -> 1
v^v -> -1
v^^ -> 0
^vvv^^vv^vv^v^ -> 1
^vvv^^vv^vv^v^^ -> 0
^vvv^^vv^vv^v^^^ -> 1
^vvv^^vv^vv^v^^v -> -1
^vvv^^vv^vv^v^^vv -> 0
^vvv^^vv^vv^v^^vvv -> -1
^vvvvvvvvvvvv -> 0
^^vvvvvvvvvvvv -> 0
^^^vvvvvvvvvvvv -> 0
vvv^^^^^^^^^^^^ -> 0
vv^^^^^^^^^^^^ -> 0
v^^^^^^^^^^^^ -> 0

*/

#include <assert.h>
#include <stdio.h>

int
vote(const char *s)
{
	static const int states[][2] = {
	    {1, 0},
	    {1, -1},
	    {0, -1},
	};

	size_t i;
	int p;

	p = 0;
	for (i = 0; s[i]; i++) {
		switch (s[i]) {
		case '^':
			p = states[p + 1][0];
			break;
		case 'v':
			p = states[p + 1][1];
			break;
		}
	}
	return p;
}

int
main(void)
{
	assert(vote("") == 0);
	assert(vote("^^") == 0);
	assert(vote("^v") == -1);
	assert(vote("^") == 1);
	assert(vote("v") == -1);
	assert(vote("v^") == 1);
	assert(vote("vv") == 0);
	assert(vote("^^^") == 1);
	assert(vote("vvv") == -1);
	assert(vote("^^^^") == 0);
	assert(vote("vvvv") == 0);
	assert(vote("^^^^^") == 1);
	assert(vote("vvvvv") == -1);
	assert(vote("^^^^^^") == 0);
	assert(vote("vvvvvv") == 0);
	assert(vote("^^v") == -1);
	assert(vote("^v^") == 1);
	assert(vote("^vv") == 0);
	assert(vote("vv^") == 1);
	assert(vote("v^v") == -1);
	assert(vote("v^^") == 0);
	assert(vote("^vvv^^vv^vv^v^") == 1);
	assert(vote("^vvv^^vv^vv^v^^") == 0);
	assert(vote("^vvv^^vv^vv^v^^^") == 1);
	assert(vote("^vvv^^vv^vv^v^^v") == -1);
	assert(vote("^vvv^^vv^vv^v^^vv") == 0);
	assert(vote("^vvv^^vv^vv^v^^vvv") == -1);
	assert(vote("^vvvvvvvvvvvv") == 0);
	assert(vote("^^vvvvvvvvvvvv") == 0);
	assert(vote("^^^vvvvvvvvvvvv") == 0);
	assert(vote("vvv^^^^^^^^^^^^") == 0);
	assert(vote("vv^^^^^^^^^^^^") == 0);
	assert(vote("v^^^^^^^^^^^^") == 0);

	return 0;
}
