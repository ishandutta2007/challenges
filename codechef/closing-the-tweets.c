/*

Little kids, Jack and Evan like playing their favorite game Glass-and-Stone. Today they want to play something new and came across Twitter on their father's laptop.

They saw it for the first time but were already getting bored to see a bunch of sentences having at most 140 characters each.
The only thing they liked to play with it is, closing and opening tweets.

There are N tweets on the page and each tweet can be opened by clicking on it, to see some statistics related to that tweet.
Initially all the tweets are closed. Clicking on an open tweet closes it and clicking on a closed tweet opens it.
There is also a button to close all the open tweets. Given a sequence of K clicks by Jack, Evan has to guess the total number of open tweets just after each click. Please help Evan in this game.

Input
First line contains two integers N K, the number of tweets (numbered 1 to N) and the number of clicks respectively (1 ≤ N, K ≤ 1000). Each of the following K lines has one of the following.
CLICK X , where X is the tweet number (1 ≤ X ≤ N)
CLOSEALL

Output
Output K lines, where the ith line should contain the number of open tweets just after the ith click.

Example
Input:
3 6
CLICK 1
CLICK 2
CLICK 3
CLICK 2
CLOSEALL
CLICK 1

Output:
1
2
3
2
0
1

Explanation:

Let open[x] = 1 if the xth tweet is open and 0 if its closed.
Initially open[1..3] = { 0 , 0 , 0 }. Here is the state of open[1..3] after each click and corresponding count of open tweets.

CLICK 1 : { 1, 0, 0 }, open count = 1
CLICK 2 : { 1, 1, 0 }, open count = 2
CLICK 3 : { 1, 1, 1 }, open count = 3
CLICK 2 : { 1, 0, 1 }, open count = 2
CLOSEALL : { 0, 0, 0 }, open count = 0
CLICK 1 : { 1, 0, 0 }, open count = 1

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int
tweets(int n, const char **s, int k, int *r)
{
	int c, i, j;
	char *b;

	b = calloc(k, sizeof(*b));
	if (!b)
		return -1;

	c = 0;
	for (i = 0; i < k; i++) {
		if (!strncmp(s[i], "CLICK", 5)) {
			j = atoi(s[i] + 5) - 1;
			if (!(0 <= j && j < n))
				continue;

			b[j] = !b[j];
			c = (b[j]) ? c + 1 : c - 1;
		} else if (!strcmp(s[i], "CLOSEALL")) {
			memset(b, 0, k * sizeof(*b));
			c = 0;
		}

		r[i] = c;
	}

	free(b);
	return 0;
}

void
test(int n, const char **s, int k, int *r)
{
	int p[128];

	assert(tweets(n, s, k, p) >= 0);
	print(p, k);
	assert(!memcmp(p, r, sizeof(*r) * k));
}

int
main(void)
{
	const char *s1[] = {
	    "CLICK 1",
	    "CLICK 2",
	    "CLICK 3",
	    "CLICK 2",
	    "CLOSEALL",
	    "CLICK 1",
	};
	int r1[] = {1, 2, 3, 2, 0, 1};

	test(3, s1, nelem(s1), r1);

	return 0;
}
