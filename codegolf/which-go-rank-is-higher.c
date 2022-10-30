/*

Players of the traditional board game Go measure their skill in a system of ranks:

Players new to the game are ranked 30th kyū (written 30k) and progress counting down to 1st kyū (written 1k). These are considered the student ranks.
A player may promote from 1st kyū to 1st dan rank (written 1d), and then progress counting up to 7th dan rank (written 7d). These are the master ranks.
Exceptionally skilled players past 7d may promote to the 1st professional dan rank 1p, and progress counting up to 9th professional dan rank (written 9p). This is the highest rank.
In short: ranks are ordered 30k < 29k < ··· < 1k < 1d < 2d < ··· < 7d < 1p < 2p < ··· < 9p.

Task
Given two strings among {30k, …, 1k, 1d, …, 7d, 1p, …, 9p} as input, output the higher rank of the two. (If they are equal, simply output either input.)

(As usual, I/O is flexible — your answer may be a function or a full program, reading input in any reasonable fashion and producing output in any reasonable fashion.)

This is code-golf: the objective is to minimize your code's byte count.

Test cases
(Format: input1 input2   output.)

29k 9k    9k
21k 27k   21k
6d 1p     1p
5d 17k    5d
1k 1d     1d
1d 1d     1d
1d 2d     2d
9p 1d     9p
2d 30k    2d
1p 1k     1p
1d 1p     1p
1p 2d     1p
7p 8p     8p
30k 30k   30k

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
rank(const char *s, int r[2])
{
	static const char title[] = "kdp";
	char c, *p;
	int v;

	r[0] = r[1] = 0;
	if (sscanf(s, "%d%c", &v, &c) != 2)
		return;

	r[0] = v;
	p = strchr(title, c);
	if (p)
		r[1] = p - title + 1;
}

int
cmp(int p[2], int q[2])
{
	if (p[1] > q[1])
		return 1;
	if (p[1] < q[1])
		return -1;
	if (p[1] < 2)
		return (p[0] < q[0]) ? 1 : -1;
	return (p[0] > q[0]) ? 1 : -1;
}

const char *
superior(const char *a, const char *b)
{
	int p[2], q[2];

	rank(a, p);
	rank(b, q);
	return (cmp(p, q) >= 0) ? a : b;
}

void
test(const char *a, const char *b, const char *r)
{
	const char *p;

	p = superior(a, b);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test("29k", "9k", "9k");
	test("21k", "27k", "21k");
	test("6d", "1p", "1p");
	test("5d", "17k", "5d");
	test("1k", "1d", "1d");
	test("1d", "1d", "1d");
	test("1d", "2d", "2d");
	test("9p", "1d", "9p");
	test("2d", "30k", "2d");
	test("1p", "1k", "1p");
	test("1d", "1p", "1p");
	test("1p", "2d", "1p");
	test("7p", "8p", "8p");
	test("30k", "30k", "30k");

	return 0;
}
