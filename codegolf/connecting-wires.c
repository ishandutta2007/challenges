/*

Your goal is to create a program. It must take input indefinitely.

Here is a sample run (the > shows that the line is the output from the program)

2,6
> 0
5,6
> 0
7,5
> 0
2,7
> 1
Since 2 is connected to 6, which in turn is connected to 5 and then 7, 2 and 7 are hence connected.

5,2
> 1

...
Clarifications
Whenever the user writes any two numbers (separated by any delimiter you prefer), the program must output whether they are connected or not.
If they are not connected, the program must output a falsy value (0), however if the wires are connected, the program must output a true value (1).

"We are to interpret the pair p-q as meaning “p is connected to q.” We assume the relation “is connected to” to be transitive: If p is connected to q, and q is connected to r, then p is connected to r."

The input must be separated from the output by a newline \n

The input will always be integers in base ten and never floats.

*/

#include <stdio.h>

int
main(void)
{
	char s[32];
	int x, y;

	for (;;) {
		printf("> ");
		if (!fgets(s, sizeof(s), stdin)) {
			printf("\n");
			break;
		}

		if (sscanf(s, "%d,%d", &x, &y) == 2)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}
