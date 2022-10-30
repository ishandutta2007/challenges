/*

A class went to a school trip. And, as usually, all N kids have got their backpacks stuffed with candy.
But soon quarrels started all over the place, as some of the kids had more candies than others.
Soon, the teacher realized that he has to step in: "Everybody, listen! Put all the candies you have on this table here!"

Soon, there was quite a large heap of candies on the teacher’s table. "Now, I will divide the candies into N equal heaps and everyone will get one of them."
announced the teacher. "Wait, is this really possible?" wondered some of the smarter kids.

Task

You are given the number of candies each child brought. Find out whether the teacher can divide the candies into N exactly equal heaps.
(For the purpose of this task, all candies are of the same type.)

Input

The first line of the input file contains an integer T,1≤T≤100 specifying the number of test cases. Each test case is preceded by a blank line.

Each test case looks as follows: The first line contains N,1≤N≤20000 – the number of children.
Each of the next N lines contains the number of candies one child brought. Each child has less than 263.

Output

For each of the test cases output a single line with a single word "YES" if the candies can be distributed equally, or "NO" otherwise.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

const char *
shareable(uvlong k, uvlong *a, size_t n)
{
	size_t i;
	uvlong c;

	c = 0;
	for (i = 0; i < n; i++)
		c = (c + a[i]) % k;
	return (c == 0) ? "YES" : "NO";
}

void
test(uvlong k, uvlong *a, size_t n, const char *r)
{
	const char *p;

	p = shareable(k, a, n);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	uvlong a1[] = {5, 2, 7, 3, 8};
	uvlong a2[] = {7, 11, 2, 7, 3, 4};

	test(5, a1, nelem(a1), "YES");
	test(6, a2, nelem(a2), "NO");

	return 0;
}
