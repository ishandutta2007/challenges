/*

Challenge :

Given an integer n as input. Create a diamond that is 2x the given number n.
Input :

Input is integer n and 2 < n ≤ 3000.
Output :

Output will be a string and it will be in form of a diamond consisting of + with an addition line at the start showing n using +
Examples :

D(3) :

+++
  +
 +++
+++++
+++++
 +++
  +

D(5) :

+++++
    +
   +++
  +++++
 +++++++
+++++++++
+++++++++
 +++++++
  +++++
   +++
    +

D(6) : 

++++++
     +
    +++
   +++++
  +++++++
 +++++++++
+++++++++++
+++++++++++
 +++++++++
  +++++++
   +++++
    +++
     +

Winning Criteria :

This is code-golf so shortest code in bytes for each programming language wins.

*/

#include <stdbool.h>
#include <stdio.h>

void
chars(char c, int n, bool nl)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%c", c);

	if (nl)
		printf("\n");
}

void
diamond(int n)
{
	int i, j;

	printf("D(%d)\n", n);
	chars('+', n, true);
	for (i = 0; i <= 2 * n; i++) {
		if (i == n)
			continue;

		j = (i < n) ? i : 2 * n - i;
		chars(' ', n - j - 1, false);
		chars('+', 2 * j + 1, true);
	}
	printf("\n");
}

int
main(void)
{
	diamond(3);
	diamond(5);
	diamond(6);
	return 0;
}
