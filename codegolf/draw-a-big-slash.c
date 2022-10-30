/*

Given a non-negative integer, print out an X that is that big. X is the output for input 0, and you will add slashes equal to the input in each direction to extend the X for larger inputs.

Test Cases
0

X
1

\ /
 X
/ \
2

\   /
 \ /
  X
 / \
/   \
...

10

\                   /
 \                 /
  \               /
   \             /
    \           /
     \         /
      \       /
       \     /
        \   /
         \ /
          X
         / \
        /   \
       /     \
      /       \
     /         \
    /           \
   /             \
  /               \
 /                 \
/                   \

Rules
You may either print the output, or return a string or list of string from a function. A trailing newline, as well as extra interior whitespace that does not affect appear, is allowed.

This is code-golf, so shortest answer in bytes wins!

*/

#include <stdio.h>

void
slash(int n)
{
	int s, x, y;

	s = (2 * n) + 1;
	for (y = 0; y < s; y++) {
		for (x = 0; x < s; x++) {
			if (x == y && x == s / 2)
				printf("X");
			else if (x == y)
				printf("\\");
			else if (x == s - y - 1)
				printf("/");
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	slash(0);
	slash(1);
	slash(2);
	slash(10);

	return 0;
}
