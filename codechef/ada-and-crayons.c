/*

Ada has an array of N crayons, some crayons are pointing upwards and some downwards. Ada thinks that an array of crayons is beautiful if all the crayons are pointing in the same direction.
In one step you can flip any segment of consecutive crayons. After flipping a segment, all crayons pointing downwards will point upwards and visceversa
What is the minimum number of steps to make the array of crayons beautiful?

Input

The first line of the input contains T the number of test cases. Each test case is described in one line containing a string S of N characters, the i-th character is 'U' if the i-th crayon is pointing upwards and 'D' if it is pointing downwards.

Output

For each test case, output a single line containing the minimum number of flips needed to make all crayons point to the same direction.

Constraints
1 ≤ T ≤ 3000
1 ≤ N ≤ 50

*/

#include <assert.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

void
inc(int c, size_t *u, size_t *d)
{
	if (c == 'U')
		(*u)++;
	else if (c == 'D')
		(*d)++;
}

size_t
flips(const char *s)
{
	size_t i, u, d;

	u = d = 0;
	inc(s[0], &u, &d);
	for (i = 1; s[i - 1] && s[i]; i++) {
		if (s[i] != s[i - 1])
			inc(s[i], &u, &d);
	}
	return min(u, d);
}

int
main(void)
{
	assert(flips("UUDDDUUU") == 1);

	return 0;
}
