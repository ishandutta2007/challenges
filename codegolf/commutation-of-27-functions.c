/*

Introduction
Let's define a ternary function as a function from the three-element set S = {0,1,2} to itself: it associates to each element of S another element of S. One example of a ternary function f is

f(0) = 0; f(1) = 2; f(2) = 0
There are exactly 27 different ternary functions, and we represent them with integers from 0 to 26: a function f is encoded as f(0) + 3*f(1) + 9*f(2). The example function above is encoded as the number 6.

We can apply two ternary functions f and g in sequence, and if f(g(k)) == g(f(k)) holds for all k in S, then the functions commute. Your task is to verify whether this is the case.

Input
Your inputs are two integers in the inclusive range from 0 to 26. They represent two ternary functions f and g. Input must be taken in decimal, binary or unary (string of 1s) format.

Output
Your output is a truthy value if f and g commute, and a falsey value if they don't. You may not assume that the inputs are ordered.

Examples
Consider the inputs 5 and 16. They encode the ternary functions

f(0) = 2; f(1) = 1; f(2) = 0
g(0) = 1; g(1) = 2; g(2) = 1
We have f(g(1)) == f(2) == 0 and g(f(1)) == g(1) == 2, so f and g don't commute and the correct output is falsey.

On the other hand, the inputs 3 and 10 encode the ternary functions

f(0) = 0; f(1) = 1; f(2) = 0
g(0) = 1; g(1) = 0; g(2) = 1
and it can be verified that f(g(k)) == g(f(k)) holds for all k in S. Then the correct output is truthy.

Here is the 27×27 table of all possible inputs, with + marking a truthy output and - a falsey output:

+ - - + - - + - - + - - + - - + - - + - - + - - + - -
- + - - - - - - - - - - + - - - - - - - - + - - - - -
- - + - - - - - - - - - - - - - - - - - - + - - + - -
+ - - + - - - - - - + - - + - - - - + - - + - - - - -
- - - - + - - - - - - - - + - - - - - - - + - - - - -
- - - - - + - - - - - - - + - - - - - - - + - - - - -
+ - - - - - + - - - - - - - - - - - - - - + - - - - -
- - - - - - - + - - - + - - - - - - - - - + - - - - -
- - - - - - - - + - - - - - - - - - + - - + - - - - -
+ - - - - - - - - + - - - - - - - - - - - + - - - - -
- - - + - - - - - - + - - - - - - - - - - + - - - - -
- - - - - - - + - - - + - - - - - - - - - + - - - - -
+ + - - - - - - - - - - + + - - - - - - - + + - - - -
- - - + + + - - - - - - + + + - - - - - - + + + - - -
- - - - - - - - - - - - - + + - - - - - - + - - - - -
+ - - - - - - - - - - - - - - + - - - - - + - - - - -
- - - - - - - - - - - - - - - - + - - - - + - + - - -
- - - - - - - - - - - - - - - - - + - - - + + - - - -
+ - - + - - - - + - - - - - - - - - + - - + - - - - +
- - - - - - - - - - - - - - - - - - - + - + - - - - +
- - - - - - - - - - - - - - - - - - - - + + - - - - +
+ + + + + + + + + + + + + + + + + + + + + + + + + + +
- - - - - - - - - - - - + + - - - + - - - + + - - - +
- - - - - - - - - - - - - + - - + - - - - + - + + - +
+ - + - - - - - - - - - - - - - - - - - - + - + + - +
- - - - - - - - - - - - - - - - - - - - - + - - - + +
- - - - - - - - - - - - - - - - - - + + + + + + + + +

Rules and scoring
You can write a full program or a function. The lowest byte count wins, and standard loopholes are disallowed.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
ternary(int n, int c[3])
{
	int i, j, k;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++) {
				if (i + (3 * j) + (9 * k) == n) {
					c[0] = i;
					c[1] = j;
					c[2] = k;
					return true;
				}
			}
		}
	}
	return false;
}

bool
commute(int n, int m)
{
	int f[3], g[3], i;

	if (!ternary(n, f) || !ternary(m, g))
		return false;

	for (i = 0; i < 3; i++) {
		if (f[g[i]] != g[f[i]])
			return false;
	}
	return true;
}

void
table(void)
{
	int i, j;

	for (i = 0; i < 27; i++) {
		for (j = 0; j < 27; j++)
			printf("%c ", commute(i, j) ? '+' : '-');
		printf("\n");
	}
}

int
main(void)
{
	table();
	return 0;
}
