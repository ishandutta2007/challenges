/*

There are three cups on a table, at positions A, B, and C.
At the start, there is a ball hidden under the cup at position B.

Image of cups where ball is under middle cup

However, I perform several swaps on the cups, which is notated as two letters.
For example, if I swap the cups at positions A and B, I could notate this as AB or BA.

Create a function that returns the letter position that the ball is at, once I finish swapping the cups.
The swaps will be given to you as an array.

Worked Example

cupSwapping(["AB", "CA", "AB"]) ➞ "C"

// Ball begins at position B.
// Cups A and B swap, so the ball is at position A.
// Cups C and A swap, so the ball is at position C.
// Cups A and B swap, but the ball is at position C, so it doesn't move.

Examples

cupSwapping(["AB", "CA"]) ➞ "C"

cupSwapping(["AC", "CA", "CA", "AC"]) ➞ "B"

cupSwapping(["BA", "AC", "CA", "BC"]) ➞ "A"

Notes

    A swap could be notated in two different ways, since both ways end up with the same outcome.
    All swaps will be notated as capital letters and will be valid.
    You cannot swap a cup with itself.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
swap(int *x, int *y)
{
	int t;

	t = *x;
	*x = *y;
	*y = t;
}

char
cupswap(const char **s, size_t n)
{
	int c[3], x, y;
	size_t i;

	c[0] = c[2] = 0;
	c[1] = 1;
	for (i = 0; i < n; i++) {
		x = s[i][0] - 'A';
		y = s[i][1] - 'A';
		if (x < 0 || y < 0 || x >= 3 || y >= 3)
			continue;

		swap(&c[x], &c[y]);
	}

	if (c[0])
		return 'A';
	if (c[1])
		return 'B';
	return 'C';
}

int
main(void)
{
	const char *s1[] = {
	    "AB",
	    "CA",
	};
	const char *s2[] = {
	    "AB",
	    "CA",
	    "AB",
	};
	const char *s3[] = {
	    "AC",
	    "CA",
	    "CA",
	    "AC",
	};
	const char *s4[] = {
	    "BA",
	    "AC",
	    "CA",
	    "BC",
	};
	const char *s5[] = {
	    "BC",
	    "CB",
	    "CA",
	    "BA",
	};
	const char *s6[] = {
	    "BC",
	};
	const char *s7[] = {
	    "BA",
	    "CA",
	    "CB",
	    "CA",
	};

	assert(cupswap(s1, nelem(s1)) == 'C');
	assert(cupswap(s2, nelem(s2)) == 'C');
	assert(cupswap(s3, nelem(s3)) == 'B');
	assert(cupswap(s4, nelem(s4)) == 'A');
	assert(cupswap(s5, nelem(s5)) == 'A');
	assert(cupswap(s6, nelem(s6)) == 'C');
	assert(cupswap(s7, nelem(s7)) == 'B');
	assert(cupswap(NULL, 0) == 'B');

	return 0;
}
