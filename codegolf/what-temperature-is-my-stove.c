/*

My stovetop has 10 (0 through 9) different settings of heat and a very odd way of cycling through them.

    It always starts at 0

    When I hit plus it increments the number, unless the number is 9 in which case it becomes 0, or the number is 0 in which case it becomes 9.

    When I hit minus it decrements the number, unless the number is zero in which case it becomes 4.

There are no other temperature control buttons.

In this challenge you will take as input a string of commands and output which setting my stovetop ends up on after running that sequence.

Answers will be scored in bytes with fewer bytes being better.
Input

You may take input in any of the following formats:

    A list/array/vector/stream of booleans/1s or 0s/1s or -1s
    A string (or list/array/vector/stream) of two different characters (which should be consistent for your program)

And you may output

    An integer on the range 0-9.

    A character on the range '0'-'9'.

    A string of size 1 consisting of the above.

Testcases

Input as a string - for decrement and + for increment.

 : 0
- : 4
+ : 9
-- : 3
-+ : 5
+- : 8
++ : 0
--- : 2
--+ : 4
-+- : 4
-++ : 6
+-- : 7
+-+ : 9
++- : 4
+++ : 9
---- : 1
---+ : 3

*/

#include <assert.h>
#include <stdio.h>

unsigned
stove(const char *s)
{
	unsigned r;
	size_t i;

	r = 0;
	for (i = 0; s[i]; i++) {
		if (s[i] == '+')
			r = (r == 0) ? 9 : (r + 1) % 10;
		else if (s[i] == '-')
			r = (r == 0) ? 4 : r - 1;
	}
	return r;
}

int
main(void)
{
	assert(stove("") == 0);
	assert(stove("-") == 4);
	assert(stove("+") == 9);
	assert(stove("--") == 3);
	assert(stove("-+") == 5);
	assert(stove("+-") == 8);
	assert(stove("++") == 0);
	assert(stove("---") == 2);
	assert(stove("--+") == 4);
	assert(stove("-+-") == 4);
	assert(stove("-++") == 6);
	assert(stove("+--") == 7);
	assert(stove("+-+") == 9);
	assert(stove("++-") == 4);
	assert(stove("+++") == 9);
	assert(stove("----") == 1);
	assert(stove("---+") == 3);

	return 0;
}
