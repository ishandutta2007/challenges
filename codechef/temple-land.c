/*

The snakes want to build a temple for Lord Cobra. There are multiple strips of land that they are looking at, but not all of them are suitable.
They need the strip of land to resemble a coiled Cobra. You need to find out which strips do so.

Formally, every strip of land, has a length. Suppose the length of the i-th strip is is Ni, then there will be Ni integers, Hi1, Hi2, .. HiNi, which represent the heights of the ground at various parts of the strip, in sequential order.
That is, the strip has been divided into Ni parts and the height of each part is given. This strip is valid, if and only if all these conditions are satisfied:

There should be an unique 'centre' part. This is where the actual temple will be built. By centre, we mean that there should be an equal number of parts to the left of this part, and to the right of this part.
Hi1 = 1
The heights keep increasing by exactly 1, as you move from the leftmost part, to the centre part.
The heights should keep decreasing by exactly 1, as you move from the centre part to the rightmost part. Note that this means that HiNi should also be 1.
Your job is to look at every strip and find if it's valid or not.

Input

The first line contains a single integer, S, which is the number of strips you need to look at. The description of each of the S strips follows
The first line of the i-th strip's description will contain a single integer: Ni, which is the length and number of parts into which it has been divided.
The next line contains Ni integers: Hi1, Hi2, .., HiNi. These represent the heights of the various parts in the i-th strip.

Output

For each strip, in a new line, output "yes" if is a valid strip, and "no", if it isn't.

Constraints

1 ≤ S ≤ 100
3 ≤ Ni ≤ 100
1 ≤ Hij ≤ 100

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
valid(int *h, size_t n)
{
	size_t i, j;
	int c;

	if (!(n & 1))
		return false;

	i = 0;
	j = n;
	for (c = 1; i < j; c++) {
		if (h[i++] != c || h[--j] != c)
			return false;
	}
	return true;
}

int
main(void)
{
	int h1[] = {1, 2, 3, 2, 1};
	int h2[] = {2, 3, 4, 5, 4, 3, 2};
	int h3[] = {1, 2, 3, 4, 3};
	int h4[] = {1, 3, 5, 3, 1};
	int h5[] = {1, 2, 3, 4, 3, 2, 1};
	int h6[] = {1, 2, 3, 2};
	int h7[] = {1, 2, 2, 1};

	assert(valid(h1, nelem(h1)) == true);
	assert(valid(h2, nelem(h2)) == false);
	assert(valid(h3, nelem(h3)) == false);
	assert(valid(h4, nelem(h4)) == false);
	assert(valid(h5, nelem(h5)) == true);
	assert(valid(h6, nelem(h6)) == false);
	assert(valid(h7, nelem(h7)) == false);

	return 0;
}
